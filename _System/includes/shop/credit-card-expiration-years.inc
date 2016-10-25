{% comment -%}
	Usage:
	{% assign displayNumberOfYears = 6 -%}
	{% include '/_System/includes/shop/credit-card-expiration-years.inc' -%}
{% endcomment -%}

{% assign currentYear = globals.site.dateNow | date: "yyyy" %}
{% for i in (0..displayNumberOfYears) -%}
	{% if i == displayNumberOfYears -%}
		{% break %}
	{% else -%}
		{% assign year = currentYear | plus: i %}		
		<option value="{{year}}"{% if year == currentYear %} selected="true"{% endif %}>{{year}}</option>
	{% endif -%}
{% endfor -%}