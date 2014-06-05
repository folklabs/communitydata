<?php

/**
 * @file
 */

/**
 * Implementation of hook_form_FORM_ID().
 */
function vizshare_settings_form() {
  $form['data_unity_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Data Unity URL'),
    '#description' => t('The URL of the Data Unity open data service.'),
    // '#attributes' => array(),
    '#default_value' => variable_get('data_unity_url', ''),

  );

  return system_settings_form($form);
}
