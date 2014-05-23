(function() {
  var vizBuilder;

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
    RestangularProvider.setBaseUrl('http://0.0.0.0:6543/api/beta');
    return RestangularProvider.addResponseInterceptor(function(data, operation, what, url, response, deferred) {
      var extractedData;
      extractedData = data;
      if (operation === "getList") {
        extractedData = data['dtbl:dataTable'];
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
        if (!model.structData) {
          structureDefURL = model['qb:structure']['@id'];
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
      ]
    }, {
      rendererName: 'vizshare.piechart',
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
      ]
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
  var vizBuilder;

  vizBuilder = angular.module("vizBuilder");

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
      _ref = $scope.$parent.selectedDataset['structure']['qb:component'];
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
            dataField: f.col['dtbl:fieldRef']
          };
          jsonSettings.fields.push(fieldData);
        }
        console.log('jsonSettings:');
        console.log(jsonSettings);
        renderOpt = {
          rendererName: scope.$parent.selectedRenderer['rendererName'],
          data: [jsonSettings],
          vizOptions: {}
        };
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
