
/**
 * Openlayer layer handler for TMS layer
 */
Drupal.openlayers.layer.googlemapstyled = function (title, map, options) {
  
  

var options2 = {
   maxExtent: new OpenLayers.Bounds(-20037508.3427892,-20037508.3427892,20037508.3427892,20037508.3427892), 
   numZoomLevels:18,
   maxResolution:156543.0339, 
   units:'m',
   isBaseLayer: options.isBaseLayer,
   projection: 'EPSG:' + options.projection,
   displayProjection: new OpenLayers.Projection("EPSG:4326"),
   type: 'png'
};

var googletileparameters = options.googletileparameters;
var base_urls = options.base_urls;

options2.getURL = function (bounds) {
    var res = this.map.getResolution();
    var x = Math.round ((bounds.left - this.maxExtent.left) / (res * this.tileSize.w));
    var y = Math.round ((this.maxExtent.top - bounds.top) / (res * this.tileSize.h));
    var z = this.map.getZoom();
    
    var path = "x=" + x + "&y=" + y + "&z=" + z + "&" + googletileparameters;
     var url = base_urls;
    if (url instanceof Array) {
        url = this.selectUrl(path, url);
    }

    return url + path;
}

//this.url = options.base_urls;
//options2['getURL'] = options['getURL'] + options.googletileparameters;
    var layer = new OpenLayers.Layer.TMS(title,options.base_urls,options2);
    return layer;
};

