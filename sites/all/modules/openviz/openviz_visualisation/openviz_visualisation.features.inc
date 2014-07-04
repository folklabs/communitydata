<?php
/**
 * @file
 * openviz_visualisation.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function openviz_visualisation_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
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
function openviz_visualisation_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function openviz_visualisation_flag_default_flags() {
  $flags = array();
  // Exported flag: "Favorites".
  $flags['ov_favorites'] = array(
    'entity_type' => 'node',
    'title' => 'Favorites',
    'global' => 0,
    'types' => array(
      0 => 'ov_review',
      1 => 'ov_visualisation',
    ),
    'flag_short' => 'Save as favourite',
    'flag_long' => '',
    'flag_message' => 'This item is added to your favorites',
    'unflag_short' => 'Remove from favourites',
    'unflag_long' => '',
    'unflag_message' => 'This item is removed from your favorites',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
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
    'module' => 'openviz_visualisation',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_node_info().
 */
function openviz_visualisation_node_info() {
  $items = array(
    'ov_visualisation' => array(
      'name' => t('Visualisation'),
      'base' => 'node_content',
      'description' => t('A visualisation of data from one or more sources.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
