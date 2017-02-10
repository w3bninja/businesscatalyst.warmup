{% comment %}
	USAGE:
	{% assign webapp_id = '43723' %}
	{% include '/_System/includes/widgets/media-library/include.inc' %}
{% endcomment %}

<div id="media" class="row">
	<div class="col-sm-9 media-library">
		{% include '/_System/includes/widgets/media-library/library.inc' %}
	</div>
	<div class="col-sm-3 media-sidebar">
		{% include '/_System/includes/widgets/media-library/sidebar.inc' %}
	</div>
</div>