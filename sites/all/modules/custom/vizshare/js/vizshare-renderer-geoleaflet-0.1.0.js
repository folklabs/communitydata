// Geo rendering using Leaflet

(function ($, d3, L) {
    var latFieldRef = "lat",
        longFieldRef = "long",
        titleFieldRef = "title",
        valueFieldRef = "value",

        getRequiredAttribute = function (obj, attribute) {
            // Helper function to retrieve an attribute from an obj.
            // Errors if attribute is missing.
            if (typeof obj === "undefined") {
                throw "Undefined object - can't get attribute '" + attribute + "'";
            }
            if (typeof obj[attribute] === "undefined") {
                throw "Undefined attribute on object - can't get attribute '" + attribute + "'";
            }
            return obj[attribute];
        },

        getOptionalAttribute = function (obj, attribute) {
            // Helper function to retrieve an attribute from an obj.
            // Returns null if attribute is missing.
            if (obj === null || typeof obj !== "object") {
                return null;
            }
            if (typeof obj[attribute] === "undefined") {
                return null;
            }
            return obj[attribute];
        },

        dataToPointGeoJSON = function (markConfig, dataHelper, dataLookup, scalesLookup) {
            // Converts csv to geo json
            var markConfig = markConfig || {},
                properties = markConfig.properties || {},
                enter_properties = properties.enter || {},
                defaultRadius = 150,
                feature = {},
                features = [],
                latRef = null,
                latVizField = null,
                latDataField = "",
                longRef = null,
                longVizField = null,
                longDataField = "",
                textRef = null,
                textVizField = null,
                textDataField = "",
                sizeRef = null,
                sizeVizField = null,
                sizeDataField = "",
                sizeScaleName = "",
                sizeScale = null,
                fillRef = null,
                fillVizField = null,
                fillDataField = "",
                fillScaleName = "",
                fillScale = null,
                datasetRef = "",
                data = null,
                dataset = null;

            // Get data
            if (typeof markConfig.from !== 'object') {
                throw "Expected marks to have a data 'from' data reference.";
            }
            datasetRef = markConfig.from.data;
            if (typeof datasetRef === 'undefined') {
                throw "Marks 'from' should have a data attribute naming the data table to be used.";
            }
            data = dataLookup[datasetRef];
            if (typeof data === 'undefined') {
                throw "No data found for marks for data reference " + datasetRef;
            }

            dataset = dataHelper.getDataset(datasetRef);

            // Lat and Long
            latRef = getRequiredAttribute(enter_properties, "lat");
            // ToDo: check for other options, like static value
            latVizField = getRequiredAttribute(latRef, "vizField");
            latDataField = dataset.getDataField(latVizField);

            longRef = getRequiredAttribute(enter_properties, "long");
            // ToDo: check for other options, like static value
            longVizField = getRequiredAttribute(longRef, "vizField");
            longDataField = dataset.getDataField(longVizField);

            sizeRef = getOptionalAttribute(enter_properties, "size");
            // ToDo: check for other options, like static value
            sizeVizField = getOptionalAttribute(sizeRef, "vizField");
            sizeDataField = dataset.getDataField(sizeVizField);
            // Optional value scale
            sizeScaleName = getOptionalAttribute(sizeRef, "scale");
            if (sizeScaleName) {
                sizeScale = scalesLookup[sizeScaleName];
            }

            // Optional popup text
            textRef = getOptionalAttribute(enter_properties, "text");
            // ToDo: check for other options, like static value
            textVizField = getOptionalAttribute(textRef, "vizField");
            textDataField = dataset.getDataField(textVizField);

            // Optional fill
            fillRef = getOptionalAttribute(enter_properties, "fill");
            // ToDo: check for other options, like static value
            fillVizField = getOptionalAttribute(fillRef, "vizField");
            fillDataField = dataset.getDataField(fillVizField);
            // Optional value scale
            fillScaleName = getOptionalAttribute(fillRef, "scale");
            if (fillScaleName) {
                fillScale = scalesLookup[fillScaleName];
            }

            $.each(data, function (index, row) {
                var lat = +row[latDataField],
                    long_ = +row[longDataField],
                    radius = defaultRadius,
                    text = "",
                    data_val = null,
                    val = 0,
                    fill = null;

                // ToDo: support static values
                // Optional: Cacluate radius from data value
                if (sizeDataField) {
                    data_val = +row[sizeDataField];
                    val = data_val;
                    if (sizeScale) {
                        val = sizeScale(val);
                    }
                    radius = Math.sqrt(val / Math.PI);
                    if (isNaN(radius)) {
                        radius = 0;
                    }
                }

                // Optional: Popup text
                if (textDataField) {
                    text = row[textDataField];
                    if (data_val !== null) {
                        text += "<br>Value: " + data_val;
                    }
                }

                // Optional fill
                if (fillDataField) {
                    fill = row[fillDataField];
                    // ToDo: look at scale type to see if
                    // it's linear/ordinal. Don't convert
                    // ordinal fields to numbers
                    if (fillScale) {
                        fill = (+fill);
                        fill = fillScale(fill);
                    }
                }

                feature = {
                    "type" : "Feature",
                    "geometry" : {
                        "type" : "Point",
                        "coordinates" : [long_, lat]
                    },
                    "properties" : {
                        "name" : "test",
                        "circle": "true",
                        "radius": radius,
                        "text": text
                    }
                };
                if (fill !== null) {
                    feature.properties.fill = fill;
                }
                features.push(feature);
            });

            return features;
        },

        createScale = function (scaleConfig, dataHelper, dataLookup) {
            var scaleType = scaleConfig.type,
                domain = scaleConfig.domain,
                range = scaleConfig.range,
                scale = null;

            if (typeof scaleType === 'undefined') {
                scaleType = "linear";
            }

            switch (scaleType) {
                case "linear":
                    scale = d3.scale.linear();
                    break;
                default:
                    throw "Can't create scales of type " + scaleType;
            }

            if (domain) {
                if ($.isArray(domain)) {
                    // Domain is already an array
                    scale.domain(domain);
                } else if (typeof domain === "object") {
                    // Domain is a reference object
                    if (!domain.hasOwnProperty("data") || !domain.hasOwnProperty("vizField")) {
                        throw "The scale's domain should have a data attribute and vizField attribute."
                    }
                    var data = dataLookup[domain.data];
                    var dataField = dataHelper.getDataset(domain.data).getDataField(domain.vizField);
                    var min = d3.min(data, function (d) { return +d[dataField]; });
                    var max = d3.max(data, function (d) { return +d[dataField]; });
                    scale.domain([min, max]);
                } else {
                    throw "Unrecognised form for scale domain."
                }
            }

            if (range) {
                if ($.isArray(range)) {
                    scale.range(range);
                } else {
                    throw "Unrecognised form for scale range."
                }
            }

            return scale;
        },

        addMarkToMap = function (markConfig, map, dataHelper, dataLookup, scalesLookup, latLongPoints) {
            var markConfig = markConfig || {},
                markType = markConfig.type,
                markerType = "circle";

            switch (markType) {
                case "latlongcircle":
                case "latlongmarker":

                    if (markType === "latlongcircle") {
                        markerType = "circle";
                    } else {
                        markerType = "marker";
                    }

                    features = dataToPointGeoJSON(markConfig, dataHelper, dataLookup, scalesLookup);

                    L.geoJson(features, {
                        pointToLayer: function (feature, latlng) {
                            var feature = feature || {},
                                featureProperties = feature.properties || {},
                                geojsonMarkerOptions = {};

                            latLongPoints.extend(latlng);
                            // Create marker
                            var marker = null;
                            //if (featureProperties.circle === 'true') {
                            if (markerType === "circle") {
                                // Fill colour
                                if (typeof featureProperties.fill !== "undefined") {
                                   geojsonMarkerOptions.color = featureProperties.fill;
                                }

                                marker = L.circle(latlng, featureProperties.radius, geojsonMarkerOptions);
                            } else {
                                marker = L.marker(latlng);
                            }

                            // Add optional popup
                            if (typeof (feature.properties) !== 'undefined' &&
                                typeof (feature.properties.text) !== 'undefined') {
                                marker.bindPopup(feature.properties.text);
                            }
                            return marker;
                        }}).addTo(map);
                    break;
                default:
                    throw "Unrecognised mark type '" + markType + "'";
            }
        },

        addMarksToMap = function (map, dataHelper, dataLookup, vizSettings, latLongPoints) {
            console.log(vizSettings);
            // Uses the data settings to add features to map
            var dataSettings = dataHelper.getDataSettings(),
                vizSettings = vizSettings || {},
                scaleConfigs = vizSettings.scales || [],
                markConfigs = vizSettings.marks || [],
                scalesLookup = {},
                marksLookup = {};

            // Generate scales lookup
            $.each(scaleConfigs, function (index, scaleConfig) {
                var scale = createScale(scaleConfig, dataHelper, dataLookup);
                scalesLookup[scaleConfig.name] = scale;
            });

            //

            // Generate marks
            $.each(markConfigs, function (index, markConfig) {
                addMarkToMap(markConfig, map, dataHelper, dataLookup, scalesLookup, latLongPoints);
            });

            // $.each(dataSettings, function (index, dataset) {
            //     var dataSetRef = dataset.name,
            //         data = dataLookup[dataSetRef];

            //         // Actual field names in the data
            //         dataset = dataHelper.getDataset(dataSetRef),
            //         fieldLat = dataset.getDataField(latFieldRef),
            //         fieldLong = dataset.getDataField(longFieldRef),
            //         fieldTitle = dataset.getDataField(titleFieldRef);


            //     // Create marks

            //     features = dataToGeoJSON(data, fieldLat, fieldLong, fieldTitle);
            //     console.log(features);

            //     L.geoJson(features, {
            //         pointToLayer: function (feature, latlng) {
            //             if (typeof (feature.properties) !== 'undefined' &&
            //                 typeof (feature.properties.circle) !== 'undefined' &&
            //                 feature.properties.circle == 'true') {
            //                 return L.circle(latlng, feature.properties.radius);
            //             }
            //             return L.marker(latlng);
            //         }}).addTo(map);
            // });
        },

        renderFuncGeoLeaflet = function (selector, dataHelper, vizSettings) {
            // References to look up in the data settings
            var domElem = $(selector).get(0),
                map = L.map(domElem),//.setView([51.505, -0.09], 13),
                latLongPoints = L.latLngBounds([]);

            // Set the background tiles
            L.tileLayer('http://{s}.tile.osm.org/{z}/{x}/{y}.png', {
                attribution: '&copy; <a href="http://osm.org/copyright">OpenStreetMap</a> contributors'
            }).addTo(map);

            // Load all the datasets
            var dataSettings = dataHelper.getDataSettings();
            var q = queue();
            $.each(dataSettings, function (index, dataset) {
                q.defer(csv, dataset.url);
            });
            q.awaitAll(function(error, results) {
                var dataLookup = {};
                //console.log("async results");
                //console.log(results);
                // Save data results
                $.each(results, function (index, data) {
                    var datasetName = dataSettings[index]["name"];
                    dataLookup[datasetName] = data;
                    //dataSettings[index]["_data"] = data;
                });
                //console.log(dataSettings);
                addMarksToMap(map, dataHelper, dataLookup, vizSettings, latLongPoints);
                map.fitBounds(latLongPoints.pad(0.1));
            });

            function csv(path, callback) {
                d3.csv(path, function(csv) {
                    csv ? callback(null, csv) : callback("error", null);
                });
            }

        };

    // Register the render function
    var renderOpts = {'renderFunc': renderFuncGeoLeaflet};
    vizshare.registerRenderer("vizshare.geoleaflet", renderOpts);
} (jQuery, d3, L));
