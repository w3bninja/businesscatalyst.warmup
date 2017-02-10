<ul class="landing-nav nav nav-pills nav-justified">
	{module_webapps id="{{appID}}" filter="classified" itemId="{{classificationID}}" collection="landing-nav" template=""}
	{% for item in landing-nav.items -%}
		<li><a href="#{{item.title | downcase}}" data-target="#{{item.title | downcase}}">{{item.title}}</a></li>
	{% endfor -%}         
</ul>