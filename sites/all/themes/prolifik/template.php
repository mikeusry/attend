<?php

/**
 * @file
 * This file contains template processing for the prolifik theme.
 */

function prolifik_preprocess_maintenance_page(&$variables) {
  $variables['logo'] = path_to_theme() . '/images/logo_maintenance.png';
}
 
function prolifik_process_maintenance_page(&$variables) {
  // Include @font-your-face support
  if (module_exists('fontyourface')) {
    fontyourface_preprocess_page($variables);
    $fonts = (array) $variables['fontyourface'];
    foreach ($fonts as $font) {
      if (module_hook($font->provider, 'preprocess_page')) {
        call_user_func_array($font->provider . '_preprocess_page', array(&$variables));
      }
    }
  }
  // Add theme's maintenance CSS
  drupal_add_css(path_to_theme() . '/css/maintenance.css', array('group' => CSS_THEME, 'weight' => 10));
  // Reset variables
  $variables['head']    = drupal_get_html_head();
  $variables['css']     = drupal_add_css();
  $variables['styles']  = drupal_get_css();
  $variables['scripts'] = drupal_get_js();
}

function prolifik_openenterprise_logo() {
  return '<img src="' . base_path() . drupal_get_path('theme', 'prolifik') . '/images/openenterprise-logo-small.png" alt="" class="openenterprise" height="16" width="122" />';
}

function prolifik_levelten_logo() {
  return '<img src="' . base_path() . drupal_get_path('theme', 'prolifik') . '/images/levelten-logo-small.png" alt="" class="levelten" height="16" width="52" />';
}

function prolifik_html_head_alter(&$head_elements) {
  // Make FavIcon Drupal cache clearable
  foreach ($head_elements as $key => $data) {
    if (strpos($key, 'drupal_add_html_head_link:shortcut icon') !== FALSE) {
      $head_elements[$key]['#attributes']['href'] .= '?' . variable_get('css_js_query_string', '0');
    }
  }
}