(function() {
  var DATA_UNITY_URL, vizBuilder;

  DATA_UNITY_URL = 'http://0.0.0.0:6543/api/beta';

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
    }
    RestangularProvider.setBaseUrl(url);
    return RestangularProvider.addResponseInterceptor(function(data, operation, what, url, response, deferred) {
      var extractedData;
      extractedData = data;
      if (operation === "getList") {
        extractedData = data.dataTable;
      }
      return extractedData;
    });
  });

}).call(this);

(function() {
  var DU_API, renderers, vizBuilder;

  DU_API = 'http://0.0.0.0:6543/';

  vizBuilder = angular.module('vizBuilder');

  vizBuilder.factory('datatableService', function($q, $timeout, $http, Restangular) {
    Restangular.extendModel('datatables', function(model) {
      model.fetchFields = function() {
        var id, structPromise, structureDefURL;
        console.log('fetchFields');
        console.log(model);
        if (!model.structData) {
          structureDefURL = model['structure'];
          console.log(structureDefURL);
          id = structureDefURL.substring(structureDefURL.lastIndexOf('/') + 1);
          console.log(id);
          structPromise = Restangular.one('qb-datastructdefs', id).get();
          return structPromise.then(function(structData) {
            console.log(structData);
            return model.structure = structData;
          });
        }
      };
      return model;
    });
    return {
      fetchTables: function() {
        var promise;
        promise = Restangular.all('datatablecatalogs/public').getList();
        return promise;
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
      type: 'barchart',
      thumbnail: '/images/chart_bar.png',
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
      type: 'piechart',
      thumbnail: '/images/chart_pie.png',
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
      type: 'map',
      thumbnail: '/images/map.png',
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
                "size": {
                  "scale": "onetoten",
                  "vizField": "value"
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

  STEPS = ['Datasets', 'Visualization type', 'Columns', 'Visualize!'];

  vizBuilder.directive('wizardProgressBar', function() {
    return {
      restrict: 'AE',
      link: function(scope, element, attrs) {
        console.log('directive wizardProgressBar');
        console.log(attrs);
        scope.activeStep = attrs.activeStep;
        scope.steps = STEPS;
        console.log('scope');
        return console.log(scope);
      },
      templateUrl: '/views/wizard-progress-bar.html'
    };
  });

  vizBuilder.controller("VizBuilderController", function($scope) {
    return console.log('VizBuilderController');
  });

  vizBuilder.controller("DatatableController", function($scope, datatableService) {
    var promise;
    $scope.select = function(dataset) {
      dataset.selected = !dataset.selected;
      $scope.$parent.selectedDataset = dataset;
      console.log($scope.$parent);
      dataset.btnState = 'btn-success';
      if (dataset.selected) {
        return dataset.btnState = 'btn-danger';
      }
    };
    promise = datatableService.fetchTables();
    return promise.then(function(data) {
      $scope.datatables = data;
      return console.log(data);
    });
  });

  vizBuilder.controller("VisualizationTypeController", function($scope, RendererService, $http) {
    $scope.renderers = RendererService.getRenderers();
    return $scope.saveRenderer = function(renderer) {
      console.log('renderer');
      console.log(renderer);
      return $scope.$parent.selectedRenderer = renderer;
    };
  });

  vizBuilder.controller("ColumnsController", function($scope, datatableService, RendererService) {
    var dtPromise;
    console.log('ColumnsController');
    console.log($scope.$parent.selectedDataset);
    console.log($scope.$parent.selectedRenderer);
    if (!$scope.$parent.selectedDataset.structure) {
      dtPromise = datatableService.fetchTable($scope.$parent.selectedDataset);
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

  vizBuilder.directive('visualization', function() {
    return {
      restrict: 'AE',
      link: function(scope, element, attrs) {
        var f, fieldData, jsonSettings, renderOpt, _i, _len, _ref;
        console.log('directive visualization');
        jsonSettings = {
          "name": "default",
          "contentType": "text/csv",
          "visualizationType": scope.$parent.selectedRenderer.type,
          "fields": []
        };
        console.log(scope);
        console.log(scope.$parent.selectedDataset);
        console.log(scope.$parent.selectedRenderer);
        jsonSettings['url'] = scope.$parent.selectedDataset['@id'] + '/raw';
        _ref = scope.$parent.selectedRenderer.datasets[0].fields;
        for (_i = 0, _len = _ref.length; _i < _len; _i++) {
          f = _ref[_i];
          console.log(f.col);
          fieldData = {
            vizField: f.vizField,
            dataField: f.col['fieldRef']
          };
          jsonSettings.fields.push(fieldData);
        }
        console.log('jsonSettings:');
        console.log(jsonSettings);
        renderOpt = {
          rendererName: scope.$parent.selectedRenderer['rendererName'],
          data: [jsonSettings],
          vizOptions: scope.$parent.selectedRenderer.vizOptions
        };
        scope.$parent.vizshareDef = JSON.stringify([jsonSettings]);
        console.log('scope.$parent');
        console.log(scope.$parent);
        return element.vizshare(renderOpt);
      }
    };
  });

  vizBuilder.controller("VisualizationController", function($scope, RendererService) {
    return $scope.renderers = RendererService.getRenderers();
  });

}).call(this);

(function() {
  angular.module("vizBuilder").controller("MainCtrl", function($scope) {
    return $scope.awesomeThings = ["HTML5 Boilerplate", "Bootstrap", "AngularJS", "HAML", "CoffeeScript", "Karma"];
  });

}).call(this);
