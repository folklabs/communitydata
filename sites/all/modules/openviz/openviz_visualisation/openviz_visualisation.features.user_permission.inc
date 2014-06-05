<?php
/**
 * @file
 * openviz_visualisation.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function openviz_visualisation_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create ov_visualisation content'.
  $permissions['create ov_visualisation content'] = array(
    'name' => 'create ov_visualisation content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any ov_visualisation content'.
  $permissions['delete any ov_visualisation content'] = array(
    'name' => 'delete any ov_visualisation content',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own ov_visualisation content'.
  $permissions['delete own ov_visualisation content'] = array(
    'name' => 'delete own ov_visualisation content',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any ov_visualisation content'.
  $permissions['edit any ov_visualisation content'] = array(
    'name' => 'edit any ov_visualisation content',
    'roles' => array(
      'editor' => 'editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own ov_visualisation content'.
  $permissions['edit own ov_visualisation content'] = array(
    'name' => 'edit own ov_visualisation content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  return $permissions;
}
