{module_shoppingcartsummary collection="cartItems" template=""}
{% for item in cartItems.items -%}
    {module_data resource="products" version="v3" fields="id,name,productCode,smallImage,largeImage" skip="0" limit="10" where="\{'catalogs.productId':'{{item.productId}}'\}" order="id" collection="productInfo"}
    <div class="row">
        <div class="col-sm-2">
        	{% if productInfo.items[0].smallImage != '' -%}
                <div class="image"><img src="{{productInfo.items[0].smallImage}}?Action=thumbnail&Width=100&Height=100&algorithm=fill_proportional" width="100%" class="img-responsive"></div>
              {% elseif productInfo.items[0].largeImage != '' -%}
                <div class="image"><img src="{{productInfo.items[0].largeImage}}?Action=thumbnail&Width=100&Height=100&algorithm=fill_proportional" width="100%" class="img-responsive"></div>
              {% else -%}
                <div class="image"><img src="/img/x.png?Action=thumbnail&Width=200&Height=200&algorithm=fill_proportional" width="100%" class="img-responsive"></div>
              {% endif -%}
        </div>
        <div class="col-sm-7">
            <div class="row">
                <div class="col-sm-8">
                	<h3><a href="{{item.url}}">{{item.name}}</a></h3>
                    <label>Options</label>
                    <div class="text">{{item.description}}</div>
                </div>
                <div class="col-sm-2">${{item.price}}<input onchange="UpdateItemQuantity(this.value,{{orderId}},{{item.catalogId}},{{item.productId}},{{item.id}},'','US');return false;" class="cartInputText" type="text" value="{{item.quantity}}"></div>
            </div>
        </div>
        <div class="col-sm-2">${{item.totalPrice}}</div>
        <div class="col-sm-1"><a href="#" onclick="UpdateItemQuantity(0,{{orderId}},{{item.catalogId}},{{item.productId}},{{item.id}},'','US');return false;" title="Remove Item"><i class="fa fa-times"></i></a></div>
    </div>
    <hr>
{% endfor -%}
<div class="row total">
    <div class="col-sm-9 total-title">Total:</div>
    <div class="col-sm-2 total-price">${{invoiceTotal}}</div>
    <div class="col-sm-1 total-price"><a href="" onclick="{{clearCartOnClick}}" title="Remove All Items"><i class="fa fa-times"></i></a></div>
</div>


<hr>
<a href="" onclick="{{clearCartOnClick}}" class="btn btn-default">Continue Shopping</a>

<a href="{{quoteUrl}}" class="btn btn-default">Get a Quote</a>
<a href="{{buyUrl}}" onclick="{{buyButtonOnClick}}" class="btn btn-primary">Buy Now</a>