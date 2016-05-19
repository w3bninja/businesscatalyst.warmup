//SRC = http://www.snows.com.au/shop/all/


//<div class="CartSummaryPanel js-checkoutSummary">
//    <a href="#" class="CartSummaryPanel-close icon-cross js-checkoutSummaryClose"></a>
//    <h3 class="CartSummaryPanel-title">Your Cart</h3>
//    <table class="CartSummaryPanel-table">
//        <thead>
//            <tr>
//                <td>Product</td>
//                <td>Price</td>
//                <td>Qty</td>
//                <td>Cost</td>
//            </tr>
//        </thead>
//        <tbody class="js-checkoutSummary-items">
//
//        </tbody>
//    </table>
//
//    <a href="/OrderRetrievev2.aspx?CatalogueID=258062" class="Button">CHECKOUT</a>
//</div>





$('.js-checkoutSummary').on('click', '.js-checkoutSummaryClose', function(event) {
    event.preventDefault();
    /* Act on the event */
    $('.js-checkoutSummary').slideUp(400);

});;

Oshoplang = {

RemoveError: 'To remove or update quantities select the View Cart link.',

Added: ' product(s) added to your shopping cart.',

OutOfStock: 'Either product is out of stock or choose a smaller quantity',

PreOrder: ' item(s) pre-ordered and added to your cart.',

InvalidQuantity: 'Quantity entered is not valid.',

CartEmpty: 'Your Shopping cart is empty.',

CartUpdateSuccess: 'Shopping cart updated successfully.',

InvalidShip: 'Please choose a shipping option.',

ChooseState: 'Please choose a destination state to calculate state tax.',

EnterZip: 'Please enter in your Postcode to calculate shipping costs for your order.',

ChooseShip: 'Please select a shipping charge for your order.',

IncorrectGForm: 'Your gift voucher form is not setup correctly. Please reset to original to restore.',

EnterGName: 'Please enter a name for the recipient of your gift voucher.',

InvalidGEmail: 'Please enter a valid email address for the recipient of your gift voucher.',

EnterGMessage: 'Please enter a personal message for the recipient of your gift voucher.'

};

// Other possible options
// MinLimit: 'Quantity entered is too small, please enter a larger quantity.',
// MaxLimit: 'Quantity entered is too large, please enter a smaller quantity.',
// ChooseAttribute: 'Please choose relevant options before adding to cart.'

    // lets us do alerts without creating an endless loop
    window.vanillaAlert = window.alert;



    // Alert Messages ------

    // We have to highjack the default AddToCart function so we can get the object that triggered the request.
    // As firefox handles events differntly we couldnt use event.target

    var addToCartHJ = function(catalogueId, productId, frame, details, blank1, blank2, buynow, options ){
        var lastItem = '#product-'+ catalogueId +'-'+productId;
        window.lastItem = lastItem;

        // vanillaAlert( catalogueId, productId, frame, details, blank1, blank2, buynow, options );
        // console.log( window.lastItem );
        AddToCart(catalogueId,productId, frame, details, blank1, blank2, buynow, options);
        // return false;
    };

    window.alert = function(message) {
        // console.log(message);

        // this should be a switch and we should have custom error handling
        if ( message.indexOf(Oshoplang.Added) >= 0) {

            // var elem = event.target || event.srcElement;
            // console.log( event.target ); // shows the button which we can bubble up to the parent and animate the item to the cart.
            // var $currentTarget = $( event.target ).attr('id');
            var $cartButtonTrigger = $(window.lastItem);

            // Give feedback
            $cartButtonTrigger.css('min-width',  $cartButtonTrigger.outerWidth() ).val('Adding…').addClass('is-processing').attr('disabled', true);

            $.get( "/OrderRetrievev2.aspx?json=true", function( data ) {
                // console.log('json call:');
                // console.log( data.overallShoppingCart_1 );
                var $checkoutSummary = $('.js-checkoutSummary-items').html('');

                $.each( data.overallShoppingCart_1.items , function( index, product ) {
                    // Build out the preview
                    var productItemAmount = product.productAmountIncludingTax;
                    var productTotalAmount = product.productTotal;

                    $checkoutSummary.append('<tr><td><img src="' + product.imagePath +'" height="20" alt="' + product.name + '" /></td><td>$' + product.productAmountIncludingTax + '</td><td>' + product.quantity + '</td><td>$' + product.productTotal + '</td></tr>');
                    //<button onclick="'+ product.removeOnClick +' return false;">Remove</button>
                    // console.log( product.name + ' ' + product.imagePath +' ' + product.quantity + ' x ' + product.productAmountIncludingTax + '=' + product.productTotal );
                });

                setTimeout(function(){
                    $cartButtonTrigger.val('Added!').addClass('is-added').removeClass('is-processing');
                    $('.js-inlineCart').addClass('has-items');
                    $('.js-checkoutSummary').slideDown('400');

                    setTimeout(function(){
                        $cartButtonTrigger.val('Add to Cart').removeClass('is-added').attr('disabled', false);;
                    }, 3000);
                }, 500);

                //().delay(5000); //.fadeOut('slow');

            });

            // Update the Button on Feedback.


            // jQuery.get('/OrderRetrievev2.aspx?json=true', function(msg){
            //   entirePage = JSON.parse(msg);
            //   console.log(msg);
            // });

        } else {
            vanillaAlert(message);
        }
        // $('#messageBox').text(message).fadeIn().delay(5000).fadeOut('slow');
    };
    // end system alert mesages