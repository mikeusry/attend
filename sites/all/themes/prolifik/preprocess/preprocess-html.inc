<?php

/**
 * @file
 * This file contains Omega html preprocessing for the prolifik theme.
 */

function prolifik_alpha_preprocess_html(&$variables) {
  drupal_add_js(array(
    'prolifik' => array(
      'search_text' => 'Search ' . variable_get('site_name', 'this site') . '...',
    )
  ), 'setting');
}
