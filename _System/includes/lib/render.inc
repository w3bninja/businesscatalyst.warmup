
{% comment -%}

	NAME: Render
	VERSION: 0.1
	LAST UPDATED: July 11, 2015
	DESCRIPTION: Renders if a variable or parameter is true.
	RIGHTS: This library item may NOT be used, shared, replicated, sold, or modified without written permission from Author.
	AUTHOR: Scott B Reynolds - http://www.thrise.com/about.htm
	
	INSTRUCTIONS:
	
	--------------------------------------------
	
	#1 DEFAULT
		Content will be hidden unless the "show" parameter in the url is assigned to "true" (ex. http://test.com?show=true):
		
		{% capture renderContent -%} Your content here. This renders if show=true is in url (as a parameter) {% endcapture -%}
        {% include "/_System/includes/lib/render.inc" -%}
	
	--------------------------------------------
	
	#2 DEFAULT WITH ALTERNATIVE CONTENT
		Alternative content will render unless the "show" parameter in the url is assigned to "true" (ex. http://test.com?show=true):
		
		{% capture renderContent -%} Your content here. This renders if show=true is in url (as a parameter) {% endcapture -%}
		{% capture renderContentAlt -%} Your content here. This renders if show=true is NOT in url (as a parameter) {% endcapture -%}
        {% include "/_System/includes/lib/render.inc" -%}
	
	--------------------------------------------
	
	#3 CUSTOM VARIABLE NAME/VALUE
		Customize the variable name and/or value.
		- Instead of the VARIABLE "show", assign render-variableName to a custom name.
		- Instead of the VALUE "true", assign render-variableValue to a custom value.
		
		{% capture renderContent -%} Your content here. This renders if your custom name and value is in url (as a parameter) {% endcapture -%}
        {% assign render-variableName = "xxx" -%}
        {% assign render-variableValue = "yyy" -%}
        {% include "/_System/includes/lib/render.inc" -%}
	
	--------------------------------------------
	
	#4 OVERRIDE URL PARAMETER
		Instead of using a parameter in the url, trigger the content by assigning the value on the page.
		- The example below will render the content because the render-variable is assigned to "true" (matching the variableValue).

        {% assign render-variable = "true" -%}
		{% capture renderContent -%} Your content here. This renders if your custom name and value is in url (as a parameter) {% endcapture -%}
        {% include "/_System/includes/lib/render.inc" -%}

{% endcomment -%}

{% assign renderContentAlt = renderContentAlt | default: "" -%}
{% assign render-variableName = render-variableName | default: "show" -%}
{% assign render-variableValue = render-variableValue | default: "true" -%}
{% assign render-variable = render-variable | default: globals.get.[render-variableName] -%}


{% if render-variable == render-variableValue -%}
	{{renderContent}}
{% else -%}
	{{renderContentAlt}}
{% endif -%}
	







