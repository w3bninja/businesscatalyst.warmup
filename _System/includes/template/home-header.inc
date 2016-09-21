{% comment -%}
{% assign header_appID = "" %}
{% assign header_classID = "" %}
{% endcomment -%}
{module_webapps template="" id="{{header_appID | default: "31770"}}" filter="classified" itemId="{{header_classID | default: "669308"}}" collection="HeaderCount"}
<div class="banner">
	<div class="banner-inner">
        <div class="cycle-slideshow" data-cycle-fx="fadeout" data-cycle-log="true" data-cycle-timeout="5000" data-cycle-pause-on-hover="true" data-cycle-slides="> div" data-cycle-pager="#pager" data-cycle-pager-template="<a href='#' class='slide{{slideNum}}'> {{slideNum}} </a>" data-cycle-prev="#prev" data-cycle-next="#next" data-cycle-log="false" data-cycle-auto-height="container">
        {module_webapps render="item" template="/_System/includes/template-content/home-slide.tpl" id="{{header_appID | default: "31770"}}" filter="classified" itemId="{{header_classID | default: "669308"}}"}
        </div>
    </div>
    {% if HeaderCount.items.size > 1 -%}
    <div id="pager" class="pager controls"></div>
    <div class="pager-arrows">
    	<a href="#" class="prev" id="prev"><i class="fa fa-angle-left"></i></a>
        <a href="#" class="next" id="next"><i class="fa fa-angle-right"></i></a>
    </div>
    {% endif -%}
</div>