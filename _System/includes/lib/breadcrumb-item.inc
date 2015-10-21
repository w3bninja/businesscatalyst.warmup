{% if first == true -%}
	<!--<li class="separator"></li>-->
{% endif -%}

<li{% if bid != '' -%} id="b-{{ bid }}" itemscope itemtype="http://data-vocabulary.org/Breadcrumb"{% if last == false -%} itemref="b-{{ bid | plus: 1 }}"{% endif -%}{% if first == false -%} itemprop="child"{% endif -%}{% endif -%}{% if css != '' -%} class="{{ css }}"{% endif -%}>
	<a href="http://{{ domain.siteUrl }}{{ url }}"{% if bid != '' -%} itemprop="url"{% endif -%}>
		<span{% if bid != '' -%} itemprop="title"{% endif -%}>{{ text }}</span>
	</a>
</li>
{% if last != true -%}
	<!--<li class="separator"></li>-->
{% endif -%}