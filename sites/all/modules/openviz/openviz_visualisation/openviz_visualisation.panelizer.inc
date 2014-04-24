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
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array();
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '3f036ecf-fe7d-41a1-80c0-73e58237fc4c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-87bf72e8-8080-44aa-9b39-959ef68c076f';
    $pane->panel = 'center';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '87bf72e8-8080-44aa-9b39-959ef68c076f';
    $display->content['new-87bf72e8-8080-44aa-9b39-959ef68c076f'] = $pane;
    $display->panels['center'][0] = 'new-87bf72e8-8080-44aa-9b39-959ef68c076f';
    $pane = new stdClass();
    $pane->pid = 'new-4b736e78-b174-4da9-b95f-9d1fa20d355b';
    $pane->panel = 'center';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_ov_categories';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'taxonomy_term_reference_link',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '4b736e78-b174-4da9-b95f-9d1fa20d355b';
    $display->content['new-4b736e78-b174-4da9-b95f-9d1fa20d355b'] = $pane;
    $display->panels['center'][1] = 'new-4b736e78-b174-4da9-b95f-9d1fa20d355b';
    $pane = new stdClass();
    $pane->pid = 'new-f697a69e-6942-406c-b473-73350ec96d3f';
    $pane->panel = 'center';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_ov_tags';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'taxonomy_term_reference_link',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f697a69e-6942-406c-b473-73350ec96d3f';
    $display->content['new-f697a69e-6942-406c-b473-73350ec96d3f'] = $pane;
    $display->panels['center'][2] = 'new-f697a69e-6942-406c-b473-73350ec96d3f';
    $pane = new stdClass();
    $pane->pid = 'new-0a635c9f-11fe-42af-b181-fe6ac8b80c94';
    $pane->panel = 'center';
    $pane->type = 'node_links';
    $pane->subtype = 'node_links';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => FALSE,
      'override_title_text' => '',
      'build_mode' => 'page_manager',
      'identifier' => '',
      'link' => TRUE,
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_class' => 'link-wrapper',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0a635c9f-11fe-42af-b181-fe6ac8b80c94';
    $display->content['new-0a635c9f-11fe-42af-b181-fe6ac8b80c94'] = $pane;
    $display->panels['center'][3] = 'new-0a635c9f-11fe-42af-b181-fe6ac8b80c94';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-0a635c9f-11fe-42af-b181-fe6ac8b80c94';
  $panelizer->display = $display;
  $export['node:ov_visualisation:default'] = $panelizer;

  return $export;
}
