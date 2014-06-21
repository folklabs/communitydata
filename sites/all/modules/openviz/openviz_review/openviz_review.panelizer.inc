<?php
/**
 * @file
 * openviz_review.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function openviz_review_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:ov_review:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'ov_review';
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
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'first_column',
          1 => 'center',
          2 => 'second_column',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Center',
        'width' => '49.9615418281894',
        'width_type' => '%',
        'parent' => 'main-row',
      ),
      'first_column' => array(
        'type' => 'region',
        'title' => 'First Column',
        'width' => '25.038458171810603',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => '',
      ),
      'second_column' => array(
        'type' => 'region',
        'title' => 'Second Column',
        'width' => '25',
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => '',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'first_column' => NULL,
      'second_column' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '2f542223-d57f-4bda-bcc9-b75bb9a265ea';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-444e78ec-3d7f-47fc-abd5-2259ddff35d4';
    $pane->panel = 'center';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 1,
      'markup' => 'none',
      'id' => '',
      'class' => '',
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '444e78ec-3d7f-47fc-abd5-2259ddff35d4';
    $display->content['new-444e78ec-3d7f-47fc-abd5-2259ddff35d4'] = $pane;
    $display->panels['center'][0] = 'new-444e78ec-3d7f-47fc-abd5-2259ddff35d4';
    $pane = new stdClass();
    $pane->pid = 'new-5c693e1f-e758-4484-978a-16d045cb2dad';
    $pane->panel = 'center';
    $pane->type = 'node_body';
    $pane->subtype = 'node_body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = '5c693e1f-e758-4484-978a-16d045cb2dad';
    $display->content['new-5c693e1f-e758-4484-978a-16d045cb2dad'] = $pane;
    $display->panels['center'][1] = 'new-5c693e1f-e758-4484-978a-16d045cb2dad';
    $pane = new stdClass();
    $pane->pid = 'new-1fb276d7-6e2b-4230-aa5b-bf1f21ca9d60';
    $pane->panel = 'first_column';
    $pane->type = 'node_author';
    $pane->subtype = 'node_author';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 1,
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1fb276d7-6e2b-4230-aa5b-bf1f21ca9d60';
    $display->content['new-1fb276d7-6e2b-4230-aa5b-bf1f21ca9d60'] = $pane;
    $display->panels['first_column'][0] = 'new-1fb276d7-6e2b-4230-aa5b-bf1f21ca9d60';
    $pane = new stdClass();
    $pane->pid = 'new-71d3648a-21d8-444c-ad75-dfc3a78db3d2';
    $pane->panel = 'first_column';
    $pane->type = 'node_created';
    $pane->subtype = 'node_created';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'format' => 'panopoly_time',
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
    $pane->uuid = '71d3648a-21d8-444c-ad75-dfc3a78db3d2';
    $display->content['new-71d3648a-21d8-444c-ad75-dfc3a78db3d2'] = $pane;
    $display->panels['first_column'][1] = 'new-71d3648a-21d8-444c-ad75-dfc3a78db3d2';
    $pane = new stdClass();
    $pane->pid = 'new-82746544-fa8a-4221-8722-87e063df29c1';
    $pane->panel = 'first_column';
    $pane->type = 'node_updated';
    $pane->subtype = 'node_updated';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'format' => 'panopoly_time',
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
    $pane->uuid = '82746544-fa8a-4221-8722-87e063df29c1';
    $display->content['new-82746544-fa8a-4221-8722-87e063df29c1'] = $pane;
    $display->panels['first_column'][2] = 'new-82746544-fa8a-4221-8722-87e063df29c1';
    $pane = new stdClass();
    $pane->pid = 'new-9fdabeef-1bd1-48d2-bf63-5ea2b63adce3';
    $pane->panel = 'first_column';
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
    $pane->uuid = '9fdabeef-1bd1-48d2-bf63-5ea2b63adce3';
    $display->content['new-9fdabeef-1bd1-48d2-bf63-5ea2b63adce3'] = $pane;
    $display->panels['first_column'][3] = 'new-9fdabeef-1bd1-48d2-bf63-5ea2b63adce3';
    $pane = new stdClass();
    $pane->pid = 'new-bff50fb6-0264-41a6-88b3-63450beccf0e';
    $pane->panel = 'first_column';
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
    $pane->uuid = 'bff50fb6-0264-41a6-88b3-63450beccf0e';
    $display->content['new-bff50fb6-0264-41a6-88b3-63450beccf0e'] = $pane;
    $display->panels['first_column'][4] = 'new-bff50fb6-0264-41a6-88b3-63450beccf0e';
    $pane = new stdClass();
    $pane->pid = 'new-7275dd56-5a1d-4059-aa6a-6a305472b682';
    $pane->panel = 'second_column';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_ov_rating';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '7275dd56-5a1d-4059-aa6a-6a305472b682';
    $display->content['new-7275dd56-5a1d-4059-aa6a-6a305472b682'] = $pane;
    $display->panels['second_column'][0] = 'new-7275dd56-5a1d-4059-aa6a-6a305472b682';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:ov_review:default'] = $panelizer;

  return $export;
}
