/**
 * @file
 * Javascript for Field Example.
 */

vizOptions = {
        "scales": [
            {
                "name": "area",
                "type": "linear",
                "domain": {"data": "default", "vizField": "value"},
                "range": [50000, 100000]
            },
            {
                "name": "onetoten",
                "type": "linear",
                "domain": [1, 10],
                "range": [50000, 1000000]
            },
            {
                "name": "colours",
                "type": "linear",
                "domain": {"data": "default", "vizField": "value"},
                "range": ["red", "blue"]
            },
            {
                "name": "coloursonetoten",
                "type": "linear",
                "domain": [1, 10],
                "range": ["red", "blue"]
            }
        ],
        "marks": [
            {
                "type": "latlongcircle",
                "from": {"data": "default"},
                "properties": {
                    "enter": {
                        "lat": {"vizField": "lat"},
                        "long": {"vizField": "long"},
                        //"size": {"scale": "onetoten", "vizField": "value"},
                        "text": {"vizField": "title"},
                        "fill": {"scale": "colours", "vizField": "value"}
                    }
                }
            }
        ]
    };

/**
 */
(function ($) {
  Drupal.behaviors.vizshare = {
    attach: function(context, settings) {
      console.log('vizshare');
      console.log(context);
      console.log(context.URL);
      console.log(context.hasOwnProperty('document'));
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
          // var vizOptions = vizDef.vizOptions;
          vizOptions.height = parseInt(this.height);
          vizOptions.width = width;
          var renderOpt = {
            //TODO: fix to generic
            rendererName: "vizshare." + vizDef.visualizationType,
            selector: selector,
            data: this.viz,
            vizOptions: vizOptions,
          };
          vizshare.render(renderOpt);
        })
        $(settings.data_unity).each(function () {
          window.data_unity_url = this.url;
        })
      }
    }
  };
})(jQuery);


