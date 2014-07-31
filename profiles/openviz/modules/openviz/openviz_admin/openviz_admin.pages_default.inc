<?php
/**
 * @file
 * openviz_admin.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function openviz_admin_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'ol_admin_dashboard';
  $page->task = 'page';
  $page->admin_title = 'Dashboard';
  $page->admin_description = 'A dashboard for regular site maintenance.';
  $page->path = 'admin/dashboard';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 3,
            1 => 4,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Dashboard',
    'name' => 'user-menu',
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
  $handler->name = 'page_ol_admin_dashboard_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'ol_admin_dashboard';
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
  $display->layout = 'phelan';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'column1' => NULL,
      'column2' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Dashboard';
  $display->uuid = '2595c746-f159-4f53-b932-02be6d9b4497';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-a7c1cd9f-a925-4f5d-938f-3f54e6fbc1c8';
    $pane->panel = 'column1';
    $pane->type = 'block';
    $pane->subtype = 'block-5';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Quick links',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'a7c1cd9f-a925-4f5d-938f-3f54e6fbc1c8';
    $display->content['new-a7c1cd9f-a925-4f5d-938f-3f54e6fbc1c8'] = $pane;
    $display->panels['column1'][0] = 'new-a7c1cd9f-a925-4f5d-938f-3f54e6fbc1c8';
    $pane = new stdClass();
    $pane->pid = 'new-6c81fe18-221a-40aa-a4e3-89a27d595ecb';
    $pane->panel = 'column1';
    $pane->type = 'views_panes';
    $pane->subtype = 'openviz_admin-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'teaser',
      'widget_title' => NULL,
      'items_per_page' => NULL,
      'exposed' => array(
        'sort_by' => NULL,
        'sort_order' => NULL,
      ),
      'use_pager' => NULL,
      'pager_id' => NULL,
      'offset' => NULL,
      'link_to_view' => NULL,
      'more_link' => NULL,
      'path' => NULL,
      'view_settings' => 'fields',
      'header_type' => 'none',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '6c81fe18-221a-40aa-a4e3-89a27d595ecb';
    $display->content['new-6c81fe18-221a-40aa-a4e3-89a27d595ecb'] = $pane;
    $display->panels['column1'][1] = 'new-6c81fe18-221a-40aa-a4e3-89a27d595ecb';
    $pane = new stdClass();
    $pane->pid = 'new-c754d7a6-65b0-4609-8c61-083f10c5d508';
    $pane->panel = 'column1';
    $pane->type = 'views_panes';
    $pane->subtype = 'openviz_admin_user_totals-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'teaser',
      'widget_title' => NULL,
      'items_per_page' => NULL,
      'exposed' => array(
        'sort_by' => NULL,
        'sort_order' => NULL,
      ),
      'use_pager' => NULL,
      'pager_id' => NULL,
      'offset' => NULL,
      'link_to_view' => NULL,
      'more_link' => NULL,
      'path' => NULL,
      'view_settings' => 'fields',
      'header_type' => 'none',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'c754d7a6-65b0-4609-8c61-083f10c5d508';
    $display->content['new-c754d7a6-65b0-4609-8c61-083f10c5d508'] = $pane;
    $display->panels['column1'][2] = 'new-c754d7a6-65b0-4609-8c61-083f10c5d508';
    $pane = new stdClass();
    $pane->pid = 'new-23cd83c1-7a75-4657-b9c8-26dc6b26bd58';
    $pane->panel = 'column2';
    $pane->type = 'views_panes';
    $pane->subtype = 'openviz_issue-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'teaser',
      'widget_title' => 'User issues',
      'items_per_page' => '',
      'exposed' => array(
        'widget_title' => 'User issues',
        'use_pager' => 0,
        'pager_id' => '',
        'sort_by' => NULL,
        'sort_order' => NULL,
      ),
      'use_pager' => NULL,
      'pager_id' => NULL,
      'offset' => NULL,
      'link_to_view' => NULL,
      'more_link' => NULL,
      'path' => NULL,
      'view_settings' => 'fields',
      'header_type' => 'none',
      'override_title' => '',
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
    $pane->uuid = '23cd83c1-7a75-4657-b9c8-26dc6b26bd58';
    $display->content['new-23cd83c1-7a75-4657-b9c8-26dc6b26bd58'] = $pane;
    $display->panels['column2'][0] = 'new-23cd83c1-7a75-4657-b9c8-26dc6b26bd58';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-23cd83c1-7a75-4657-b9c8-26dc6b26bd58';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['ol_admin_dashboard'] = $page;

  return $pages;

}
