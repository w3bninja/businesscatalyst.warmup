{% capture results -%}{module_webappsresults}{% endcapture -%}
{% capture results_map -%}{module_webappsresultsmap}{% endcapture -%}
{% if results_map != '' -%}
    {{results_map}}
{% else -%}
    {module_webappsmap id="{{location_id}}" filter="all"}
{% endif -%}


<form name="catcustomcontentform62354" method="post" onsubmit="return checkWholeForm62354(this)" action="/Default.aspx?CCID={{location_id}}&amp;FID=533576&amp;ExcludeBoolFalse=True&amp;PageID={module_oid}">
<div class="row">
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




{% if results != '' -%}
    {{results}}
{% else -%}
    {module_webapps id="{{location_id}}" filter="all"}
{% endif -%}
