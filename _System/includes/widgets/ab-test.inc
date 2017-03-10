{% assign testType = "webapp" -%}
{% capture testValueA -%}A{% endcapture -%}
{% capture testValueB -%}B{% endcapture -%}

{% if testType == "webapp" -%}
	randomizer
	webapp
	{{testValueA}}
	{{testValueB}}
	end randomizer
{% endif -%}