<?php
/**
 * @file
 * openviz_home.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function openviz_home_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'openviz_home';
  $page->task = 'page';
  $page->admin_title = 'OpenViz Home';
  $page->admin_description = '';
  $page->path = 'frontpage';
  $page->access = array();
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Home',
    'name' => 'main-menu',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_openviz_home_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'openviz_home';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 1,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'bartlett';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'sidebar' => NULL,
      'contentheader' => NULL,
      'contentcolumn1' => NULL,
      'contentcolumn2' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '9315f11a-54ef-487d-acda-69d42a75e597';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-67150374-b491-453e-ab7d-929456eebb12';
    $pane->panel = 'contentcolumn1';
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
    $pane->uuid = '67150374-b491-453e-ab7d-929456eebb12';
    $display->content['new-67150374-b491-453e-ab7d-929456eebb12'] = $pane;
    $display->panels['contentcolumn1'][0] = 'new-67150374-b491-453e-ab7d-929456eebb12';
    $pane = new stdClass();
    $pane->pid = 'new-70231c1a-3ebf-4d45-9cd2-2fc8751750e9';
    $pane->panel = 'sidebar';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'fpid:1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'Full',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '70231c1a-3ebf-4d45-9cd2-2fc8751750e9';
    $display->content['new-70231c1a-3ebf-4d45-9cd2-2fc8751750e9'] = $pane;
    $display->panels['sidebar'][0] = 'new-70231c1a-3ebf-4d45-9cd2-2fc8751750e9';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-70231c1a-3ebf-4d45-9cd2-2fc8751750e9';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['openviz_home'] = $page;

  return $pages;

}
