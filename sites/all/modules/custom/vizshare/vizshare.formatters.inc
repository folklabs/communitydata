<?php

/**
 * @file
 * Leaflet field formatter functions.
 */

/**
 * Implements hook_field_formatter_info().
 */
function vizshare_field_formatter_info() {
  $formatters = array();

  $formatters['vizshare_draw'] = array(
    'label' => t('Vizshare renderer'),
    'field types' => array('vizshare_value'),
    'settings' => array(
      'height' => 400,
    )
  );

  return $formatters;
}

/**
 * Implements hook_field_formatter_settings_form().
 */
function vizshare_field_formatter_settings_form($field, $instance, $view_mode, $form, &$form_state) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];
  $entity_type = $instance['entity_type'];

  $element = array();

  $element['height'] = array(
    '#title' => t('Visualization height'),
    '#type' => 'textfield',
    '#default_value' => $settings['height'],
    '#field_suffix' => t('px'),
    '#element_validate' => array('element_validate_integer_positive'),
  );

  return $element;
}

/**
 * Implements hook_field_formatter_settings_summary().
 */
function vizshare_field_formatter_settings_summary($field, $instance, $view_mode) {
  $display = $instance['display'][$view_mode];
  $settings = $display['settings'];
  $summary = t('Height: @height px', array(
    '@height'     => $settings['height'],
  )); // we use t() for translation and placeholders to guard against attacks
  return $summary;
}



