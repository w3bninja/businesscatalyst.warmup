{% capture tag_selected -%}{module_url param="tag"}{% endcapture -%}
{% assign show = '' -%}
{% if tag_selected != '' -%}
	<h3 class="alert alert-info">Tag: {{tag_selected}}</h3>
{% endif -%}

{module_webapps id="{{webapp_id}}" filter="all" collection="media" template=""}
{% for item in media.items -%}
	{% assign image = item.['Thumbnail Image'] -%}
	{% if image == '' -%}
		{% assign image = '/assets/img/x.png' -%}
	{% endif -%}

	{% if tag_selected != '' -%}
		{% assign tags = item.['Tags'] | strip | downcase -%}
		
		{% if tags != '' -%}
			{% assign tags = tags | remove:"'" | remove:'"' | remove:'-' -%}
			{% assign tags = tags | replace:' ,', ',' | replace:', ', ',' | replace:' ', '+' -%}
			{% assign tags = tags | split:',' -%}
			{% assign tag_selected = tag_selected | replace:' ', '+' -%}
				
			{% comment -%}<pre>{{tags | json}}</pre>{% endcomment -%}
			{% for item in tags -%}
				{% if item == tag_selected -%}
					{% assign show = true -%}
				{% endif -%}
			{% endfor -%}
		{% else -%}
			{% assign show = false -%}
		{% endif -%}
	{% else -%}
		{% assign show = true -%}
	{% endif -%}
	
	{% if show == false -%}
		{% continue -%}
	{% endif -%}

	<a href="{{item.['File Path']}}" class="col-sm-3 item">
		<img src="{{image}}?Action=thumbnail&Width=270&Height=365&algorithm=fill_proportional" class="img-responsive">
		<h4>{{item.['Name']}}</h4>
	</a>

	{% assign show = '' -%}
{% endfor -%}