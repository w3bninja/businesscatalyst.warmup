<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1, maximum-scale=1, user-scalable=no">
<title>{module_pagetitle}</title>


<link rel="shortcut icon" type="image/x-icon" href="/favicon.ico" />

<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.2.0/css/bootstrap.min.css">
<link href="/assets/css/font-awesome.min.css" rel="stylesheet">
<link href="/assets/css/styles.css" rel="stylesheet">
<link href="/assets/css/nav.css" rel="stylesheet">

<link href="/assets/css/template.css" rel="stylesheet">


<script type="text/javascript" src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.1/jquery.min.js"></script>
<!-- ADD BOOTSTRAP JS -->
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.5/js/bootstrap.min.js"></script>
<script src="/assets/js/dropdown.js"></script>

<!-- ADD JPUSHMENU -->
<link href="/assets/css/jPushMenu.css" rel="stylesheet">
<script type="text/javascript" src="/assets/js/jPushMenu.js"></script>

<!-- ADD WEBTICKER -->
<link href="/assets/css/webticker.css" rel="stylesheet">
<script type="text/javascript" src="/assets/js/jquery.webticker.js"></script>

<!-- ADD CYCLE -->
<script type="text/javascript" src="/assets/js/jquery.cycle2.js"></script>
<script type="text/javascript" src="/assets/js/jquery.cycle2.carousel.min.js"></script>

<!-- ADD RESPONSIVE TABS -->
<link rel="stylesheet" href="/assets/css/responsive-tabs.css">
<script type="text/javascript" src="/assets/js/jquery.responsiveTabs.min.js"></script>

<!-- ADD DATE PICKER -->
<link href="/assets/css/bootstrap-datepicker.min.css" rel="stylesheet" />
<script type="text/javascript" src="/assets/js/bootstrap-datepicker.js"></script>

<!-- ADD FANCYBOX -->
<link rel="stylesheet" href="/assets/js/fancy/jquery.fancybox.css?v=2.1.5" type="text/css" media="screen" />
<script type="text/javascript" src="/assets/js/fancy/jquery.fancybox.pack.js?v=2.1.5"></script>

<!-- ANIMATIONS -->
<script src="/assets/js/jquery.inview.js"></script>

<!-- PARALLAX -->
<script src="/assets/js/parallax.min.js"></script>

<!-- GRID -->
<script type="text/javascript" src="//cdnjs.cloudflare.com/ajax/libs/masonry/3.1.5/masonry.pkgd.min.js"></script>
<script src="https://npmcdn.com/imagesloaded@4.1/imagesloaded.pkgd.min.js"></script>

<!-- FITVIDS -->
<script type="text/javascript" src="/assets/js/jquery.fitVids.js"></script>

<script type="text/javascript" src="/assets/js/javascript.js"></script>
<script>
	var page = "http://{module_sitehost}/"
</script>
{% if page_url contains "ZoneProcess.aspx" -%}
	{module_referreraddress collection="refer" template=""}
	{% capture referrer -%}{% for item in refer.referrer -%}{{item}}{% endfor -%}{% endcapture -%}
	<script>
		var referrer = "{{referrer}}";
		window.location = referrer + "?loginFailed=true";
		var page = "http://{module_sitehost}"
	</script>
{% endif -%}

{% if page_url contains "loginFailed" -%}
	<script>	
		$(document).ready(function() {	
			$('.btn-login').trigger('click');
		});
	</script>
{% endif -%}

