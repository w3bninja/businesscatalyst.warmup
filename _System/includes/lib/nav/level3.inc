{% assign segments = parentSegments.size | minus: 1 -%}
{% assign firstFound = false -%}
<ul>
	{% for first in menu.items -%}
		{% assign parentURL = '' -%}
		{% for segment in parentSegments | limit: segments -%}
			{% assign parentURL = parentURL | append: '/' | append: segment -%}
			{% if first.url == parentURL and first.items -%}
				{% assign firstFound = true -%}
				{% for second in first.items -%}
					{% assign parentURL = '' -%}
					{% assign segments = segments | plus: 1 -%}
					{% for segment in parentSegments | limit: segments -%}
						{% assign parentURL = parentURL | append: '/' | append: segment -%}
						{% if second.url == parentURL -%}
							{% if second.items or second.label == 'SDK' -%}
								<li class="leveltitle">
									<span>{{second.label}}</span>
									{% if second.items or second.label == 'SDK' -%}
										<ul>
											{% for second in second.items -%}
												<li class="{{second.css}}"><a href="{{second.url}}"> {% if second.image != '' -%}<span class="icon"><img {% if second.css contains 'svg' -%}data-state="{{second.cssSelected}}" data-src="{{second.image}}" class="iconic iconic-sm"{% else -%}src="{{second.image}}"{% endif -%} alt="{{second.label}}" /></span>{% endif -%}{{second.label}}</a></li>
											{% endfor -%}
											{% if second.label == 'SDK' -%}
												{module_json json="/_System/Apps/bcpie-sdk/public/sdk.json" collection="properties" template=""}
												{% capture nav -%}
													{% include '/_System/Includes/library/sdk/nav.inc' %}
												{% endcapture -%}
												{% assign nav = nav | trim -%}
												{{nav}}
											{% endif -%}
										</ul>
									{% endif -%}
								</li>
							{% endif -%}
							{% break -%}
						{% endif -%}
					{% endfor -%}
				{% endfor -%}
				{% break -%}
			{% endif -%}
		{% endfor -%}
		{% if firstFound == true -%}{% break -%}{% endif -%}
	{% endfor -%}
</ul>