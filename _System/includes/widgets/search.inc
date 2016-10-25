{% comment -%}
{% assign searchID = "4425" -%}
{% assign resultsPageID = "/search" -%}
{% endcomment -%}

{% if searchUsage == 'template' %}
	<div class="search">
		<div class="site-search">
			<form name="seach" method="GET" action="/search">
				<div class="input-group">
					<input class="form-control site-search" type="text" name="CAT_Search" id="CAT_Search" placeholder="Search">
					<span class="input-group-addon">
						<input type="submit" value="">
						<i class="fa fa-search"></i>
					</span>
				</div>
			</form>
		</div>
	</div>
{% else %}
	<form name="seach" method="GET" action="/search">
		<div class="input-group">
			<input type="text" placeholder="{{searchQuery}}" name="CAT_Search" class="form-control input-lg">
			<div class="input-group-btn">
				<button class="btn btn-lg btn-primary" type="submit">Search</button>
			</div>
		</div>
	</form>
{% endif %}
