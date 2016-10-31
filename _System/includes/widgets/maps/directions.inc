<style>
.adp-placemark{margin:0; border:0;}
.adp-placemark td{padding:10px 20px;}
.adp-directions td{padding:10px; border-top:1px solid #EEE;}
</style>


        
        <script type="text/javascript">

    var map;
    var gdir;
    var geocoder = null;
    var addressMarker;
    
    function initialize() {
      if (GBrowserIsCompatible()) {      
        map = new GMap2(document.getElementById("map_canvas"));
        gdir = new GDirections(map, document.getElementById("directions"));
        GEvent.addListener(gdir, "load", onGDirectionsLoad);
        GEvent.addListener(gdir, "error", handleErrors);
    
        setDirections("New Orleans", "Baton Rouge General Medical Center, 8585 Picardy Avenue, Baton Rouge, Louisiana 70809", "en_US");
      }
    }
    
    function setDirections(fromAddress, toAddress, locale) {
      gdir.load("from: " + fromAddress + " to: " + toAddress,
                { "locale": locale });
    }
    
    function handleErrors(){
     if (gdir.getStatus().code == G_GEO_UNKNOWN_ADDRESS)
       alert("No corresponding geographic location could be found for one of the specified addresses. This may be due to the fact that the address is relatively new, or it may be incorrect.\nError code: " + gdir.getStatus().code);
     else if (gdir.getStatus().code == G_GEO_SERVER_ERROR)
       alert("A geocoding or directions request could not be successfully processed, yet the exact reason for the failure is not known.\n Error code: " + gdir.getStatus().code);
     
     else if (gdir.getStatus().code == G_GEO_MISSING_QUERY)
       alert("The HTTP q parameter was either missing or had no value. For geocoder requests, this means that an empty address was specified as input. For directions requests, this means that no query was specified in the input.\n Error code: " + gdir.getStatus().code);
    
    //   else if (gdir.getStatus().code == G_UNAVAILABLE_ADDRESS)  <--- Doc bug... this is either not defined, or Doc is wrong
    //     alert("The geocode for the given address or the route for the given directions query cannot be returned due to legal or contractual reasons.\n Error code: " + gdir.getStatus().code);
       
     else if (gdir.getStatus().code == G_GEO_BAD_KEY)
       alert("The given key is either invalid or does not match the domain for which it was given. \n Error code: " + gdir.getStatus().code);
    
     else if (gdir.getStatus().code == G_GEO_BAD_REQUEST)
       alert("A directions request could not be successfully parsed.\n Error code: " + gdir.getStatus().code);
      
     else alert("An unknown error occurred.");
    }
    
    function onGDirectionsLoad(){ 
        // Use this function to access information about the latest load()
        // results.
    
        // e.g.
        // document.getElementById("getStatus").innerHTML = gdir.getStatus().code;
      // and yada yada yada...
    }
    </script>
        <h2>Directions</h2>
        <p>To get directions to either of our locations, type your starting address in the "From" field then choose the appropriate campus from the drop down menu and click "Get Directions."</p>
        <table width="100%" class="directions">
  <tbody>
    <tr>
      <td style="padding: 5px; background-color: #eeeeee;">
      <form action="#" onsubmit="setDirections(this.from.value, this.to.value, this.locale.value); return false" class="form-inline">
      	<div class="row no-gutters">
        	<div class="col-sm-8">
            	<div class="input-group">
                <span class="input-group-addon"><label>From:</label></span>
                <input class="form-control" type="text" id="fromAddress" name="from" value="New Orleans" />
                <span class="input-group-addon"><label for="exampleInputEmail2">&nbsp;&nbsp;To:&nbsp;</label></span>
                
                <select class="form-control" id="toAddress" name="to">
                        
                    <option value="Baton Rouge General Medical Center, 8585 Picardy Avenue, Baton Rouge, LA 70809">Bluebonnet</option>
                    <input type="hidden" id="locale" name="locale" value="en" />        
                </select>
              </div>
            </div>
            <div class="col-sm-4"><input type="submit" name="submit" value="Get Directions!" class="btn btn-primary" /></div>
          </div>
        </form></td>
    </tr>
    <tr>
      <td valign="top">
      	<div class="row no-gutters">
      		<div class="col-sm-6">
            	<div id="map_canvas" style="width: 100%; height: 500px;"></div>
            </div>
      		<div class="col-sm-6">
            	<div id="directions" style="width:100%;"></div>
            </div>
      	</div>
        </td>
    </tr>
  </tbody>
</table>