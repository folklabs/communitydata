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
          //TODO: fix to generic
          rendererName: "vizshare.barchart",
          selector: '#' + this.vizId,
          data: this.viz,
          vizOptions: {
            height: parseInt(this.height),
            // width: 1100
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


