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
    'ov_visualization_type' => array(
      'name' => 'Type',
      'machine_name' => 'ov_visualization_type',
      'description' => 'Visualization Type Vocabulary',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
