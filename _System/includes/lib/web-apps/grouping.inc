{%comment-%}
{% assign app_id = "WEBAPP ID" -%}
{% assign groupType = "VALUE TO FILTER BY" -%}
{% include "/_System/includes/lib/web-apps/grouping.inc" -%}
{%endcomment-%}

{module_webapps render="collection" id="{{app_id}}" filter="all" collection="items-to-group" template=""}

{%comment-%} GROUP BY {%endcomment-%}

{%comment-%}Create Grouping Array{%endcomment-%}
{% capture groupList -%}{% for item in items-to-group.items -%}{% if item.[groupType] != '' -%}{% assign itemGroup = item.[groupType] -%}{{itemGroup | convert: "string" | strip}}{% if forloop.last == false -%},{% endif -%}{% endif -%}{% endfor -%}{% endcapture -%}

{%comment-%}Remove Duplicates{%endcomment-%}
{% assign array = groupList | strip | split: ',' -%}
{% assign tags = array[1] -%}
{% for item in array -%}{% unless tags contains item -%}{% capture tags %}{{ tags }},{{ item }}{% endcapture -%}{% endunless -%}{% endfor -%}
{% assign groupItems = tags | convert: "string" | split: "," | sort -%}

{%comment-%} END GROUP BY {%endcomment-%}

{%comment-%} LAYOUT {%endcomment-%}
{%comment-%}
{% for group in groupItems -%}
	<h3>{{group}}</h3>
    {% assign groupName = group | convert: "string" | strip -%}
    {% for item in items-to-group.items -%}
    	{% assign groupItem = item.state | convert: "string" -%}
        
        {% if groupItem contains groupName -%}
        
        
        
        <div class="location">
        	<a href="{{item.folder}}/home" class="link"><i class="fa fa-chevron-right"></i></a> 
 			<div class="row">
                <div class="col-md-4">
                    <div class="location-image">
                    {% if item.image != '' %}<img src="{{item.image}}?Action=thumbnail&Width=200&algorithm=fill_proportional" class="img-responsive">{% else -%}<img src="/img/x.png?Action=thumbnail&Width=200&Height=70&algorithm=fill_proportional" class="img-responsive">{% endif %}
                    </div>
                </div>
                <div class="col-md-8">
                    <div class="location-text">
                        {% if item.folder != '' -%}
                            <h4><a href="{{item.folder}}/home">{{item.name}}</a></h4>
                        {% else -%}
                            <h4>{{item.name}}</h4>
                        {% endif -%}
                        {% if item.address1 != '' -%}
                            <div class="address">
                            {{item.address1}}, {% if item.address2 != '' -%}{{item.address2}},{% endif -%}
                            {{item.city}}, {{item.state}} {{item.zipcode}}
                            </div>
                            {% capture addressLink -%}{{item.address1 | split: " " | join: "+"}},{% if item.address2 != '' -%}{{item.address2 | split: " " | join: "+"}},{% endif -%}{{item.city | split: " " | join: "+"}},{{item.state | split: " " | join: "+"}}+{{item.zipcode | split: " " | join: "+"}}{% endcapture -%}
                            <div class="directions pull-left"><i class="fa fa-map-marker"></i> <a href="https://www.google.com/maps/dir/{{addressLink | split: "," | join: ",+"}}//" target="_blank">Get Directions</a></div>
                        {% endif -%}
                        {% if item.phone != '' -%}
                            <div class="phone pull-left"><i class="fa fa-phone"></i> {{item.phone}}</div>
                        {% endif -%}
                         
                    </div>
                </div>
            </div>
        </div>
        {% endif -%}
    {% endfor -%}
    <hr>
{% endfor -%}
{%endcomment-%}