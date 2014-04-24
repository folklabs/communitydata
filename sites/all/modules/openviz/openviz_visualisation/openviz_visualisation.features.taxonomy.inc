<?php
/**
 * @file
 * openviz_visualisation.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function openviz_visualisation_taxonomy_default_vocabularies() {
  return array(
    'ov_categories' => array(
      'name' => 'Categories',
      'machine_name' => 'ov_categories',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'ov_tags' => array(
      'name' => 'Tags',
      'machine_name' => 'ov_tags',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
