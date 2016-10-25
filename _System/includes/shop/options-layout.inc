{% comment -%}
	Include this in a Layout to pull product options. If it is used on a non-product page, a catalog and product id will need to be set.
	{% include "/_System/includes/shop/options-layout.inc" -%}
{% endcomment -%}

{% capture options %}{tag_attributes}{% endcapture %}
{% if options != '' %}
	{module_data resource="productsattributes" version="v3" fields="id,siteId,productId,groupName,fieldTypeId,mandatory,keepStock,product" skip="0" limit="10" where="\{'product.id':'{{id}}'\}" order="id" collection="productAttributes"}
	{module_product render="items" catalogId="{{catalogId}}" targetFrame="_blank" productid="{{id}}" useLi="false" collection="product" template=""}

	{% comment %}
	<div id="ninja" style="display:none;">
		collection: productAttributes<br>
		<pre>{{productAttributes | json}}</pre>
		
		collection: product<br>
		<pre>{{product | json}}</pre>
		
		collection: productAttributeOptions<br>
		{module_data resource="productsattributeoptions" version="v3" fields="id,siteId,groupId,optionName,imagePath,attribute" resourceId="{{id}}" skip="0" limit="10" order="id" collection="productAttributeOptions"}
		<pre>{{productAttributeOptions | json}}</pre>
	</div>
	{% endcomment %}	
	
	{% for attr in productAttributes.items %}
		{% assign optionName = attr.groupName %}
		{% assign optionId = attr.id %}
		{% assign mandatory = attr.mandatory %}
		
		{% assign selectOptions = '' %}
		{% assign previousProductID = '' %}
		
		<div class="catProductAttributeGroup">
			<label class="catProdAttributeTitle">{{optionName}}</label>
			{% for option in product.attributes.[optionName] %}
				{% case option.displayType -%}
					{% when '7' -%}
						{% assign inputType = "radio" %}
					{% when '6' -%}
						{% assign inputType = "checkbox" %}
					{% when '5' -%}
						{% assign inputType = "select" %}
					{% else -%}
				{% endcase -%}
				
				{% if inputType != "select" %}
					{% capture inputContent %}
						{{inputContent | default:''}}
						<div class="{{inputType}} catProdAttributeItem">
							<label for="{{option.id}}">
								<input type="{{inputType}}" id="{{option.id}}" name="{{optionId}}" mandatory="1">{{option.name}} {{option.price | money}}
							</label>
						</div>
					{% endcapture %}
				{% else %}
					{% assign previousProductID == option.id %}
					{% assign selectOptions = selectOptions | append: '<option value="' | append:option.id | append:'">' | append:option.name | append:'</option>' %}
				{% endif %}		
			{% endfor %}
	
			{% if inputType != "select" %}
				{{inputContent}}
			{% else %}
				<select {% if mandatory == true %}mandatory="1"{% endif %} class="form-control catProdAttributeItem">
					<option value="">-- Please select --</option>
					{{selectOptions}}
				</select>
			{% endif %}
		</div>
	{% endfor %}	
{% endif %}
