<?php

// /**
//  * Implementation of hook_menu().
//  */
// function vizshare_menu() {
//   $items = array();
//   $items['visualization/new'] = array(
//     'title' => 'Create visualization',
//     'description' => 'Create a visualization',
//     // 'menu_name'       => 'main-menu',
//     'page callback' => 'vizshare_get_viz_form',
//     'page arguments' => array('vizshare_submit_form'),
//     'access arguments' => array('access content')
//   );
//   return $items;
// }

// function vizshare_get_viz_form() {
//   return t('hello');
// }

// function vizshare_submit_form() {
//   $form = array();
//   $form['name'] = array(
//     '#type' => 'textfield',
//     '#title' => 'Name'
//   );
//   $form['last_name'] = array(
//     '#type' => 'textfield',
//     '#title' => 'Last Name'
//   );
//   $form['address'] = array(
//     '#type' => 'textarea',
//     '#title' => 'Your full address',
//     '#description' => 'Please include aptartment number and postal code'
//   );
//   $form['submit'] = array(
//     '#type' => 'submit',
//     '#value' => 'Add yourself'
//   );
//   return $form;
// }
