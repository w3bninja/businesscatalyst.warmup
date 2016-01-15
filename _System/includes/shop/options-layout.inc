{% comment -%}
Include this in a Layout to pull product options. If it is used on a non-product page, a catalog and product id will need to be set.
{% include "/_System/includes/shop/options-layout.inc" -%}
{% endcomment -%}

{% capture options %}{tag_attributes}{% endcapture %}
{% if options != '' %}
	{module_data resource="productsattributes" version="v3" fields="id,siteId,productId,groupName,fieldTypeId,mandatory,keepStock,product" skip="0" limit="10" where="\{'product.id':'{{id}}'\}" order="id" collection="productAttributes"}
	{module_product render="items" catalogId="{{catalogId}}" targetFrame="_blank" productid="{{id}}" useLi="false" collection="product" template=""}
	{% for attr in productAttributes.items %}
		{% assign optionName = attr.groupName %}
		{% assign optionId = attr.id %}
		{% assign mandatory = attr.mandatory %}
		<b>{{optionName}}</b>
		{% for option in product.attributes.[optionName] %}
			{% case option.displayType -%}
				{% when '7' -%}
					{% assign inputType = "radio" %}
				{% when '6' -%}
					{% assign inputType = "checkbox" %}
				{% else -%}
			{% endcase -%}
			<div class="{{inputType}}">
				<label for="{{option.id}}">
					<input type="{{inputType}}" id="{{option.id}}" name="{{optionId}}" mandatory="{{mandatory}}">{{option.name}} {{option.price | money}}
				</label>
			</div>				
		{% endfor %}
	{% endfor %}
{% endif %}