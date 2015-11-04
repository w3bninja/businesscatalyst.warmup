{module_shoppingcartsummary collection="cartItems" template=""}
{% for item in cartItems.items -%}
    {module_data resource="products" version="v3" fields="id,name,productCode,smallImage,largeImage" skip="0" limit="10" where="\{'catalogs.productId':'{{item.productId}}'\}" order="id" collection="productInfo"}
    <div class="row">
        <div class="col-sm-1"><img src="{{productInfo.items[0].largeImage}}?Action=thumbnail&Width=200&Height=200&algorithm=fill_proportional" width="100%"></div>
        <div class="col-sm-8">
            <div class="row">
                <h3>
                	<a href="{{item.url}}?desc={{item.description}}">{{item.name}}</a>
                    <a href="#" onclick="UpdateItemQuantity(0,{{orderId}},{{item.catalogId}},{{item.productId}},{{item.id}},'','US');return false;"><i class="fa fa-times"></i></a>
                    
                </h3>
                <div class="pull-right">${{item.price}}<input onchange="UpdateItemQuantity(this.value,{{orderId}},{{item.catalogId}},{{item.productId}},{{item.id}},'','US');return false;" class="cartInputText" type="text" value="{{item.quantity}}"></div>
            </div>
          {{item.description}}
            <a href="{{item.smallImage}}?Action=thumbnail&Width=800&Height=800&algorithm=fill_proportional" class="fancy"><img src="{{item.smallImage}}?Action=thumbnail&Width=800&Height=200&algorithm=fill_proportional" width="100%"></a>
        </div>
        <div class="col-sm-2">${{item.totalPrice}}</div>
    </div>
{% endfor -%}

{{invoiceTotal}}
<a href="" onclick="{{clearCartOnClick}}">Clear</a>
<a href="{{quoteUrl}}" class="btn btn-primary">Get a Quote</a>
<a href="{{buyUrl}}" onclick="{{buyButtonOnClick}}">By Now</a>