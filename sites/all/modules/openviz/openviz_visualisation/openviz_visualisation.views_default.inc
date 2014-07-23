<?php
/**
 * @file
 * openviz_visualisation.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function openviz_visualisation_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'openviz_facets';
  $view->description = '(ASH)';
  $view->tag = 'openviz';
  $view->base_table = 'search_api_index_database_node_index';
  $view->human_name = 'Openviz Facets';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Openviz Facets';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_database_node_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_database_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'ov_visualisation' => 'ov_visualisation',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Node: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_database_node_index';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['link_to_entity'] = 0;
  $handler->display->display_options['path'] = 'openviz-facets';

  /* Display: OpenViz Facets View Tags Pane Display */
  $handler = $view->new_display('panel_pane', 'OpenViz Facets View Tags Pane Display', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Openviz Facets Tags Pane';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Node: Tags */
  $handler->display->display_options['fields']['field_ov_tags']['id'] = 'field_ov_tags';
  $handler->display->display_options['fields']['field_ov_tags']['table'] = 'search_api_index_database_node_index';
  $handler->display->display_options['fields']['field_ov_tags']['field'] = 'field_ov_tags';
  $handler->display->display_options['fields']['field_ov_tags']['list']['mode'] = 'first';
  $handler->display->display_options['fields']['field_ov_tags']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_ov_tags']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_ov_tags']['bypass_access'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Indexed Node: Tags */
  $handler->display->display_options['arguments']['field_ov_tags']['id'] = 'field_ov_tags';
  $handler->display->display_options['arguments']['field_ov_tags']['table'] = 'search_api_index_database_node_index';
  $handler->display->display_options['arguments']['field_ov_tags']['field'] = 'field_ov_tags';
  $handler->display->display_options['arguments']['field_ov_tags']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_ov_tags']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_ov_tags']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_ov_tags']['not'] = 0;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_database_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'ov_visualisation' => 'ov_visualisation',
  );

  /* Display: OpenViz Facets View Type Pane */
  $handler = $view->new_display('panel_pane', 'OpenViz Facets View Type Pane', 'panel_pane_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Openviz Facets Type Pane';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Node: Type */
  $handler->display->display_options['fields']['field_ov_type']['id'] = 'field_ov_type';
  $handler->display->display_options['fields']['field_ov_type']['table'] = 'search_api_index_database_node_index';
  $handler->display->display_options['fields']['field_ov_type']['field'] = 'field_ov_type';
  $handler->display->display_options['fields']['field_ov_type']['label'] = '';
  $handler->display->display_options['fields']['field_ov_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ov_type']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_ov_type']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_ov_type']['bypass_access'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Indexed Node: Type */
  $handler->display->display_options['sorts']['field_ov_type']['id'] = 'field_ov_type';
  $handler->display->display_options['sorts']['field_ov_type']['table'] = 'search_api_index_database_node_index';
  $handler->display->display_options['sorts']['field_ov_type']['field'] = 'field_ov_type';

  /* Display: OpenViz Facets View Updated Pane */
  $handler = $view->new_display('panel_pane', 'OpenViz Facets View Updated Pane', 'panel_pane_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Openviz Facets Updated Pane';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Node: Date changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'search_api_index_database_node_index';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = '';
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'time ago';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'panopoly_time';
  $handler->display->display_options['fields']['changed']['link_to_entity'] = 1;

  /* Display: OpenViz Facets View Category Pane */
  $handler = $view->new_display('panel_pane', 'OpenViz Facets View Category Pane', 'panel_pane_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Openviz Facets Category Pane';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Node: Categories */
  $handler->display->display_options['fields']['field_ov_categories']['id'] = 'field_ov_categories';
  $handler->display->display_options['fields']['field_ov_categories']['table'] = 'search_api_index_database_node_index';
  $handler->display->display_options['fields']['field_ov_categories']['field'] = 'field_ov_categories';
  $handler->display->display_options['fields']['field_ov_categories']['label'] = '';
  $handler->display->display_options['fields']['field_ov_categories']['alter']['path'] = '/category/';
  $handler->display->display_options['fields']['field_ov_categories']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ov_categories']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_ov_categories']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_ov_categories']['bypass_access'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_database_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'ov_visualisation' => 'ov_visualisation',
  );
  $handler->display->display_options['inherit_panels_path'] = '0';

  /* Display: OpenViz Facets View Title Pane */
  $handler = $view->new_display('panel_pane', 'OpenViz Facets View Title Pane', 'panel_pane_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Openviz Facets Title Pane';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'date_views_pager';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_database_node_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_database_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'ov_visualisation' => 'ov_visualisation',
  );

  /* Display: Visualization Browser Centre Pane */
  $handler = $view->new_display('panel_pane', 'Visualization Browser Centre Pane', 'panel_pane_6');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_ov_thumbnail' => 'field_ov_thumbnail',
    'title' => 'title',
    'field_ov_categories' => 'title',
    'field_ov_tags' => 'title',
    'field_ov_type' => 'field_ov_type',
    'author' => 'field_ov_type',
    'field_ov_rating' => 'field_ov_type',
    'created' => 'title',
    'changed' => 'title',
    'body' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_ov_thumbnail' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'align' => 'views-align-left',
      'separator' => ' <br>',
      'empty_column' => 0,
    ),
    'field_ov_categories' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_ov_tags' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_ov_type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '<br>',
      'empty_column' => 0,
    ),
    'author' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-right',
      'separator' => '<br>',
      'empty_column' => 0,
    ),
    'field_ov_rating' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Indexed Node: Visualization */
  $handler->display->display_options['relationships']['field_viz']['id'] = 'field_viz';
  $handler->display->display_options['relationships']['field_viz']['table'] = 'search_api_index_database_node_index';
  $handler->display->display_options['relationships']['field_viz']['field'] = 'field_viz';
  /* Relationship: Indexed Node: Type */
  $handler->display->display_options['relationships']['field_ov_type']['id'] = 'field_ov_type';
  $handler->display->display_options['relationships']['field_ov_type']['table'] = 'search_api_index_database_node_index';
  $handler->display->display_options['relationships']['field_ov_type']['field'] = 'field_ov_type';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: OV Thumbnail */
  $handler->display->display_options['fields']['field_ov_thumbnail']['id'] = 'field_ov_thumbnail';
  $handler->display->display_options['fields']['field_ov_thumbnail']['table'] = 'entity_taxonomy_term';
  $handler->display->display_options['fields']['field_ov_thumbnail']['field'] = 'field_ov_thumbnail';
  $handler->display->display_options['fields']['field_ov_thumbnail']['relationship'] = 'field_ov_type';
  $handler->display->display_options['fields']['field_ov_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_ov_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ov_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_ov_thumbnail']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Indexed Node: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_database_node_index';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['text'] = 'Name: [title]';
  $handler->display->display_options['fields']['title']['element_type'] = 'strong';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  /* Field: Indexed Node: Categories */
  $handler->display->display_options['fields']['field_ov_categories']['id'] = 'field_ov_categories';
  $handler->display->display_options['fields']['field_ov_categories']['table'] = 'search_api_index_database_node_index';
  $handler->display->display_options['fields']['field_ov_categories']['field'] = 'field_ov_categories';
  $handler->display->display_options['fields']['field_ov_categories']['label'] = '';
  $handler->display->display_options['fields']['field_ov_categories']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_ov_categories']['alter']['text'] = 'Category: [field_ov_categories] ';
  $handler->display->display_options['fields']['field_ov_categories']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ov_categories']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_ov_categories']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_ov_categories']['bypass_access'] = 0;
  /* Field: Indexed Node: Tags */
  $handler->display->display_options['fields']['field_ov_tags']['id'] = 'field_ov_tags';
  $handler->display->display_options['fields']['field_ov_tags']['table'] = 'search_api_index_database_node_index';
  $handler->display->display_options['fields']['field_ov_tags']['field'] = 'field_ov_tags';
  $handler->display->display_options['fields']['field_ov_tags']['label'] = '';
  $handler->display->display_options['fields']['field_ov_tags']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_ov_tags']['alter']['text'] = 'Tags: [field_ov_tags]';
  $handler->display->display_options['fields']['field_ov_tags']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ov_tags']['empty'] = 'Tags: <em>(none)</em>';
  $handler->display->display_options['fields']['field_ov_tags']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_ov_tags']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_ov_tags']['bypass_access'] = 0;
  /* Field: Indexed Node: Type */
  $handler->display->display_options['fields']['field_ov_type']['id'] = 'field_ov_type';
  $handler->display->display_options['fields']['field_ov_type']['table'] = 'search_api_index_database_node_index';
  $handler->display->display_options['fields']['field_ov_type']['field'] = 'field_ov_type';
  $handler->display->display_options['fields']['field_ov_type']['label'] = '';
  $handler->display->display_options['fields']['field_ov_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ov_type']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_ov_type']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_ov_type']['bypass_access'] = 0;
  /* Field: Indexed Node: Author */
  $handler->display->display_options['fields']['author']['id'] = 'author';
  $handler->display->display_options['fields']['author']['table'] = 'search_api_index_database_node_index';
  $handler->display->display_options['fields']['author']['field'] = 'author';
  $handler->display->display_options['fields']['author']['label'] = '';
  $handler->display->display_options['fields']['author']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['author']['alter']['text'] = 'Created by: [author] ';
  $handler->display->display_options['fields']['author']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['author']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['author']['view_mode'] = 'full';
  $handler->display->display_options['fields']['author']['bypass_access'] = 0;
  /* Field: Indexed Node: Rating */
  $handler->display->display_options['fields']['field_ov_rating']['id'] = 'field_ov_rating';
  $handler->display->display_options['fields']['field_ov_rating']['table'] = 'search_api_index_database_node_index';
  $handler->display->display_options['fields']['field_ov_rating']['field'] = 'field_ov_rating';
  $handler->display->display_options['fields']['field_ov_rating']['label'] = '';
  $handler->display->display_options['fields']['field_ov_rating']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ov_rating']['click_sort_column'] = 'rating';
  $handler->display->display_options['fields']['field_ov_rating']['settings'] = array(
    'widget' => array(
      'fivestar_widget' => 'default',
    ),
    'expose' => 1,
    'style' => 'average',
    'text' => 'none',
  );
  /* Field: Indexed Node: Date created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'search_api_index_database_node_index';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['created']['alter']['text'] = 'First submitted: [created] ';
  $handler->display->display_options['fields']['created']['element_type'] = 'em';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'D, d/m/Y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'panopoly_time';
  $handler->display->display_options['fields']['created']['link_to_entity'] = 0;
  /* Field: Indexed Node: Date changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'search_api_index_database_node_index';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = '';
  $handler->display->display_options['fields']['changed']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['changed']['alter']['text'] = 'Updated: [changed]';
  $handler->display->display_options['fields']['changed']['element_type'] = 'em';
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'D, d/m/Y';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'panopoly_time';
  $handler->display->display_options['fields']['changed']['link_to_entity'] = 0;
  /* Field: Indexed Node: The main body text */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'search_api_index_database_node_index';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '200',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_database_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'ov_visualisation' => 'ov_visualisation',
  );
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_database_node_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Search by Name';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['inherit_panels_path'] = '1';
  $export['openviz_facets'] = $view;

  $view = new view();
  $view->name = 'openviz_selectors';
  $view->description = '(ASH)';
  $view->tag = 'openviz';
  $view->base_table = 'node';
  $view->human_name = 'OpenViz Selectors';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'OpenViz Ta Selector';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'ov_visualisation' => 'ov_visualisation',
  );

  /* Display: Base Page */
  $handler = $view->new_display('page', 'Base Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'OpenViz Selector Base Page';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['path'] = 'openviz-selectors';

  /* Display: OpenViz Tag Selector Pane */
  $handler = $view->new_display('panel_pane', 'OpenViz Tag Selector Pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Tags';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Tags (field_ov_tags) */
  $handler->display->display_options['relationships']['field_ov_tags_tid']['id'] = 'field_ov_tags_tid';
  $handler->display->display_options['relationships']['field_ov_tags_tid']['table'] = 'field_data_field_ov_tags';
  $handler->display->display_options['relationships']['field_ov_tags_tid']['field'] = 'field_ov_tags_tid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Tags */
  $handler->display->display_options['fields']['field_ov_tags']['id'] = 'field_ov_tags';
  $handler->display->display_options['fields']['field_ov_tags']['table'] = 'field_data_field_ov_tags';
  $handler->display->display_options['fields']['field_ov_tags']['field'] = 'field_ov_tags';
  $handler->display->display_options['fields']['field_ov_tags']['label'] = '';
  $handler->display->display_options['fields']['field_ov_tags']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ov_tags']['group_column'] = 'entity_id';
  $handler->display->display_options['fields']['field_ov_tags']['group_columns'] = array(
    'tid' => 'tid',
  );
  $handler->display->display_options['fields']['field_ov_tags']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_ov_tags']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Taxonomy term: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  $handler->display->display_options['sorts']['name']['relationship'] = 'field_ov_tags_tid';

  /* Display: OpenViz Type Selector Pane */
  $handler = $view->new_display('panel_pane', 'OpenViz Type Selector Pane', 'panel_pane_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Type';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Type (field_ov_type) */
  $handler->display->display_options['relationships']['field_ov_type_tid']['id'] = 'field_ov_type_tid';
  $handler->display->display_options['relationships']['field_ov_type_tid']['table'] = 'field_data_field_ov_type';
  $handler->display->display_options['relationships']['field_ov_type_tid']['field'] = 'field_ov_type_tid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_ov_type']['id'] = 'field_ov_type';
  $handler->display->display_options['fields']['field_ov_type']['table'] = 'field_data_field_ov_type';
  $handler->display->display_options['fields']['field_ov_type']['field'] = 'field_ov_type';
  $handler->display->display_options['fields']['field_ov_type']['label'] = '';
  $handler->display->display_options['fields']['field_ov_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ov_type']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Taxonomy term: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  $handler->display->display_options['sorts']['name']['relationship'] = 'field_ov_type_tid';

  /* Display: OpenViz Category Selector Pane */
  $handler = $view->new_display('panel_pane', 'OpenViz Category Selector Pane', 'panel_pane_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Category';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Categories (field_ov_categories) */
  $handler->display->display_options['relationships']['field_ov_categories_tid']['id'] = 'field_ov_categories_tid';
  $handler->display->display_options['relationships']['field_ov_categories_tid']['table'] = 'field_data_field_ov_categories';
  $handler->display->display_options['relationships']['field_ov_categories_tid']['field'] = 'field_ov_categories_tid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_ov_categories']['id'] = 'field_ov_categories';
  $handler->display->display_options['fields']['field_ov_categories']['table'] = 'field_data_field_ov_categories';
  $handler->display->display_options['fields']['field_ov_categories']['field'] = 'field_ov_categories';
  $handler->display->display_options['fields']['field_ov_categories']['label'] = '';
  $handler->display->display_options['fields']['field_ov_categories']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ov_categories']['group_columns'] = array(
    'tid' => 'tid',
  );
  $handler->display->display_options['fields']['field_ov_categories']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_ov_categories']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Taxonomy term: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  $handler->display->display_options['sorts']['name']['relationship'] = 'field_ov_categories_tid';

  /* Display: OpenViz Favourite Selector Pane */
  $handler = $view->new_display('panel_pane', 'OpenViz Favourite Selector Pane', 'panel_pane_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Favourites';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
    'field_ov_icon' => 'field_ov_icon',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Flags: ov_favorites */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'ov_favorites';
  $handler->display->display_options['relationships']['flag_content_rel']['user_scope'] = 'any';
  /* Relationship: Flags: ov_favorites counter */
  $handler->display->display_options['relationships']['flag_count_rel']['id'] = 'flag_count_rel';
  $handler->display->display_options['relationships']['flag_count_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_count_rel']['field'] = 'flag_count_rel';
  $handler->display->display_options['relationships']['flag_count_rel']['flag'] = 'ov_favorites';
  /* Relationship: Content: Type (field_ov_type) */
  $handler->display->display_options['relationships']['field_ov_type_tid']['id'] = 'field_ov_type_tid';
  $handler->display->display_options['relationships']['field_ov_type_tid']['table'] = 'field_data_field_ov_type';
  $handler->display->display_options['relationships']['field_ov_type_tid']['field'] = 'field_ov_type_tid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: OV Icon */
  $handler->display->display_options['fields']['field_ov_icon']['id'] = 'field_ov_icon';
  $handler->display->display_options['fields']['field_ov_icon']['table'] = 'field_data_field_ov_icon';
  $handler->display->display_options['fields']['field_ov_icon']['field'] = 'field_ov_icon';
  $handler->display->display_options['fields']['field_ov_icon']['relationship'] = 'field_ov_type_tid';
  $handler->display->display_options['fields']['field_ov_icon']['label'] = '';
  $handler->display->display_options['fields']['field_ov_icon']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ov_icon']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_ov_icon']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Flags: Flag counter */
  $handler->display->display_options['sorts']['count']['id'] = 'count';
  $handler->display->display_options['sorts']['count']['table'] = 'flag_counts';
  $handler->display->display_options['sorts']['count']['field'] = 'count';
  $handler->display->display_options['sorts']['count']['relationship'] = 'flag_count_rel';
  $handler->display->display_options['sorts']['count']['order'] = 'DESC';
  $export['openviz_selectors'] = $view;

  $view = new view();
  $view->name = 'openviz_visualisation';
  $view->description = '';
  $view->tag = 'openviz';
  $view->base_table = 'node';
  $view->human_name = 'OpenViz Visualization';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_ov_categories']['id'] = 'field_ov_categories';
  $handler->display->display_options['fields']['field_ov_categories']['table'] = 'field_data_field_ov_categories';
  $handler->display->display_options['fields']['field_ov_categories']['field'] = 'field_ov_categories';
  /* Field: Content: Rating */
  $handler->display->display_options['fields']['field_ov_rating']['id'] = 'field_ov_rating';
  $handler->display->display_options['fields']['field_ov_rating']['table'] = 'field_data_field_ov_rating';
  $handler->display->display_options['fields']['field_ov_rating']['field'] = 'field_ov_rating';
  $handler->display->display_options['fields']['field_ov_rating']['label'] = '';
  $handler->display->display_options['fields']['field_ov_rating']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ov_rating']['click_sort_column'] = 'rating';
  $handler->display->display_options['fields']['field_ov_rating']['settings'] = array(
    'widget' => array(
      'fivestar_widget' => 'default',
    ),
    'expose' => 0,
    'style' => 'average',
    'text' => 'average',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Post date';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'ov_visualisation' => 'ov_visualisation',
  );

  /* Display: List */
  $handler = $view->new_display('panel_pane', 'List', 'panel_pane_1');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Visualization data */
  $handler->display->display_options['fields']['field_ov_visualization_data']['id'] = 'field_ov_visualization_data';
  $handler->display->display_options['fields']['field_ov_visualization_data']['table'] = 'field_data_field_ov_visualization_data';
  $handler->display->display_options['fields']['field_ov_visualization_data']['field'] = 'field_ov_visualization_data';
  $handler->display->display_options['fields']['field_ov_visualization_data']['label'] = '';
  $handler->display->display_options['fields']['field_ov_visualization_data']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_ov_visualization_data']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_ov_visualization_data']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ov_visualization_data']['type'] = 'vizshare_icon';
  $handler->display->display_options['fields']['field_ov_visualization_data']['settings'] = array(
    'height' => '200',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_ov_categories']['id'] = 'field_ov_categories';
  $handler->display->display_options['fields']['field_ov_categories']['table'] = 'field_data_field_ov_categories';
  $handler->display->display_options['fields']['field_ov_categories']['field'] = 'field_ov_categories';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Content: Rating */
  $handler->display->display_options['fields']['field_ov_rating']['id'] = 'field_ov_rating';
  $handler->display->display_options['fields']['field_ov_rating']['table'] = 'field_data_field_ov_rating';
  $handler->display->display_options['fields']['field_ov_rating']['field'] = 'field_ov_rating';
  $handler->display->display_options['fields']['field_ov_rating']['label'] = '';
  $handler->display->display_options['fields']['field_ov_rating']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ov_rating']['click_sort_column'] = 'rating';
  $handler->display->display_options['fields']['field_ov_rating']['settings'] = array(
    'widget' => array(
      'fivestar_widget' => 'default',
    ),
    'expose' => 0,
    'style' => 'average',
    'text' => 'average',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'ov_visualisation' => 'ov_visualisation',
  );
  /* Filter criterion: Content: Categories (field_ov_categories) */
  $handler->display->display_options['filters']['field_ov_categories_tid']['id'] = 'field_ov_categories_tid';
  $handler->display->display_options['filters']['field_ov_categories_tid']['table'] = 'field_data_field_ov_categories';
  $handler->display->display_options['filters']['field_ov_categories_tid']['field'] = 'field_ov_categories_tid';
  $handler->display->display_options['filters']['field_ov_categories_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_ov_categories_tid']['expose']['operator_id'] = 'field_ov_categories_tid_op';
  $handler->display->display_options['filters']['field_ov_categories_tid']['expose']['label'] = 'Categories';
  $handler->display->display_options['filters']['field_ov_categories_tid']['expose']['operator'] = 'field_ov_categories_tid_op';
  $handler->display->display_options['filters']['field_ov_categories_tid']['expose']['identifier'] = 'field_ov_categories_tid';
  $handler->display->display_options['filters']['field_ov_categories_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_ov_categories_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_ov_categories_tid']['vocabulary'] = 'ov_categories';
  $handler->display->display_options['filters']['field_ov_categories_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Author uid */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'node';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Author uid';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['uid']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['uid']['group_info']['label'] = 'Author uid';
  $handler->display->display_options['filters']['uid']['group_info']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['group_info']['remember'] = FALSE;
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
  $handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;

  /* Display: Top rated */
  $handler = $view->new_display('panel_pane', 'Top rated', 'panel_pane_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Top visualizations';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_ov_icon' => 'field_ov_icon',
    'counter' => 'counter',
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Vote results */
  $handler->display->display_options['relationships']['votingapi_cache']['id'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['votingapi'] = array(
    'value_type' => '',
    'tag' => '',
    'function' => 'count',
  );
  /* Relationship: Content: Type (field_ov_type) */
  $handler->display->display_options['relationships']['field_ov_type_tid']['id'] = 'field_ov_type_tid';
  $handler->display->display_options['relationships']['field_ov_type_tid']['table'] = 'field_data_field_ov_type';
  $handler->display->display_options['relationships']['field_ov_type_tid']['field'] = 'field_ov_type_tid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Taxonomy term: OV Icon */
  $handler->display->display_options['fields']['field_ov_icon']['id'] = 'field_ov_icon';
  $handler->display->display_options['fields']['field_ov_icon']['table'] = 'field_data_field_ov_icon';
  $handler->display->display_options['fields']['field_ov_icon']['field'] = 'field_ov_icon';
  $handler->display->display_options['fields']['field_ov_icon']['relationship'] = 'field_ov_type_tid';
  $handler->display->display_options['fields']['field_ov_icon']['label'] = '';
  $handler->display->display_options['fields']['field_ov_icon']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ov_icon']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_ov_icon']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['counter']['alter']['text'] = '[counter].';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Rating (field_ov_rating:rating) */
  $handler->display->display_options['sorts']['field_ov_rating_rating']['id'] = 'field_ov_rating_rating';
  $handler->display->display_options['sorts']['field_ov_rating_rating']['table'] = 'field_data_field_ov_rating';
  $handler->display->display_options['sorts']['field_ov_rating_rating']['field'] = 'field_ov_rating_rating';
  $handler->display->display_options['sorts']['field_ov_rating_rating']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'ov_visualisation' => 'ov_visualisation',
  );

  /* Display: Vis Browser Centre Pane */
  $handler = $view->new_display('panel_pane', 'Vis Browser Centre Pane', 'panel_pane_3');
  $handler->display->display_options['display_description'] = 'Centre area river of most recent Visualization nodes';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Visualization data */
  $handler->display->display_options['fields']['field_ov_visualization_data']['id'] = 'field_ov_visualization_data';
  $handler->display->display_options['fields']['field_ov_visualization_data']['table'] = 'field_data_field_ov_visualization_data';
  $handler->display->display_options['fields']['field_ov_visualization_data']['field'] = 'field_ov_visualization_data';
  $handler->display->display_options['fields']['field_ov_visualization_data']['label'] = '';
  $handler->display->display_options['fields']['field_ov_visualization_data']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_ov_visualization_data']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_ov_visualization_data']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ov_visualization_data']['type'] = 'vizshare_icon';
  $handler->display->display_options['fields']['field_ov_visualization_data']['settings'] = array(
    'height' => '200',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'First Submitted';
  $handler->display->display_options['fields']['created']['date_format'] = 'panopoly_day';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'panopoly_time';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'panopoly_day';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'panopoly_time';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '200',
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Created by';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Content: Rating */
  $handler->display->display_options['fields']['field_ov_rating']['id'] = 'field_ov_rating';
  $handler->display->display_options['fields']['field_ov_rating']['table'] = 'field_data_field_ov_rating';
  $handler->display->display_options['fields']['field_ov_rating']['field'] = 'field_ov_rating';
  $handler->display->display_options['fields']['field_ov_rating']['label'] = '';
  $handler->display->display_options['fields']['field_ov_rating']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ov_rating']['click_sort_column'] = 'rating';
  $handler->display->display_options['fields']['field_ov_rating']['settings'] = array(
    'widget' => array(
      'fivestar_widget' => 'default',
    ),
    'expose' => 0,
    'style' => 'average',
    'text' => 'average',
  );
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_ov_type']['id'] = 'field_ov_type';
  $handler->display->display_options['fields']['field_ov_type']['table'] = 'field_data_field_ov_type';
  $handler->display->display_options['fields']['field_ov_type']['field'] = 'field_ov_type';
  $handler->display->display_options['fields']['field_ov_type']['label'] = '';
  $handler->display->display_options['fields']['field_ov_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Post date';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'ov_visualisation' => 'ov_visualisation',
  );
  /* Filter criterion: Content: Categories (field_ov_categories) */
  $handler->display->display_options['filters']['field_ov_categories_tid']['id'] = 'field_ov_categories_tid';
  $handler->display->display_options['filters']['field_ov_categories_tid']['table'] = 'field_data_field_ov_categories';
  $handler->display->display_options['filters']['field_ov_categories_tid']['field'] = 'field_ov_categories_tid';
  $handler->display->display_options['filters']['field_ov_categories_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_ov_categories_tid']['expose']['operator_id'] = 'field_ov_categories_tid_op';
  $handler->display->display_options['filters']['field_ov_categories_tid']['expose']['label'] = 'Categories';
  $handler->display->display_options['filters']['field_ov_categories_tid']['expose']['operator'] = 'field_ov_categories_tid_op';
  $handler->display->display_options['filters']['field_ov_categories_tid']['expose']['identifier'] = 'field_ov_categories_tid';
  $handler->display->display_options['filters']['field_ov_categories_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );
  $handler->display->display_options['filters']['field_ov_categories_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_ov_categories_tid']['vocabulary'] = 'ov_categories';
  $handler->display->display_options['filters']['field_ov_categories_tid']['error_message'] = FALSE;

  /* Display: Top rated sidebar */
  $handler = $view->new_display('panel_pane', 'Top rated sidebar', 'panel_pane_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Top Visualizations';
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['display_description'] = 'Title-only sidebar list of top Visualizations';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'counter' => 'counter',
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Vote results */
  $handler->display->display_options['relationships']['votingapi_cache']['id'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['votingapi'] = array(
    'value_type' => '',
    'tag' => '',
    'function' => 'count',
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['counter']['alter']['text'] = '[counter].';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Rating (field_ov_rating:rating) */
  $handler->display->display_options['sorts']['field_ov_rating_rating']['id'] = 'field_ov_rating_rating';
  $handler->display->display_options['sorts']['field_ov_rating_rating']['table'] = 'field_data_field_ov_rating';
  $handler->display->display_options['sorts']['field_ov_rating_rating']['field'] = 'field_ov_rating_rating';
  $handler->display->display_options['sorts']['field_ov_rating_rating']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'ov_visualisation' => 'ov_visualisation',
  );

  /* Display: Related visualizations */
  $handler = $view->new_display('panel_pane', 'Related visualizations', 'panel_pane_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Related visualizations';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Post date';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['expose']['label'] = 'Title';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['not'] = TRUE;
  /* Contextual filter: Content: Has taxonomy term ID (with depth) */
  $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_action'] = 'default';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['term_page'] = FALSE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['node'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['anyall'] = '+';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['limit'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['vocabularies'] = array(
    'ov_categories' => 'ov_categories',
  );
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['term_node_tid_depth']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['vocabularies'] = array(
    'ov_categories' => 'ov_categories',
  );
  $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '0';
  /* Contextual filter: Content: Has taxonomy term ID depth modifier */
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['id'] = 'term_node_tid_depth_modifier';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['field'] = 'term_node_tid_depth_modifier';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['summary']['format'] = 'default_summary';
  $handler->display->display_options['argument_input'] = array(
    'term_node_tid_depth' => array(
      'type' => 'none',
      'context' => 'entity:node.field-ov-categories',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Has taxonomy term ID (with depth)',
    ),
    'term_node_tid_depth_modifier' => array(
      'type' => 'context',
      'context' => 'entity:node.field-ov-categories',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Has taxonomy term ID depth modifier',
    ),
  );
  $export['openviz_visualisation'] = $view;

  return $export;
}
