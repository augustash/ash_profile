<?php

/**
 * Implementation of hook_views_default_views().
 */
function aai_custom_search_views_default_views() {
  module_load_include('inc', 'aai_custom_search', 'aai_custom_search.features.views');
  $args = func_get_args();
  return call_user_func_array('_aai_custom_search_views_default_views', $args);
}
