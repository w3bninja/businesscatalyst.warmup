{% comment -%}
    {% assign mapName = 'Test Map' -%}
    {% assign pinImage = 'https://maps.google.com/mapfiles/kml/shapes/parking_lot_maps.png' -%}
    {% if this.phone != '' -%}
        {% assign mapPhone = this.phone -%}
    {% endif -%}
    {% assign mapAddress = this.address1 -%}
    {% assign mapCity = this.city -%}
    {% assign mapState = this.state -%}
    {% assign mapZip = this.zipcode -%}
    
    {% assign mapViewType = "s" -%}
        Types:
        s = Static - static.inc
        i = Interactive (Default) - single.inc
        d = Directions - direction.inc
        c = Custom - custom.inc
        m = Multiple Pins - multiple.inc
     
    {% assign mapWidth = "300" -%}
    {% assign mapHeight = "200" -%}
    {% assign mapZoom = "15" -%}
    {% assign mapType = "terrain" -%}
    	Static maps made using: http://staticmapmaker.com/google/
    
    {% assign hideDirections = true -%}
    {% assign mapAddressFull = '' -%}
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
    	<script src="http://maps.google.com/maps?file=api&amp;v=2&amp;sensor=false&amp;key=AIzaSyBD95dE4wxd4xI6hNDNnJ4GIOgAkXdpTz4" type="text/javascript"></script>
    	{% include "/_System/includes/widgets/maps/directions.inc" -%}
    {% elsif mapViewType == "c"  -%}
    	<script type="text/javascript" src="https://maps.googleapis.com/maps/api/js"></script>
    	{% include "/_System/includes/widgets/maps/custom.inc" -%}
    {% elsif mapViewType == "m"  -%}
    	<script type="text/javascript" src="https://maps.googleapis.com/maps/api/js"></script>
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