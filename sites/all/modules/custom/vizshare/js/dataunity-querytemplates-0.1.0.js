var dataunity = dataunity || {};

// ToDo: move out to core file
dataunity.config = (function () {
    // Private members
    var defaultBaseUrl = '',
        baseUrl = defaultBaseUrl,
        setBaseUrl = function (url) {
            // Sets the base urls for all requests. By default
            // requests will be made relative to current site,
            // but a different site can be specified.
            // The supplied url must not be terminated in a
            // forward slash
            baseUrl = url;
        },
        getBaseUrl = function () {
            return baseUrl;
        },
        resetBaseUrl = function () {
            setBaseUrl(defaultBaseUrl);
        };

    // Public
    return {
        getBaseUrl: getBaseUrl,
        setBaseUrl: setBaseUrl,
        resetBaseUrl: resetBaseUrl
    };
}());

dataunity.querytemplate = (function ($) {
    // Dependencies
    var duConfig = dataunity.config,
        DU_PIPES_PREFIX = 'pipes', // ToDo: needs moving out to namespace module

    // Private members
        createGroupAggregateDataTable = function (label, sourceDataTableURL, groupField, aggField, aggType) {
            var deferred = $.Deferred();
            var flowDefTemplateURL = duConfig.getBaseUrl() + "/api/beta/pipes/flow-defs/templates/datatabletap-group-aggregate",
                dataTableTemplateURL = duConfig.getBaseUrl() + "/api/beta/datatables/templates/datatabletap",
                flowDefsURL = duConfig.getBaseUrl() + "/api/beta/pipes/flow-defs",
                dataTablesURL = duConfig.getBaseUrl() + "/api/beta/datatables",
                flowDefTemplatePromise = $.get(flowDefTemplateURL),
                dataTableTemplatePromise = $.get(dataTableTemplateURL);//,
                //flowDefTemplate = null,
                //dataTableTemplate = null;

            $.when(flowDefTemplatePromise, dataTableTemplatePromise)
                .done(function (flowDefTemplateData, dataTableTemplateData) {

                    var flowDefTemplate = flowDefTemplateData[0],
                        dataTableTemplate = dataTableTemplateData[0];
                    console.log(flowDefTemplate);
                    console.log(dataTableTemplate);

                    flowDefTemplate.source.tap.dataTable["@id"] = sourceDataTableURL;
                    $.each(flowDefTemplate.pipeAssembly.pipe, function (index, pipe) {
                        if (pipe["@type"] === 'GroupBy') {
                            pipe.argumentSelector.name = groupField;
                        } else if (pipe["@type"] === 'Every') {
                            pipe.argumentSelector.name = aggField;
                            pipe.aggregator["@type"] = DU_PIPES_PREFIX + ":" + aggType;
                        }
                    });

                    $.ajax({
                            type: "POST",
                            url: flowDefsURL,
                            data: JSON.stringify(flowDefTemplate),
                            contentType: 'application/json'
                        })
                        .done(function (data, textStatus, jqXHR) {
                            var flowDefURL = jqXHR.getResponseHeader("Location");
                            console.log("flowDefURL:");
                            console.log(flowDefURL);

                            $.get(flowDefURL)
                                .done(function (data, textStatus, jqXHR) {
                                    // Find the tailsink tap of flowdef
                                    var tailSinkTap = data.tailSink.tap["@id"];
                                    console.log("tailSinkTap:");
                                    console.log(tailSinkTap);

                                    // Create DataTable
                                    dataTableTemplate.label = label;
                                    dataTableTemplate.dataSource.tap = tailSinkTap;
                                    $.ajax({
                                            type: "POST",
                                            url: dataTablesURL,
                                            data: JSON.stringify(dataTableTemplate),
                                            contentType: 'application/json'
                                        })
                                        .done(function (data, textStatus, jqXHR) {
                                            var dataTableURL = jqXHR.getResponseHeader("Location");
                                            deferred.resolve(dataTableURL);
                                        });
                                });
                        });
                });

            return deferred.promise();
        };

        groupAggregateDataTableFieldNames = function (groupField, aggField, aggType) {
            return {
                'groupField': groupField,
                'aggField': aggType.toLowerCase()
            };
        };

    // Public
    return {
        createGroupAggregateDataTable: createGroupAggregateDataTable,
        groupAggregateDataTableFieldNames: groupAggregateDataTableFieldNames
    };
} (jQuery));
