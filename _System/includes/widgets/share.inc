{% comment -%}
{% assign title = "" -%}
{% assign text = "" -%}
{% assign image = "" -%}
{% assign url = "" -%}
{% include "/_System/includes/widgets/share.inc" -%}
{% endcomment -%}
{% capture titleDefault -%}{module_pagename}{% endcapture -%}
{% capture textDefault -%}{module_pagetitle}{% endcapture -%}
{% capture textLink -%}{module_pageaddress}{% endcapture -%}
{% assign title = titleDefault -%}
{% assign text = textDefault -%}
{% assign image = "" -%}
{% assign url = textLink -%}

<script type="text/javascript" src="/assets/js/SocialShare.min.js"></script>
<script>
var shareTitle = "{{title}}";
var shareText = "{{text}}";
var shareImage = "{{image}}";
var shareLink = "{{url}}";
$(document).ready(function(){
	$('.share').ShareLink({
		title: shareTitle, // title for share message
		text: shareText, // text for share message
		image: 'http://my-site-url.com/images/funny-cats.png', // optional image for share message (not for all networks)
		url: shareLink, // link on shared page
		class_prefix: 's_', // optional class prefix for share elements (buttons or links or everything), default: 's_'
		width: 640, // optional popup initial width
		height: 480 // optional popup initial height
	});
	
	
	$('.counter').ShareCounter({
		url: 'http://my-site-url.com/my-article.html', // url for which you want show like counter
		class_prefix: 'c_', // optional class prefix for counter elements, default: 'c_'
		display_counter_from: 0 // optional to set when counter is display, default: 0
	});
});
</script>


<a class="btn btn-default share s_twitter" title="Twitter"><i class="fa fa-twitter"></i></a>
<a class="btn btn-default share s_facebook" title="Facebook"><i class="fa fa-facebook"></i></a>
<a class="btn btn-default share s_pinterest" title="Pinterest"><i class="fa fa-pinterest"></i></a>
<a class="btn btn-default share s_linkedin" title="LinkedIn"><i class="fa fa-linkedin"></i></a>