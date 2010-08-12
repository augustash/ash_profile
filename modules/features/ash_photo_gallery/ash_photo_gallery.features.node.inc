<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _ash_photo_gallery_node_info() {
  $items = array(
    'photo' => array(
      'name' => t('Photo'),
      'module' => 'features',
      'description' => t('A place to upload photos for the photo gallery.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => '',
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
