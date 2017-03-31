<ul class="landing-nav nav nav-pills nav-justified">
	{module_webapps id="{{appID}}" filter="classified" sortType="weightreverse" itemId="{{classificationID}}" collection="landing-nav" template=""}
	{% for item in landing-nav.items -%}
		<li><a href="#{{item.title | downcase|replace:' ','-'}}" data-target="#{{item.title | downcase|replace:' ','-'}}">{{item.name}}</a></li>
	{% endfor -%}         
</ul>