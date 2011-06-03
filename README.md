Use Firebug's net tab, or similar method to view the URL being used to get the Google tiles as you style them with the wizard. A <a href="http://mt1.google.com/vt/x=266&y=407&z=10&v=apt.116&hl=en-US&src=apiv3&s=G&lyrs=r&apistyle=s.t:33|p.v:off&apistyle=s.t:49|s.e:l|p.v:on|p.l:50|p.s:24,s.t:5|p.v:off,s.t:6|p.v:off,s.t:1|p.v:off,s.t:5|p.v:off,s.t:2|p.v:off">simple example</a> might just remove a lot of features.

After styling a map you might have a tile URL like:

	http://mt1.google.com/vt/x=266&y=407&z=10&v=apt.116&hl=en-US&src=apiv3&s=G&lyrs=r&apistyle=s.t:33|p.v:off&apistyle=s.t:49|s.e:l|p.v:on|p.l:50|p.s:24,s.t:5|p.v:off,s.t:6|p.v:off,s.t:1|p.v:off,s.t:5|p.v:off,s.t:2|p.v:off</code>

When adding your Google Map Styled layer, it would be:

Base path:

	http://mt1.google.com/vt/</code>

Google tile style:

	v=apt.116&hl=en-US&src=apiv3&s=G&lyrs=r&apistyle=s.t:33|p.v:off&apistyle=s.t:49|s.e:l|p.v:on|p.l:50|p.s:24,s.t:5|p.v:off,s.t:6|p.v:off,s.t:1|p.v:off,s.t:5|p.v:off,s.t:2|p.v:off</code>

Plans to decode the style information given when clicking the Show JSON button would be the next logical major update for this module. Assuming this module appears useful.

The javascript code was based on these examples:
http://docs.openlayers.org/library/spherical_mercator.html

Module code was based reviewing other modules like Mapbox and the OpenLayers module itself.
