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
      'id' => 1,
      'identifier' => 'String',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
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
    $pane->pid = 'new-394bcb02-383b-4613-aa1f-a33ebfbb5345';
    $pane->panel = 'column1';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-NatjyGQD25Y4D2SjmW8rPVELZEZ3lpY3';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_string_1',
      'override_title' => 1,
      'override_title_text' => 'Categories',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'devices' => array(
          'hidden-xs' => 0,
          'hidden-sm' => 0,
          'hidden-md' => 0,
          'hidden-lg' => 0,
        ),
        'pane_style' => array(
          'pull-left' => 0,
          'pull-right' => 0,
          'clearfix' => 0,
          'jumbotron' => 0,
          'well' => 0,
        ),
      ),
      'style' => 'kalacustomize',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '394bcb02-383b-4613-aa1f-a33ebfbb5345';
    $display->content['new-394bcb02-383b-4613-aa1f-a33ebfbb5345'] = $pane;
    $display->panels['column1'][0] = 'new-394bcb02-383b-4613-aa1f-a33ebfbb5345';
    $pane = new stdClass();
    $pane->pid = 'new-112999f9-a2f9-46f8-a14d-fd1fc4aa050b';
    $pane->panel = 'column1';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-xxho1lgJggpOtHd03006NfRIwP3O1NLZ';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_string_1',
      'override_title' => 1,
      'override_title_text' => 'Tags',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'devices' => array(
          'hidden-xs' => 0,
          'hidden-sm' => 0,
          'hidden-md' => 0,
          'hidden-lg' => 0,
        ),
        'pane_style' => array(
          'pull-left' => 0,
          'pull-right' => 0,
          'clearfix' => 0,
          'jumbotron' => 0,
          'well' => 0,
        ),
      ),
      'style' => 'kalacustomize',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '112999f9-a2f9-46f8-a14d-fd1fc4aa050b';
    $display->content['new-112999f9-a2f9-46f8-a14d-fd1fc4aa050b'] = $pane;
    $display->panels['column1'][1] = 'new-112999f9-a2f9-46f8-a14d-fd1fc4aa050b';
    $pane = new stdClass();
    $pane->pid = 'new-40a6172c-4cb1-40b3-ace7-e4813d775cc5';
    $pane->panel = 'column1';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-NgSfb0eS59In9VTVACBv9V0fQpxT7WdO';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_string_1',
      'override_title' => 1,
      'override_title_text' => 'Type',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'devices' => array(
          'hidden-xs' => 0,
          'hidden-sm' => 0,
          'hidden-md' => 0,
          'hidden-lg' => 0,
        ),
        'pane_style' => array(
          'pull-left' => 0,
          'pull-right' => 0,
          'clearfix' => 0,
          'jumbotron' => 0,
          'well' => 0,
        ),
      ),
      'style' => 'kalacustomize',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '40a6172c-4cb1-40b3-ace7-e4813d775cc5';
    $display->content['new-40a6172c-4cb1-40b3-ace7-e4813d775cc5'] = $pane;
    $display->panels['column1'][2] = 'new-40a6172c-4cb1-40b3-ace7-e4813d775cc5';
    $pane = new stdClass();
    $pane->pid = 'new-70c411f5-7e8f-426b-bcff-91399e491e85';
    $pane->panel = 'column1';
    $pane->type = 'block';
    $pane->subtype = 'facetapi-AXM2f5h1FYkWf1syhGV0cP50X1jwDNcZ';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_string_1',
      'override_title' => 1,
      'override_title_text' => 'Author',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'devices' => array(
          'hidden-xs' => 0,
          'hidden-sm' => 0,
          'hidden-md' => 0,
          'hidden-lg' => 0,
        ),
        'pane_style' => array(
          'pull-left' => 0,
          'pull-right' => 0,
          'clearfix' => 0,
          'jumbotron' => 0,
          'well' => 0,
        ),
      ),
      'style' => 'kalacustomize',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '70c411f5-7e8f-426b-bcff-91399e491e85';
    $display->content['new-70c411f5-7e8f-426b-bcff-91399e491e85'] = $pane;
    $display->panels['column1'][3] = 'new-70c411f5-7e8f-426b-bcff-91399e491e85';
    $pane = new stdClass();
    $pane->pid = 'new-502b1349-f695-4299-9267-dfc3c8a3d229';
    $pane->panel = 'column2';
    $pane->type = 'views_panes';
    $pane->subtype = 'openviz_visualisation-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_settings' => 'fields',
      'header_type' => 'none',
      'view_mode' => 'teaser',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'devices' => array(
          'hidden-xs' => 0,
          'hidden-sm' => 0,
          'hidden-md' => 0,
          'hidden-lg' => 0,
        ),
        'pane_style' => array(
          'pull-left' => 0,
          'pull-right' => 0,
          'clearfix' => 0,
          'jumbotron' => 0,
          'well' => 0,
        ),
      ),
      'style' => 'kalacustomize',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '502b1349-f695-4299-9267-dfc3c8a3d229';
    $display->content['new-502b1349-f695-4299-9267-dfc3c8a3d229'] = $pane;
    $display->panels['column2'][0] = 'new-502b1349-f695-4299-9267-dfc3c8a3d229';
    $pane = new stdClass();
    $pane->pid = 'new-fa43a191-2c47-4e62-8d7c-272e22b5f4b3';
    $pane->panel = 'column2';
    $pane->type = 'views_panes';
    $pane->subtype = 'recently_read-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_settings' => 'fields',
      'header_type' => 'none',
      'view_mode' => 'teaser',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'devices' => array(
          'hidden-xs' => 0,
          'hidden-sm' => 0,
          'hidden-md' => 0,
          'hidden-lg' => 0,
        ),
        'pane_style' => array(
          'pull-left' => 0,
          'pull-right' => 0,
          'clearfix' => 0,
          'jumbotron' => 0,
          'well' => 0,
        ),
      ),
      'style' => 'kalacustomize',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'fa43a191-2c47-4e62-8d7c-272e22b5f4b3';
    $display->content['new-fa43a191-2c47-4e62-8d7c-272e22b5f4b3'] = $pane;
    $display->panels['column2'][1] = 'new-fa43a191-2c47-4e62-8d7c-272e22b5f4b3';
    $pane = new stdClass();
    $pane->pid = 'new-41a0f78b-af6d-48a9-8544-27d90957a922';
    $pane->panel = 'column2';
    $pane->type = 'views_panes';
    $pane->subtype = 'openviz_selectors-panel_pane_4';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_settings' => 'fields',
      'header_type' => 'none',
      'view_mode' => 'teaser',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'devices' => array(
          'hidden-xs' => 0,
          'hidden-sm' => 0,
          'hidden-md' => 0,
          'hidden-lg' => 0,
        ),
        'pane_style' => array(
          'pull-left' => 0,
          'pull-right' => 0,
          'clearfix' => 0,
          'jumbotron' => 0,
          'well' => 0,
        ),
      ),
      'style' => 'kalacustomize',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '41a0f78b-af6d-48a9-8544-27d90957a922';
    $display->content['new-41a0f78b-af6d-48a9-8544-27d90957a922'] = $pane;
    $display->panels['column2'][2] = 'new-41a0f78b-af6d-48a9-8544-27d90957a922';
    $pane = new stdClass();
    $pane->pid = 'new-01e09fc4-bca1-4999-813e-26363d303140';
    $pane->panel = 'contentmain';
    $pane->type = 'views_panes';
    $pane->subtype = 'openviz_facets-panel_pane_6';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_settings' => 'fields',
      'header_type' => 'none',
      'view_mode' => 'teaser',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'devices' => array(
          'hidden-xs' => 0,
          'hidden-sm' => 0,
          'hidden-md' => 0,
          'hidden-lg' => 0,
        ),
        'pane_style' => array(
          'pull-left' => 0,
          'pull-right' => 0,
          'clearfix' => 0,
          'jumbotron' => 0,
          'well' => 0,
        ),
      ),
      'style' => 'kalacustomize',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '01e09fc4-bca1-4999-813e-26363d303140';
    $display->content['new-01e09fc4-bca1-4999-813e-26363d303140'] = $pane;
    $display->panels['contentmain'][0] = 'new-01e09fc4-bca1-4999-813e-26363d303140';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['ov_visualizations'] = $page;

  return $pages;

}
