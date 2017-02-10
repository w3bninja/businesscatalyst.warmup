{% comment -%}
{% assign appID = "42602" -%}
{% assign classificationID = "669308" -%}


{% assign landingType = "nav" -%}
{% assign landingType = "section" -%}
{% include "/_System/includes/template/landing.inc" -%}
{% endcomment -%}

{% if landingType != null -%}
	{% if landingType == "nav" -%}
		{% include "/_System/includes/template/landing-page/nav.tpl" -%}
	{% elsif landingType == "section" -%}
		{% include "/_System/includes/template/landing-page/section.tpl" -%}
	{% endif -%}
{% else -%}
	{% include "/_System/includes/template/landing-page/nav.tpl" -%}
	{% include "/_System/includes/template/landing-page/section.tpl" -%}
{% endif -%}