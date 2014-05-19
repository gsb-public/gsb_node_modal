<?php

/**
 * @file
 * Contains gsb_node_modal_handler_field_node_link_delete.
 */

/**
 * Provides a node delete link for a modal.
 */
class gsb_node_modal_handler_field_node_link_delete extends views_handler_field_node_link_delete {

  /**
   * {@inheritdoc}
   */
  function render_link($node, $values) {
    if ($link = parent::render_link($node, $values)) {
      // Add the libraries needed for a modal.
      ctools_include('ajax');
      ctools_include('modal');
      ctools_modal_add_js();
      // Add the link class needed.
      $this->options['alter']['link_class'] = 'ctools-use-modal';
      // Customize the path.
      $this->options['alter']['path'] = "gsb-node/nojs/delete/$node->nid";
    }
    return $link;
  }

}
