<?php
/**
 * @file
 * Google Map Styled -  A custom Google layer
 */

/**
 * OpenLayers WMS Layer Type class tweeted for custom Google tiles
 */
class openlayers_layer_type_googlemapstyled extends openlayers_layer_type {
  function __construct($layer = array(), $map = array()) {
    parent::__construct($layer, $map);
    if (isset($this->data)) {
      if (isset($this->data['options']['srs'])) {
        $pts = explode(':', $this->data['options']['srs']);
        $this->data['projection'] = array($pts[1]);
        $this->data['params']['resolutions'] = openlayers_get_resolutions($pts[1]);
        $this->data['params']['projection'] = $this->data['options']['srs'];
        $this->data['params']['maxextent'] =  openlayers_get_extent($pts[1]);
      }
      if (isset($this->data['base_url'])) {
        $this->data['base_urls'][] = $this->data['base_url'];
      }
     if (isset($this->data['base_url2'])) {
        $this->data['base_urls'][] = $this->data['base_url2'];
      }
      $this->data['isBaseLayer'] = $this->data['params']['isBaseLayer'];
      $this->data['maxzoom'] = $this->data['options']['maxzoom'];
      $this->data['googletileparameters'] = $this->data['options']['googletileparameters'];
      $this->data += $this->options_init();
    }
    else {
      $this->data = $this->options_init();
    }
  }

  /**
   * Provide initial values for options.
   */
  function options_init() {
    return array(
      'layer_handler' => 'googlemapstyled',
      'baselayer' => FALSE
    );
  }

  /**
   * Options form which generates layers
   */
  function options_form() {
    return array(
      'base_url' => array(
        '#type' => 'textfield',
        '#description' => t('Server address of where the tiles are hosted. For example, http://mt0.google.com/vt/'),
        '#title' => t('Base URL'),
        '#default_value' => isset($this->data['base_url']) ?
          $this->data['base_url'] : ''
      ),
      'base_url2' => array(
        '#type' => 'textfield',
        '#title' => t('Base URL 2'),
        '#description' => t('Optional second location. Ideal for speeding up browser downloads. For example, http://mt1.google.com/vt/'),
        '#default_value' => isset($this->data['base_url2']) ?
          $this->data['base_url2'] : ''
      ),
        'params' => array(
        'isBaseLayer' => array(
          '#type' => 'hidden',
          '#value' => FALSE,
        ),
            ),

       'options' => array(
        'googletileparameters' => array(
          '#type' => 'textarea',
          '#title' => t('Google tile style'),
          '#description' => t('Using the Google Style wizard at <a href="http://gmaps-samples-v3.googlecode.com/svn/trunk/styledmaps/wizard/index.html">Google Maps API Styled Map Wizard</a>. After you style your map, look at the URL being called for the tiles. Copy/Paste those parameters here'),
          '#default_value' => isset($this->data['options']['googletileparameters']) ?
            $this->data['options']['googletileparameters'] : 'v=apt.116&hl=en-US&src=apiv3&s=G&lyrs=r&apistyle=s.t:33|p.v:off&apistyle=s.t:49|s.e:l|p.v:on|p.l:50|p.s:24,s.t:5|p.v:off,s.t:6|p.v:off,s.t:1|p.v:off,s.t:5|p.v:off,s.t:2|p.v:off'
        ),
       
        //not used, but here to satisfy the sanity check.
       'srs' => array(
          '#type' => 'hidden',
          '#value' => '900913'
      ),
           ),
      'layer_type' => array(
        '#type' => 'hidden',
        '#value' => 'openlayers_layer_type_googlemapstyled'
      )
    );
  }

   /**
   * Render.
   */
  function render(&$map) {
    drupal_add_js(drupal_get_path('module', 'googlemapstyled') .'/includes/layer_types/googlemapstyled.js');
    return $this->options;
  }
}
