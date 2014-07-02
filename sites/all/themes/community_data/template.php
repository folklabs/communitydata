<?php
/**
 * @file
 * Sass Kalatheme's primary theme functions and alterations.
 */

/**
 * Adds a Panopoly/Panels search form to the header.
 */
function community_data_preprocess_page(&$variables) {
  $variables['search_form'] = '';
  if (module_exists('search') && user_access('search content')) {
    $search_box_form = drupal_get_form('search_form');
    $search_box_form['basic']['keys']['#title'] = '';
    $search_box_form['basic']['keys']['#attributes'] = array('placeholder' => 'Search this site');
    $search_box_form['basic']['keys']['#attributes']['class'][] = 'search-query';
    $search_box_form['basic']['submit']['#value'] = t('Search');
    $search_box = drupal_render($search_box_form);
    $variables['search_form'] = (user_access('search content')) ? $search_box : NULL;
  }
}
