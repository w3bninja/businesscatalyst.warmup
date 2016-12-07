// Developer: Adam Culpepper & Aaron Landry
// Firm: Envoc (envoc.com)

$(function () {
	$('#demo div').inview();
	
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
	
	// Sticky Element - Sticks the element to the top of the site
	$(".sticky").wrap("<div class='sticky-container'></div>");
	$(".sticky").wrap("<div class='sticky-container-inner'></div>");
	$(window).on('scroll', function () {
		var scrollTop	= $(window).scrollTop(),
		elementOffset	= $('.sticky-container').offset().top,
		distance		= (elementOffset - scrollTop);
		$(".sticky-container").height($(".sticky-container-inner").height());
		if(distance < 0){
			$('.sticky-container-inner').addClass('container-fixed');
		} else {
			$('.sticky-container-inner').removeClass('container-fixed');
		}
	});
	
	// PARALLAX
	if ($('.parallax').length > 0) {
		$('.parallax').parallax();
	}
	
	// SMOOTH SCROLL
	if ($('.scroll').length > 0) {
		$(".scroll").on("click", function(event){
			 event.preventDefault();
			 //calculate destination place
			 var dest=0;
			 var destOffset = 0;
			 if($(this.hash).offset().top > $(document).height()-$(window).height()){
				  dest=$(document).height()-$(window).height();
			 }else{
				  dest=$(this.hash).offset().top;
			 }
			 //go to destination
			 $('html,body').animate({scrollTop:dest-destOffset}, 1000,'swing');
		 });
	 }
	
	
	// LAYOUT
	
	// Headers
	$('.page-header-inner').appendTo( $('.page-header') );
	// Sidebars
	 $('.sidebar-section').wrapAll('<div class="col-md-3 sidebar"/>');
	$('.sidebar-section').appendTo($('.sidebar-inner'));
	$('.sidebar').appendTo( $('.content-inner') );
	
	if ($('.sidebar').length > 0) { 
		$('.content-col').wrapAll('<div class="col-md-9"/>');
	}
	
	// FAQ Control
	$('.faq-nav').appendTo($('.faq-control'));
	
	// Cycle Carousel Control Hide
	if ($('.cycle-carousel-wrap .box').length <= 5) { 
		$('.areas .controls').hide();
	}
	
	//Masonry Grid
	var $grid = $('.grid').imagesLoaded( function() {
	  // init Masonry after all images have loaded
	  $grid.masonry({
		itemSelector: '.item'
	  });
	});
	
	//Auto Adust Height Grid
	var $gridbox = $('.grid-box').imagesLoaded( function() {
	  $gridbox.each(function(){  
			 var $columns = $('.item',this);
			 var maxHeight = Math.max.apply(Math, $columns.map(function(){
				 return $(this).height();
			 }).get());
			 $columns.height(maxHeight);
		});
	});
	
	//set items container to full screen width
	$(".inline-full").wrap("<div class='inline-full-container'></div>");
	$(".inline-full").wrap("<div class='inline-full-container-inner'></div>");
	$(".inline-full-container").height($(".inline-full-container-inner").height());

	//Push Navigation Menu
	$('.toggle-menu').jPushMenu({
		closeOnClickLink   : false,
		closeOnClickOutside: false
	});
	
	// News Ticker
	if ($('#webticker').length > 0) {
		$("#webticker ul").webTicker();
	}
	
	// responsive Tabs
	$('.responsiveTabs').responsiveTabs({
		rotate: false,
		startCollapsed:	'accordion',
		collapsible: 	'accordion',
		setHash: 		true,
		active:			0,
		scrollToAccordion: true
	});
	
	if ($('.dropdown-toggle').length > 0) {
		$('.dropdown-toggle').dropdown();
	}
	
	
	/////////// BC FIXES ///////////
	
	
	// Pagination
	jQuery.fn.cleanWhitespace = function() {
		textNodes = this.contents().filter(
			function() { return (this.nodeType == 3 && !/\S/.test(this.nodeValue)); })
			.remove();
		return this;
	}
		
	$('.pagination').cleanWhitespace();
	
	// WebApps
	$(function() {
		$('.pag-current').contents().filter(
			function() {
				return this.nodeType == Node.TEXT_NODE;
			}
		).wrap("<span>").text()
	});
	$('.pag-current').addClass('active');
	
	// Store
	$(function() {
		$('.pagination').contents().filter(
			function() {
				return this.nodeType == Node.TEXT_NODE;
			}
		).wrap("<li class='active'><a href='#'><span>").text()
	});
	$('.paginate a').wrap('<li/>');
	$(".paginate li a:contains('Prev')").parent().prependTo('.pagination');
	$(".paginate li a:contains('Next')").parent().appendTo('.pagination');
	
	// SEarch Results
	$('#searchnext, #searchprev').wrap('<li></li>');
	$('#searchnext, #searchprev').parent().wrapAll('<ul class="pager"/>');
	$('#searchprev').parent().addClass('previous');
	$('#searchnext').parent().addClass('next');


	
	
	//responsive photogallery
	
	jQuery(".photogalleryTable").each(function(index,elem){
		var gallery = jQuery(elem),
		bootstrapGallery = jQuery('<div class="custom-gallery row"></div>');
		
		gallery.find(".photogalleryItem > a").each(function(index,elem){
			var galleryItem = jQuery(elem),
			image = galleryItem.find("img"),
			imageSrc = image.attr("src").split("?"),
			bootstrapGalleryItem = jQuery('<div class="col-sm-3 gallery-item" />');
			
			galleryItem.prop("href",imageSrc[0] + "?Action=thumbnail&Width=1200&Height=800&algorithm=fill_proportional");
			image.prop("src",imageSrc[0] + "?Action=thumbnail&Width=400&Height=300&algorithm=fill_proportional");
			image.addClass("thumbnail img-responsive");
	 
			bootstrapGalleryItem.append(galleryItem);
			bootstrapGallery.append(bootstrapGalleryItem);
		});
		
		gallery.after(bootstrapGallery);
		// Add Pager
		$('.photogalleryNavigation a').wrap('<li></li>');
		$('.photogalleryNavigation li').wrapAll('<ul class="pager"/>');
		$('.photogalleryNavigation ul').appendTo('.custom-gallery');
		$('.custom-gallery .pager li').first().addClass('previous');
		$('.custom-gallery .pager li').last().addClass('next');
			
		gallery.remove();
	});
	//Standard Gallery
	$('.gallery-item a').prop( "onclick", null ).removeAttr('onclick').removeAttr('rel').addClass('thumb fancy').attr('rel', 'group');
	
	//Advanced Gallery
	$('.gallery-item').first().clone().insertBefore('.custom-gallery').addClass('main');
	$('.custom-gallery .gallery-item').removeClass('col-sm-3').addClass('col-md-6').wrapAll('<div class="col-sm-3"/>');
	$('.gallery-item.main').removeClass('col-sm-3').wrapAll('<div class="col-sm-9"/>');
	$('.custom-gallery .gallery-item a').removeClass('fancy');
	
	var s = $('.gallery-item.main img').attr("src");
	if(typeof s !== 'undefined'){
		s = s.substring(0, s.indexOf('?'));
	}
	$('.gallery-item.main img').prop("src",s + "?Action=thumbnail&Width=1200&Height=800&algorithm=fill_proportional");
	
	
	$('.custom-gallery .gallery-item a').on("click",function(e){
		e.preventDefault();
		var newSource = $(this).attr('href');
		$('.gallery-item.main img').prop("src", newSource);
	});


	

	// Favorites
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

	

	// Blog Controls
	$('.blogs .sidebar-section .blog-controls ul').addClass('list-group');
	$('.blogs .sidebar-section .blog-controls ul li').addClass('list-group-item');


	// BOOTSTRAP FORMS
	//General Form style overrides
	$('input, textarea, select').addClass('form-control');
	$('input[type=submit], input[type=radio], input[type=checkbox]').removeClass('form-control');
	
	$('input[type=submit]').addClass('btn btn-primary');
	// Reset Layout
	$('.content form[name*=catwebform]:not(".skip-form-reset")').each(function() {
		$(this).wrapAll($('<div class="content-form"/>'));
	});
	
	var contentForm = $('.content-form');
	contentForm.find('table').each(function() {
		$(this).replaceWith($(this).html()
			.replace(/<tbody/gi, "<div class='row'")
			.replace(/<tr/gi, "<div class='col-sm-12'><div class='form-group'")
			.replace(/<\/tr>/gi, "</div></div>")
			.replace(/<td/gi, "<div")
			.replace(/<\/td>/gi, "</div>")
			.replace(/<\/tbody/gi, "<\/div")
		);
	});
	contentForm.find('input[type=text], textarea, select').addClass('form-control');
	contentForm.find('input[type=checkbox]').each(function(){
		$(this).parent().addClass('hide').addClass('form-label');
		$(this).prev("label").appendTo($(this).parent().parent());
		$(this).appendTo($(this).parent().parent()).wrap('<div class="checkbox"><label>');
		$(this).after($(this).val());
		$('.form-group .form-label.hide label').prependTo($(this).parent().parent().parent());
	});
	contentForm.find('input[type=radio]').each(function(){
		$(this).parent().addClass('hide').addClass('form-label');
		$(this).prev("label").appendTo($(this).parent().parent());
		$(this).appendTo($(this).parent().parent()).wrap('<div class="radio"><label>');
		$(this).after($(this).val());
		$('.form-group .form-label.hide label').prependTo($(this).parent().parent().parent());
	});
	contentForm.find('input[type=submit]').removeClass('form-control').addClass('btn btn-primary pull-right');
	// Remove Title
	contentForm.find('select[name=Title]').parent().parent().remove();
	// Split Name Layout
	contentForm.find('input[name=FirstName]').parent().parent().parent().addClass('col-sm-6');
	contentForm.find('input[name=LastName]').parent().parent().parent().addClass('col-sm-6');
	// Split Address Layout
	contentForm.find('input[name=WorkCity]').parent().parent().parent().addClass('col-sm-6');
	contentForm.find('input[name=WorkState]').parent().parent().parent().addClass('col-sm-4');
	contentForm.find('label[for=WorkZip]').html('Zip Code *');
	contentForm.find('input[name=WorkZip]').parent().parent().parent().addClass('col-sm-2');
	contentForm.find('select[name=WorkCountry]').parent().parent().parent().remove();
	// Remove <br>
	contentForm.find('br').remove();	
	
	// Update Date Picker //
	if ($('#DOB').length > 0) {
		$('#DOB').prop("onfocus", null).removeAttr('onfocus').removeAttr('title');
		$('#DOB').datepicker({
			toggleActive: true
		});	
	}
	
	 // Dynamic Form Action
	 //contentForm.find('form').attr('action', function(i, value) {
	 //	facility = facility.replace('/', '%2f');
	 //	return value + "&CID=0&SendInvoice=true";
	 //});	
	
	// When on 'worldsecuresystems.com', replace all internal links so user stays on that domain
	if (window.location.href.indexOf('.worldsecuresystems.com') > -1) {
		$("a[href^='/']").each(function() {
			var linkURL = $(this).attr('href');
			if (linkURL === undefined) {
				return true;
			} else if (linkURL === '#login'){
				var newURL = linkURL.replace(/\//g, '');
				$(this).attr('href', newURL);
			} else {
				var newURL = page + linkURL.replace(/\//g, '');
				$(this).attr('href', newURL);
			}
		});
	}
	
	
	
	/////////// BC FIXES ///////////
});

window.addToCartButtonClick = function(catalogId,productId,frame){
	AddToCart(catalogId,productId,'',frame,'','',false);
	$('.dropdown-toggle').dropdown(); // rerun the Bootstrap dropdowns
};

 window.alert = function(msg) {
	msg = msg.replace('ERROR: ','');
	$('.msg').text(msg);
	$('.msg').parent().fadeIn().delay(5000).fadeOut()
 }

$(document).ready(function() {
	
	$('.pager .slide1').addClass('active');
	$('.cycle-slideshow').on('cycle-after', function(e, opts) {
		console.log(opts.slideNum);
		var current = opts.slideNum;
		var previous = current - 1;
		console.log(previous + '|' + current);
		$('.pager a').removeClass('active');
		$('.pager .slide' + current).addClass('active');
	});
	
	if ($('.nav-accordion').length > 0) {
		$(".nav-accordion li:has(ul li)").find("a:first").addClass("subs");
		$( "<i class='fa fa-angle-down'></i>" ).appendTo( ".nav-accordion .subs" );
		$('.nav-accordion .subs i').on("click",function(e){
			e.preventDefault();
			$(this).parent().parent().find('ul:first').toggle();
		});
	}
	
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
	$(".signin-box").fancybox({
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
    jQuery(window).on("scroll",function() {
        if (jQuery(this).scrollTop() > offset) {
            jQuery('.back-to-top').fadeIn(duration);
        } else {
            jQuery('.back-to-top').fadeOut(duration);
        }
    });
    
    jQuery('.back-to-top').on("click",function(event) {
        event.preventDefault();
        jQuery('html, body').animate({scrollTop: 0}, duration);
        return false;
    });
});


