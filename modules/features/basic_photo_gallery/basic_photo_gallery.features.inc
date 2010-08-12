<?php

/**
 * Implementation of hook_content_default_fields().
 */
function basic_photo_gallery_content_default_fields() {
  module_load_include('inc', 'basic_photo_gallery', 'basic_photo_gallery.defaults');
  $args = func_get_args();
  return call_user_func_array('_basic_photo_gallery_content_default_fields', $args);
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function basic_photo_gallery_imagecache_default_presets() {
  module_load_include('inc', 'basic_photo_gallery', 'basic_photo_gallery.defaults');
  $args = func_get_args();
  return call_user_func_array('_basic_photo_gallery_imagecache_default_presets', $args);
}

/**
 * Implementation of hook_node_info().
 */
function basic_photo_gallery_node_info() {
  module_load_include('inc', 'basic_photo_gallery', 'basic_photo_gallery.features.node');
  $args = func_get_args();
  return call_user_func_array('_basic_photo_gallery_node_info', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function basic_photo_gallery_views_default_views() {
  module_load_include('inc', 'basic_photo_gallery', 'basic_photo_gallery.features.views');
  $args = func_get_args();
  return call_user_func_array('_basic_photo_gallery_views_default_views', $args);
}
