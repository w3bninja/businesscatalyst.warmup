{% comment -%}
    {% assign mapAPI = "AIzaSyDNE12LS3cPYeL_f6gjV5GYRFh5Dez_Isk" -%} - API Key: https://developers.google.com/maps/documentation/javascript/get-api-key
    
    SETTINGS
    {% assign mapAddress = '' -%}
    {% assign mapCity = '' -%}
    {% assign mapState = '' -%}
    {% assign mapZip = '' -%}
    
    {% assign mapAddressFull = '' -%} - Full Address Override
    
    {% assign hideDirections = true -%}
    {% assign mapViewType = '' -%}
        Types:
        s = Static - static.inc
        i = Interactive (Default) - single.inc
        d = Directions - direction.inc
        c = Custom - custom.inc
        m = Multiple Pins - multiple.inc
    
    STANDARD
    {% assign mapWidth = "300" -%}
    {% assign mapHeight = "200" -%}
    {% assign mapZoom = "15" -%}
    {% assign mapType = "terrain" -%} - Static maps made using: http://staticmapmaker.com/google/
    
    ADVANCED(Uses the API)
    {% assign mapStyle = true -%}
    
    MULTIPLE
    {% assign mapAppID = '' -%}
    {% assign mapResultsPins = true -%}
    
    CUSTOM
    {% assign mapPinName = 'Test Map' -%}
    
    Note: 
    - Google Map Styles - https://snazzymaps.com 
    - /_System/includes/widgets/maps/custom/map-style.inc
    
    DIRECTIONS (Uses v2)
    {% assign mapDirectionsStart = '' -%}
    {% assign mapDirectionsEnd = '' -%}
    
    
    {% include "/_System/includes/widgets/map.inc" -%}
{% endcomment -%}

{% if mapAddressFull == '' -%}
	{% capture addressLink -%}{{mapAddress | split: " " | join: "+"}},{% if this.address2 != '' -%}{{this.address2 | split: " " | join: "+"}},{% endif -%}{{mapCity | split: " " | join: "+"}},{{mapState | split: " " | join: "+"}}+{{mapZip | split: " " | join: "+"}}{% endcapture -%}
{% else -%}
	{% capture addressLink -%}{{mapAddressFull | split: " " | join: "+"}}{% endcapture -%}
{% endif -%}

<div class="map">
	{% if mapViewType == "s" -%}
		{% include "/_System/includes/widgets/maps/static.inc" -%}
    {% elsif mapViewType == "i"  -%}
    	{% include "/_System/includes/widgets/maps/interactive.inc" -%}
    {% elsif mapViewType == "d"  -%}
	    {% assign hideDirections = true -%}
    	{% include "/_System/includes/widgets/maps/directions.inc" -%}
    {% elsif mapViewType == "c"  -%}
    	{% assign mapStyle = true -%}
    	{% include "/_System/includes/widgets/maps/custom.inc" -%}
    {% elsif mapViewType == "m"  -%}
    	{% assign hideDirections = true -%}
    	{% include "/_System/includes/widgets/maps/multiple.inc" -%}
    {% else -%}
    	{% include "/_System/includes/widgets/maps/interactive.inc" -%}
    {% endif -%}
</div>


{% if hideDirections != true -%}
<div class="text-right">
<a href="https://www.google.com/maps/dir//{{addressLink | split: "," | join: ",+"}}/" target="_blank"><small>Get Directions</small></a>
</div>
{% endif -%}