<?php
/**
 * @file
 * openviz_visualisation.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function openviz_visualisation_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:ov_visualisation:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'ov_visualisation';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->css_class = '';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $display = new panels_display();
  $display->layout = 'harris';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'header' => NULL,
      'column1' => NULL,
      'column2' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '651143d9-6df5-4ec9-a9b8-89dfce3ed11c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-fd93cad9-a301-423c-bbe7-5a426864f503';
    $pane->panel = 'column1';
    $pane->type = 'node_author';
    $pane->subtype = 'node_author';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 1,
      'context' => 'panelizer',
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'fd93cad9-a301-423c-bbe7-5a426864f503';
    $display->content['new-fd93cad9-a301-423c-bbe7-5a426864f503'] = $pane;
    $display->panels['column1'][0] = 'new-fd93cad9-a301-423c-bbe7-5a426864f503';
    $pane = new stdClass();
    $pane->pid = 'new-4df1d453-51ed-4341-9212-f51d97c74803';
    $pane->panel = 'column1';
    $pane->type = 'node_created';
    $pane->subtype = 'node_created';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'format' => 'short',
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '4df1d453-51ed-4341-9212-f51d97c74803';
    $display->content['new-4df1d453-51ed-4341-9212-f51d97c74803'] = $pane;
    $display->panels['column1'][1] = 'new-4df1d453-51ed-4341-9212-f51d97c74803';
    $pane = new stdClass();
    $pane->pid = 'new-85a753ab-6e50-49ea-bcff-4a4aba459748';
    $pane->panel = 'column1';
    $pane->type = 'node_updated';
    $pane->subtype = 'node_updated';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'format' => 'short',
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '85a753ab-6e50-49ea-bcff-4a4aba459748';
    $display->content['new-85a753ab-6e50-49ea-bcff-4a4aba459748'] = $pane;
    $display->panels['column1'][2] = 'new-85a753ab-6e50-49ea-bcff-4a4aba459748';
    $pane = new stdClass();
    $pane->pid = 'new-2b4c89f1-3ff4-4a80-a7cc-82963f6d832a';
    $pane->panel = 'column1';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_ov_categories';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'taxonomy_term_reference_link',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => array(),
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '2b4c89f1-3ff4-4a80-a7cc-82963f6d832a';
    $display->content['new-2b4c89f1-3ff4-4a80-a7cc-82963f6d832a'] = $pane;
    $display->panels['column1'][3] = 'new-2b4c89f1-3ff4-4a80-a7cc-82963f6d832a';
    $pane = new stdClass();
    $pane->pid = 'new-0e6d84e7-29a4-4386-b436-9411c95f5682';
    $pane->panel = 'column1';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_ov_tags';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'taxonomy_term_reference_link',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
      'context' => array(),
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '0e6d84e7-29a4-4386-b436-9411c95f5682';
    $display->content['new-0e6d84e7-29a4-4386-b436-9411c95f5682'] = $pane;
    $display->panels['column1'][4] = 'new-0e6d84e7-29a4-4386-b436-9411c95f5682';
    $pane = new stdClass();
    $pane->pid = 'new-8caa1d79-5b28-43b7-965f-eb482c61608e';
    $pane->panel = 'column2';
    $pane->type = 'flag_link';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'flag_name' => 'ov_favorites',
      'context' => 'panelizer',
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '8caa1d79-5b28-43b7-965f-eb482c61608e';
    $display->content['new-8caa1d79-5b28-43b7-965f-eb482c61608e'] = $pane;
    $display->panels['column2'][0] = 'new-8caa1d79-5b28-43b7-965f-eb482c61608e';
    $pane = new stdClass();
    $pane->pid = 'new-6dd08950-0e8a-44f5-9601-359f303efa2a';
    $pane->panel = 'column2';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_ov_rating';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'fivestar_formatter_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'widget' => array(
          'fivestar_widget' => 'default',
        ),
        'style' => 'average',
        'text' => 'average',
        'expose' => 1,
      ),
      'context' => array(),
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '6dd08950-0e8a-44f5-9601-359f303efa2a';
    $display->content['new-6dd08950-0e8a-44f5-9601-359f303efa2a'] = $pane;
    $display->panels['column2'][1] = 'new-6dd08950-0e8a-44f5-9601-359f303efa2a';
    $pane = new stdClass();
    $pane->pid = 'new-c1dfb35d-804e-4282-8b51-2ba5bd3cbbe4';
    $pane->panel = 'column2';
    $pane->type = 'node_links';
    $pane->subtype = 'node_links';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
      'build_mode' => 'full',
      'identifier' => '',
      'link' => 1,
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'c1dfb35d-804e-4282-8b51-2ba5bd3cbbe4';
    $display->content['new-c1dfb35d-804e-4282-8b51-2ba5bd3cbbe4'] = $pane;
    $display->panels['column2'][2] = 'new-c1dfb35d-804e-4282-8b51-2ba5bd3cbbe4';
    $pane = new stdClass();
    $pane->pid = 'new-3b00bb75-ad77-47e5-a798-64f7618a8a73';
    $pane->panel = 'contentmain';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 0,
      'markup' => 'h1',
      'id' => '',
      'class' => '',
      'context' => 'panelizer',
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '3b00bb75-ad77-47e5-a798-64f7618a8a73';
    $display->content['new-3b00bb75-ad77-47e5-a798-64f7618a8a73'] = $pane;
    $display->panels['contentmain'][0] = 'new-3b00bb75-ad77-47e5-a798-64f7618a8a73';
    $pane = new stdClass();
    $pane->pid = 'new-f362fc82-2751-4360-a22c-2ec2f3b043f8';
    $pane->panel = 'contentmain';
    $pane->type = 'node_body';
    $pane->subtype = 'node_body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'panelizer',
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'f362fc82-2751-4360-a22c-2ec2f3b043f8';
    $display->content['new-f362fc82-2751-4360-a22c-2ec2f3b043f8'] = $pane;
    $display->panels['contentmain'][1] = 'new-f362fc82-2751-4360-a22c-2ec2f3b043f8';
    $pane = new stdClass();
    $pane->pid = 'new-7a56a3ed-280a-4688-a28d-78ff17fa7452';
    $pane->panel = 'contentmain';
    $pane->type = 'node_comment_form';
    $pane->subtype = 'node_comment_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'anon_links' => 0,
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '7a56a3ed-280a-4688-a28d-78ff17fa7452';
    $display->content['new-7a56a3ed-280a-4688-a28d-78ff17fa7452'] = $pane;
    $display->panels['contentmain'][2] = 'new-7a56a3ed-280a-4688-a28d-78ff17fa7452';
    $pane = new stdClass();
    $pane->pid = 'new-bc0ee681-eddd-4449-a937-a77ef9e12e0c';
    $pane->panel = 'contentmain';
    $pane->type = 'node_comments';
    $pane->subtype = 'node_comments';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'mode' => '1',
      'comments_per_page' => '50',
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'bc0ee681-eddd-4449-a937-a77ef9e12e0c';
    $display->content['new-bc0ee681-eddd-4449-a937-a77ef9e12e0c'] = $pane;
    $display->panels['contentmain'][3] = 'new-bc0ee681-eddd-4449-a937-a77ef9e12e0c';
    $pane = new stdClass();
    $pane->pid = 'new-b8b16644-6b75-40b0-a5a1-a2e1234ff949';
    $pane->panel = 'header';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_ov_visualization_data';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'vizshare_draw',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'height' => '400',
      ),
      'context' => array(),
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b8b16644-6b75-40b0-a5a1-a2e1234ff949';
    $display->content['new-b8b16644-6b75-40b0-a5a1-a2e1234ff949'] = $pane;
    $display->panels['header'][0] = 'new-b8b16644-6b75-40b0-a5a1-a2e1234ff949';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:ov_visualisation:default'] = $panelizer;

  return $export;
}
