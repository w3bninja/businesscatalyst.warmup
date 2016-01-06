{% comment -%}GLOBAL{% endcomment -%}
{% capture page_url -%}{module_pageaddress}{% endcapture -%}
{% capture is_home -%}http://{module_sitehost}/{% endcapture -%}
{% capture site_name_default -%}{module_sitename}{% endcapture -%}
{% capture isloggedin -%}{module_isloggedin}{% endcapture -%}

{% comment -%}Page Slug{% endcomment -%}
{module_siteurl collection="domain" template=""}
{module_pageaddress collection="pageaddress" template=""}
{% assign page_slug = pageaddress.pageUrl | remove: domain.siteUrl | remove: 'https://' | remove: 'http://' | split: '/' | join: " " -%}



{% assign site = "" -%}
{% assign site_name = site_name_default -%}
{% assign site_domain = is_home -%}
{% assign is_facility = "false" -%}
{% assign logo = "/img/logo.png" -%}
{% capture menu_id -%}1931027{% endcapture -%}
{% capture class_id -%}669308{% endcapture -%}
{% assign phone = "800-401–4277" -%}

{% comment -%}
{% comment -%}WEBAPP VARIABLES PER SITE{% endcomment -%}
{% assign is_facility = "true" -%}

{module_webapps id="31768" filter="all" collection="sites" template=""}

{% for item in sites.items -%}
	{% if page_url contains item.folder -%}
		{% assign site = item.folder -%}
        {% assign site_name = item.name -%}
        {% capture site_domain -%}http://{module_sitehost}{{item.folder}}/home{% endcapture -%}
        {% assign logo = item.image -%}
        {% assign menu_id = item.["Menu ID"] -%}
        {% assign class_id = item.["Classification ID"] -%}
        {% assign phone = item.phone -%}
        {% assign is_facility = "true" -%}
    {% endif -%}
{% endfor -%}
{% endcomment -%}