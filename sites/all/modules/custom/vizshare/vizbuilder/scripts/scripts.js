(function() {
  var DATA_UNITY_HOST, DATA_UNITY_URL, vizBuilder;

  DATA_UNITY_URL = 'http://0.0.0.0:6543/api/beta';

  DATA_UNITY_HOST = 'http://data-unity.com';

  DATA_UNITY_URL = DATA_UNITY_HOST + '/api/beta';

  vizBuilder = angular.module("vizBuilder", ['restangular']);

  vizBuilder.config(function($routeProvider) {
    return $routeProvider.when("/", {
      templateUrl: "/views/datatables.html",
      controller: "DatatableController"
    }).when("/datatables", {
      templateUrl: "/views/datatables.html",
      controller: "DatatableController"
    }).when("/select-type", {
      templateUrl: "/views/select-type.html",
      controller: "VisualizationTypeController"
    }).when("/select-columns", {
      templateUrl: "/views/select-columns.html",
      controller: "ColumnsController"
    }).when("/visualization", {
      templateUrl: "/views/visualization.html",
      controller: "VisualizationController"
    }).otherwise({
      redirectTo: "/"
    });
  });

  vizBuilder.config([
    '$httpProvider', 'RestangularProvider', function($httpProvider, RestangularProvider) {
      $httpProvider.defaults.useXDomain = true;
      return delete $httpProvider.defaults.headers.common['X-Requested-With'];
    }
  ]);

  vizBuilder.config(function(RestangularProvider) {
    var url;
    url = DATA_UNITY_URL;
    console.log(window.data_unity_url);
    if (window.data_unity_url !== void 0) {
      url = window.data_unity_url;
    } else {
      window.data_unity_url = DATA_UNITY_URL;
    }
    return RestangularProvider.setBaseUrl(url);
  });

}).call(this);

