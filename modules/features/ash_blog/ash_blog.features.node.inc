<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _ash_blog_node_info() {
  $items = array(
    'blog' => array(
      'name' => t('Blog Entry'),
      'module' => 'features',
      'description' => t('A basic blog entry.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
