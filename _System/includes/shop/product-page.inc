<div class="hidden">{tag_poplets collection="poplets" template=""}</div>
<div class="row">
	<div class="col-md-12">
    	<div class="image">
        	<a href="/img/nathan.png" class="fancy"><img src="{{largeImageUrl}}" class="img-responsive"></a>
            <div class="poplets">
            	{% for item in poplets -%}
                	<a href="{{item.path}}?Action=thumbnail&Width=800&Height=800&algorithm=fill_proportional" class="fancy" rel="poplets"><img src="{{item.path}}?Action=thumbnail&Width=100&Height=100&algorithm=fill_proportional"></a>
                {% endfor -%}
            </div>
        </div>
        <img src="{{smallImageUrl}}" class="img-responsive">
    </div>
	<div class=" col-md-12">
    	<ul>
          <li class="price"><strong>{{salePrice}}</strong></li>
          <li class="instock">In stock: <strong>{{inStock}}</strong></li>
          <li class="quantity">
          
          
          	{tag_addtocartinputfield}
            <button class="btn btn-primary" onclick="AddToCart({{catalogId}},{{id}},'',4,'','',false);return false;">Add to Cart</button>
          </li>
        </ul>
        <div class="description">{{description}}</div>
    </div>
</div>