<?php
// $Id$

/**
 * @file
 * OpenSpace Layer Type
 */

/**
 * OpenLayers OpenSpace Layer Type class
 */
class openlayers_layer_type_openspace extends openlayers_layer_type {
  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'serverResolutions' => array( 2500, 1000, 500, 200, 100, 50, 25, 10, 5, 2, 1 ),
      'maxExtent' => array( 0, 0, 800000, 1300000 ),
      'projection' => array('27700'),
      'key' => variable_get('openlayers_layers_openspace_api', ''),
      'base_url' => variable_get('openspace_server', ''),
      'tile_server' => variable_get('openspace_ts', ''),
      'osm' => FALSE,
      'baselayer' => TRUE,
      'layer_handler' => 'openspace'
    );
  }

  /**
   * Options form which generates layers
   */
  function options_form() {
     return array(
      'layername' => array(
        '#type' => 'textfield',
        '#title' => t('Layer Name'),
        '#default_value' => isset($this->data['layername']) ?
          $this->data['layername'] : ''
      ),
      'layer_type' => array(
        '#type' => 'hidden',
        '#value' => 'openlayers_layer_type_openspace'
      ),
      $warning
    );
  }
  
  
  /**
   * Layer-type-wide settings form
   */
  function settings_form() {
    return array(
      'openlayers_layers_openspace_api' => array(
        '#type' => 'textfield',
        '#title' => t('OpenSpace API Key'),
        '#default_value' => variable_get('openlayers_layers_openspace_api', ''),
        '#description' => t('<a href="@openspace">Get an OpenSpace API Key</a>',
          array('@openspace' => 'http://openspace.ordnancesurvey.co.uk/'))
      ),
      'openspace_server' => array(
        '#type' => 'textfield',
        '#title' => t('OpenSpace Server'),
        '#default_value' => isset($this->data['openspace_server']) ?
          $this->data['openspace_server'] : 'http://openspace.ordnancesurvey.co.uk/osmapapi/'
      ),
      'openspace_ts' => array(
        '#type' => 'textfield',
        '#title' => t('OpenSpace Tile Server Path'),
        '#default_value' => isset($this->data['openspace_ts']) ?
          $this->data['openspace_ts'] : 'ts'
      ),
      'proj4js' => array(
        '#type' => 'textfield',
        '#title' => t(''),
        '#description' => t('JavaScript library that provides methods for coordinate transformations between map projections and longitude/latitude - the magic sauce that allows us to draw points on the map'),
        '#default_value' => isset($this->data['proj4js']) ?
          $this->data['proj4js'] : 'http://proj4js.org/lib/proj4js-compressed.js'
      ),
    );
  }
  
  

  /**
   * Render.
   */
  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'openspace') . '/includes/layer_types/openspace.js');
    drupal_set_html_head('<script src="' . check_url(variable_get('proj4js', 'http://proj4js.org/lib/proj4js-compressed.js')) . '"type="text/javascript"></script>');
    return $this->options;
  }
}
