/**
 * @file
 * Javascript for Field Example.
 */

// jsonSettings =
// [
//     {
//         "name": "default",
//         "url": "http://dev.cod.p:8888/sites/default/files/data1.csv",
//         "contentType": "text/csv",
//         "fields": [
//             {
//                 "vizField": "xAxis",
//                 "dataField": "Country"
//             },
//             {
//                 "vizField": "yAxis",
//                 "dataField": "Number"
//             }
//         ]
//     }
// ]
// ;

/**
 */
(function ($) {
  Drupal.behaviors.vizshare = {
    attach: function(context, settings) {
      console.log('vizshare');
      $(settings.vizshare).each(function () {
        // var vizshareObj = $('#vizshare');
        // console.log(vizshareObj);
        // console.log(vizshareObj.length);
        // if (vizshareObj.length > 0 ) {
        // console.log(this.vizId);
        // console.log(this.viz);
        jsonSettings = JSON.parse(this.viz);
        console.log(jsonSettings);
        // vizshareObj.empty();

        var renderOpt = {
          rendererName: "vizshare.barchart",
          selector: '#' + this.vizId,
          data: jsonSettings,
          vizOptions: {}
        };
        // vizshare.render(renderOpt);
      })
    }
  };
})(jQuery);

(function ($) {
  Drupal.behaviors.my_name_submit= {
          attach: function (context, settings) {
            $('#execute-query', context).click(function (event) {
                  //getting the value from textfield
                  var user_name=$("#my-name").val();
                  //passing the value using 'POST' method
                  var post = "&name=wubble";
                $.ajax({
                  'url': '/vizbuilder/save',
                  'type': 'POST',
                  'dataType': 'json',
                  'data': post,
                  'success': function(data)
                      {

                       if(data == "success")
                         {

                            $('#status').attr("innerHTML","<font color='green'>Name submitted successfully!</font>");
                        }
                      else
                       {
                           $('#status').attr("innerHTML","<font color='red'>Name submit failed!</font>");
                        }
                  },
                  beforeSend: function()
                      {
                     $(document).ready(function () {
                        $('#status').attr("innerHTML","Loading....");
                     });
                },
                 'error': function(data)
                 {

                   $(document).ready(function () {
                    $('#status').attr("innerHTML","ERROR OCCURRED!");
                   });
                 }
               });

                  });
          }
        };
})(jQuery);

