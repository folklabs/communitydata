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

        var renderOpt = {
          rendererName: "vizshare.barchart",
          selector: '#' + this.vizId,
          // data: jsonSettings,
          data: this.viz,
          vizOptions: {
            height: parseInt(this.height),
            // width: 1100
          }
        };
        vizshare.render(renderOpt);
      })
    }
  };
})(jQuery);


