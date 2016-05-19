<script src="/assets/js/searchfilter.js"></script>
<script src="//maps.googleapis.com/maps/api/js?v=3&sensor=false&key=" type="text/javascript"></script>
<script src="/assets/js/custom_gmaps.js" type="text/javascript"></script>
<script src="/assets/js/google_markerclusterer.js" type="text/javascript"></script>
<div id="webapp-map" style="height: 400px; width: 100%;"></div>

{module_webappsresults collection="results" template=""}
{module_webapps id="{{app_id}}" filter="all" collection="locations" template=""}

<script type="text/javascript">
    var locations = {{locations.['items'] | json}};
    //convert locations into a format that buscat's gmapinit script likes. format is: []
    var convertedPoints = locations.map(function(location,index){
        return [0,0,index+1,location.name,"",[location.address1,location.city,location.state,location.zipcode].join(',')];
    });
    CMS.Maps.Initialize({
        id:"webapp-map",
        width:400,
        points:convertedPoints
    });
</script>

{% if page_url contains "PageID" -%}
	{% if map.items != null -%}
		{module_webappsresultsmap}
    {% else -%}
        
    {% endif -%}
{% else -%}
    {%comment%}
    {module_webappsmap id="{{app_id}}" filter="all"}
    {%endcomment%}
{% endif -%}

<div class="location-search">
<form name="catcustomcontentform62354" method="post" onsubmit="return checkWholeForm62354(this)" action="/Default.aspx?CCID={{app_id}}&amp;FID=533576&amp;ExcludeBoolFalse=True&amp;PageID={module_oid}">
<div class="row" data-search-key="location">
	<div class="col-sm-3">
        <label for="CAT_txtKeywords">Keywords</label>
        <input type="text" name="CAT_txtKeywords" id="CAT_txtKeywords" class="cat_textbox" maxlength="255">
    </div>
    <div class="col-sm-3">
    	<label for="Postcode_31768">Search by Zipcode</label>
        <input type="text" maxlength="255" name="Postcode_31768" id="Postcode_31768" class="cat_textbox">
    </div>
    <div class="col-sm-3">
    	<input type="hidden" id="Country_31768" name="Country_31768" value="US">
        <label for="Distance_31768">Distance</label>
        <select name="Distance_31768" id="Distance_31768" class="cat_dropdown">
            <option value="5">5 miles</option>
            <option value="10">10 miles</option>
            <option value="20">20 miles</option>
            <option value="50">50 miles</option>
            <option value="100">100 miles</option>
        </select>
    </div>
    <div class="col-sm-3">
    	<label>&nbsp;</label>
    	<input class="cat_button" type="submit" value="Search">
    </div>
</div>
</form>
<script type="text/javascript" src="/CatalystScripts/ValidationFunctions.js?vs=b1857.r474501-phase1"></script>
<script type="text/javascript">
    function checkWholeForm62354(theForm) {
        var why = "";
        if (why != "") {
            alert(why);
            return false;
        }
        return true;
    }
</script>
</div>




{% if page_url contains "PageID" -%}
	{% if results.items != null -%}
		{module_webappsresults}
    {% else -%}
        No Results Found.
    {% endif -%}
{% else -%}
	{module_webapps id="{{app_id}}" filter="all"}
{% endif -%}
