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
      console.log(url);
      extractedData = data;
      if (operation === "getList") {
        if (url.match('datatablecatalogs')) {
          extractedData = data.dataTable;
        } else if (url.match('sources-datasets')) {
          extractedData = [data.dataset];
        }
      }
      console.log(extractedData.structure);
      extractedData.structure2 = extractedData.structure;
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
      model.createGroupAggregateDataTable = function(groupField, aggField) {
        var deferred, tableCreated;
        deferred = $q.defer();
        dataunity.config.setBaseUrl('http://data-unity.com');
        tableCreated = dataunity.querytemplate.createGroupAggregateDataTable('name', this['@id'], groupField, aggField);
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
          timeout: 3000
        }).success(function(data, status, headers, config) {
          var jobID, jobUrl;
          console.log('success (creating a job)');
          jobID = headers()['location'].replace(url, '');
          jobID = jobID.replace('/', '');
          console.log(jobID);
          jobUrl = window.data_unity_url + '/jobs/datatable-jobs/' + jobID;
          return model._poll(jobUrl, callback);
        }).error(function(dataE, statusE, headersE, configE) {
          return console.log('error!');
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
              console.log('dataTable2.structure');
              console.log(dataTable.structure);
              console.log(dataTable.label);
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
        dtPromise = Restangular.one('datatables', id).get();
        dtPromise.then(function(datatable) {
          console.log('fetchFields promise');
          return datatable.fetchFields();
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
              required: true
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
              required: true
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
  var STEPS, vizBuilder;

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

  vizBuilder.directive('initModel', [
    '$compile', function($compile) {
      return {
        restrict: 'A',
        link: function(scope, element, attrs) {
          console.log('directive initModel');
          scope.$parent.imagePath = element.attr('image-path');
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
    $scope.state = {};
    return $rootScope.$watch('vizDef', function(newVal, old) {
      return $scope.state.vizDef = newVal;
    });
  });

  vizBuilder.controller("VizBuilderController", function($scope) {
    return console.log('VizBuilderController');
  });

  vizBuilder.controller("DatatableController", function($scope, DatatableService) {
    var tablesFetched;
    $scope.select = function(dataset) {
      dataset.selected = !dataset.selected;
      $scope.$parent.selectedDataset = dataset;
      console.log($scope.$parent);
      dataset.btnState = 'btn-success';
      if (dataset.selected) {
        return dataset.btnState = 'btn-danger';
      }
    };
    tablesFetched = DatatableService.fetchTables();
    return tablesFetched.then(function(data) {
      console.log('tablesFetched');
      $scope.datatables = data;
      console.log(data);
      return data[0].fetchSources();
    });
  });

  vizBuilder.controller("VisualizationTypeController", function($scope, RendererService, $http) {
    $scope.renderers = RendererService.getRenderers();
    return $scope.selectRenderer = function(renderer) {
      var r, _i, _len, _ref;
      _ref = $scope.renderers;
      for (_i = 0, _len = _ref.length; _i < _len; _i++) {
        r = _ref[_i];
        r.selected = false;
      }
      $scope.$parent.selectedRenderer = renderer;
      return renderer.selected = true;
    };
  });

  vizBuilder.controller("ColumnsController", function($scope, DatatableService, RendererService) {
    var dtPromise;
    console.log('ColumnsController');
    console.log($scope.$parent.selectedDataset);
    console.log($scope.$parent.selectedRenderer);
    if (!$scope.$parent.selectedDataset.structure) {
      dtPromise = DatatableService.fetchTable($scope.$parent.selectedDataset);
      dtPromise.then(function(datatable) {
        console.log('fetchTable promise');
        console.log(datatable);
        $scope.$parent.selectedDataset = datatable;
        return $scope.structureAvailable = true;
      });
    } else {
      $scope.structureAvailable = true;
    }
    return $scope.selectColForField = function(field, col) {
      var c, _i, _len, _ref;
      if (col.selected === void 0) {
        col.selected = {};
      }
      _ref = $scope.$parent.selectedDataset['structure']['component'];
      for (_i = 0, _len = _ref.length; _i < _len; _i++) {
        c = _ref[_i];
        if (c.selected !== void 0) {
          c.selected[field.vizField] = false;
        }
      }
      console.log(field);
      console.log(col);
      field.col = col;
      return col.selected[field.vizField] = !col.selected[field.vizField];
    };
  });

  vizBuilder.directive('visualization', [
    '$rootScope', function($rootScope) {
      return {
        restrict: 'AE',
        link: function(scope, element, attrs) {
          var endPoint, jsonSettings, vizType;
          console.log('directive visualization');
          vizType = scope.$parent.selectedRenderer.type;
          jsonSettings = {
            "name": "default",
            "contentType": "text/csv",
            "visualizationType": vizType,
            "fields": [],
            "vizOptions": scope.$parent.selectedRenderer.vizOptions
          };
          return endPoint = scope.$parent.selectedDataset.getDataEndpoint(function(endpoint) {
            var f, fieldData, renderOpt, _i, _len, _ref;
            jsonSettings['url'] = endpoint;
            _ref = scope.$parent.selectedRenderer.datasets[0].fields;
            for (_i = 0, _len = _ref.length; _i < _len; _i++) {
              f = _ref[_i];
              fieldData = {
                vizField: f.vizField,
                dataField: f.col['fieldRef']
              };
              jsonSettings.fields.push(fieldData);
            }
            element.css('width', '900px');
            element.css('height', '500px');
            renderOpt = {
              selector: '#map',
              rendererName: scope.$parent.selectedRenderer['rendererName'],
              data: [jsonSettings],
              vizOptions: scope.$parent.selectedRenderer.vizOptions
            };
            $rootScope.vizDef = JSON.stringify([jsonSettings]);
            return element.vizshare(renderOpt);
          });
        }
      };
    }
  ]);

  vizBuilder.controller("VisualizationController", function($scope, RendererService) {
    return $scope.renderers = RendererService.getRenderers();
  });

}).call(this);
