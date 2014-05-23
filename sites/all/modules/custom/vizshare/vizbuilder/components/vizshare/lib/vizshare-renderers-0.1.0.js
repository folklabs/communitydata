/*
 * VizShare Renderers
 */
 var vizshare = vizshare || {};

vizshare.vega = (function (vg) {
    var render = function (renderTo, spec) {
              vg.parse.spec(spec, function (chart) { 
                  chart({el: renderTo}).renderer("svg").update(); 
              });
        },
        encodeFieldName = function (fieldName) {
            return fieldName.replace(".", "\\.");
        };

    return {
        render: render,
        encodeFieldName: encodeFieldName
    };
}(vg));

// Bar chart renderer
// Note: requires Vega and D3
(function (vegaHelper) {
    var renderFuncBar = function (selector, dataHelper, vizSettings) {
            // References to look up in the data settings
        var dataSetRef = "default",
            xAxisFieldRef = "xAxis",
            yAxisFieldRef = "yAxis",

            // Actual field names in the data
            dataset = dataHelper.getDataset(dataSetRef),
            fieldXAxis = dataset.getDataField(xAxisFieldRef),
            fieldYAxis = dataset.getDataField(yAxisFieldRef),

            // Viz
            vegaSpec = null;

        // Encode vega field references
        fieldXAxis = vegaHelper.encodeFieldName(fieldXAxis);
        fieldYAxis = vegaHelper.encodeFieldName(fieldYAxis);
        
        // Vega spec
        vegaSpec = {
            "width": 400,
            "height": 200,
            "data": [
                {
                    "name": dataSetRef,
                    "url": dataset.url,
                    "format": {"type": "csv", "parse": {fieldYAxis: "number"}}
                }
            ],
            "scales": [
                {
                    "name": "x",
                    "type": "ordinal",
                    "range": "width",
                    "domain": {"data": dataSetRef, "field": "data." + fieldXAxis}
                },
                {
                    "name": "y",
                    "range": "height",
                    "nice": true,
                    "domain": {"data": dataSetRef, "field": "data." + fieldYAxis}
                },
                {
                    "name": "color",
                    "type": "ordinal",
                    "range": "category20",
                    "domain": {"data": dataSetRef, "field": "data." + fieldXAxis}
                }
            ],
            "axes": [
                {
                    "type": "x", 
                    "scale": "x"
                },
                {"type": "y", "scale": "y"}
            ],
            "marks": [
                {
                    "type": "rect",
                    "from": {"data": dataSetRef},
                    "properties": {
                        "enter": {
                            "x": {"scale": "x", "field": "data." + fieldXAxis},
                            "width": {"scale": "x", "band": true, "offset": -1},
                            "y": {"scale": "y", "field": "data." + fieldYAxis},
                            "y2": {"scale": "y", "value": 0}
                        },
                        "update": {
                            "fill": {"scale": "color", "field": "data." + fieldXAxis}
                        },
                        "hover": {
                            "fill": {"value": "red"}
                        }
                    }
                }
            ]
        };

        //console.log(JSON.stringify(vegaSpec, undefined, 2));
        vegaHelper.render(selector, vegaSpec);
    };

    // Register the render function
    var renderOpts = {'renderFunc': renderFuncBar};
    vizshare.registerRenderer("vizshare.barchart", renderOpts);
} (vizshare.vega));


