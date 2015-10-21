
{% comment --------------------------%}

    Name: Rolodex List
    Version: 0.1.0
    Author: Dave Haggblad - http://www.digitalinkmultimedia.com/about
    Last Updated: Thursday, June 11, 2015
    Rights: Commercial use requires one-time purchase of accompanying video course 
    				(http://thri.se/liquidlessons)
    
		Description:
		-- provides Rolodex Style output for a given web app.
		-- optionally add custom template, adjust sort order, and customize the Rolodex 
    
    Required:
		-- upload this include file to your website, we suggest in the following location
				/_System/includes/lib/web-apps/rolodex-output.inc

		-- Copy and paste the following lines where you want the rolodex and webapp output to go. Then update ro-WebappID with your webappâ€™s id number

		{% assign ro-WebappID = "27491" %}
		{% assign ro-RolodexString = "A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,1,2,3,4,5,6,7,8,9,0" %} 
		{% include "/_System/includes/lib/web-apps/rolodex-output.inc" %} 

		Optional:
		NOTE: paste any optional variables above the required include (above).

		-- to apply a custom template to the results, update the path to match where your template is
		{% assign ro-OutputTemplate = "/layouts/webapps/search with liquid results/rolodex.tpl" %}

		-- change the default sort order, use any valid webapp sort parameter.
		{% assign ro-Sort = "date" -%}

		â€” to suppress the output of letters/numbers in the Rolodex that do not have any webapp items
		{% assign ro-ShowEmpty = false -%}

		â€” to suppress the output of lthe Show All link at the end of the Rolodex list
		{% assign ro-ShowAll = false -%}

		-- to change the elements and classes used for the Rolodex and webapp output.
				use inspect element in browser to determine what you want to change
		{% assign ro-RolodexLinkClass = "rolodex" %}
		{% assign ro-RolodexTop = "p" %}
		{% assign ro-RolodexTopClass = "lead" %}

		{% assign ro-RolodexOutput = "div" %}
		{% assign ro-RolodexOutputClass = "rolodexOutput mt40" %}

    
    Example:
    This example shows the most basic use of the library item
    
		{% assign ro-WebappID = "27491" %}
		{% assign ro-RolodexString = "A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,1,2,3,4,5,6,7,8,9,0" %}
				
		{% include "/_System/includes/lib/web-apps/rolodex-output.inc" %}
    
{% endcomment -----------------------%}


{% comment -%} To get path use "url" if in webapp, otherwise globals.get.id {% endcomment -%} 
{% if globals.get.id == itemid -%} 
	{% assign path = url -%} 
{% else -%} 
	{% assign path = globals.get.id -%} 
{% endif -%} 

{% comment -%} Get the webapp id or set up to output an error is not provided{% endcomment -%} 
{% assign ro-WebappIDSize = ro-WebappID | size -%}
{% unless ro-WebappIDSize > 0 -%}
	{% assign ro-NoWebappID = true -%}
{% endunless -%}

{% comment -%} Default Rolodex is A-Z, 1-0 {% endcomment -%}
{% unless ro-RolodexString -%}
	{% assign ro-RolodexString = "A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,1,2,3,4,5,6,7,8,9,0" -%} 
{% endunless -%}

{% comment -%} If ShowAll is not set by the user to false, make it default to true {% endcomment -%}
{% unless ro-ShowAll == false -%}
	{% assign ro-ShowAll = true -%}
{% endunless -%}

{% comment -%} If ShowEmpty is not set by the user to false, make it default to true, this will show a letter or number in the rolodex even if there are no results that start with that letter/number {% endcomment -%}
{% unless ro-ShowEmpty == false -%}
	{% assign ro-ShowEmpty = true -%}
{% endunless -%}

{% comment -%} If no sort order is provided, default to Alphabetical {% endcomment -%}
{% unless ro-Sort -%}
	{% assign ro-Sort = "ALPHABETICAL" -%}
{% endunless -%}

{% comment -%} Some default html and classes for the output {% endcomment -%}
{% unless ro-RolodexTop  -%}
	{% assign ro-RolodexTop = "p" -%}
{% endunless -%}
{% unless ro-RolodexTopClass -%}
	{% assign ro-RolodexTopClass = "lead" -%}
{% endunless -%}
{% unless ro-RolodexOutput -%}
	{% assign ro-RolodexOutput = "div" -%}
{% endunless -%}
{% unless ro-RolodexOutputClass -%}
	{% assign ro-RolodexOutputClass = "rolodexOutput mt40" -%}
{% endunless -%}
{% unless ro-RolodexLinkClass -%}			
	{% assign ro-RolodexLinkClass = "rolodex" %}			
{% endunless -%}
				
{% if ro-NoWebappID -%}
	<p class="lead">Sorry, we can't find the information you're looking for. Please check your settings.</p>	
{% else -%}

	{module_webapps id="{{ro-WebappID}}" filter="all" sortType="{{ ro-Sort }}" render="collection" collection="rolodexList" template="" } 
	
	{% comment -%} If no template was provided, use the default list view {% endcomment -%}
	{% unless ro-OutputTemplate -%}
		{% assign ro-NoTemplate = true -%}
	{% endunless -%}
	
	{% assign ro-RolodexArray = ro-RolodexString | split: ',' -%}

	<{{ro-RolodexTop}} class="{{ro-RolodexTopClass}}">
		{% for rolodexLetter in ro-RolodexArray -%}{% assign itemCount = 0 -%}{% for item in rolodexList.items -%}{% assign firstLetter = item.name | truncate: 1, "" | upcase%}{% if firstLetter == rolodexLetter and itemCount == 0 -%}<a class="{{ro-RolodexLinkClass}}" href="{{ path }}?show={{firstLetter}}" >{{ firstLetter }}</a>&nbsp;&nbsp;{% assign itemCount = 1 -%}{% elseif forloop.last and itemCount == 0 -%}{% if ro-ShowEmpty -%}{{ rolodexLetter }}&nbsp;&nbsp;{% endif -%}{% endif -%}{% endfor -%}{% endfor -%}{% if ro-ShowAll -%} - <a class="rolodex" href="{{ path }}?show=all">Show All</a>{% endif -%}
	</{{ro-RolodexTop}}>

	<{{ro-RolodexOutput}} class="{{ro-RolodexOutputClass}}">
		
		{% if globals.get.show -%} 
			{% if globals.get.show == "all"%}
				<h4>Showing all items </h4>
				<hr> 
				{% for item in rolodexList.items -%}
					{% if ro-NoTemplate -%}
						{module_webapps id="{{ro-WebappID}}" filter="item" itemId="{{ item.itemid }}" }
					{% else -%}
						{% include "{{ ro-OutputTemplate }}" -%}
					{% endif -%}
				{% endfor -%} 
			{% else -%}
				<h4>Showing items that begin with {{globals.get.show}} </h4>
				<hr> 
				{% for item in rolodexList.items -%} 
					{% assign firstLetter = item.name | truncate: 1, "" | upcase%} 
					{% if firstLetter == globals.get.show -%}
						{% if ro-NoTemplate -%}
							{module_webapps id="{{ro-WebappID}}" filter="item" itemId="{{ item.itemid }}" }
						{% else -%}
							{% include "{{ ro-OutputTemplate }}" -%}
						{% endif -%}
					{% endif -%} 
				{% endfor -%} 
			{% endif -%} 
		{% endif -%}

	</{{ro-RolodexOutput}}>
{% endif -%}