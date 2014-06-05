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
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_ov_visualization_data' => 'field_ov_visualization_data',
    'title' => 'title',
    'field_ov_categories' => 'title',
    'field_ov_tags' => 'field_ov_tags',
    'name' => 'name',
    'field_ov_rating' => 'name',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_ov_visualization_data' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
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
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_ov_rating' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Content: Visualization data */
  $handler->display->display_options['fields']['field_ov_visualization_data']['id'] = 'field_ov_visualization_data';
  $handler->display->display_options['fields']['field_ov_visualization_data']['table'] = 'field_data_field_ov_visualization_data';
  $handler->display->display_options['fields']['field_ov_visualization_data']['field'] = 'field_ov_visualization_data';
  $handler->display->display_options['fields']['field_ov_visualization_data']['label'] = '';
  $handler->display->display_options['fields']['field_ov_visualization_data']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ov_visualization_data']['settings'] = array(
    'height' => '150',
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
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
  $handler->display->display_options['filters']['field_ov_categories_tid']['value'] = array(
    1 => '1',
    2 => '2',
  );
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
  );
  $handler->display->display_options['filters']['field_ov_categories_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_ov_categories_tid']['vocabulary'] = 'ov_categories';
  $handler->display->display_options['filters']['field_ov_categories_tid']['error_message'] = FALSE;

  /* Display: List */
  $handler = $view->new_display('panel_pane', 'List', 'panel_pane_1');
  $handler->display->display_options['exposed_block'] = TRUE;
  $export['openviz_visualisation'] = $view;

  return $export;
}
