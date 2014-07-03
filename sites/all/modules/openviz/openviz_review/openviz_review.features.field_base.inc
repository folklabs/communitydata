<?php
/**
 * @file
 * openviz_review.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function openviz_review_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_review_reason'
  $field_bases['field_review_reason'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_review_reason',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  return $field_bases;
}
