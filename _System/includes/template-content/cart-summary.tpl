{% if item.smallImage == null -%}
{% assign imgValue = "/assets/img/x.png?Action=thumbnail&Width=200&Height=200&algorithm=fill_proportional" -%}
{% else -%}
{% assign imgValue = item.smallImage -%}
{% endif -%}

<div id="cart-summary"> 
    {% if itemCount == 0 -%}
    	<span><a title="Go to Cart" href="{{cartUrl}}" class="btn btn-default btn-cart"><i class="fa fa-shopping-basket"></i></a></span>
    {% else -%}
     	<div id="cart-items">
            <div class="dropdown">
              <button class="btn btn-default btn-cart dropdown-toggle" type="button" id="dropdownMenu2" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
                <i class="fa fa-shopping-basket"></i>
                <span class="badge">{{itemCount}}</span> {% comment -%}item{% if itemCount != 1 -%}s{% endif -%}{% endcomment -%}
              </button>
            <ul class="dropdown-menu dropdown-menu-right" aria-labelledby="dropdownMenu2">
              <li class="cart-summary-padding">
                {% for item in items -%}
                <div class="row">
                    <div class="col-xs-4"><a href="{{item.url}}"><img src="{{imgValue}}" alt="{{item.name}}" width="100%" class="thumbnail img-responsive"></a></div>
                    <div class="col-xs-8">
                        <strong><a href="{{item.url}}">{{item.name}}</a></strong> (x {{item.quantity}})<br>
                        <em>{{currencyFormat}} {{item.price}}</em>
                    </div>
                </div>
                <hr>
                {% endfor -%}
                <div class="subtotal"><strong>Subtotal:</strong> {{currencyFormat}} {tag_totalAmount}</div>
                <a title="Go to Cart" href="{{cartUrl}}" class="btn btn-primary">View Cart</a>
                </li>
            </ul>
            </div>
        </div>
    {% endif -%}
</div>