{% if comments == 1 -%}

{module_ratingfeedback}
<hr>
<div class="comment-form">
    <h3>Comment</h3>
    <form name="catratingform56897" onsubmit="return checkWholeForm56897(this)" method="post" action="/RatingProcess.aspx?OID={module_oid}&amp;OTYPE={module_otype}">
        <div class="form">
            <div class="item">
                <label>Was this helpful?</label>
                <br>No
                <input type="radio" name="Rating" value="1">
                <input type="radio" name="Rating" value="2">
                <input type="radio" name="Rating" checked="checked" value="3">
                <input type="radio" name="Rating" value="4">
                <input type="radio" name="Rating" value="5">Very</div>
            <div class="item">
                <label id="RFeedback">Do you have feedback? (Optional)</label>
                <br>
                <textarea class="comment" name="Feedback" id="RFeedback" cols="10" rows="4"></textarea>
            </div>
            <div class="item">
                <label id="RFullName">Name (Optional)</label>
                <br>
                <input class="cat_textbox_small" type="text" name="FullName" id="RFullName" maxlength="255">
            </div>
            <div class="item">
                <label id="RWebsite">Website (Optional)</label>
                <br>
                <input class="cat_textbox_small" type="text" name="Website" id="RWebsite" maxlength="255">
            </div>
            <div class="item">
                <label id="REmailAddress">Email Address (Optional)</label>
                <br>
                <input class="cat_textbox_small" type="text" name="EmailAddress" id="REmailAddress" maxlength="255">
            </div>
            <div class="item">
                <label>Enter Word Verification in box below •</label>
                <br>{module_captchav2}</div>
            <div class="item">
                <input class="cat_button" type="submit" value="Submit">
            </div>
        </div>
        <script type="text/javascript" src="/CatalystScripts/ValidationFunctions.js?vs=b1829.r473174-phase1"></script>
        <script type="text/javascript">
            //<![CDATA[
            function checkWholeForm56897(theForm) {
                    var why = "";
                    if (theForm.EmailAddress)
                        if (theForm.EmailAddress.value.length > 0) why += checkEmail(theForm.EmailAddress.value);
                    if (theForm.CaptchaV2) why += captchaIsInvalid(theForm, "Enter Word Verification in box below",
                        "Please enter the correct Word Verification as seen in the image");
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

{% endif -%}