<?php

/**
* Return an array of the modules to be enabled when this profile is installed.
*
* @return
*  An array of modules to be enabled.
*/
function ash_profile_profile_modules() {

  // Enable required core modules first.
  $core_req = array(
    'block', 'filter', 'node', 'system', 'user'
  );
  
  // Enable optional core modules next.
  $core_opt = array(
    'comment', 'help', 'menu', 'taxonomy', 'path', 'search', 'php'
  );
  
  // Then, enable any contributed modules here.
  $contrib = array(
    'admin', 'devel', 'ctools', 'content', 'views', 'views_ui', 'fieldgroup', 'filefield', 'imagefield', 'number', 'optionwidgets', 'text', 'date_api', 'date', 'date_timezone', 'imageapi', 'imageapi_gd', 'imagecache', 'imagecache_ui', 'jquery_update', 'token', 'pathauto', 'advanced_help', 'wysiwyg', 'better_formats', 'vertical_tabs', 'features', 'smtp', 'page_title', 'nodewords', 'strongarm',
  );
  
  return array_merge($core_req, $core_opt, $contrib);
}

/**
* Return a description of the profile for the initial installation screen.
*
* @return
*   An array with keys 'name' and 'description' describing this profile.
*/
function ash_profile_profile_details() {
  return array(
    'name' => 'August Ash',
    'description' => 'This installs and enables all of the modules for the August Ash base Drupal install. It will make your life easier.',
  );
}

/**
 * Return a list of tasks that this profile supports.
 *
 * @return
 *   A keyed array of tasks the profile will perform during
 *   the final stage. The keys of the array will be used internally,
 *   while the values will be displayed to the user in the installer
 *   task list.
 */
function ash_profile_profile_task_list() {
}

/**
 * Perform any final installation tasks for this profile.
 *
 * The installer goes through the profile-select -> locale-select
 * -> requirements -> database -> profile-install-batch
 * -> locale-initial-batch -> configure -> locale-remaining-batch
 * -> finished -> done tasks, in this order, if you don't implement
 * this function in your profile.
 *
 * If this function is implemented, you can have any number of
 * custom tasks to perform after 'configure', implementing a state
 * machine here to walk the user through those tasks. First time,
 * this function gets called with $task set to 'profile', and you
 * can advance to further tasks by setting $task to your tasks'
 * identifiers, used as array keys in the hook_profile_task_list()
 * above. You must avoid the reserved tasks listed in
 * install_reserved_tasks(). If you implement your custom tasks,
 * this function will get called in every HTTP request (for form
 * processing, printing your information screens and so on) until
 * you advance to the 'profile-finished' task, with which you
 * hand control back to the installer. Each custom page you
 * return needs to provide a way to continue, such as a form
 * submission or a link. You should also set custom page titles.
 *
 * You should define the list of custom tasks you implement by
 * returning an array of them in hook_profile_task_list(), as these
 * show up in the list of tasks on the installer user interface.
 *
 * Remember that the user will be able to reload the pages multiple
 * times, so you might want to use variable_set() and variable_get()
 * to remember your data and control further processing, if $task
 * is insufficient. Should a profile want to display a form here,
 * it can; the form should set '#redirect' to FALSE, and rely on
 * an action in the submit handler, such as variable_set(), to
 * detect submission and proceed to further tasks. See the configuration
 * form handling code in install_tasks() for an example.
 *
 * Important: Any temporary variables should be removed using
 * variable_del() before advancing to the 'profile-finished' phase.
 *
 * @param $task
 *   The current $task of the install system. When hook_profile_tasks()
 *   is first called, this is 'profile'.
 * @param $url
 *   Complete URL to be used for a link or form action on a custom page,
 *   if providing any, to allow the user to proceed with the installation.
 *
 * @return
 *   An optional HTML string to display to the user. Only used if you
 *   modify the $task, otherwise discarded.
 */
