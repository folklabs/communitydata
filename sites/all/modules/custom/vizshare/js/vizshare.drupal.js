/**
 * @file
 * Javascript for Field Example.
 */

// vizOptions = {
//         "scales": [
//             {
//                 "name": "area",
//                 "type": "linear",
//                 "domain": {"data": "default", "vizField": "value"},
//                 "range": [50000, 100000]
//             },
//             {
//                 "name": "onetoten",
//                 "type": "linear",
//                 "domain": [1, 10],
//                 "range": [50000, 1000000]
//             },
//             {
//                 "name": "colours",
//                 "type": "linear",
//                 "domain": {"data": "default", "vizField": "value"},
//                 "range": ["red", "blue"]
//             },
//             {
//                 "name": "coloursonetoten",
//                 "type": "linear",
//                 "domain": [1, 10],
//                 "range": ["red", "blue"]
//             }
//         ],
//         "marks": [
//             {
//                 "type": "latlongcircle",
//                 "from": {"data": "default"},
//                 "properties": {
//                     "enter": {
//                         "lat": {"vizField": "lat"},
//                         "long": {"vizField": "long"},
//                         //"size": {"scale": "onetoten", "vizField": "value"},
//                         "text": {"vizField": "title"},
//                         "fill": {"scale": "colours", "vizField": "value"}
//                     }
//                 }
//             }
//         ]
//     };

/**
 */
(function ($) {
  function callback(dataURL) {
      console.log("Results: " + dataURL);
  }

  function errorCallback(dataURL) {
      console.log("There was an error.");
  }

  // Poll job status
  function poll(statusUrl, finishedCallback) {
      console.log("Polling..." + statusUrl);
      jQuery.ajax({
          type: "GET",
          url: statusUrl
      })
          .fail(function (jqXHR, textStatus, errorThrown) {
              if (jqXHR.status == 404) {
                  // Job might not have been queued yet, try again
                  console.log("404 error, going to try again");
                  setTimeout(function () { poll(statusUrl, finishedCallback); }, 1000);
              } else {
                  alert("There was a problem: " + textStatus);
                  console.log(errorThrown);
              }
          })
          .done(function (data, textStatus, jqXHR) {
              // console.log(data);
              console.log(textStatus);
              console.log(jqXHR);
              if (data.status === 'completed') {
                  finishedCallback(data.data);
              } else if (data.status === 'error') {
                  errorCallback(data.data);
              } else {
                  setTimeout(function () { poll(statusUrl, finishedCallback); }, 10000);
              }
          });
  }

  // Start a job and poll for results
  function runDataTable(dataTableURL, callback) {
      console.log('window.data_unity_url');
      console.log(window.data_unity_url);
      console.log(dataTableURL);
      jQuery.ajax({
          type: "POST",
          url: window.data_unity_url + '/jobs/datatable-jobs',
          data: JSON.stringify({"dataTable": dataTableURL}),
          //success: success,
          contentType: 'application/json'
      })
          .done(function (data, textStatus, jqXHR) {
              console.log("Job created");
              console.log(textStatus);
              console.log(jqXHR.getAllResponseHeaders());
              var statusUrl = jqXHR.getResponseHeader("Location");
              console.log(statusUrl);
              poll(statusUrl, callback);
          })
          .fail(function (jqXHR, textStatus, errorThrown) {
              console.log(jqXHR);
              console.log(textStatus);
              console.log(errorThrown);
          });
  }

  Drupal.behaviors.vizshare = {
    attach: function(context, settings) {
      console.log('vizshare');
      console.log(context);
      console.log(context.URL);
      console.log(context.hasOwnProperty('document'));
      $(settings.data_unity).each(function () {
        console.log('set DU URL');
          window.data_unity_url = this.url;
          console.log(window.data_unity_url);
        })
      if (context.URL) {
        $(settings.vizshare).each(function () {
          // var vizshareObj = $('#vizshare');
          // console.log(vizshareObj);
          // console.log(vizshareObj.length);
          // if (vizshareObj.length > 0 ) {
          console.log(this.vizId);
          console.log(this);
          // jsonSettings = JSON.parse(this.viz);
          // console.log(jsonSettings);
          // vizshareObj.empty();
          var selector = '#' + this.vizId;
          var vizDef = this.viz[0];
          var width = $(selector).width();
          // TODO: does this make sense?
          if (width < 200) {
            width = 200;
          }
          // console.log();
          var vizOptions = vizDef.vizOptions;
          vizOptions.height = parseInt(this.height);
          vizOptions.width = width;
          var renderOpt = {
            //TODO: fix to generic
            rendererName: "vizshare." + vizDef.visualizationType,
            selector: selector,
            data: this.viz,
            vizOptions: vizOptions,
          };
          runDataTable(vizDef.datatable_url, function(data) {
            console.log(data);
            renderOpt.data[0]['url'] = data;
            console.log(renderOpt);
            vizshare.render(renderOpt);
          });

        })
      }
    }
  };
})(jQuery);