(function() {
  var renderers, vizBuilder;

  vizBuilder = angular.module('vizBuilder');

  vizBuilder.config(function(RestangularProvider) {
    return RestangularProvider.addResponseInterceptor(function(data, operation, what, url, response, deferred) {
      var extractedData;
      extractedData = data;
      if (operation === "getList") {
        if (url.match('datatablecatalogs')) {
          extractedData = data.dataTable;
        } else if (url.match('sources-datasets')) {
          extractedData = [data.dataset];
        }
      }
      return extractedData;
    });
  });

  vizBuilder.factory('DatatableService', function($q, $timeout, $http, Restangular, $rootScope) {
    Restangular.extendModel('datatables', function(model) {
      model.fetchSources = function() {
        var gotDatasets;
        gotDatasets = this.all('sources-datasets').getList();
        return gotDatasets.then(function(data) {
          return model.source = data[0];
        });
      };
      model.createGroupAggregateDataTable = function(groupField, aggField, aggType) {
        var deferred, tableCreated;
        deferred = $q.defer();
        dataunity.config.setBaseUrl('http://data-unity.com');
        tableCreated = dataunity.querytemplate.createGroupAggregateDataTable('name', this['@id'], groupField, aggField, aggType);
        tableCreated.done(function(dataTableURL) {
          return $rootScope.$apply(deferred.resolve(dataTableURL));
        });
        return deferred.promise;
      };
      model._poll = function(url, callback) {
        console.log('poll: ' + url);
        return $http.get(url, {
          timeout: 1000
        }).success(function(data, status, headers, config) {
          console.log('success');
          if (data.status === 'completed') {
            return callback(data.data);
          } else {
            return $timeout(function() {
              console.log('waiting...');
              return model._poll(url, callback);
            }, 1000);
          }
        }).error(function(data, status, headers, config) {
          if (status === 404) {
            console.log("404 error, going to try again");
            return $timeout(function() {
              return model._poll(url, callback);
            }, 1000);
          } else {
            return console.log(data);
          }
        });
      };
      model.getDataEndpoint = function(callback) {
        var dataIn, url;
        console.log('getDataEndpoint');
        console.log(this['@id']);
        url = window.data_unity_url + '/jobs/datatable-jobs';
        dataIn = {
          "dataTable": this['@id']
        };
        return $http.post(url, dataIn, {
          cache: false,
          timeout: 9000
        }).success(function(data, status, headers, config) {
          var jobID, jobUrl;
          console.log('success (creating a job)');
          jobID = headers()['location'].replace(url, '');
          jobID = jobID.replace('/', '');
          console.log(jobID);
          jobUrl = window.data_unity_url + '/jobs/datatable-jobs/' + jobID;
          return model._poll(jobUrl, callback);
        }).error(function(dataE, statusE, headersE, configE) {
          console.log('error!');
          console.log(statusE);
          console.log(headersE);
          console.log(dataE);
          return console.log(configE);
        });
      };
      return model;
    });
    return {
      fetchTables: function() {
        var deferred, gotList;
        deferred = $q.defer();
        gotList = Restangular.all('datatablecatalogs/public').getList();
        gotList.then(function(data) {
          var dataTables;
          dataTables = data.map(function(tableRef) {
            var dataTable, id, tableURL;
            console.log(tableRef['@id']);
            tableURL = tableRef['@id'];
            id = tableURL.substring(tableURL.lastIndexOf('/') + 1);
            dataTable = Restangular.one('datatables', id);
            dataTable['@id'] = tableRef['@id'];
            dataTable.label = tableRef.label;
            dataTable.get({
              retrieve: 'structure'
            }).then(function(dataTableData) {
              dataTable.structure = dataTableData.structure;
              return dataTable.fetchSources();
            });
            return dataTable;
          });
          console.log($rootScope);
          return $timeout(function() {
            return deferred.resolve(dataTables);
          });
        });
        return deferred.promise;
      },
      fetchTable: function(tableRef) {
        var dtPromise, id, tableURL;
        console.log('fetchTable');
        tableURL = tableRef['@id'];
        id = tableURL.substring(tableURL.lastIndexOf('/') + 1);
        dtPromise = Restangular.one('datatables', id).get({
          retrieve: 'structure'
        });
        return dtPromise;
      }
    };
  });

  renderers = [
    {
      rendererName: 'vizshare.barchart',
      label: 'Bar chart',
      description: 'A bar chart or bar graph is a chart with rectangular bars with lengths proportional to the quantitative values that they represent.',
      type: 'barchart',
      thumbnail: '/images/thmb-barchart-245px.png',
      datasets: [
        {
          name: 'dataset1',
          fields: [
            {
              vizField: 'xAxis',
              dataType: ['string'],
              required: true
            }, {
              vizField: 'yAxis',
              dataType: ['decimal'],
              required: true,
              needsAggregate: true
            }
          ]
        }
      ],
      vizOptions: {}
    }, {
      rendererName: 'vizshare.piechart',
      label: 'Pie chart',
      description: 'A pie chart is a circular chart divided into sectors, illustrating numerical proportion. In a pie chart, the arc length of each sector (and consequently its central angle and area), is proportional to the quantity it represents.',
      type: 'piechart',
      thumbnail: '/images/thmb-donutchart-245px.png',
      datasets: [
        {
          name: 'dataset1',
          fields: [
            {
              vizField: 'name',
              dataType: ['string'],
              required: true
            }, {
              vizField: 'value',
              dataType: ['decimal'],
              required: true,
              needsAggregate: true
            }
          ]
        }
      ],
      vizOptions: {}
    }, {
      rendererName: 'vizshare.geoleaflet',
      label: 'Map plot',
      description: 'Maps are symbolic depictions highlighting the relationships between elements such as objects, regions and themes within a territorial space.',
      type: 'geoleaflet',
      thumbnail: '/images/thmb-map-location-245px.png',
      datasets: [
        {
          name: 'dataset1',
          "fields": [
            {
              "vizField": "lat",
              "dataField": "Lat"
            }, {
              "vizField": "long",
              "dataField": "Long"
            }, {
              "vizField": "title",
              "dataField": "Name"
            }, {
              "vizField": "value",
              "dataField": "Value"
            }
          ]
        }
      ],
      vizOptions: {
        "scales": [
          {
            "name": "area",
            "type": "linear",
            "domain": {
              "data": "default",
              "vizField": "value"
            },
            "range": [50000, 100000]
          }, {
            "name": "onetoten",
            "type": "linear",
            "domain": [1, 10],
            "range": [50000, 1000000]
          }, {
            "name": "colours",
            "type": "linear",
            "domain": {
              "data": "default",
              "vizField": "value"
            },
            "range": ["red", "blue"]
          }, {
            "name": "coloursonetoten",
            "type": "linear",
            "domain": [1, 10],
            "range": ["red", "blue"]
          }
        ],
        "marks": [
          {
            "type": "latlongcircle",
            "from": {
              "data": "default"
            },
            "properties": {
              "enter": {
                "lat": {
                  "vizField": "lat"
                },
                "long": {
                  "vizField": "long"
                },
                "text": {
                  "vizField": "title"
                },
                "fill": {
                  "scale": "colours",
                  "vizField": "value"
                }
              }
            }
          }
        ]
      }
    }
  ];

  vizBuilder.factory('RendererService', function() {
    return {
      getRenderers: function() {
        return renderers;
      }
    };
  });

}).call(this);

