<?php
/**
 * @file
 * Provide adaptions for the entityreference selection handler.
 */

/**
 * Override for the github_project entity type.
 */
class EntityReferenceSelectionHandlerGeneric_github_project extends EntityReferenceSelectionHandlerGeneric {

  protected $label_key = 'name';

}
