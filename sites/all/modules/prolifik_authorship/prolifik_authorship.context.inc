<?php
/**
 * @file
 * prolifik_authorship.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function prolifik_authorship_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'article_type';
  $context->description = 'Articles';
  $context->tag = 'Content Type';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'article' => 'article',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-4' => array(
          'module' => 'block',
          'delta' => '4',
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
        'block-6' => array(
          'module' => 'block',
          'delta' => '6',
          'region' => 'sidebar_second',
          'weight' => '-9',
        ),
        'block-5' => array(
          'module' => 'block',
          'delta' => '5',
          'region' => 'sidebar_second',
          'weight' => '-8',
        ),
        'views-authorship-block' => array(
          'module' => 'views',
          'delta' => 'authorship-block',
          'region' => 'content',
          'weight' => '2',
        ),
        'disqus-disqus_comments' => array(
          'module' => 'disqus',
          'delta' => 'disqus_comments',
          'region' => 'content',
          'weight' => '4',
        ),
        'widgets-s_socialmedia_share-default' => array(
          'module' => 'widgets',
          'delta' => 's_socialmedia_share-default',
          'region' => 'content',
          'weight' => '10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Articles');
  t('Content Type');
  $export['article_type'] = $context;

  return $export;
}
