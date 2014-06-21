<?php
/**
 * @file
 * openviz_review.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function openviz_review_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create ov_review content'.
  $permissions['create ov_review content'] = array(
    'name' => 'create ov_review content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any panopoly_page content'.
  $permissions['delete any panopoly_page content'] = array(
    'name' => 'delete any panopoly_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own ov_review content'.
  $permissions['delete own ov_review content'] = array(
    'name' => 'delete own ov_review content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any panopoly_page content'.
  $permissions['edit any panopoly_page content'] = array(
    'name' => 'edit any panopoly_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own ov_review content'.
  $permissions['edit own ov_review content'] = array(
    'name' => 'edit own ov_review content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
