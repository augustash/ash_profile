<?php

/**
 * Helper to implementation of hook_content_default_fields().
 */
function _ash_blog_content_default_fields() {
  $fields = array();

  // Exported field: field_blog_image
  $fields[] = array(
    'field_name' => 'field_blog_image',
    'type_name' => 'blog',
    'display_settings' => array(
      'weight' => '-4',
      'parent' => '',
      'label' => array(
        'format' => 'hidden',
      ),
      'teaser' => array(
        'format' => 'blog_page_default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'blog_page_default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'image_plain',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'filefield',
    'required' => '0',
    'multiple' => '0',
    'module' => 'filefield',
    'active' => '1',
    'list_field' => '0',
    'list_default' => 1,
    'description_field' => '0',
    'widget' => array(
      'file_extensions' => 'png gif jpg jpeg',
      'file_path' => '',
      'progress_indicator' => 'bar',
      'max_filesize_per_file' => '',
      'max_filesize_per_node' => '',
      'max_resolution' => '0',
      'min_resolution' => '0',
      'alt' => '',
      'custom_alt' => 0,
      'title' => '',
      'custom_title' => 0,
      'title_type' => 'textfield',
      'default_image' => NULL,
      'use_default_image' => 0,
      'label' => 'Image',
      'weight' => '-4',
      'description' => '',
      'type' => 'imagefield_widget',
      'module' => 'imagefield',
    ),
  );

  // Translatables
  array(
    t('Image'),
  );

  return $fields;
}

/**
 * Helper to implementation of hook_imagecache_default_presets().
 */
function _ash_blog_imagecache_default_presets() {
  $items = array(
    'blog_list' => array(
      'presetname' => 'blog_list',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '150',
            'height' => '150',
            'upscale' => 0,
          ),
        ),
        '1' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_crop',
          'data' => array(
            'width' => '200',
            'height' => '150',
            'xoffset' => 'center',
            'yoffset' => 'center',
          ),
        ),
      ),
    ),
    'blog_page' => array(
      'presetname' => 'blog_page',
      'actions' => array(
        '0' => array(
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '400',
            'height' => '400',
            'upscale' => 0,
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Helper to implementation of hook_user_default_permissions().
 */
function _ash_blog_user_default_permissions() {
  $permissions = array();

  // Exported permission: create blog content
  $permissions[] = array(
    'name' => 'create blog content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: delete any blog content
  $permissions[] = array(
    'name' => 'delete any blog content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: delete own blog content
  $permissions[] = array(
    'name' => 'delete own blog content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: edit any blog content
  $permissions[] = array(
    'name' => 'edit any blog content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  // Exported permission: edit own blog content
  $permissions[] = array(
    'name' => 'edit own blog content',
    'roles' => array(
      '0' => 'administrator',
    ),
  );

  return $permissions;
}
