<!--Needs: opts|Email|Physical Address|Phone Number-->
{% assign Custom = "opts|Size|Filter|Recess|Top|Bottom|Side" -%}
{% assign sectionTitle = "Shade Details" -%}

{% capture capturedetails %}{tag_capturedetails}{% endcapture %}
{% if Custom contains 'opts' and capturedetails != ''%}
    {% assign CustomFields = Custom | remove: 'opts' %}
    {% assign CustomFields = CustomFields | split: '|' %}
    <script>var CustomFields = "{{Custom}}";</script>
    
    <h3 class="line">{{sectionTitle}}</h3><br>
    <div id="custom-fields" class="alert alert-info">
        {% for option in CustomFields -%}
            <div class="form-group">
                <label class="control-label">{{option}}</label>
                <input type="text" class="form-control {{option | replace: ' ', '-' | downcase}}">
            </div>
        {% endfor -%}
    </div>
    <div id="capturedetails" class="hidden">{tag_capturedetails}</div>
{% endif %}

<script>
$(function () {
//Custom Valules for items that can be customized
	$("#custom-fields input").change(function() {
		var customFieldData = $('.line').text() + "\n";
		$("#custom-fields input").each(function(index) {
			if ($(this).val()) {
				customFieldData = customFieldData + $(this).parent().find('label').text() + ": " + $(this).val() + "\n";
			}
		});
		$('#capturedetails textarea').val(customFieldData);
	});
	
	$("#custom-fields input").keyup(function() {
		$("#custom-fields input").each(function(index, el) {

			var text = $(el).val();
			var className = '.' + el.className;

			if ($(el).val()) {
				$('.main-image .proofing').find(className).text(text).removeClass('hide');
				console.error(text);
			} else {
				$('.main-image .proofing').find(className).addClass('hide');
			}
		});
	});
});
</script>