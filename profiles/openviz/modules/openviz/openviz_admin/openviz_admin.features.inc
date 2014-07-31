<?php
/**
 * @file
 * openviz_admin.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function openviz_admin_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function openviz_admin_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function openviz_admin_flag_default_flags() {
  $flags = array();
  // Exported flag: "Report abuse".
  $flags['ol_report_abuse'] = array(
    'entity_type' => 'node',
    'title' => 'Report abuse',
    'global' => 0,
    'types' => array(
      0 => 'ov_visualisation',
    ),
    'flag_short' => 'Report abuse',
    'flag_long' => 'Flag this content as containing abusive content',
    'flag_message' => 'Thank you for reporting this. It will be reviewed!',
    'unflag_short' => 'Cancel report abuse',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => 'Reported abuse can only be cancelled by hte administrator.',
    'link_type' => 'toggle',
    'weight' => -6,
    'show_in_links' => array(
      'full' => 'full',
      'teaser' => 0,
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'featured' => 0,
      'token' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => FALSE,
    'i18n' => 0,
    'module' => 'openviz_admin',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}
