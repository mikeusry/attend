<?php
/**
 * @file
 * prolifik_authorship.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function prolifik_authorship_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_personal|user|user|form';
  $field_group->group_name = 'group_personal';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_profile';
  $field_group->data = array(
    'label' => 'Personal Information',
    'weight' => '9',
    'children' => array(
      0 => 'field_name',
      1 => 'field_job_title',
      2 => 'field_biography',
      3 => 'field_profile_picutre',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_personal|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_profile|user|user|form';
  $field_group->group_name = 'group_profile';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Profile Infromation',
    'weight' => '7',
    'children' => array(
      0 => 'group_personal',
      1 => 'group_social',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'label' => 'Profile Infromation',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_profile|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_social|user|user|form';
  $field_group->group_name = 'group_social';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_profile';
  $field_group->data = array(
    'label' => 'Social Profiles',
    'weight' => '10',
    'children' => array(
      0 => 'field_google_plus',
      1 => 'field_facebook_page',
      2 => 'field_twitter_account',
      3 => 'field_linkedin',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_social|user|user|form'] = $field_group;

  return $export;
}
