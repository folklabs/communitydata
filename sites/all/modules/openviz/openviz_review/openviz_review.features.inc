<?php
/**
 * @file
 * openviz_review.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function openviz_review_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "panelizer" && $api == "panelizer") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function openviz_review_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function openviz_review_node_info() {
  $items = array(
    'ov_review' => array(
      'name' => t('Review'),
      'base' => 'node_content',
      'description' => t('Review content type'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
