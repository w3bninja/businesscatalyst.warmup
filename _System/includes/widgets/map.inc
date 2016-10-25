{% comment -%}
{% assign mapName = this.name -%}
{% if this.phone != '' -%}
    {% assign mapPhone = this.phone -%}
{% endif -%}
{% assign mapAddress = this.address1 -%}
{% assign mapCity = this.city -%}
{% assign mapState = this.state -%}
{% assign mapZip = this.zipcode -%}

{% assign mapViewType = "s" -%}
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
	<img src="http://maps.googleapis.com/maps/api/staticmap?center={{addressLink | split: "," | join: ",+"}}&zoom={{mapZoom | default:'15'}}&scale=false&size={{mapWidth | default:'300'}}x{{mapHeight | default:'200'}}&maptype={{mapType| default:'roadmap'}}&format=png&visual_refresh=true&markers=size:mid%7Ccolor:0xff0000%7Clabel:%7C{{addressLink | split: "," | join: ",+"}}" class="img-responsive">
    {% else -%}
    <iframe src="http://maps.google.com/maps?q={{addressLink | split: "," | join: ",+"}}&output=embed" width="100%" height="{{mapHeight | default:'200'}}" frameborder="0" style="border:0" allowfullscreen></iframe>
    {% endif -%}
</div>


{% if hideDirections != true -%}
<div class="text-right">
<a href="https://www.google.com/maps/dir//{{addressLink | split: "," | join: ",+"}}/" target="_blank"><small>Get Directions</small></a>
</div>
{% endif -%}