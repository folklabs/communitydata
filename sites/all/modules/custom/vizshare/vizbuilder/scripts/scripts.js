(function() {
  var DATA_UNITY_HOST, DATA_UNITY_URL, vizBuilder;

  DATA_UNITY_URL = 'http://0.0.0.0:6543/api/beta';

  DATA_UNITY_HOST = 'http://data-unity.com';

  DATA_UNITY_HOST = 'http://lambeth.dataunityapp.com';

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
      console.log('Getting DATA_UNITY_URL from window environment...');
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
        var deferred, duBaseUrl, tableCreated, urlElement;
        deferred = $q.defer();
        urlElement = document.createElement("a");
        urlElement.href = window.data_unity_url;
        duBaseUrl = 'http://' + urlElement.hostname;
        dataunity.config.setBaseUrl(duBaseUrl);
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
          console.log('success: ' + status + ' ' + data.status);
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
        console.log(url);
        dataIn = {
          "dataTable": this['@id']
        };
        return $http.post(url, dataIn, {
          cache: false,
          timeout: 60000
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
              label: "X axis",
              description: "This defines the horizontal labels",
              required: true,
              needsGroup: true
            }, {
              vizField: 'yAxis',
              dataType: ['decimal'],
              label: "Y axis",
              description: "This defines the size each bar",
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
              label: "Name",
              description: "This defines the label of a segment",
              required: true,
              needsGroup: true
            }, {
              vizField: 'value',
              dataType: ['decimal'],
              label: "Value",
              description: "This defines the size of a segment",
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
              "label": "Latitude",
              "description": "This defines the horizontal position on the map",
              "dataField": "Lat"
            }, {
              "vizField": "long",
              "label": "Longitude",
              "description": "This defines the vertical position on the map",
              "dataField": "Long"
            }, {
              "vizField": "title",
              "label": "Title",
              "description": "The content of the popup.",
              "dataField": "Name"
            }, {
              "vizField": "value",
              "label": "Value",
              "description": "",
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
      name: 'datatables',
      text: 'Select datasets'
    }, {
      name: 'select-type',
      text: 'Select visualization type'
    }, {
      name: 'select-columns',
      text: 'Select data columns'
    }, {
      name: 'visualization',
      text: 'Edit visualization'
    }
  ];

  AGGREGATION_METHODS = [
    {
      name: "Count",
      description: 'Shows the total number of items'
    }, {
      name: "Sum",
      description: 'Shows the sum of all the item values'
    }, {
      name: "Average",
      description: 'Shows the mean average of all the item values'
    }, {
      name: "Min",
      description: 'Shows the minimum value from all the item values'
    }, {
      name: "Max",
      description: 'Shows the maximum value from all the item values'
    }, {
      name: "First",
      description: 'Shows the first value in the list of values'
    }, {
      name: "Last",
      description: 'Shows the last value in the list of values'
    }
  ];

  vizBuilder.directive('initModel', [
    '$rootScope', '$compile', function($rootScope, $compile) {
      return {
        restrict: 'A',
        link: function(scope, element, attrs) {
          var vizDefContent;
          console.log('directive initModel');
          $rootScope.imagePath = element.attr('image-path');
          console.log(element[0].value);
          if ($rootScope.state === void 0) {
            $rootScope.state = {};
          }
          console.log($rootScope.state);
          vizDefContent = element[0].value;
          if (vizDefContent !== void 0) {
            vizDefContent = vizDefContent.replace(/^\s+|\s+$/g, "");
          }
          if (vizDefContent.length > 0) {
            $rootScope.state.vizDef = JSON.parse(vizDefContent);
            $rootScope.state.edit = true;
            console.log(JSON.parse(vizDefContent));
          }
          console.log($rootScope.state);
          element.removeAttr('init-model');
          $compile(element)(scope);
          console.log('$rootScope');
          return console.log($rootScope);
        }
      };
    }
  ]);

  vizBuilder.directive('wizardProgressBar', function() {
    return {
      restrict: 'AE',
      link: function(scope, element, attrs) {
        var index, _results;
        scope.activeStep = attrs.activeStep;
        scope.steps = STEPS;
        index = 0;
        _results = [];
        while (scope.steps[index].name !== scope.activeStep) {
          scope.steps[index].completed = true;
          _results.push(index += 1);
        }
        return _results;
      },
      templateUrl: '/views/wizard-progress-bar.html'
    };
  });

  vizBuilder.controller("VizDefController", function($scope, $rootScope) {
    console.log('VizDefController');
    if ($rootScope.state === void 0) {
      return $rootScope.state = {};
    }
  });

  vizBuilder.controller("VizBuilderController", function($scope) {
    return console.log('VizBuilderController');
  });

  vizBuilder.controller("DatatableController", function($scope, $rootScope, DatatableService) {
    var tablesFetched;
    $scope.select = function(dataset) {
      dataset.selected = !dataset.selected;
      if (dataset.selected) {
        $rootScope.state.dataset = dataset;
      } else {
        $rootScope.state.dataset = void 0;
      }
      dataset.btnState = 'btn-primary';
      if (dataset.selected) {
        return dataset.btnState = 'btn-danger';
      }
    };
    if ($scope.datatables === void 0) {
      tablesFetched = DatatableService.fetchTables();
      return tablesFetched.then(function(data) {
        var d, _i, _len, _results;
        console.log('tablesFetched');
        $rootScope.datatables = data;
        console.log(data);
        if ($rootScope.state.edit && $rootScope.state.vizDef[0].datatable) {
          console.log('Scanning to initialize datatable');
          _results = [];
          for (_i = 0, _len = data.length; _i < _len; _i++) {
            d = data[_i];
            if (d['@id'] === $rootScope.state.vizDef[0].datatable['@id']) {
              _results.push($scope.select(d));
            } else {
              _results.push(void 0);
            }
          }
          return _results;
        }
      });
    }
  });

  vizBuilder.controller("VisualizationTypeController", function($scope, $rootScope, RendererService, $http) {
    var r, _i, _len, _ref, _results;
    $scope.selectRenderer = function(renderer) {
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
    $scope.renderers = RendererService.getRenderers();
    if ($rootScope.state.edit && $rootScope.state.vizDef[0].visualizationType) {
      _ref = $scope.renderers;
      _results = [];
      for (_i = 0, _len = _ref.length; _i < _len; _i++) {
        r = _ref[_i];
        if (r.type === $rootScope.state.vizDef[0].visualizationType) {
          _results.push($scope.selectRenderer(r));
        } else {
          _results.push(void 0);
        }
      }
      return _results;
    }
  });

  vizBuilder.controller("ColumnsController", function($scope, $rootScope, DatatableService, RendererService) {
    var col, colMatch, field, fieldMapping, fieldMatch, _i, _j, _k, _len, _len1, _len2, _ref, _ref1, _ref2, _results;
    $scope.selectColForField = function(field, col) {
      var c, isAllColumnsSelected, _i, _j, _len, _len1, _ref, _ref1;
      console.log('selectColForField');
      if (col['selected'] === void 0) {
        col.selected = {};
      }
      _ref = $rootScope.state.dataset['structure']['component'];
      for (_i = 0, _len = _ref.length; _i < _len; _i++) {
        c = _ref[_i];
        if (c.selected !== void 0) {
          c.selected[field.vizField] = false;
        }
      }
      console.log(field);
      console.log(col);
      field.col = col;
      col.selected[field.vizField] = !col.selected[field.vizField];
      isAllColumnsSelected = true;
      _ref1 = $rootScope.state.renderer.datasets[0].fields;
      for (_j = 0, _len1 = _ref1.length; _j < _len1; _j++) {
        field = _ref1[_j];
        if (field.col === void 0) {
          isAllColumnsSelected = false;
        }
      }
      return $scope.isAllColumnsSelected = isAllColumnsSelected;
    };
    console.log('ColumnsController');
    console.log($rootScope.state.dataset);
    console.log($rootScope.state.renderer);
    $scope.aggregationMethods = AGGREGATION_METHODS;
    $rootScope.state.aggregationMethod = "Count";
    $scope.a = {};
    $scope.aggregationMethod = "Count";
    $scope.$watch('state.aggregationMethod', function(newVal, oldVal) {
      return console.log('aggregationMethod ' + newVal);
    });
    if ($rootScope.state.edit) {
      console.log($rootScope.state.vizDef);
      _ref = $rootScope.state.vizDef[0].fields;
      _results = [];
      for (_i = 0, _len = _ref.length; _i < _len; _i++) {
        fieldMapping = _ref[_i];
        fieldMatch = void 0;
        _ref1 = $rootScope.state.renderer.datasets[0].fields;
        for (_j = 0, _len1 = _ref1.length; _j < _len1; _j++) {
          field = _ref1[_j];
          if (field.vizField === fieldMapping.vizField) {
            fieldMatch = field;
          }
        }
        colMatch = void 0;
        _ref2 = $rootScope.state.dataset['structure']['component'];
        for (_k = 0, _len2 = _ref2.length; _k < _len2; _k++) {
          col = _ref2[_k];
          if (col.fieldRef === fieldMapping.fieldRefLabel) {
            colMatch = col;
          }
        }
        if (fieldMatch !== void 0 && colMatch !== void 0) {
          _results.push($scope.selectColForField(fieldMatch, colMatch));
        } else {
          _results.push(console.log('Existing state: field match failed: ' + fieldMatch + ', ' + colMatch));
        }
      }
      return _results;
    }
  });

  vizBuilder.directive('visualization', [
    '$rootScope', 'DatatableService', function($rootScope, DatatableService) {
      return {
        restrict: 'AE',
        link: function(scope, element, attrs) {
          var aggDataField, aggField, aggType, dataTable, dataset, f, fieldNames, groupDataField, groupField, renderOpt, tableCreated, vizDef, vizType, _i, _j, _len, _len1, _ref, _ref1;
          console.log('directive visualization');
          element.css('width', '900px');
          element.css('height', '500px');
          vizType = $rootScope.state.renderer.type;
          vizDef = {
            "name": "default",
            "contentType": "text/csv",
            "visualizationType": vizType,
            "fields": [],
            "vizOptions": $rootScope.state.renderer.vizOptions,
            datatable: {
              '@id': $rootScope.state.dataset['@id']
            }
          };
          dataset = $rootScope.state.renderer.datasets[0];
          dataTable = $rootScope.state.dataset;
          console.log(dataset.fields[0].col['fieldRef']);
          console.log(dataset.fields[1].col['fieldRef']);
          console.log(dataTable);
          renderOpt = {
            selector: '#map',
            rendererName: $rootScope.state.renderer['rendererName'],
            vizOptions: $rootScope.state.renderer.vizOptions
          };
          if ($rootScope.state.renderer.type !== 'geoleaflet') {
            console.log('Getting endpoint for a chart');
            groupDataField = null;
            aggDataField = null;
            _ref = dataset.fields;
            for (_i = 0, _len = _ref.length; _i < _len; _i++) {
              f = _ref[_i];
              if (f.needsGroup) {
                groupDataField = f.col['fieldRef'];
              }
              if (f.needsAggregate) {
                aggDataField = f.col['fieldRef'];
              }
            }
            aggType = $rootScope.state.aggregationMethod;
            fieldNames = dataunity.querytemplate.groupAggregateDataTableFieldNames(groupDataField, aggDataField, aggType);
            console.log(fieldNames);
            groupField = fieldNames.groupField;
            aggField = fieldNames.aggField;
            _ref1 = dataset.fields;
            for (_j = 0, _len1 = _ref1.length; _j < _len1; _j++) {
              f = _ref1[_j];
              f.vizDataFieldName = f.col['fieldRef'];
              if (f.needsGroup) {
                f.vizDataFieldName = fieldNames.groupField;
              }
              if (f.needsAggregate) {
                f.vizDataFieldName = fieldNames.aggField;
              }
            }
            console.log(dataset);
            tableCreated = dataTable.createGroupAggregateDataTable(groupDataField, aggDataField, aggType);
            console.log(tableCreated);
            return tableCreated.then(function(dataTableURL) {
              var tableFetched;
              console.log(dataTableURL);
              tableFetched = DatatableService.fetchTable({
                '@id': dataTableURL
              });
              console.log(tableFetched);
              return tableFetched.then(function(pipeDataTable) {
                console.log('tableFetched');
                console.log(pipeDataTable);
                vizDef['datatable_url'] = dataTableURL;
                return pipeDataTable.getDataEndpoint(function(endpoint) {
                  var fieldData, _k, _len2, _ref2;
                  vizDef['url'] = endpoint;
                  _ref2 = dataset.fields;
                  for (_k = 0, _len2 = _ref2.length; _k < _len2; _k++) {
                    f = _ref2[_k];
                    console.log(f.col);
                    fieldData = {
                      vizField: f.vizField,
                      dataField: f.vizDataFieldName,
                      fieldRefLabel: f.col['fieldRef']
                    };
                    vizDef.fields.push(fieldData);
                  }
                  renderOpt.data = [vizDef];
                  $rootScope.state.vizDef = [vizDef];
                  console.log($rootScope.state.vizDef);
                  $rootScope.state.vizRendered = true;
                  return element.vizshare(renderOpt);
                });
              });
            });
          } else {
            console.log('Getting endpoint for a map');
            vizDef['datatable_url'] = dataTable['@id'];
            return dataTable.getDataEndpoint(function(endpoint) {
              var fieldData, renderDef, _k, _len2, _ref2;
              _ref2 = dataset.fields;
              for (_k = 0, _len2 = _ref2.length; _k < _len2; _k++) {
                f = _ref2[_k];
                console.log(f.col);
                fieldData = {
                  vizField: f.vizField,
                  dataField: f.col['fieldRef']
                };
                vizDef.fields.push(fieldData);
              }
              renderDef = angular.copy(vizDef);
              renderDef['url'] = endpoint;
              renderOpt.data = [renderDef];
              console.log('Setting vizDef...');
              console.log(vizDef);
              console.log(renderDef);
              $rootScope.state.vizDef = [vizDef];
              $rootScope.state.vizRendered = true;
              return element.vizshare(renderOpt);
            });
          }
        }
      };
    }
  ]);

  vizBuilder.controller("VisualizationController", function($scope, $rootScope, RendererService) {
    $scope.handleFormSubmit = function() {
      console.log('handleFormSubmit');
      return $rootScope.vizDefText = JSON.stringify($rootScope.state.vizDef);
    };
    return $scope.renderers = RendererService.getRenderers();
  });

}).call(this);
