{% comment -%}
{% capture stateList -%}AL,LA,GA,WA,TN,NB,FL{% endcapture -%}
{% include "/_System/includes/lib/state-switcher.inc" -%}
{% endcomment -%}
{% assign states = stateList | split:','; -%}
{% capture stateItem -%}
{% for state in states -%}
	{% case state -%}
	  	{% when 'AL' -%}Alabama
		{% when 'AK' -%}Alaska
		{% when 'AZ' -%}Arizona
		{% when 'AR' -%}Arkansas
		{% when 'CA' -%}California
		{% when 'CO' -%}Colorado
		{% when 'CT' -%}Connecticut
		{% when 'DE' -%}Delaware
		{% when 'FL' -%}Florida
		{% when 'GA' -%}Georgia
		{% when 'HI' -%}Hawaii
		{% when 'ID' -%}Idaho
		{% when 'IL' -%}Illinois
		{% when 'IN' -%}Indiana
		{% when 'IA' -%}Iowa
		{% when 'KS' -%}Kansas
		{% when 'KY' -%}Kentucky
		{% when 'LA' -%}Louisiana
		{% when 'ME' -%}Maine
		{% when 'MD' -%}Maryland
		{% when 'MA' -%}Massachusetts
		{% when 'MI' -%}Michigan
		{% when 'MN' -%}Minnesota
		{% when 'MS' -%}Mississippi
		{% when 'MO' -%}Missouri
		{% when 'MT' -%}Montana
		{% when 'NE' -%}Nebraska
		{% when 'NV' -%}Nevada
		{% when 'NH' -%}New Hampshire
		{% when 'NJ' -%}New Jersey
		{% when 'NM' -%}New Mexico
		{% when 'NY' -%}New York
		{% when 'NC' -%}North Carolina
		{% when 'ND' -%}North Dakota
		{% when 'OH' -%}Ohio
		{% when 'OK' -%}Oklahoma
		{% when 'OR' -%}Oregon
		{% when 'PA' -%}Pennsylvania
		{% when 'RI' -%}Rhode Island
		{% when 'SC' -%}South Carolina
		{% when 'SD' -%}South Dakota
		{% when 'TN' -%}Tennessee
		{% when 'TX' -%}Texas
		{% when 'UT' -%}Utah
		{% when 'VT' -%}Vermont
		{% when 'VA' -%}Virginia
		{% when 'WA' -%}Washington
		{% when 'WV' -%}West Virginia
		{% when 'WI' -%}Wisconsin
		{% when 'WY' -%}Wyoming
	  {% else -%}
	  {{state}}
	{% endcase -%}
{% endfor -%}
{% endcapture -%}
{{stateItem | strip}}