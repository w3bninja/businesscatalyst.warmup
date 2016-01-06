{% if isloggedin == 1 -%}
	
    <div class="dropdown">
      <button class="btn btn-default dropdown-toggle" type="button" id="dropdownMenu1" data-toggle="dropdown" aria-haspopup="true" aria-expanded="true">
        {module_username}
        <span class="caret"></span>
      </button>
      <ul class="dropdown-menu" aria-labelledby="dropdownMenu1">
        {module_webapps id="34049" filter="all"}
        <li role="separator" class="divider"></li>
        <li>{module_logout}</li>
      </ul>
    </div>

						
						
						
{% else -%}
    <a href="#login" class="signin-box btn btn-default">Login</a>
    
    
    <div id="signup" style="display:none;">
    <div class="panel panel-default secure-login">
                <div class="panel-heading">Signup</div>
                    <div class="panel-body">
                        {module_webform id="501228"}
                    </div>
        <div class="panel-footer"><a href="#login" class="various">Back to Login</a></div>
    </div>
</div>



<div id="login" style="display:none;">
    <div class="panel panel-default secure-login">
        <div class="panel-heading">Login</div>
            <div class="panel-body">
        <form name="catseczoneform76507" onsubmit="return checkWholeForm76507(this)" method="post" action="https://envoc.worldsecuresystems.com/ZoneProcess.aspx?ZoneID=51&amp;Referrer={module_siteUrl,true,true}&amp;OID={module_oid}&amp;OTYPE={module_otype}">
            <div class="form">
                <div class="item">
                    <label for="SZUsername">Username</label>
                    <br />
                    <input class="cat_textbox_small" type="text" name="Username" id="SZUsername" maxlength="255"> </div>
                <div class="item">
                    <label for="SZPassword">Password</label>
                    <br />
                    <input class="cat_textbox_small" type="password" name="Password" id="SZPassword" maxlength="255" autocomplete="off"> </div>
                <div class="item">
                    <input type="checkbox" name="RememberMe" id="RememberMe">
                    <label for="RememberMe">Remember Me</label>
                </div>
                <div class="item">
                    <input class="cat_button" type="submit" value="Log in">&nbsp;<a href="/_System/SystemPages/PasswordRetrieveRequest">Lost password?</a> </div>
            </div>
            <script type="text/javascript" src="/CatalystScripts/ValidationFunctions.js?vs=b1766.r468257-phase1"></script>
            <script type="text/javascript">
                //<![CDATA[
                function checkWholeForm76507(theForm) {
                        var why = "";
                        if (theForm.Username) why += isEmpty(theForm.Username.value, "Username");
                        if (theForm.Password) why += isEmpty(theForm.Password.value, "Password");
                        if (why != "") {
                            alert(why);
                            return false;
                        }
                        theForm.submit();
                        return false;
                    }
                    //]]>
            </script>
        </form>
        </div>
        <div class="panel-footer"><a href="#signup" class="signin-box">Signup</a></div>
    </div>
</div>
{% endif -%}