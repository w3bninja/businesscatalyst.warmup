<div class="pages">
{module_webapps id="{{appID}}" filter="classified" itemId="{{classificationID}}" collection="landing-section" template=""}
{% for item in landing-section.items -%}
	<div class="page" id="{{item.title | downcase}}">
		<div class="container">
			<h1>{{item.Title}}</h1>
			{{item.description}}
		</div>
	</div>
{% endfor -%} 
</div>