<?php

/**
 * Implementation of hook_strongarm().
 */
function ash_blog_strongarm() {
  $export = array();
  $strongarm = new stdClass;
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_blog_pattern';
  $strongarm->value = 'blog/[yyyy][mm]/[title-raw]';

  $export['pathauto_node_blog_pattern'] = $strongarm;
  return $export;
}
