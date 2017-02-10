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