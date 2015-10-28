{% if isloggedin == 1 -%}
                        Welcome, {module_username}. {module_logout} | {module_webapps id="34049" filter="all"}
                    {% else -%}
                        <a href="#login" class="various btn btn-default">Login</a>
<div id="signup" style="display:none;width:500px;">
<a href="#login" class="various btn btn-default">Cancel</a>
{module_webform id="501228"}</div>
                        <div id="login" style="display:none;width:500px;">
                            <div class="secure-login">
                                <h3>LOGIN</h3>
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
<a href="#signup" class="various">Signup</a>
                            </div>
                            <br /> </div>
                    {% endif -%}
