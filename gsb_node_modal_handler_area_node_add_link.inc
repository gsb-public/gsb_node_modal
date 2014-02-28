<?php

/**
 * @file
 * Contains gsb_node_modal_handler_area_node_add_link.
 */

/**
 * Provides a node add link for a modal.
 */
class gsb_node_modal_handler_area_node_add_link extends views_handler_area {

  /**
   * {@inheritdoc}
   */
  public function option_definition() {
    $options = parent::option_definition();
    $options['bundle'] = array(
      'default' => '',
    );
    $options['text'] = array(
      'default' => '',
      'translatable' => TRUE,
    );
    return $options;
  }

  /**
   * {@inheritdoc}
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['label']['#access'] = FALSE;
    $form['empty']['#access'] = FALSE;
    $form['bundle'] = array(
      '#type' => 'select',
      '#title' => t('Content type'),
      '#description' => t('The content type this link should add.'),
      '#options' => node_type_get_names(),
      '#default_value' => $this->options['bundle'],
    );
    $form['text'] = array(
      '#type' => 'textfield',
      '#title' => t('Link text'),
      '#description' => t('The text to use for this link.'),
      '#default_value' => $this->options['text'],
    );
    return $form;
  }

  /**
   * {@inheritdoc}
   */
  public function admin_summary() {
    if ($this->isLinkConfigured()) {
      $label = $this->options['text'];
    }
    else {
      $label = t('Not configured');
    }
    return $label;
  }

  /**
   * {@inheritdoc}
   */
  public function render($empty = FALSE) {
    if ($this->isLinkConfigured()) {
      return gsb_node_modal_add_link($this->options['text'], $this->options['bundle']);
    }
  }

  /**
   * Indicates if the link is configured.
   *
   * @return bool
   */
  protected function isLinkConfigured() {
    return !empty($this->options['bundle']) && !empty($this->options['text']);
  }

}
