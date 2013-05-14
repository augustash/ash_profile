<?php

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Allows the profile to alter the site configuration form.
 */
function ash_profile_form_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate the site name with the server name.
  $form['site_information']['site_name']['#default_value'] = $_SERVER['SERVER_NAME'];

  // Pre-populate the site email with a default value
  $form['site_information']['site_mail']['#default_value'] = 'code@augustash.com';

  // Pre-populate the country name with the United States.
  $form['server_settings']['site_default_country']['#default_value'] = 'US';

  // Prepopulate the username and email
  $form['admin_account']['name']['#default_value'] = 'augustash';
  $form['admin_account']['mail']['#default_value'] = 'code@augustash.com';
}
