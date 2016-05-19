{% if item.smallImage == null -%}
{% assign imgValue = "/assets/img/x.png?Action=thumbnail&Width=200&Height=200&algorithm=fill_proportional" -%}
{% else -%}
{% assign imgValue = item.smallImage -%}
{% endif -%}

<div id="cart-summary"> 
    {% if itemCount == 0 -%}
    <span><a title="Go to Cart" href="{{cartUrl}}" class="btn btn-default"><i class="fa fa-shopping-cart"></i></a></span>
    {% else -%}
     
    {% endif -%}
    {% if itemCount > 0 -%}
    <div id="cart-items">
    	<div class="dropdown">
          <button class="btn btn-default dropdown-toggle" type="button" id="dropdownMenu2" data-toggle="dropdown" aria-haspopup="true" aria-expanded="true">
            {{itemCount}} {% comment -%}item{% if itemCount != 1 -%}s{% endif -%}{% endcomment -%}
            <i class="fa fa-shopping-cart"></i>
            <span class="caret"></span>
          </button>
        <ul class="dropdown-menu dropdown-menu-right" aria-labelledby="dropdownMenu2">
        {% for item in items -%}
          <li>
          	<div class="row">
                <div class="col-xs-4"><a href="{{item.url}}"><img src="{{imgValue}}" alt="{{item.name}}" width="100%" class="thumbnail img-repsonsive"></a></div>
                <div class="col-xs-8">
                    <strong><a href="{{item.url}}">{{item.name}}</a></strong> (x {{item.quantity}})<br>
                    <em>{{currencyFormat}} {{item.price}}</em>
                </div>
            </div>
            </li>
        {% endfor -%}
        <li role="separator" class="divider"></li>
        <li><a title="Go to Cart" href="{{cartUrl}}">View Cart - {{currencyFormat}} {tag_totalAmount}</a></li>
        </ul>
        </div>
    </div>
    {% endif -%}
</div>




