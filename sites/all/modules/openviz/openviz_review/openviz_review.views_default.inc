<?php
/**
 * @file
 * openviz_review.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function openviz_review_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'review_requests';
  $view->description = '';
  $view->tag = 'openviz';
  $view->base_table = 'entityform';
  $view->human_name = 'OpenViz Review Requests';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Review Requests';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    5 => '5',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_viz_target_id']['id'] = 'field_viz_target_id';
  $handler->display->display_options['relationships']['field_viz_target_id']['table'] = 'field_data_field_viz';
  $handler->display->display_options['relationships']['field_viz_target_id']['field'] = 'field_viz_target_id';
  /* Field: Entityform Submission: Entityform submission ID */
  $handler->display->display_options['fields']['entityform_id']['id'] = 'entityform_id';
  $handler->display->display_options['fields']['entityform_id']['table'] = 'entityform';
  $handler->display->display_options['fields']['entityform_id']['field'] = 'entityform_id';
  /* Sort criterion: Entityform Submission: Date submitted */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'entityform';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  /* Filter criterion: Entityform Submission: Entityform Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'entityform';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'review_request' => 'review_request',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'entityform_id' => 'entityform_id',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'entityform_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_viz_target_id']['id'] = 'field_viz_target_id';
  $handler->display->display_options['relationships']['field_viz_target_id']['table'] = 'field_data_field_viz';
  $handler->display->display_options['relationships']['field_viz_target_id']['field'] = 'field_viz_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_viz_target_id_1']['id'] = 'field_viz_target_id_1';
  $handler->display->display_options['relationships']['field_viz_target_id_1']['table'] = 'field_data_field_viz';
  $handler->display->display_options['relationships']['field_viz_target_id_1']['field'] = 'field_viz_target_id';
  $handler->display->display_options['relationships']['field_viz_target_id_1']['relationship'] = 'field_viz_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Entityform Submission: Entityform submission ID */
  $handler->display->display_options['fields']['entityform_id']['id'] = 'entityform_id';
  $handler->display->display_options['fields']['entityform_id']['table'] = 'entityform';
  $handler->display->display_options['fields']['entityform_id']['field'] = 'entityform_id';
  $handler->display->display_options['fields']['entityform_id']['label'] = 'Seq No';
  /* Field: Field: Visualization */
  $handler->display->display_options['fields']['field_viz_1']['id'] = 'field_viz_1';
  $handler->display->display_options['fields']['field_viz_1']['table'] = 'field_data_field_viz';
  $handler->display->display_options['fields']['field_viz_1']['field'] = 'field_viz';
  $handler->display->display_options['fields']['field_viz_1']['settings'] = array(
    'link' => 1,
  );
  /* Field: Entityform Submission: Date submitted */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'entityform';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'panopoly_time';
  /* Field: Entityform Submission: Review Reason */
  $handler->display->display_options['fields']['field_review_reason']['id'] = 'field_review_reason';
  $handler->display->display_options['fields']['field_review_reason']['table'] = 'field_data_field_review_reason';
  $handler->display->display_options['fields']['field_review_reason']['field'] = 'field_review_reason';
  /* Field: Field: Visualization */
  $handler->display->display_options['fields']['field_viz']['id'] = 'field_viz';
  $handler->display->display_options['fields']['field_viz']['table'] = 'field_data_field_viz';
  $handler->display->display_options['fields']['field_viz']['field'] = 'field_viz';
  $handler->display->display_options['fields']['field_viz']['label'] = 'Write Review';
  $handler->display->display_options['fields']['field_viz']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_viz']['alter']['text'] = '<a href="/visualizations/[field_viz]">Check Visualization</a><br>
