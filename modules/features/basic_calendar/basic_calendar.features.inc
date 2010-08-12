<?php

/**
 * Implementation of hook_content_default_fields().
 */
function basic_calendar_content_default_fields() {
  module_load_include('inc', 'basic_calendar', 'basic_calendar.defaults');
  $args = func_get_args();
  return call_user_func_array('_basic_calendar_content_default_fields', $args);
}

/**
 * Implementation of hook_node_info().
 */
function basic_calendar_node_info() {
  module_load_include('inc', 'basic_calendar', 'basic_calendar.features.node');
  $args = func_get_args();
  return call_user_func_array('_basic_calendar_node_info', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function basic_calendar_views_default_views() {
  module_load_include('inc', 'basic_calendar', 'basic_calendar.features.views');
  $args = func_get_args();
  return call_user_func_array('_basic_calendar_views_default_views', $args);
}
