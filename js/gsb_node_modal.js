(function ($) {

/**
 * Provides an AJAX command to reload all views on the page.
 */
Drupal.ajax.prototype.commands.gsb_node_modal_reload = function () {
  // Ensure there are AJAX views on the page.
  if (!Drupal.views || !Drupal.views.instances) {
    return;
  }
  // Loop through all views on the page.
  for (var dom_id in Drupal.views.instances) {
    if (Drupal.views.instances.hasOwnProperty(dom_id)) {
      // Copy the AJAX views instance, and assign our own custom event.
      var $view = $.extend(true, {}, Drupal.views.instances[dom_id]);
      $view.element_settings.event = 'gsb_node_modal_reload_event';

      // Create a new AJAX element, and trigger it to refresh the view.
      var ajax = new Drupal.ajax(false, $view, $view.element_settings);
      $(ajax.element).trigger('gsb_node_modal_reload_event');
    }
  }
};

}(jQuery));
