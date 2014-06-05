<?php
/**
 * @file
 * openviz_admin.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function openviz_admin_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'OpenViz Admin dashboard links';
  $fe_block_boxes->format = 'panopoly_wysiwyg_text';
  $fe_block_boxes->machine_name = 'ol_admin_dashboard_links';
  $fe_block_boxes->body = '<p><a href="admin/reports/google-analytics">Google Analytics</a></p><p></p>';

  $export['ol_admin_dashboard_links'] = $fe_block_boxes;

  return $export;
}
