<?php
/**
 * @file
 * prolifik_authorship.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function prolifik_authorship_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'authorship';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Authorship';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'The Author';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Field: User: Blog Avatar */
  $handler->display->display_options['fields']['field_blog_avatar']['id'] = 'field_blog_avatar';
  $handler->display->display_options['fields']['field_blog_avatar']['table'] = 'field_data_field_blog_avatar';
  $handler->display->display_options['fields']['field_blog_avatar']['field'] = 'field_blog_avatar';
  $handler->display->display_options['fields']['field_blog_avatar']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_blog_avatar']['label'] = '';
  $handler->display->display_options['fields']['field_blog_avatar']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_blog_avatar']['element_class'] = 'avatar';
  $handler->display->display_options['fields']['field_blog_avatar']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_blog_avatar']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_blog_avatar']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_blog_avatar']['settings'] = array(
    'image_style' => 'large',
    'image_link' => 'content',
  );
  /* Field: Content: Author uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'node';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['field_name']['id'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['fields']['field_name']['field'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_name']['label'] = '';
  $handler->display->display_options['fields']['field_name']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_name']['element_class'] = 'profile-name';
  $handler->display->display_options['fields']['field_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_name']['element_default_classes'] = FALSE;
  /* Field: User: Job Title */
  $handler->display->display_options['fields']['field_job_title']['id'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['table'] = 'field_data_field_job_title';
  $handler->display->display_options['fields']['field_job_title']['field'] = 'field_job_title';
  $handler->display->display_options['fields']['field_job_title']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_job_title']['label'] = '';
  $handler->display->display_options['fields']['field_job_title']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_job_title']['element_class'] = 'job-title';
  $handler->display->display_options['fields']['field_job_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_job_title']['element_default_classes'] = FALSE;
  /* Field: User: Authorship Blurb */
  $handler->display->display_options['fields']['field_authorship_blurb']['id'] = 'field_authorship_blurb';
  $handler->display->display_options['fields']['field_authorship_blurb']['table'] = 'field_data_field_authorship_blurb';
  $handler->display->display_options['fields']['field_authorship_blurb']['field'] = 'field_authorship_blurb';
  $handler->display->display_options['fields']['field_authorship_blurb']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_authorship_blurb']['label'] = '';
  $handler->display->display_options['fields']['field_authorship_blurb']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Find [field_name] on Social Media';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: User: Facebook Page */
  $handler->display->display_options['fields']['field_facebook_page']['id'] = 'field_facebook_page';
  $handler->display->display_options['fields']['field_facebook_page']['table'] = 'field_data_field_facebook_page';
  $handler->display->display_options['fields']['field_facebook_page']['field'] = 'field_facebook_page';
  $handler->display->display_options['fields']['field_facebook_page']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_facebook_page']['label'] = '';
  $handler->display->display_options['fields']['field_facebook_page']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_facebook_page']['alter']['text'] = '<a href="[field_facebook_page-value] " rel="nofollow" target="_blank"><img src="/social/facebook.png" alt="[field_full_name] on Facebook" /></a>';
  $handler->display->display_options['fields']['field_facebook_page']['element_label_colon'] = FALSE;
  /* Field: User: Google Plus */
  $handler->display->display_options['fields']['field_google_plus']['id'] = 'field_google_plus';
  $handler->display->display_options['fields']['field_google_plus']['table'] = 'field_data_field_google_plus';
  $handler->display->display_options['fields']['field_google_plus']['field'] = 'field_google_plus';
  $handler->display->display_options['fields']['field_google_plus']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_google_plus']['label'] = '';
  $handler->display->display_options['fields']['field_google_plus']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_google_plus']['alter']['text'] = '<a href="[field_google_plus]" rel="author" target="_blank"><img src="/social/google-plus.png" alt="[field_full_name] on Google Plus" /></a>';
  $handler->display->display_options['fields']['field_google_plus']['element_label_colon'] = FALSE;
  /* Field: User: Twitter Account */
  $handler->display->display_options['fields']['field_twitter_account']['id'] = 'field_twitter_account';
  $handler->display->display_options['fields']['field_twitter_account']['table'] = 'field_data_field_twitter_account';
  $handler->display->display_options['fields']['field_twitter_account']['field'] = 'field_twitter_account';
  $handler->display->display_options['fields']['field_twitter_account']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_twitter_account']['label'] = '';
  $handler->display->display_options['fields']['field_twitter_account']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_twitter_account']['alter']['text'] = '<a href="[field_twitter_account-value]" rel="nofollow" target="_blank"><img src="/social/twitter.png" alt="[field_full_name] on Twitter" /></a>';
  $handler->display->display_options['fields']['field_twitter_account']['element_label_colon'] = FALSE;
  /* Field: User: LinkedIn */
  $handler->display->display_options['fields']['field_linkedin']['id'] = 'field_linkedin';
  $handler->display->display_options['fields']['field_linkedin']['table'] = 'field_data_field_linkedin';
  $handler->display->display_options['fields']['field_linkedin']['field'] = 'field_linkedin';
  $handler->display->display_options['fields']['field_linkedin']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_linkedin']['label'] = '';
  $handler->display->display_options['fields']['field_linkedin']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_linkedin']['alter']['text'] = '<a href="[field_linkedin]" rel="nofollow" target="_blank"><img src="/social/linkedin.png" alt="[field_full_name] on LinkedIn" /></a>';
  $handler->display->display_options['fields']['field_linkedin']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_linkedin']['element_default_classes'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = TRUE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $export['authorship'] = $view;

  return $export;
}
