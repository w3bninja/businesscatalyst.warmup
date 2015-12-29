{% comment -%}
{% assign searchID = "4425" -%}
{% assign resultsPageID = "/search" -%}
{% assign layout = "full" -%}
{% endcomment -%}

{% if layout == 'full' -%}
<h2>Site Search</h2>
{% endif -%}
<div class="site-search">
	<form name="catsearchform11819" method="post" action="/Default.aspx?SiteSearchID={{searchID}}&amp;PageID={{resultsPageID}}">
		<div class="input-group">
			<input class="form-control" type="text" name="CAT_Search" id="CAT_Search" placeholder="Search">
			<span class="input-group-addon"><input type="submit" value="Search"></span>
		</div>
	</form>
</div>
{% if layout == 'full' -%}
<hr />
{module_searchresults,,5}
{% endif -%}