function ash_profile_profile_tasks(&$task, $url) {

  // Insert default user-defined node types into the database. For a complete
  // list of available node type attributes, refer to the node type API
  // documentation at: http://api.drupal.org/api/HEAD/function/hook_node_info.
  $types = array(
    array(
      'type' => 'page',
      'name' => st('Page'),
      'module' => 'node',
      'description' => st("This is for regular content entries, like an <em>About Us</em> page for example. By default, a <em>page</em> entry does not allow visitor comments and is not featured on the site's initial home page."),
      'custom' => TRUE,
      'modified' => TRUE,
      'locked' => FALSE,
      'help' => '',
      'min_word_count' => '',
    ),
  );

  foreach ($types as $type) {
    $type = (object) _node_type_set_defaults($type);
    node_type_save($type);
  }

  // Default page to not be promoted and have comments disabled.
  variable_set('node_options_page', array('status'));
  variable_set('comment_page', COMMENT_NODE_DISABLED);

  // Don't display date and author information for page nodes by default.
  $theme_settings = variable_get('theme_settings', array());
  $theme_settings['toggle_node_info_page'] = FALSE;
  variable_set('theme_settings', $theme_settings);
  
  //Create 'admin' role and give it some permissions.
  db_query("INSERT INTO {role} (rid, name) VALUES (%d, '%s')", 3, 'administrator');
  //Add all permissions in the system.
  //TODO: Make this programmatical.
  $perms = 'use admin toolbar, view advanced help index, view advanced help popup, view advanced help topic, access aai news, administer blocks, use PHP for block visibility, administer CAPTCHA settings, skip CAPTCHA, access comments, administer comments, post comments, post comments without approval, view date repeats, access devel information, display source code, execute php code, switch users, administer filters, administer imageapi, administer imagecache, flush imagecache, administer menu, access content, administer content types, administer nodes, create page content, delete any page content, delete own page content, delete revisions, edit any page content, edit own page content, revert revisions, view revisions, administer url aliases, create url aliases, administer pathauto, notify of path changes, administer search, search content, use advanced search, access administration pages, access site reports, administer actions, administer files, administer site configuration, administer taxonomy, access user profiles, administer permissions, administer users, change own username, access all views, administer views';
  db_query("INSERT INTO {permission} (pid, rid, perm) VALUES (%d, %d, '%s')", 3, 3, $perms);
  
  //Add the new User 1 to the "administrator" role.
  db_query("INSERT INTO {users_roles} (uid, rid) VALUES (%d, %d)", 1, 3);
  
  //Enable and make default AA Zen starter theme.
  //Also enable Tao and Rubik, make Rubik the admin theme, and have it apply to edit forms.
  db_query("UPDATE {system} SET status=%d WHERE name = '%s'", 1, 'ash_squareone');
  db_query("UPDATE {system} SET status=%d WHERE name = '%s'", 1, 'tao');
  db_query("UPDATE {system} SET status=%d WHERE name = '%s'", 1, 'rubik');
  variable_set('theme_default', 'ash_squareone');
  variable_set('admin_theme', 'rubik');
  variable_set('node_admin_theme', 1);
  
  //Enable TinyMCE for both "Filtered HTML" and "Full HTML" input formats.
  for ($i = 1; $i <=3; $i++) {
    db_query('INSERT INTO {wysiwyg} SET format = %d', $i);
  } 
  db_query("UPDATE {wysiwyg} SET editor = 'tinymce' WHERE format = 1 OR format = 2");
  
  //Add better default settings for the Better Formats module.
  db_query('UPDATE `better_formats_defaults` SET `format` = %d, `type_weight` = %d, `weight` = %d WHERE `rid` = %d AND `type` = \'%s\'', 1, 1 -24, 1, 'node');
  db_query('UPDATE `better_formats_defaults` SET `format` = %d, `type_weight` = %d, `weight` = %d WHERE `rid` = %d AND `type` = \'%s\'', 0, 1, 0, 1, 'comment');
  db_query('UPDATE `better_formats_defaults` SET `format` = %d, `type_weight` = %d, `weight` = %d WHERE `rid` = %d AND `type` = \'%s\'', 0, 1, 25, 1, 'block');
  db_query('UPDATE `better_formats_defaults` SET `format` = %d, `type_weight` = %d, `weight` = %d WHERE `rid` = %d AND `type` = \'%s\'', 1, 1, -23, 2, 'node');
  db_query('UPDATE `better_formats_defaults` SET `format` = %d, `type_weight` = %d, `weight` = %d WHERE `rid` = %d AND `type` = \'%s\'', 0, 1, 0, 2, 'comment');
  db_query('UPDATE `better_formats_defaults` SET `format` = %d, `type_weight` = %d, `weight` = %d WHERE `rid` = %d AND `type` = \'%s\'', 0, 1, 25, 2, 'block');
  db_query("INSERT INTO `better_formats_defaults` (`rid`, `type`, `format`, `type_weight`, `weight`) VALUES 
    (3, 'node', 2, 1, -25),
    (3, 'comment', 0, 1, 0),
    (3, 'block', 2, 1, 25);");
	
  //Set Page's URL to be the Menu Path
  variable_set('pathauto_node_page_pattern', '[menupath-raw]');

	// Setting smtp module backup server to VISI.
	variable_set('smtp_hostbackup', 'smtp.visi.com');

	// Setting some default date formats.
	variable_set('date_format_date_only', 'F j, Y');
	variable_set('date_format_time_only', 'g:i a');
	
	$date = new stdClass();
	$date->type = 'date_only';
	$date->title = 'Date Only';
	$date->locked = 0;
	$time = new stdClass();
	$time->type = 'time_only';
	$time->title = 'Time Only';
	$time->locked = 0;
	drupal_write_record('date_format_types', $date);
	drupal_write_record('date_format_types', $time);
	unset($date); unset($time);
	
	$date = new stdClass();
	$date->format = 'F j, Y';
	$date->type = 'custom';
	$date->locked = 0;
	$time = new stdClass();
	$time->format = 'g:i a';
	$time->type = 'custom';
	$time->locked = 0;
	drupal_write_record('date_formats', $date);
	drupal_write_record('date_formats', $time);

  // Update the menu router information.
  menu_rebuild();
}

/**
 * Setting our profile as the default.
 */
function system_form_install_select_profile_form_alter(&$form, $form_state) {
  foreach($form['profile'] as $key => $element) {
    $form['profile'][$key]['#value'] = 'ash_profile';
  }
}

/**
 * Alter the install profile configuration form and provide timezone location options.
 */
function system_form_install_configure_form_alter(&$form, $form_state) {
  $form['site_information']['site_name']['#default_value'] = 'August Ash Base Install';
  $form['site_information']['site_mail']['#default_value'] = 'info@'. $_SERVER['HTTP_HOST'];
  $form['admin_account']['account']['name']['#default_value'] = 'augustash';
  $form['admin_account']['account']['mail']['#default_value'] = 'you@augustash.com';
}

?>