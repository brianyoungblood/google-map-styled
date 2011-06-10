1) Install, drop this folder in your module directory (ie sites/all/modules or sites/default/modules) and enable it as you would any other module. This module requires <a href="http://drupal.org/project/openlayers">OpenLayers</a> module.

2) Style a map using <a href="http://gmaps-samples-v3.googlecode.com/svn/trunk/styledmaps/wizard/index.html">Google Maps API Styled Map Wizard</a>

3) Use Firebug's net tab, or similar method to view the URL being used to get the Google tiles as you style them with the wizard. A <a href="http://mt1.google.com/vt/x=266&y=407&z=10&v=apt.116&hl=en-US&src=apiv3&s=G&lyrs=r&apistyle=s.t:33|p.v:off&apistyle=s.t:49|s.e:l|p.v:on|p.l:50|p.s:24,s.t:5|p.v:off,s.t:6|p.v:off,s.t:1|p.v:off,s.t:5|p.v:off,s.t:2|p.v:off">simple example</a> might just remove a lot of features.

4) Add a new Google Map Styled layer from the OpenLayers add layer interface in Drupal.

If you have a tile URL like this one:
	http://mt1.google.com/vt/x=266&y=407&z=10&v=apt.116&hl=en-US&src=apiv3&s=G&lyrs=r&apistyle=s.t:33|p.v:off&apistyle=s.t:49|s.e:l|p.v:on|p.l:50|p.s:24,s.t:5|p.v:off,s.t:6|p.v:off,s.t:1|p.v:off,s.t:5|p.v:off,s.t:2|p.v:off


Your base path would be:

	http://mt1.google.com/vt/

Google tile style:

	v=apt.116&hl=en-US&src=apiv3&s=G&lyrs=r&apistyle=s.t:33|p.v:off&apistyle=s.t:49|s.e:l|p.v:on|p.l:50|p.s:24,s.t:5|p.v:off,s.t:6|p.v:off,s.t:1|p.v:off,s.t:5|p.v:off,s.t:2|p.v:off



Other things worth noting..
Plans to decode the style information given when clicking the Show JSON button would be the next logical major update for this module. Assuming this module appears useful.

The javascript code was based on these examples:
http://docs.openlayers.org/library/spherical_mercator.html

Module code was based reviewing other modules like Mapbox and the OpenLayers module itself.