// Pie chart renderer
// Note: requires Vega and D3
(function (vegaHelper) {
    var renderFuncPie = function (selector, dataHelper, vizSettings) {
            // References to look up in the data settings
        var dataSetRef = "default",
            nameFieldRef = "name",
            valueFieldRef = "value",

            // Actual field names in the data
            dataset = dataHelper.getDataset(dataSetRef),
            nameField = dataset.getDataField(nameFieldRef),
            valueField = dataset.getDataField(valueFieldRef),

            // Viz
            vegaSpec = null;

        // Encode vega field references
        nameField = vegaHelper.encodeFieldName(nameField);
        valueField = vegaHelper.encodeFieldName(valueField);

        // Viz dimensions
        var height = 400;
        var width = 400;
        minExtent = Math.min(height, width);
        outerRadius = Math.floor(minExtent / 2);
        innerRadius = Math.floor(minExtent * 0.30);
        labelRadius = Math.floor(innerRadius + ((outerRadius - innerRadius) / 2));
        
        // Vega spec
        vegaSpec = {
            "width": width,
            "height": height,
            "data": [
                {
                    "name": dataSetRef,
                    "url": dataset.url,
                    "format": {"type": "csv", "parse": {valueField: "number"}},
                    "transform": [
                        {"type": "pie", "value": "data." + valueField},
                        {"type": "formula", "field": "hyp", "expr": String(labelRadius)},
                        {"type": "formula", "field": "theta", "expr": "d.startAngle + 0.5 *(d.endAngle - d.startAngle) - 1.57079633"},
                        {"type": "formula", "field": "x_mid", "expr": String(width / 2)},
                        {"type": "formula", "field": "y_mid", "expr": String(height / 2)},
                        {"type": "formula", "field": "x", "expr": "d.x_mid + (d.hyp * Math.cos(d.theta))"},
                        {"type": "formula", "field": "y", "expr": "d.y_mid + (d.hyp * Math.sin(d.theta))"}
                    ]
                }
            ],
            "scales": [
                {
                    "name": "r",
                    "type": "sqrt",
                    "domain": {"data": "table", "field": "data." + valueField},
                    "range": [20, 100]
                },
                {
                    "name": "color",
                    "type": "ordinal",
                    "range": "category20",
                    "domain": {"data": "table", "field": "data." + nameField}
                }
            ],
            "legends": [
                {
                    "fill": "color",
                    "offset": 0,
                    "properties": {
                        "symbols": {
                            "fillOpacity": {"value": 0.5},
                            "stroke": {"value": "transparent"}
                        }
                    }
                }
            ],
            "marks": [
                {
                    "type": "arc",
                    "from": {"data": dataSetRef},
                    "properties": {
                        "enter": {
                            "x": {"group": "width", "mult": 0.5},
                            "y": {"group": "height", "mult": 0.5},
                            "startAngle": {"field": "startAngle"},
                            "endAngle": {"field": "endAngle"},
                            "outerRadius": {"value": outerRadius},
                            "innerRadius": {"value": innerRadius},
                            "stroke": {"value": "#fff"}
                        },
                        "update": {
                            "fill": {"scale": "color", "field": "data." + nameField}
                        }
                    }
                },
                {
                    "type": "text",
                    "from": {"data": dataSetRef},
                    "properties": {
                        "enter": {
                            "y": {"field": "y"},
                            "x": {"field": "x"},
                            "fill": {"value": "black"},
                            "align": {"value": "center"},
                            "baseline": {"value": "middle"},
                            "text": {"field": "data." + valueField}
                        }
                    }
                }
            ]
        };

        //console.log(JSON.stringify(vegaSpec, undefined, 2));
        vegaHelper.render(selector, vegaSpec);
    };

    // Register the render function
    var renderOpts = {'renderFunc': renderFuncPie};
    vizshare.registerRenderer("vizshare.piechart", renderOpts);
} (vizshare.vega));


// Line chart renderer
// Note: requires Vega and D3
/*
 * THERE IS A PROBLEM WITH LINE RENDERER
 * One single line is drawn for all the series, so it always
 * stays the same colour (see svg source)
 */
(function (vegaHelper) {
    var renderFuncLine = function (selector, dataHelper, vizSettings) {
            // References to look up in the data settings
        var dataSetRef = "default",
            xAxisFieldRef = "xAxis",
            yAxisFieldRef = "yAxis",
            nameFieldRef = "name",

            // Actual field names in the data
            dataset = dataHelper.getDataset(dataSetRef),
            fieldXAxis = dataset.getDataField(xAxisFieldRef),
            fieldYAxis = dataset.getDataField(yAxisFieldRef),
            fieldName = dataset.getDataField(nameFieldRef),

            // Viz
            vegaSpec = null;

        // Encode vega field references
        fieldXAxis = vegaHelper.encodeFieldName(fieldXAxis);
        fieldYAxis = vegaHelper.encodeFieldName(fieldYAxis);
        fieldName = vegaHelper.encodeFieldName(fieldName);
        
        // Vega spec
        vegaSpec = {
            "width": 400,
            "height": 200,
            "data": [
                {
                    "name": dataSetRef,
                    "url": dataset.url,
                    "format": {
                        "type": "csv", 
                        "parse": {
                            fieldXAxis: "number",
                            fieldYAxis: "number"
                        }
                    }
                }
            ],
            "scales": [
                {
                    "name": "x",
                    "type": "linear",
                    "range": "width",
                    "domain": {"data": dataSetRef, "field": "data." + fieldXAxis}
                },
                {
                    "name": "y",
                    "type": "linear",
                    "range": "height",
                    "nice": true,
                    "domain": {"data": dataSetRef, "field": "data." + fieldYAxis}
                },
                {
                    "name": "color", 
                    "type": "ordinal", 
                    "range": "category10"
                }
            ],
            "axes": [
                {
                    "type": "x", 
                    "scale": "x"
                },
                {
                    "type": "y", 
                    "scale": "y"
                }
            ],
            "legends": [
                {
                    "fill": "color",
                    "offset": 0,
                    "properties": {
                        "symbols": {
                            "fillOpacity": {"value": 0.5},
                            "stroke": {"value": "transparent"}
                        }
                    }
                }
            ],
            "marks": [
                {
                    "type": "group",
                    "from": {
                        "data": dataSetRef,
                        "transform": [{"type": "facet", "keys": ["data." + fieldName]}]
                    },
                    "marks": [
                        {
                            "type": "line",
                            "from": {"data": dataSetRef},
                            "properties": {
                                "enter": {
                                    "x": {"scale": "x", "field": "data." + fieldXAxis},
                                    "y": {"scale": "y", "field": "data." + fieldYAxis},
                                    "stroke": {"scale": "color", "field": "data." + fieldName},
                                    "strokeWidth": {"value": 2}
                                }
                            }
                        }
                    ]
                }
                
            ]
        };

        console.log(JSON.stringify(vegaSpec, undefined, 2));
        vegaHelper.render(selector, vegaSpec);
    };

    // Register the render function
    var renderOpts = {'renderFunc': renderFuncLine};
    vizshare.registerRenderer("vizshare.linechart", renderOpts);
} (vizshare.vega));