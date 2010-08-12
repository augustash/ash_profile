<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _ash_calendar_node_info() {
  $items = array(
    'event' => array(
      'name' => t('Event'),
      'module' => 'features',
      'description' => t('Events contain a time, place, and description. They will appear in the calendar.'),
      'has_title' => '1',
      'title_label' => t('Event Name'),
      'has_body' => '1',
      'body_label' => t('Description'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
