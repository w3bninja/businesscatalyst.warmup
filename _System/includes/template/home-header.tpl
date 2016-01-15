{% comment -%}
{% assign header_appID = "" %}
{% assign header_classID = "" %}
{% endcomment -%}
<div class="banner">
	<div class="banner-inner">
        <div class="cycle-slideshow" data-cycle-fx="fadeout" data-cycle-timeout="5000" data-cycle-pause-on-hover="true" data-cycle-slides="> div" data-cycle-pager="#pager" data-cycle-pager-template="<strong><a href=#> {{slideNum}} </a></strong>" data-cycle-auto-height="container">
        {module_webapps render="item" template="/_System/includes/template-content/home_header.tpl"  id="{{header_appID | default: "31770"}}" filter="classified" itemId="{{header_classID | default: "669308"}}"}
        </div>
    </div>
    <div id="pager" class="controls"></div>
</div>