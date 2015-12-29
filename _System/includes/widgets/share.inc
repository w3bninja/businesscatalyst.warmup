{% comment -%}
{% assign title = "" -%}
{% assign text = "" -%}
{% assign image = "" -%}
{% assign url = "" -%}
{% endcomment -%}

<script type="text/javascript" src="https://rawgit.com/AyumuKasuga/SocialShare/master/SocialShare.min.js"></script>
<script>
$(document).ready(function(){
	$('.share').ShareLink({
		title: 'My great post', // title for share message
		text: 'text of my great post', // text for share message
		image: 'http://my-site-url.com/images/funny-cats.png', // optional image for share message (not for all networks)
		url: 'http://my-site-url.com/my-article.html', // link on shared page
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