<?php
/**
 * Implements of hook_views_query_substitutions()
 */
function recently_read_views_query_substitutions($view) {
  return array(
    '***CURRENT_SESSION***' => session_api_get_sid(),
  );
}


/**
 * Implements of hook_views_data().
 **/
function recently_read_views_data() {
  $data['recently_read']['table']['group'] = t('Recently Read');

  $data['recently_read']['sid'] = array(
    'title' => t('Recently read Session api sid'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'relationship' => array(
      'base' => 'session_api',
      'base field' => 'sid',
      'handler' => 'views_handler_relationship',
      'label' => t('Label for sid'),
      'title' => t('Session api'),
      'help' => t('Relationship to session api'),
    ),
  );
  $data['recently_read']['type'] = array(
    'title' => t('entity type'),
    'help' => t('Entity Type'),
    'filter' => array(
      'handler' => 'recently_read_handler_filter_entity_type',
    ),
  );

  $data['recently_read']['entity_id'] = array(
    'title' => t('Recently Read Entity Id'),
    'help' => t('Recently Read Entity Id'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_user_name',
    ),
  );

  $data['recently_read']['current'] = array(
    'real field' => 'sid',
    'title' => t('Current'),
    'help' => t('Filter the view to the current user.'),
    'filter' => array(
      'handler' => 'recently_read_handler_filter_current',
      'type' => 'yes-no',
    ),
  );

  $data['recently_read']['timestamp'] = array(
    'title' => t('Recently Read Date'),
    'help' => t('Recently Read Time'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );
  return $data;
}

/**
 * Implements of hook_views_data_alter().
 **/
function recently_read_views_data_alter(&$data) {
  $info = entity_get_info();
  foreach ($info as $type => $entity) {
    $data['recently_read']['table']['join'] = array(
      $entity['base table'] => array(
        'left_field' => $entity['entity keys']['id'],
        'field' => 'entity_id',
      ),
    );
    $data[$entity['base table']][$type . '_rr_' . $entity['entity keys']['id']] = array(
      'title' => t('Recently Read'),
      'help' => t('Recently Read Relationship'),
      'relationship' => array(
        'group' => 'Recently Read',
        'label' => t('Recently Read'),
        'base' => 'recently_read',
        'base field' => 'entity_id',
        'relationship field' => $entity['entity keys']['id'],
        'handler' => 'views_handler_relationship'
      ),
    );
  }
}

