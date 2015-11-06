{% comment -%}GLOBAL{% endcomment -%}
{% capture page_url -%}{module_pageaddress}{% endcapture -%}
{% capture is_home -%}http://{module_sitehost}/{% endcapture -%}
{% capture site_name_default -%}{module_sitename}{% endcapture -%}
{% capture isloggedin -%}{module_isloggedin}{% endcapture -%}

{module_siteurl collection="domain" template=""}
{module_pageaddress collection="pageaddress" template=""}
{% assign page_slug = pageaddress.pageUrl | remove: domain.siteUrl | remove: 'https://' | remove: 'http://' | split: '/' | join: " " -%}


{% if page_url contains "facility-1" %}
	{% assign site_name = "Facility 1" -%}
	{% assign site_domain = "http://{module_sitehost}/facility-1/home" -%}
    {% capture menu_id -%}2040584{% endcapture -%}
{% elseif page_url contains is_home -%}
	{% assign site_name = site_name_default -%}
    {% assign site_domain = is_home -%}
    {% capture menu_id -%}1931027{% endcapture -%}
{% endif -%}