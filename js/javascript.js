// Baton Rouge General Physicians
// Programmer: Adam Culpepper
// Firm: Envoc (envoc.com)

$(function () {
	window.location.origin || (window.location.origin = window.location.protocol + '//' + window.location.host);
	window.app = {};
	var url = app.url = (location.href); //Cached for heavy general use

	//Navigation helper
    $(".navigation-inner ul li").hover(function(){
        $(this).addClass("hover");
        $('ul:first',this).css('visibility', 'visible');
    }, function(){
        $(this).removeClass("hover");
        $('ul:first',this).css('visibility', 'hidden');
    });
	
	//Push Navigation Menu
	$('.toggle-menu').jPushMenu({
		closeOnClickLink   : false,
		closeOnClickOutside: false
	});
	
	$("#webticker ul").webTicker();
	
	
	// Headers
	$('.page-header-inner').appendTo( $('.page-header') );
	// Sidebars
	 $('.sidebar-section').wrapAll('<div class="col-md-3 sidebar"/>');
	$('.sidebar-section').appendTo($('.sidebar-inner'));
	$('.sidebar').appendTo( $('.content-inner') );
	
	if ($('.sidebar').length > 0) { 
		$('.content-col').wrapAll('<div class="col-md-9"/>');
	}
	
	if ($('.cycle-carousel-wrap .box').length <= 5) { 
		$('.areas .controls').hide();
	}
	
	//responsive Tabs 
	//$('.tab-label').wrap($('<li class="tab-li"></li>'));
//	$('.tab-li').wrapAll($('<ul class="tab-nav"></ul>'));
//	$('.tab-description').wrapAll($('<div class="responsiveTabs"></div>'));
//	$('.responsiveTabs').prepend($('.tab-nav'));
	
	$('.responsiveTabs').responsiveTabs({
		startCollapsed: 'accordion'
	});
	
	// FAQ Control
	$('.faq-nav').appendTo($('.faq-control'));
	
	//responsive photogallery
	jQuery(".photogalleryTable").each(function(index,elem){
		var gallery = jQuery(elem),
			bootstrapGallery = jQuery('<div class="gallery row"></div>');
	 
		gallery.find(".photogalleryItem > a").each(function(index,elem){
			var galleryItem = jQuery(elem),
				image = galleryItem.find("img"),
				imageSrc = image.attr("src").split("?"),
				bootstrapGalleryItem = jQuery('<div class="col-sm-3 gallery-item" />');
	 
			image.prop("src",imageSrc[0] + "?Action=thumbnail&Width=400&Height=200&algorithm=fill_proportional");
			image.addClass("thumbnail img-responsive");
	 
			bootstrapGalleryItem.append(galleryItem);
			bootstrapGallery.append(bootstrapGalleryItem);
		});
	 
		gallery.after(bootstrapGallery);
		gallery.remove();
	});
	$('.gallery a').prop( "onclick", null ).removeAttr('onclick').removeAttr('rel').addClass('thumb fancy');
	
	

// DATE PICKER //
$('#DOB').prop( "onfocus", null ).removeAttr('onfocus').removeAttr('title');
$('#DOB').datepicker({
	toggleActive: true
}); 

$('.dropdown-toggle').dropdown();   
	

// FAVORITE INTERACTION //
jQuery(document).unbind().on('click', '.favoritelink', function(e) {
	e.preventDefault();
	var $el = jQuery(this);
	jQuery.ajax({
		url: $el.attr('href'),
		cache: false
	});
	if ($el.hasClass('fav-add')) {
		$el.attr('href', $el.attr('href').replace('FavoriteProcess.aspx?', 'FavoriteProcess.aspx?A=Remove&'));
	} else {
		$el.attr('href', $el.attr('href').replace('FavoriteProcess.aspx?A=Remove&', 'FavoriteProcess.aspx?'));
	}
	$el.toggleClass('fav-add').toggleClass('fav-remove');
	$el.find('i').toggleClass('fa-heart').toggleClass('fa-heart-o');
});

	
	
	
	
	
	
	
	
	
});


$(document).ready(function() {
    $("img").error(function(){
        $(this).remove();
    });
	
	$(".fancy").fancybox({
		maxWidth	: 800,
		maxHeight	: 600,
		fitToView	: true,
		width		: '70%',
		height		: '70%',
		autoSize	: true,
		closeClick	: false,
		openEffect	: 'none',
		closeEffect	: 'none'
	});
	$(".fancy.ajax").fancybox({type: 'ajax'});
	$(".various").fancybox({
		maxWidth	: 800,
		maxHeight	: 600,
		fitToView	: false,
		width		: '70%',
		height		: '70%',
		autoSize	: true,
		closeClick	: false,
		openEffect	: 'none',
		closeEffect	: 'none',
		padding		: 0,
		margin		: 0
	});
	
	var offset = 220;
    var duration = 500;
    jQuery(window).scroll(function() {
        if (jQuery(this).scrollTop() > offset) {
            jQuery('.back-to-top').fadeIn(duration);
        } else {
            jQuery('.back-to-top').fadeOut(duration);
        }
    });
    
    jQuery('.back-to-top').click(function(event) {
        event.preventDefault();
        jQuery('html, body').animate({scrollTop: 0}, duration);
        return false;
    });
});


