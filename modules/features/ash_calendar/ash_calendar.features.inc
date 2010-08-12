<?php

/**
 * Implementation of hook_content_default_fields().
 */
function ash_calendar_content_default_fields() {
  module_load_include('inc', 'ash_calendar', 'ash_calendar.defaults');
  $args = func_get_args();
  return call_user_func_array('_ash_calendar_content_default_fields', $args);
}

/**
 * Implementation of hook_node_info().
 */
function ash_calendar_node_info() {
  module_load_include('inc', 'ash_calendar', 'ash_calendar.features.node');
  $args = func_get_args();
  return call_user_func_array('_ash_calendar_node_info', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function ash_calendar_views_default_views() {
  module_load_include('inc', 'ash_calendar', 'ash_calendar.features.views');
  $args = func_get_args();
  return call_user_func_array('_ash_calendar_views_default_views', $args);
}
