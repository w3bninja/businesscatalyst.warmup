{% assign appID = '31768' -%}
{% assign inputID = 'CAT_Custom_2158047' -%}
<script>
$(function () {
	$('.webbapp-select').insertBefore( $('#{{inputID}}') );
	$("select.webbapp-select").on("change", function () {    //when selected value changed
		$("input[type=text]#{{inputID}}").val($(this).val());  //change value in textbox
	});
	$('#{{inputID}}').addClass('hidden');
});
</script>
{module_webapps id="{{appID}}" filter="all" collection="webapp-selection" template=""}
<select class="webbapp-select">
	<option>Choose An Option</option>
{% for item in webapp-selection.items %}
	<option value="{{item.name}}">{{item.name}}</option>
{% endfor %}
</select>
