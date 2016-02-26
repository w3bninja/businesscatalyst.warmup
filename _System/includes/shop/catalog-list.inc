{module_catalogueselect parentId="-1" collection="catalogSelect" template=""}
<div class="row">
{% for item in catalogSelect.items -%}
	<div class="col-sm-4">
		{module_catalogue render="item" catalogId="{{item.id}}"}
    </div>
{% endfor -%}
</div>