{module_shoppingcartsummary template="/_System/includes/template-content/cart-summary.tpl"}
{% comment -%}
{module_shoppingcartsummary,horizontal collection="cartSummary" template=""}
{% if cartSummary.itemCount > 0 -%}
<div class="dropdown">
  <button class="btn btn-default dropdown-toggle" type="button" id="dropdownMenu2" data-toggle="dropdown" aria-haspopup="true" aria-expanded="true">
	{% for item in cartSummary -%}
		{{item.itemCount}}
	{% endfor -%}
	<i class="fa fa-shopping-cart"></i>
	<span class="caret"></span>
  </button>
  <ul class="dropdown-menu dropdown-menu-right" aria-labelledby="dropdownMenu2">
	{% for item in cartSummary.items -%}
		<li>
			<a href="{{item.url}}">
				<div class="row">
					<div class="col-xs-4"><img src="{{item.smallImage}}" width="100%" class="thumbnail img-repsonsive"></div>
					<div class="col-xs-8">{{item.name}} ({{item.quantity}})<br>{{item.totalPrice | money}}</div>
				</div>
			</a>
		</li>
	{% endfor -%}
	<li role="separator" class="divider"></li>
	<li><a href="{{cartSummary.cartUrl}}">Check Out</a></li>
  </ul>
</div>
{% else -%}
<a href="{{cartSummary.cartUrl}}" class="btn btn-default"><i class="fa fa-shopping-cart"></i></a>
{% endif -%}
{% endcomment -%}