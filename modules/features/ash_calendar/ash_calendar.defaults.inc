<?php

/**
 * Helper to implementation of hook_content_default_fields().
 */
function _ash_calendar_content_default_fields() {
  $fields = array();

  // Exported field: field_event_location
  $fields[] = array(
    'field_name' => 'field_event_location',
    'type_name' => 'event',
    'display_settings' => array(
      'weight' => '-3',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'text',
    'required' => '0',
    'multiple' => '0',
    'module' => 'text',
    'active' => '1',
    'text_processing' => '0',
    'max_length' => '',
    'allowed_values' => '',
    'allowed_values_php' => '',
    'widget' => array(
      'rows' => 5,
      'size' => '60',
      'default_value' => array(
        '0' => array(
          'value' => '',
          '_error_element' => 'default_value_widget][field_event_location][0][value',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Location',
      'weight' => '-3',
      'description' => '',
      'type' => 'text_textfield',
      'module' => 'text',
    ),
  );

  // Exported field: field_event_when
  $fields[] = array(
    'field_name' => 'field_event_when',
    'type_name' => 'event',
    'display_settings' => array(
      'weight' => '-4',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'short',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'short',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'date',
    'required' => '1',
    'multiple' => '1',
    'module' => 'date',
    'active' => '1',
    'granularity' => array(
      'year' => 'year',
      'month' => 'month',
      'day' => 'day',
      'hour' => 'hour',
      'minute' => 'minute',
    ),
    'timezone_db' => 'UTC',
    'tz_handling' => 'site',
    'todate' => 'optional',
    'repeat' => 1,
    'repeat_collapsed' => '1',
    'default_format' => 'medium',
    'widget' => array(
      'default_value' => 'now',
      'default_value_code' => '',
      'default_value2' => 'strtotime',
      'default_value_code2' => '+1 week',
      'input_format' => 'm/d/Y - g:i:sa',
      'input_format_custom' => '',
      'increment' => '5',
      'text_parts' => array(),
      'year_range' => '-3:+3',
      'label_position' => 'none',
      'label' => 'When',
      'weight' => '-4',
      'description' => '',
      'type' => 'date_popup_repeat',
      'module' => 'date',
    ),
  );

  // Translatables
  array(
    t('Location'),
    t('When'),
  );

  return $fields;
}
