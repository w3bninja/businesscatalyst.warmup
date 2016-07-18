{% assign segments = parentSegments.size | minus: 1 -%}
{% if segments == 0 -%}
	{% assign segments = 1 -%}
{% endif -%}
{% assign firstFound = false -%}
<ul>
	{% for first in menu.items -%}
		{% assign parentURL = '' -%}
		{% for segment in parentSegments | limit: segments -%}
			{% assign parentURL = parentURL | append: '/' | append: segment -%}
			{% if first.url == parentURL or first.url == pageaddress %}
				{% if first.items -%}
					{% assign firstFound = true -%}
					<li class="leveltitle {{first.css}}">
						<a href="{{first.url}}"><span class="icon"><img {% if first.css contains 'svg' -%}data-state="{{first.cssSelected}}" data-src="{{first.image}}" class="iconic iconic-sm"{% else -%}src="{{first.image}}"{% endif -%} alt="{{first.label}}" /></span>{{first.label}}</a>
						{% if first.items -%}
							<ul>
								{% for second in first.items -%}
									<li class="{{second.css}}"><a href="{{second.url}}">{{second.label}}</a></li>
								{% endfor -%}
							</ul>
						{% endif -%}
					</li>
					{% break -%}
				{% endif -%}
			{% endif -%}
		{% endfor -%}
		{% if firstFound == true -%}{% break -%}{% endif -%}
	{% endfor -%}
</ul>