(function() {
  var AGGREGATION_METHODS, STEPS, vizBuilder;

  vizBuilder = angular.module("vizBuilder");

  STEPS = [
    {
      name: 'datasets',
      text: 'Select datasets'
    }, {
      name: 'type',
      text: 'Select visualization type'
    }, {
      name: 'columns',
      text: 'Select data columns'
    }, {
      name: 'visualize',
      text: 'Edit visualization'
    }
  ];

  AGGREGATION_METHODS = ["Count", "Sum", "Average", "Min", "Max", "First", "Last"];

  vizBuilder.directive('initModel', [
    '$rootScope', '$compile', function($rootScope, $compile) {
      return {
        restrict: 'A',
        link: function(scope, element, attrs) {
          console.log('directive initModel');
          $rootScope.imagePath = element.attr('image-path');
          console.log(element[0].value);
          scope.vizDef = element[0].value;
          element.attr('ng-model', 'vizDef');
          element.removeAttr('init-model');
          $compile(element)(scope);
          console.log('scope');
          return console.log(scope);
        }
      };
    }
  ]);

  vizBuilder.directive('wizardProgressBar', function() {
    return {
      restrict: 'AE',
      link: function(scope, element, attrs) {
        scope.activeStep = attrs.activeStep;
        return scope.steps = STEPS;
      },
      templateUrl: '/views/wizard-progress-bar.html'
    };
  });

  vizBuilder.controller("VizDefController", function($scope, $rootScope) {
    console.log('VizDefController');
    $rootScope.state = {};
    return $rootScope.$watch('vizDef', function(newVal, old) {
      return $scope.state.vizDef = newVal;
    });
  });

  vizBuilder.controller("VizBuilderController", function($scope) {
    return console.log('VizBuilderController');
  });

  vizBuilder.controller("DatatableController", function($scope, $rootScope, DatatableService) {
    var tablesFetched;
    $scope.select = function(dataset) {
      dataset.selected = !dataset.selected;
      $rootScope.state.dataset = dataset;
      dataset.btnState = 'btn-primary';
      if (dataset.selected) {
        return dataset.btnState = 'btn-danger';
      }
    };
    tablesFetched = DatatableService.fetchTables();
    return tablesFetched.then(function(data) {
      console.log('tablesFetched');
      $scope.datatables = data;
      return console.log(data);
    });
  });

  vizBuilder.controller("VisualizationTypeController", function($scope, $rootScope, RendererService, $http) {
    $scope.renderers = RendererService.getRenderers();
    return $scope.selectRenderer = function(renderer) {
      var r, _i, _len, _ref;
      console.log('selectRenderer');
      _ref = $scope.renderers;
      for (_i = 0, _len = _ref.length; _i < _len; _i++) {
        r = _ref[_i];
        r.selected = false;
      }
      $rootScope.state.renderer = renderer;
      console.log($rootScope.state);
      return renderer.selected = true;
    };
  });

  vizBuilder.controller("ColumnsController", function($scope, $rootScope, DatatableService, RendererService) {
    console.log('ColumnsController');
    console.log($rootScope.state.dataset);
    console.log($rootScope.state.renderer);
    $scope.aggregationMethods = AGGREGATION_METHODS;
    $rootScope.state.aggregationMethod = "Count";
    console.log($scope);
    $scope.$watch('state.aggregationMethod', function(newVal) {
      return console.log('aggregationMethod ' + newVal);
    });
    $scope.selectAggregationMethod = function(method) {
      return $scope.selectedMethod = method;
    };
    return $scope.selectColForField = function(field, col) {
      var c, _i, _len, _ref;
      if (col.selected === void 0) {
        col.selected = {};
      }
      _ref = $rootScope.state.dataset['structure']['component'];
      for (_i = 0, _len = _ref.length; _i < _len; _i++) {
        c = _ref[_i];
        if (c.selected !== void 0) {
          c.selected[field.vizField] = false;
        }
      }
      field.col = col;
      return col.selected[field.vizField] = !col.selected[field.vizField];
    };
  });

  vizBuilder.directive('visualization', [
    '$rootScope', 'DatatableService', function($rootScope, DatatableService) {
      return {
        restrict: 'AE',
        link: function(scope, element, attrs) {
          var aggField, aggType, dataTable, dataset, fieldNames, groupField, jsonSettings, tableCreated, vizType;
          console.log('directive visualization');
          console.log($rootScope.state.aggregationMethod);
          vizType = $rootScope.state.renderer.type;
          jsonSettings = {
            "name": "default",
            "contentType": "text/csv",
            "visualizationType": vizType,
            "fields": [],
            "vizOptions": $rootScope.state.renderer.vizOptions
          };
          dataset = $rootScope.state.renderer.datasets[0];
          dataTable = $rootScope.state.dataset;
          console.log(dataset.fields[0].col['fieldRef']);
          console.log(dataset.fields[1].col['fieldRef']);
          console.log(dataTable);
          groupField = dataset.fields[0].col['fieldRef'];
          aggField = dataset.fields[1].col['fieldRef'];
          aggType = $rootScope.state.aggregationMethod;
          fieldNames = dataunity.querytemplate.groupAggregateDataTableFieldNames(groupField, aggField, aggType);
          console.log('fieldNames');
          console.log(fieldNames);
          tableCreated = dataTable.createGroupAggregateDataTable(groupField, aggField, aggType);
          console.log(tableCreated);
          return tableCreated.then(function(dataTableURL) {
            var tableFetched;
            console.log(dataTableURL);
            tableFetched = DatatableService.fetchTable({
              '@id': dataTableURL
            });
            console.log(tableFetched);
            return tableFetched.then(function(pipeDataTable) {
              var endPoint;
              return endPoint = pipeDataTable.getDataEndpoint(function(endpoint) {
                var dataField, f, fieldData, renderOpt, _i, _len, _ref;
                jsonSettings['url'] = endpoint;
                _ref = dataset.fields;
                for (_i = 0, _len = _ref.length; _i < _len; _i++) {
                  f = _ref[_i];
                  console.log(f.col);
                  dataField = fieldNames.groupField;
                  if (f.needsAggregate) {
                    dataField = fieldNames.aggField;
                  }
                  fieldData = {
                    vizField: f.vizField,
                    dataField: dataField
                  };
                  jsonSettings.fields.push(fieldData);
                }
                element.css('width', '900px');
                element.css('height', '500px');
                renderOpt = {
                  selector: '#map',
                  rendererName: $rootScope.state.renderer['rendererName'],
                  data: [jsonSettings],
                  vizOptions: $rootScope.state.renderer.vizOptions
                };
                $rootScope.vizDef = JSON.stringify([jsonSettings]);
                $rootScope.state.vizRendered = true;
                return element.vizshare(renderOpt);
              });
            });
          });
        }
      };
    }
  ]);

  vizBuilder.controller("VisualizationController", function($scope, RendererService) {
    return $scope.renderers = RendererService.getRenderers();
  });

}).call(this);
