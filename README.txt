This module provides access, via the OpenLayers javascript library (http://openlayers.org/) and the OpenLayers Drupal module (http://drupal.org/project/openlayers) to the OpenSpace Ordnance Survey maps (http://openspace.ordnancesurvey.co.uk/) which are specific to the UK allowing you to use the maps on your site.

While the Ordnance Survey offers its own javascript library and APIs to access the maps this module makes it possible to just stay within the latest (2.8) OpenLayer library so you can easily use the OpenLayers module.

#Requirements
Makes sure you install the OpenLayers module and that is working ok with default maps before proceed to installing the OpenSpace module.

#Installation
Upload the module to the appropriate Drupal directory and activate.

To use the OpenSpace maps you first need to obtain an API key by visiting the OpenSpace website (http://openspace.ordnancesurvey.co.uk/)

Subsequently via the OpenLayers interface add the OpenSpace Ordnance Layer by visiting 'http://test.istos.it/openspace/admin/build/openlayers/layers/add'

Set the key by visiting 'admin/build/openlayers/layers/settings', unless you know what you are doing you don't really need to change the other settings.

#Usage
To use the OpenSpace layers add a preset at 'admin/build/openlayers/presets/add' and select the 27700 projection in Layers & Styles which will give you the OpenSpace layer option. 

#Disclaimer
This implementation should be considered experimental and is not yet ready for use on production sites. 



# Authors/Credits
The module was financed by Brightlemon Ltd (http://www.brightlemon.com)
* [istos] (http://drupal.org/user/200188)
* [johngriffin] (http://drupal.org/user/282666)
