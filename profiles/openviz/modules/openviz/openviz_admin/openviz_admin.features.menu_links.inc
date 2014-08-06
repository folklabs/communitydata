<?php
/**
 * @file
 * openviz_admin.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function openviz_admin_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_dashboards:dashboards
  $menu_links['main-menu_dashboards:dashboards'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'dashboards',
    'router_path' => 'dashboards',
    'link_title' => 'Dashboards',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'disabled',
        ),
      ),
      'identifier' => 'main-menu_dashboards:dashboards',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: main-menu_home:frontpage
  $menu_links['main-menu_home:frontpage'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'frontpage',
    'router_path' => 'frontpage',
    'link_title' => 'Home',
    'options' => array(
      'identifier' => 'main-menu_home:frontpage',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: main-menu_visualizations:visualizations
  $menu_links['main-menu_visualizations:visualizations'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'visualizations',
    'router_path' => 'visualizations',
    'link_title' => 'Visualizations',
    'options' => array(
      'identifier' => 'main-menu_visualizations:visualizations',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: user-menu_add-dashboard:node/add/ov-dashboard
  $menu_links['user-menu_add-dashboard:node/add/ov-dashboard'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'node/add/ov-dashboard',
    'router_path' => 'node/add/ov-dashboard',
    'link_title' => 'Add dashboard',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'user-menu_add-dashboard:node/add/ov-dashboard',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'user-menu_add:node/add',
  );
  // Exported menu link: user-menu_add-dataset:http://lambeth.dataunityapp.com/#
  $menu_links['user-menu_add-dataset:http://lambeth.dataunityapp.com/#'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'http://lambeth.dataunityapp.com/#',
    'router_path' => '',
    'link_title' => 'Add dataset',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'user-menu_add-dataset:http://lambeth.dataunityapp.com/#',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'user-menu_add:node/add',
  );
  // Exported menu link: user-menu_add-review:node/add/ov-review
  $menu_links['user-menu_add-review:node/add/ov-review'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'node/add/ov-review',
    'router_path' => 'node/add/ov-review',
    'link_title' => 'Add review',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'user-menu_add-review:node/add/ov-review',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'parent_identifier' => 'user-menu_add:node/add',
  );
  // Exported menu link: user-menu_add-visualization:visualization/new
  $menu_links['user-menu_add-visualization:visualization/new'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'visualization/new',
    'router_path' => 'visualization/new',
    'link_title' => 'Add visualization',
    'options' => array(
      'attributes' => array(),
      'identifier' => 'user-menu_add-visualization:visualization/new',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'user-menu_add:node/add',
  );
  // Exported menu link: user-menu_add:node/add
  $menu_links['user-menu_add:node/add'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'node/add',
    'router_path' => 'node/add',
    'link_title' => 'Add',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'dropdown-toggle',
        ),
      ),
      'identifier' => 'user-menu_add:node/add',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: user-menu_dashboard:admin/dashboard
  $menu_links['user-menu_dashboard:admin/dashboard'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'admin/dashboard',
    'router_path' => 'admin/dashboard',
    'link_title' => 'Dashboard',
    'options' => array(
      'identifier' => 'user-menu_dashboard:admin/dashboard',
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
  );
  // Exported menu link: user-menu_log-in:user/login
  $menu_links['user-menu_log-in:user/login'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/login',
    'router_path' => 'user/login',
    'link_title' => 'Log in',
    'options' => array(
      'identifier' => 'user-menu_log-in:user/login',
    ),
    'module' => 'system',
    'hidden' => -1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'user-menu_my-account:user',
  );
  // Exported menu link: user-menu_log-out:user/logout
  $menu_links['user-menu_log-out:user/logout'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Log out',
    'options' => array(
      'identifier' => 'user-menu_log-out:user/logout',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'user-menu_my-account:user',
  );
  // Exported menu link: user-menu_review-requests:view_review_requests
  $menu_links['user-menu_review-requests:view_review_requests'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'view_review_requests',
    'router_path' => 'view_review_requests',
    'link_title' => 'Review Requests',
    'options' => array(
      'attributes' => array(
        'title' => 'Pending Review Requests for Mentors',
      ),
      'identifier' => 'user-menu_review-requests:view_review_requests',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'user-menu_my-account:user',
  );
  // Exported menu link: user-menu_user-account:user
  $menu_links['user-menu_user-account:user'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'User account',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'dropdown-toggle',
        ),
      ),
      'identifier' => 'user-menu_user-account:user',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -47,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Add');
  t('Add dashboard');
  t('Add dataset');
  t('Add review');
  t('Add visualization');
  t('Dashboard');
  t('Dashboards');
  t('Home');
  t('Log in');
  t('Log out');
  t('Review Requests');
  t('User account');
  t('Visualizations');


  return $menu_links;
}
