{% assign start_date_hour = {{this.["Start Time"] | slice: 0, 2 }} -%}
{% assign start_date_hour = {{start_date_hour | replace: ':', '' }} -%}
{% capture start_date_hour -%} 
	{% if this.["Start Time AM/PM"] == 'PM' -%}
		{{start_date_hour | plus: 12}}
	{% else -%}
		{{start_date_hour}}
	{% endif -%}
{% endcapture -%}

{% assign start_date_hour = {{start_date_hour | strip }} -%}
{% assign start_date_minute = {{this.["Start Time"] | slice: -2, 2 | strip }} -%}
{% capture start_time | strip %}{{start_date_hour}}:{{start_date_minute}}{% endcapture -%}
	{% capture start_date_time | strip %}{{start_date_hour}}:{{start_date_minute}}{% endcapture -%}
{% assign start_date = {{this.["Start Date"] | date: "yyyy-%M-dd"}} -%}


{% assign end_date_hour = {{this.["End Time"] | slice: 0, 2 }} -%}
{% assign end_date_hour = {{end_date_hour | replace: ':', '' }} -%}
{% capture end_date_hour %} 
	{% if this.["End Time AM/PM"] == 'PM' -%}
		{{end_date_hour | plus: 12}}
	{% else -%}
		{{end_date_hour}}
	{% endif -%}
{% endcapture -%}

{% assign end_date_hour = {{end_date_hour | strip }} -%}
{% assign end_date_minute = {{this.["End Time"] | slice: -2, 2 | strip }} -%}
{% capture end_time | strip %}{{end_date_hour}}:{{end_date_minute}}{% endcapture -%}
	{% capture end_date_time | strip %}{{end_date_hour}}:{{end_date_minute}}{% endcapture -%}
{% assign end_date = {{this.["End Date"] | date: "yyyy-%M-dd"}} -%}



{% assign dows = this.["Days"] | split: ',' -%}
{% capture dow_array -%}
	{% for dow in dows -%}
		{% case dow -%} 
			{% when 'Monday' -%}
				1,
			{% when 'Tuesday' -%}
				2,
			{% when 'Wednesday' -%}
				3,
			{% when 'Thursday' -%}
				4,
			{% when 'Friday' -%}
				5,
			{% when 'Saturday' -%}
				6,
			{% when 'Sunday' -%}
				0,
		{% endcase -%}
	{% endfor -%}
{% endcapture -%}
{% assign dow_array = dow_array | strip_newlines -%}
{% assign dow_array = {{dow_array | replace: '	', ''}} -%}
{% assign dow_array = dow_array | strip -%}
{% assign dow_array_size = {{dow_array | size}} | minus: 1 -%}
{% assign dow_array = dow_array | slice: 0, dow_array_size -%}

					{
						title: "{{this.name}}",
						url: "{{this.url}}",
                        start: "{{start_date}}T{{start_time}}:00"{% if this.["End Time"] != '' -%},
                        	end: "{{end_date}}"{% endif -%}{% if dow_array != '' -%},
                        	dow: "[ {{dow_array}} ]"{% endif -%}
					},