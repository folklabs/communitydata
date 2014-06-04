<?php
/**
 * @file
 * openviz_visualisation.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function openviz_visualisation_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'ov_visualizations';
  $page->task = 'page';
  $page->admin_title = 'Visualizations';
  $page->admin_description = 'Can browse all available visualizations.';
  $page->path = 'visualizations/!input';
  $page->access = array();
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Visualizations',
    'name' => 'main-menu',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
    'input' => array(
      'id' => '',
      'identifier' => '',
      'argument' => '',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_ov_visualizations_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'ov_visualizations';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'harris';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'sidebar' => NULL,
      'contentmain' => NULL,
      'header' => NULL,
      'column1' => NULL,
      'column2' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Visualizations';
  $display->uuid = '45faa438-da2c-4722-8af1-d7140cc91947';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f3f5c7ed-d062-43fe-b138-38fae43d4b19';
    $pane->panel = 'column1';
    $pane->type = 'block';
    $pane->subtype = 'views-53a3ce4c87e98a145ea02b5100775022';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'inherit_path' => 1,
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
    $pane->uuid = 'f3f5c7ed-d062-43fe-b138-38fae43d4b19';
    $display->content['new-f3f5c7ed-d062-43fe-b138-38fae43d4b19'] = $pane;
    $display->panels['column1'][0] = 'new-f3f5c7ed-d062-43fe-b138-38fae43d4b19';
    $pane = new stdClass();
    $pane->pid = 'new-adbf6e20-b4ae-447f-8e55-23258589fbcc';
    $pane->panel = 'contentmain';
    $pane->type = 'views_panes';
    $pane->subtype = 'openviz_visualisation-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_settings' => 'fields',
      'header_type' => 'none',
      'view_mode' => 'teaser',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'adbf6e20-b4ae-447f-8e55-23258589fbcc';
    $display->content['new-adbf6e20-b4ae-447f-8e55-23258589fbcc'] = $pane;
    $display->panels['contentmain'][0] = 'new-adbf6e20-b4ae-447f-8e55-23258589fbcc';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-adbf6e20-b4ae-447f-8e55-23258589fbcc';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['ov_visualizations'] = $page;

  return $pages;

}