<?php

/**
 * @file
 * Definition of views_handler_filter_user_current.
 */

/**
 * Filter handler for the current user.
 *
 * @ingroup views_filter_handlers
 */
class recently_read_handler_filter_current extends views_handler_filter_boolean_operator {
  function construct() {
    parent::construct();
    $this->value_value = t('Is the current session?');
  }

  function query(){
    $this->ensure_my_table();

    $field = $this->table_alias . '.' . $this->real_field . ' ';
    $or = db_or();

    if (empty($this->value)) {
      $or->condition($field, '***CURRENT_SESSION***', '<>');
      if ($this->accept_null) {
        $or->isNull($field);
      }
    }
    else {
      $or->condition($field, '***CURRENT_SESSION***', '=');
    }
    $this->query->add_where($this->options['group'], $or);
  }  
}

