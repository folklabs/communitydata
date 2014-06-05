/**
 * @file
 * Javascript for Field Example.
 */

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
        console.log(this.vizId);
        console.log(this);
        // jsonSettings = JSON.parse(this.viz);
        // console.log(jsonSettings);
        // vizshareObj.empty();
        var selector = '#' + this.vizId;
        var width = $(selector).width();
        if (width < 200) {
          width = 200;
        }
        console.log();
        var renderOpt = {
          //TODO: fix to generic
          rendererName: "vizshare.barchart",
          selector: selector,
          data: this.viz,
          vizOptions: {
            height: parseInt(this.height),
            width: width,
          }
        };
        vizshare.render(renderOpt);
      })
      $(settings.data_unity).each(function () {
        window.data_unity_url = this.url;
      })
    }
  };
})(jQuery);


