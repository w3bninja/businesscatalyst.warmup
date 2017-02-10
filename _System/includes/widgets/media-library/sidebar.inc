<h3>Tags</h3>
{% assign tag_array = '' -%}
{module_webapps id="{{webapp_id}}" filter="all" collection="sidebar_tags" template=""}
{% for item in sidebar_tags.items -%}
	{% if item.['Tags'] != '' -%}
		{% assign tag_array = tag_array | append: item.['Tags'] | append:',' -%}
	{% endif -%}
{% endfor -%}

{% comment -%}Clean-up spaces{% endcomment -%}
{% assign tag_array = tag_array | replace:', ', ',' | replace:' ,', ',' -%}

{% comment -%}Remove Duplicates{% endcomment -%}
{% assign array = tag_array | split: ',' -%}
{% assign sidebar_tags_string = array[1] -%}
{% for item in array -%}
	{% assign sidebar_tags = sidebar_tags_string | split: '|' -%}
    {% unless sidebar_tags contains item -%}
    {% assign sidebar_tags_string = sidebar_tags_string | append: '|' | append: item -%}
    {% endunless -%}
{% endfor -%}

{% assign sidebar_tags = sidebar_tags_string | split: '|' | sort -%}
{% for item in sidebar_tags -%}
	<a href="?tag={{item | downcase | replace:' ', '+' | remove:"'" | remove:'"' | remove:'-'}}">{{item | capitalize}}</a>
{% endfor -%}