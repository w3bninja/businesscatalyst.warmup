// Baton Rouge General Physicians
// Programmer: Adam Culpepper
// Firm: Envoc (envoc.com)

$(function () {
	
	window.location.origin || (window.location.origin = window.location.protocol + '//' + window.location.host);
	window.app = {};
	var url = app.url = (location.href); //Cached for heavy general use

	//Add the name of the page to the body ID for better CSS targeting
	url = url.split('?')[0];
	
	var urlPieces = app.urlPieces = $.trim((url.replace(window.location.origin, '')).split("/").join(" "));
	
	var bodyID = (url).split("/").pop();
	if (urlPieces == "") {
		urlPieces = "home";
	}

	$("body").addClass(urlPieces);
	$("body").attr('id', bodyID);
	
	app.isOnPage = function(pageName) {
		return app.url.split("?")[0].split("/").pop() == pageName;
	}
	
	//Navigation helper
    $(".navigation-inner ul li").hover(function(){
        $(this).addClass("hover");
        $('ul:first',this).css('visibility', 'visible');
    }, function(){
        $(this).removeClass("hover");
        $('ul:first',this).css('visibility', 'hidden');
    });
	
	$('.toggle-menu').jPushMenu();
	
	$("#webticker ul").webTicker();
	
	
	// Headers
	$('.page-header-inner').appendTo( $('.page-header') );
	// Sidebars
	 $('.sidebar-section').wrapAll('<div class="col-md-3 sidebar"/>');
	$('.sidebar-section').appendTo($('.sidebar-inner'));
	$('.sidebar').appendTo( $('.content-inner') );
	
	if ($('.sidebar').length > 0) { 
		$('.content-col').wrapAll('<div class="col-md-9 pull-right"/>');
	}
	
});


$(document).ready(function() {
    $("img").error(function(){
        $(this).remove();
    });
	
	$(".fancy").fancybox({
		maxWidth	: 800,
		maxHeight	: 600,
		fitToView	: false,
		width		: '70%',
		height		: '70%',
		autoSize	: false,
		closeClick	: false,
		openEffect	: 'none',
		closeEffect	: 'none'
	});
	$(".fancy.ajax").fancybox({type: 'ajax'});
	
	
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


