<?php

/**
 * Implements hook_views_data().
 */
function github_stats_views_data() {
  $data['github_stats']['table']['group'] = t('Github stats');
  $data['github_stats']['table']['base'] = array(
    'field' => 'id',
    'title' => t('Github stats'),
    'help' => t('Github stats contains data fetched via Github API'),
  );
  $data['github_stats']['id'] = array(
    'title' => t('ID'),
    'help' => t('Record ID for this repo record.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
     ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['github_stats']['github_path'] = array(
    'title' => t('Github path'),
    'help' => t('Path of the repo on Github.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['github_stats']['name'] = array(
    'title' => t('Project name'),
    'help' => t('Human readable name of the repo.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['github_stats']['repo_created'] = array(
    'title' => t('Repo created'),
    'help' => t('Datetime when this repository has been created on Github.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );
  $data['github_stats']['default_branch'] = array(
    'title' => t('Default branch'),
    'help' => t('Name of the default branch for this repo.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data['github_stats']['open_issues_count'] = array(
    'title' => t('Open issues'),
    'help' => t('Number of open issues on Github.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
     ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['github_stats']['release_count'] = array(
    'title' => t('Releases'),
    'help' => t('Number of releases of this project.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
     ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['github_stats']['latest_release_date'] = array(
    'title' => t('Release date'),
    'help' => t('Datetime of the latest release for this project.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );
  $data['github_stats']['download_count'] = array(
    'title' => t('Downloads'),
    'help' => t('Number of release downloads for this project.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
     ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['github_stats']['borg_usage_count'] = array(
    'title' => t('Usage'),
    'help' => t('Usage number for this project from backdropcms.org.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
     ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['github_stats']['last_fetched'] = array(
    'title' => t('Last fetched'),
    'help' => t('The last time this info has been fetched.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );
  return $data;
}
