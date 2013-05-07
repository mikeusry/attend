<?php
/**
 * @file
 * prolifik_authorship.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function prolifik_authorship_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'user|user|full';
  $ds_fieldsetting->entity_type = 'user';
  $ds_fieldsetting->bundle = 'user';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'user_facebook' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'user_google_plus' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'user_linkedin' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'user_twitter' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['user|user|full'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function prolifik_authorship_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'user_facebook';
  $ds_field->label = 'User Facebook';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'user' => 'user',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<a href="[user:field_facebook]" rel="nofollow" target="_blank"><img src="/social/facebook.png" alt="[user:field_name] on facebook" /></a>',
      'format' => 'pure_html',
    ),
    'use_token' => 1,
  );
  $export['user_facebook'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'user_google_plus';
  $ds_field->label = 'User Google Plus';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'user' => 'user',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<a href="[user:field_google_plus]" rel="nofollow" target="_blank"><img src="/social/google-plus.png" alt="[user:field_name] on Google Plus" /></a>',
      'format' => 'pure_html',
    ),
    'use_token' => 1,
  );
  $export['user_google_plus'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'user_linkedin';
  $ds_field->label = 'User LinkedIn';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'user' => 'user',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<a href="[user:field_linkedin]" rel="nofollow" target="_blank"><img src="/social/linkedin.png" alt="[user:field_name] on LinkedIn" /></a>',
      'format' => 'pure_html',
    ),
    'use_token' => 1,
  );
  $export['user_linkedin'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'user_twitter';
  $ds_field->label = 'User Twitter';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'user' => 'user',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<a href="[user:field_twitter]" rel="nofollow" target="_blank"><img src="/social/twitter.png" alt="[user:field_name] on Twitter" /></a>',
      'format' => 'pure_html',
    ),
    'use_token' => 1,
  );
  $export['user_twitter'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function prolifik_authorship_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'user|user|full';
  $ds_layout->entity_type = 'user';
  $ds_layout->bundle = 'user';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_2col_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_profile_picutre',
        1 => 'user_google_plus',
        2 => 'user_linkedin',
        3 => 'user_twitter',
        4 => 'user_facebook',
        5 => 'field_credentials',
      ),
      'right' => array(
        6 => 'field_job_title',
        7 => 'field_biography',
      ),
    ),
    'fields' => array(
      'field_profile_picutre' => 'left',
      'user_google_plus' => 'left',
      'user_linkedin' => 'left',
      'user_twitter' => 'left',
      'user_facebook' => 'left',
      'field_credentials' => 'left',
      'field_job_title' => 'right',
      'field_biography' => 'right',
    ),
    'classes' => array(),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 0,
  );
  $export['user|user|full'] = $ds_layout;

  return $export;
}
