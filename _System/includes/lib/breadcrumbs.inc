
<!-- we grab the domain and page address -->
{module_siteurl collection="domain" template=""}
{module_pageaddress collection="pageaddress" template=""}

<!-- split the pageaddress by the '/', first removing site protocols and the domain -->
{% assign links = pageaddress.pageUrl | remove: domain.siteUrl | remove: 'https://' | remove: 'http://' | split: '/' -%}

<!-- list of unavailable pages (more on this later), then turn it into an array -->
{% assign unavailablepage = "category,tag,calendar" -%}
{% assign unavailablepage = unavailablepage | split: "," -%}

<!-- we use this variable to keep track on where we are within our breadcrumbs -->
{% assign fullurl = '' -%}
<!-- this is used for our structured data (more on this later) -->
{% assign count = 1 -%}

<nav id="breadcrumbs">
	
	<ul class="breadcrumb">
		<li><a href="/">Home</a></li>
	
		{% if pageaddress.pageUrl contains 'Default.aspx' -%}

			{module_breadcrumbs collection="breadcrumbs" template=""}

			{% for link in breadcrumbs.items reversed -%}

				{% if link.url != "/index.html" and link.url != "/index.htm" and link.url != "/" -%}
						
					{% unless unavailablepage contains link -%}
					
						{% assign first = false -%}
						{% if links.first == link -%}{% assign first = true -%}{% endif -%}
						
						{% assign last = false -%}
						{% if links.last != link -%}{% assign last = true -%}{% endif -%}

						{% assign css = '' -%}
						{% if links.last == link -%}{% assign css = css | append: " current" -%}{% endif -%}
						{% assign css = css | remove_first: " " -%}

						{% assign text = link.name | replace: '%20', ' ' | replace: '%26', '&' | replace: '%3F', '?' | replace: '%21','!' | replace: '%2C', ',' | replace: "%27", "'" -%}

						{% assign url = link.url | remove: '/index.html' -%}

						{% assign bid = count -%}
						{% assign count = count | plus: 1 -%}
						
						{% include '/_System/includes/breadcrumb-item.inc' -%}

					{% endunless -%}

				{% endif -%}

			{% endfor -%}

		{% else -%}

			{module_data resource="pages" version="v3" fields="id,pageUrl,name,title" skip="0" limit="50" where="\{'pageUrl':\{'$contains':'{{ links[0] }}'\}\}" collection="pages"}

			{% if links.last == 'index.html' or links.last == 'index.htm' %}
				{% assign links = links | join: "," | remove: ',index.html' | remove: ',index.htm' | split: "," %}
			{% endif %}

			{% for link in links -%}

				{% assign fullurl = fullurl | append: '/' | append: link -%}
				{% assign thispage = ""  -%}

				{% for page in pages.items -%}

					{% assign url = page.pageUrl | remove: '/index.html' -%}
					{% if fullurl == url -%}
						{% assign thispage = page  -%}
					{% endif -%}

				{% endfor -%}

				{% if thispage == "" -%}
					
					{% unless unavailablepage contains link -%}
					
						{% assign first = false -%}
						{% if links.first == link -%}{% assign first = true -%}{% endif -%}
						
						{% assign last = false -%}
						{% if links.last == link -%}{% assign last = true -%}{% endif -%}

						{% assign css = '' -%}
						{% if links.last == link -%}{% assign css = css | append: " current" -%}{% endif -%}
						{% assign css = css | remove_first: " " -%}

						{% assign text = link | remove: '/index.html' | replace: '-', ' ' | capitalize | replace: '%20', ' ' | replace: '%26', '&' | replace: '%3F', '?' | replace: '%21','!' | replace: '%2C', ',' | replace: "%27", "'" -%}

						{% assign url = fullurl -%}

						{% assign bid = count -%}
						{% assign count = count | plus: 1 -%}

						{% include '/_System/includes/lib/breadcrumb-item.inc' -%}

					{% endunless -%}


				{% else -%}
					
					{% unless unavailablepage contains link -%}
					
						{% assign first = false -%}
						{% if links.first == link -%}{% assign first = true -%}{% endif -%}
						
						{% assign last = false -%}
						{% if links.last == link -%}{% assign last = true -%}{% endif -%}

						{% assign css = '' -%}
						{% if links.last == link -%}{% assign css = css | append: " current" -%}{% endif -%}
						{% assign css = css | remove_first: " " -%}

						{% assign text = thispage.name -%}

						{% assign url = thispage.pageUrl | remove: '/index.html' -%}

						{% assign bid = count -%}
						{% assign count = count | plus: 1 -%}

						{% include '/_System/includes/lib/breadcrumb-item.inc' -%}

					{% endunless -%}

				{% endif -%}

			{% endfor -%}

		{% endif -%}

	</ul>

</nav>