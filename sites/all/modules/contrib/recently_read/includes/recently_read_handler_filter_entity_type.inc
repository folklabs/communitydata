<?php
/**
 * Filter by entity type.
 */
class recently_read_handler_filter_entity_type extends views_handler_filter_in_operator {
  function get_value_options() {
    if (!isset($this->value_options)) {
      foreach (entity_get_info() as $type => $info) {
        $options[$type] = t($info['label']);
      }
      asort($options);
      $this->value_options = $options;
    }
  }
}
