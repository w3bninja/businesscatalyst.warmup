{%comment-%}
{% assign app_id = "WEBAPP ID" -%}
{% assign groupType = "VALUE TO GROUP BY" -%}
{% assign groupTitle = "h2" -%}
{% capture groupHead %}
<table class="table table-responsive">
    <tr>
    	<th>Item Name</th>
        <th>Address</th>
        <th>Phone</th>
        <th>Fax</th>
        <th>Company</th>
        <th>Email</th>
    </tr>
{% endcapture -%}
{% capture groupFoot %}
</table>
{% endcapture -%}
{% assign groupTemplate = "" -%}
{% assign groupReverse = "reversed" -%}
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

{%comment-%} GROUP BY TEMPLATE {%endcomment-%}
{% if groupTemplate != '' -%}
	{% capture groupTemplateValue -%}template="{{groupTemplate}}"{% endcapture -%}
{% else -%}
	{% assign groupTemplateValue = "" -%}
{% endif -%}


{% if groupReverse == true -%}
	{% for group in groupItems reversed -%}{%comment-%} Groups {%endcomment-%}
		<{{groupTitle | default : "h3" }} class="group-title">{{group}}</{{groupTitle | default : "h3"}}>  
		{{groupHead | default : ""}}
		{% assign groupName = group | convert: "string" | strip -%}
		{% for item in items-to-group.items -%}
			{% assign groupItem = item.state | convert: "string" -%}
			{% if groupItem contains groupName -%}{%comment-%} Grouped Items {%endcomment-%}
				{module_webapps id="{{app_id}}" filter="item" itemId="{{item.itemid}}" {{groupTemplateValue}}}     
			{% endif -%}      
		{% endfor -%}
		{{groupFoot | default : ""}}    
	{% endfor -%}
{% else -%}
	{% for group in groupItems -%}{%comment-%} Groups {%endcomment-%}
		<{{groupTitle | default : "h3" }} class="group-title">{{group}}</{{groupTitle | default : "h3"}}>  
		{{groupHead | default : ""}}
		{% assign groupName = group | convert: "string" | strip -%}
		{% for item in items-to-group.items -%}
			{% assign groupItem = item.state | convert: "string" -%}
			{% if groupItem contains groupName -%}{%comment-%} Grouped Items {%endcomment-%}
				{module_webapps id="{{app_id}}" filter="item" itemId="{{item.itemid}}" {{groupTemplateValue}}}     
			{% endif -%}      
		{% endfor -%}
		{{groupFoot | default : ""}}    
	{% endfor -%}
{% endif -%}
