<?php

function current_node_nid(){
    if (arg(0)=='node' && is_numeric(arg(1)))
        return arg(1);
    else 
        return 0;
}

function attendance_menu() {
	$items = array();

	$items['flag2/%/%flag/%/%'] = array(
		'title' => 'Flag',
		'page callback' => 'attendance_flag_page',
		'page arguments' => array(1, 2, 3, 4),
		'access callback' => 'user_access',
		'access arguments' => array('access content'),
		'type' => MENU_CALLBACK,
	);

	return $items;
}

function attendance_flag_page($action, $flag, $user_id, $content_id) {

  // Shorten up the variables that affect the behavior of this page.
  $js = isset($_REQUEST['js']);
  $token = $_REQUEST['token'];

  // Specifically $_GET to avoid getting the $_COOKIE variable by the same key.
  $has_js = isset($_GET['has_js']);

  $user = user_load($user_id);

  // Check the flag token, then perform the flagging.
  if (!flag_check_token($token, $user_id)) {
    $error = t('Bad token. You seem to have followed an invalid link.');
  }
  elseif (!$user) {
    $error = t('Invalid user.');
  }
  elseif ($user->uid == 0 && !$has_js) {
    $error = t('You must have JavaScript and cookies enabled in your browser to flag content.');
  }
  else {
    $result = $flag->flag($action, $content_id, $user);
    if (!$result) {
      $error = t('You are not allowed to flag, or unflag, this content.');
    }
  }

  // If an error was received, set a message and exit.
  if (isset($error)) {
    if ($js) {
      drupal_add_http_header('Content-Type', 'text/javascript; charset=utf-8');
      print drupal_json_encode(array(
        'status' => FALSE,
        'errorMessage' => $error,
      ));
      drupal_exit();
    }
    else {
      drupal_set_message($error);
      drupal_access_denied();
      return;
    }
  }

  // If successful, return data according to the request type.
  if ($js) {
    drupal_add_http_header('Content-Type', 'text/javascript; charset=utf-8');
    $flag->link_type = 'toggle';
    print drupal_json_encode(flag_build_javascript_info($flag, $content_id));
    drupal_exit();
  }
  else {
    drupal_set_message($flag->get_label($action . '_message', $content_id));
    drupal_goto();
  }
}

function attendance_flag_link_types() {
	$types = array();
	$types['attendance'] = array(
		'title' => 'Attendance',
		'description' => 'Flag for tracking attendance on a user',
		'options' => array(
		),
		'uses standard js' => true,
		'uses standard css' => true,
	);
	return $types;
}

function attendance_flag_link($flag, $action, $content_id) {
	$token = flag_get_token($content_id);
	$flag_name = ($flag->name == 'event_user_attending'?'event_session_attending':$flag->name);
	$node_id = current_node_nid();
  
	return array(
		'href' => 'flag2/' . ($flag->link_type == 'confirm' ? 'confirm/' : '') . "$action/$flag->name/$content_id/$node_id",
		'query' => drupal_get_destination() + ($flag->link_type == 'confirm' ? array() : array('token' => $token)),
	);
}

/*removed for now
function attendance_flag_javascript_info_alter($flag, $content_id) {
	if ($flag->name == 'event_user_attending') {
		$flag_name = 'event_session_attending';
	}
	else {
		$flag_name = $flag->name;
	}

	$info = array(
		'contentType' => $type,
		'nodeId' => current_node_nid(),
		'flagName' => $flag_name);
	return $info;
}*/

