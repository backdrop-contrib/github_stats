<?php
/**
 * @file
 * Admin form handling for github_stats module.
 */

/**
 * Form callback to create an item.
 */
function github_stats_project_create_form($form, &$form_state) {
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#required' => TRUE,
  );
  $form['github_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Github path'),
    '#required' => TRUE,
    '#attributes' => array(
      'placeholder' => 'backdrop-contrib/example',
    ),
  );
  $form['actions']['#type'] = 'actions';
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save and fetch data'),
  );
  return $form;
}

/**
 * Validation callback for item creation.
 */
function github_stats_project_create_form_validate(&$form, &$form_state) {
  $github_path = $form_state['values']['github_path'];
  $exists = (bool) db_query('SELECT 1 FROM {github_stats} WHERE github_path = :path', array(
    ':path' => $github_path,
  ))->fetchField();
  if ($exists) {
    form_error($form['github_path'], t('A project with the Github path %path already exists.', array(
      '%path' => $github_path,
    )));
  }
}

/**
 * Submission callback for item creation.
 */
function github_stats_project_create_form_submit(&$form, &$form_state) {
  $entity = entity_create('github_project', array(
    'name' => $form_state['values']['name'],
    'github_path' => $form_state['values']['github_path'],
  ));
  $entity->save();
  $id = $entity->id();

  $form_state['redirect'] = 'github-project/' . $id;
  $success = _github_stats_update_data($id, FALSE);
  if ($success) {
    backdrop_set_message(t('Project %name has been created.', array(
      '%name' => $entity->label(),
    )));
  }
  else {
    backdrop_set_message(t('Project %name has been created, but problems occured when fetching data.', array(
      '%name' => $entity->label(),
    )), 'warning');
  }
}

/**
 * Form callback to delete an item.
 */
function github_stats_project_delete_form($form, &$form_state, GithubProject $project) {
  $message = t('Are you sure you want to delete the record for %project? This action cannot be undone.', array(
    '%project' => $project->label(),
  ));
  $form['infotext'] = array(
    '#type' => 'markup',
    '#markup' => '<p>' . $message . '</p>',
  );
  $form['#entity'] = $project;
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Delete'),
    '#attributes' => array('class' => array('button-danger', 'button-primary')),
  );
  $form['actions']['cancel'] = array(
    '#type' => 'link',
    '#title' => t('Cancel'),
    '#href' => "github-project/{$project->id}",
  );
  return $form;
}

/**
 * Submission callback to delete an item.
 */
function github_stats_project_delete_form_submit($form, &$form_state) {
  $name = $form['#entity']->label();
  $form['#entity']->delete();
  $form_state['redirect'] = '<front>';
  backdrop_set_message(t('Record for %name has been deleted', array(
    '%name' => $name,
  )));
}

/**
 * Form callback to update an item.
 */
function github_stats_project_edit_form($form, &$form_state, GithubProject $project) {
  $project_label = $project->label();
  $project_id = $project->id();
  backdrop_set_title(t('Edit @name', array('@name' => $project_label)));
  $form['#entity'] = $project;
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#required' => TRUE,
    '#default_value' => $project_label,
  );
  $form['github_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Github path'),
    '#disabled' => TRUE,
    '#default_value' => $project->github_path,
  );
  $form['actions']['#type'] = 'actions';
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  $form['actions']['submit_fetch'] = array(
    '#type' => 'submit',
    '#value' => t('Fetch fresh data'),
  );
  $form['actions']['delete'] = array(
    '#type' => 'link',
    '#title' => t('Delete'),
    '#href' => "github-project/{$project_id}/delete",
    '#options' => array(
      'query' => isset($_GET['destination']) ? backdrop_get_destination() : array(),
      'attributes' => array(
        'class' => array('button', 'button-secondary', 'form-delete'),
      ),
    ),
  );
  $form['actions']['cancel'] = array(
    '#type' => 'link',
    '#title' => t('Cancel'),
    '#href' => "github-project/{$project_id}",
  );
  return $form;
}

/**
 * Submission callback to update an item.
 */
function github_stats_project_edit_form_submit($form, &$form_state) {
  $project = $form['#entity'];
  $id = $project->id();
  $form_state['redirect'] = "github-project/$id";

  if ($form_state['triggering_element']['#id'] == 'edit-submit-fetch') {
    _github_stats_update_data($id, FALSE);

    backdrop_set_message(t('Fetching fresh data for %name has been attempted.', array(
      '%name' => $project->label(),
    )));
  }
  else {
    $project->name = $form_state['values']['name'];
    $project->save();
    backdrop_set_message(t('Project %name has been saved.', array(
      '%name' => $project->label(),
    )));
  }
}
