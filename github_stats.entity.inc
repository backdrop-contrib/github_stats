<?php
/**
 * @file
 */

/**
 * Custom entity definitions for github_project type.
 */
class GithubProject extends Entity {
  public $id;
  public $github_path = '';
  public $name = '';
  public $repo_created = '';
  public $default_branch = '';
  public $open_issues_count = 0;
  public $release_count = 0;
  public $latest_release_date = '';
  public $latest_release_tag = '';
  public $download_count = 0;
  public $borg_usage_count = NULL;
  public $last_fetched = 0;

  /**
   * Implements EntityInterface::id().
   */
  public function id() {
    return $this->id;
  }

  /**
   * Implements EntityInterface::entityType().
   */
  public function entityType() {
    return 'github_project';
  }

  /**
   * Implements EntityInterface::label().
   */
  public function label() {
    return $this->name;
  }

  /**
   * Implements EntityInterface::uri().
   */
  public function uri() {
    return array(
      'path' => 'github-project/' . $this->id,
      'options' => array(),
    );
  }

  /**
   * Overrides Entity::createAccess().
   */
  public static function createAccess($bundle = NULL, $account = NULL) {
    if (empty($account)) {
      $account = $GLOBALS['user'];
    }

    return user_access('administer github stats', $account);
  }

  /**
   * Overrides Entity::access().
   */
  public function access($op, $account = NULL) {
    if ($op == 'create') {
      return self::createAccess(NULL, $account);
    }
    elseif (!in_array($op, array('view', 'update', 'delete'))) {
      return FALSE;
    }
    if (empty($account)) {
      $account = $GLOBALS['user'];
    }
    if ($op == 'view') {
      return user_access('view github stats', $account) || user_access('administer github stats', $account);
    }
    return user_access('administer github stats', $account);
  }

}

/**
 * Controller class for github_project entities.
 */
class GithubProjectStorageController extends EntityDatabaseStorageController {

  /**
   * Overrides EntityDatabaseStorageController::buildContent().
   *
   * @param GithubProject $project
   *   The GithubProject.
   * @param string $view_mode
   *   Not used in this entity type.
   * @param string|null $langcode
   *   Not used in this entity type.
   */
  public function buildContent($project, $view_mode = 'full', $langcode = NULL) {// phpcs:ignore
    $items = array();
    $properties = get_object_vars($project);
    // @todo This might need some stricter approach because of dynamic
    // properties.
    foreach ($properties as $key => $value_raw) {
      switch ($key) {
        case 'is_active_revision':
        case 'entity_view_prepared':
        case 'content':
          continue 2;

        case 'repo_created':
        case 'latest_release_date':
          if ($value_raw) {
            $time = strtotime($value_raw);
            $value = format_date($time, 'short');
          }
          else {
            $value = '';
          }
          break;

        case 'last_fetched':
          $value = format_date($value_raw, 'short');
          break;

        case 'github_path':
        case 'name':
          $value = check_plain($value_raw);
          break;

        default:
          $value = $value_raw;
      }
      $items[] = '<strong>' . $key . '</strong>: ' . $value;
    }
    $project->content = array(
      '#theme' => 'item_list',
      '#items' => $items,
      '#title' => t('Raw data:'),
    );
  }

}