<a href="/node/add/ov-review?field_viz=[field_viz-target_id]">Write Review</a>';
  $handler->display->display_options['fields']['field_viz']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['path'] = 'view_review_requests';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Review Requests';
  $handler->display->display_options['menu']['description'] = 'Pending Review Requests for Mentors';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Review Requests Pane */
  $handler = $view->new_display('panel_pane', 'Review Requests Pane', 'panel_pane_1');
  $handler->display->display_options['display_description'] = 'List of pending review requests';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'entityform_id' => 'entityform_id',
    'created' => 'created',
    'field_review_reason' => 'field_review_reason',
    'field_viz' => 'field_viz',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'entityform_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
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
    'field_review_reason' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_viz' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Entityform Submission: Entityform submission ID */
  $handler->display->display_options['fields']['entityform_id']['id'] = 'entityform_id';
  $handler->display->display_options['fields']['entityform_id']['table'] = 'entityform';
  $handler->display->display_options['fields']['entityform_id']['field'] = 'entityform_id';
  /* Field: Field: Visualization */
  $handler->display->display_options['fields']['field_viz_1']['id'] = 'field_viz_1';
  $handler->display->display_options['fields']['field_viz_1']['table'] = 'field_data_field_viz';
  $handler->display->display_options['fields']['field_viz_1']['field'] = 'field_viz';
  $handler->display->display_options['fields']['field_viz_1']['settings'] = array(
    'link' => 1,
  );
  /* Field: Entityform Submission: Date submitted */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'entityform';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'panopoly_time';
  /* Field: Entityform Submission: Review Reason */
  $handler->display->display_options['fields']['field_review_reason']['id'] = 'field_review_reason';
  $handler->display->display_options['fields']['field_review_reason']['table'] = 'field_data_field_review_reason';
  $handler->display->display_options['fields']['field_review_reason']['field'] = 'field_review_reason';
  /* Field: Field: Visualization */
  $handler->display->display_options['fields']['field_viz']['id'] = 'field_viz';
  $handler->display->display_options['fields']['field_viz']['table'] = 'field_data_field_viz';
  $handler->display->display_options['fields']['field_viz']['field'] = 'field_viz';
  $handler->display->display_options['fields']['field_viz']['label'] = 'Write Review';
  $handler->display->display_options['fields']['field_viz']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_viz']['alter']['text'] = '<a href="/visualizations/[field_viz]">Check Visualization</a><br>
<a href="/node/add/ov-review?field_viz=[field_viz-target_id]">Write Review</a>';
  $handler->display->display_options['fields']['field_viz']['settings'] = array(
    'link' => 0,
  );

  /* Display: My Review requests */
  $handler = $view->new_display('panel_pane', 'My Review requests', 'panel_pane_2');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Field: Entityform Submission: Date submitted */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'entityform';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'panopoly_time';
  /* Field: Entityform Submission: Review Reason */
  $handler->display->display_options['fields']['field_review_reason']['id'] = 'field_review_reason';
  $handler->display->display_options['fields']['field_review_reason']['table'] = 'field_data_field_review_reason';
  $handler->display->display_options['fields']['field_review_reason']['field'] = 'field_review_reason';
  $handler->display->display_options['fields']['field_review_reason']['label'] = '';
  $handler->display->display_options['fields']['field_review_reason']['element_label_colon'] = FALSE;
  /* Field: Entityform Submission: Entityform submission ID */
  $handler->display->display_options['fields']['entityform_id']['id'] = 'entityform_id';
  $handler->display->display_options['fields']['entityform_id']['table'] = 'entityform';
  $handler->display->display_options['fields']['entityform_id']['field'] = 'entityform_id';
  $handler->display->display_options['fields']['entityform_id']['label'] = '';
  $handler->display->display_options['fields']['entityform_id']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['entityform_id']['alter']['text'] = '<a href="/entityforms/[entityform_id]/delete">Delete this request</a>';
  $handler->display->display_options['fields']['entityform_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Entityform Submission: Date submitted */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'entityform';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'field_viz_target_id';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $export['review_requests'] = $view;

  return $export;
}
