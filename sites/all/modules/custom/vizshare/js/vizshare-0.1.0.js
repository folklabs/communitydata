var vizshare = vizshare || {};

vizshare = (function () {
    var rendererLookup = {},

    // Private methods
        render = function (options) {
            var rendererName = null, 
                selector = null, 
                data = null, 
                vizOptions = {},
                renderOpt = null,
                renderFunc = null,
                dataHelper = null;

            // Check required properties have been supplied
            if (typeof options !== 'object') {
                throw "The render options must be supplied as an object.";
            }
            if (!options.hasOwnProperty("rendererName")) {
                throw "The rendererName must be supplied as part of the render options.";
            }
            if (!options.hasOwnProperty("selector")) {
                throw "The selector must be supplied as part of the render options.";
            }
            if (!options.hasOwnProperty("data")) {
                throw "The data settings must be supplied as part of the render options.";
            }

            // Get the render options
            rendererName = options["rendererName"];
            selector = options["selector"];
            data = options["data"];
            if (options.hasOwnProperty("vizOptions")) {
                vizOptions = options["vizOptions"]
            }

            // Setup the data helper
            if (typeof data === 'undefined') {
                throw "No data settings were supplied when getting renderer."
            }
            dataHelper = new vizshare.dataHelper(data);
            
            // Run renderer
            if (!rendererLookup.hasOwnProperty(rendererName)) {
                throw "No renderer has been registered with the name '" + rendererName + "'";
            }
            renderOpt = rendererLookup[rendererName];
            renderFunc = renderOpt.renderFunc;
            if (typeof renderFunc !== 'function') {
                throw "The renderer with the name '" + rendererName + "' is not a function.";
            }
            renderFunc(selector, dataHelper, vizOptions);
        },

        registerRenderer = function (rendererName, rendererOptions) {
            rendererLookup[rendererName] = rendererOptions;
        };

        //createDataHelper = function (dataSettings) {
        //    var dataHelper = {};
        //    dataHelper.dataSettings = dataSettings;
        //};

    // Public
    return {
        registerRenderer: registerRenderer,
        render: render
    };
} ());

vizshare.dataHelper = (function () {
    var Constr,
        dataSettings = {};
    // public API -- constructor
    Constr = function (dataSettings1) {
        var item = this;
        dataSettings = dataSettings1;
    };

    // public API -- prototype
    Constr.prototype = {
        constructor: vizshare.dataHelper,
        version: "0.1.0",
        dataSettings: dataSettings,
        getDataset: function (datasetName) {
            var datasets = dataSettings,
                len = datasets.length,
                i = 0,
                dataSetHelper = null,
                dataSetSettings = {};
            for (i = 0; i < len; i += 1) {
                if (datasets[i].name === datasetName) {
                    dataSetSettings = datasets[i];
                    dataSetHelper = new vizshare.dataSetHelper(dataSetSettings);
                    return dataSetHelper;
                }
            }
            return null;
        },
        getDataSettings: function () {
            // Gets the original data settings sent to the renderer
            return dataSettings;
        }
    };
    
    // return the constructor to be assigned to the new namespace
    return Constr;
} ());

vizshare.dataSetHelper = (function () {
    var Constr,
        dataSetSettings = {},
        url = null;
    // public API -- constructor
    Constr = function (dataSetSettings) {
        var item = this;
        item.dataSetSettings = dataSetSettings;

        // Copy the data settings onto the helper for easy access
        item.url = dataSetSettings.url;
    };

    // public API -- prototype
    Constr.prototype = {
        constructor: vizshare.dataSetHelper,
        version: "0.1.0",
        url: url,
        dataSetSettings: dataSetSettings,
        getDataField: function (vizFieldName) {
            var fields = this.dataSetSettings.fields,
                len = fields.length,
                i = 0,
                field = null;
            for (i = 0; i < len; i += 1) {
                if (fields[i].vizField === vizFieldName) {
                    field = fields[i];
                    if (typeof field === 'undefined') {
                        throw "Could not find field with viz name'" + vizFieldName + "'";
                    }
                    return field.dataField;
                }
            }
            return null;
        }
    };

    // return the constructor to be assigned to the new namespace
    return Constr;
} ());

// jQuery wrapper
// ToDo: split jquery plug in into a separate file?
(function ($) {
    $.fn.duGetPath = function () {
        // From http://stackoverflow.com/questions/2068272/getting-a-jquery-selector-for-an-element
        if (this.length != 1) throw 'Requires one element.';

        var path, node = this;
        while (node.length) {
            var realNode = node[0];
            var name = (
                // IE9 and non-IE
                realNode.localName ||
                // IE <= 8
                realNode.tagName ||
                realNode.nodeName
            );

            // on IE8, nodeName is '#document' at the top level, but we don't need that
            if (!name || name == '#document') break;

            name = name.toLowerCase();
            if (realNode.id) {
                // As soon as an id is found, there's no need to specify more.
                return name + '#' + realNode.id + (path ? '>' + path : '');
            } else if (realNode.className) {
                name += '.' + realNode.className.split(/\s+/).join('.');
            }

            var parent = node.parent(), siblings = parent.children(name);
            if (siblings.length > 1) name += ':eq(' + siblings.index(node) + ')';
            path = name + (path ? '>' + path : '');

            node = parent;
        }

        return path;
    };

    $.fn.vizshare = function (opts) {
        return this.each(function () {
            var path = $(this).duGetPath(),
                renderOpts = $.extend({}, opts, {selector: path});
            vizshare.render(renderOpts);
        });
    };
}(jQuery));