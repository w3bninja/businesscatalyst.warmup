{% comment -%}
{% assign contentAppID = "34305" -%}
{% assign contentClassID = "702228" -%}
{% assign contentLayout = "accordion" -%}
{% assign tabClasses = "" -%}
{% include "/_System/includes/lib/web-apps/content-widget.inc" -%}
{% endcomment -%}

{% if setCounter == null -%}
	{% assign setCounter = "0" -%}
{% endif -%}
{% assign contentClassID = contentClassID | default: "" -%}
{% assign tabClasses = tabClasses | default: "" -%}
{% if contentClassID == null -%}
	{module_webapps id="{{contentAppID}}" filter="classified" itemId="{{contentClassID}}" collection="set1" template=""}
{% else -%}
	{module_webapps id="{{contentAppID}}" filter="all" collection="set1" template=""}
{% endif -%}
<div class="responsiveTabs {{contentLayout | default:'tabs' }}">
  <ul class="tab-nav {{tabClasses}}">
  	{% for item in set1.items -%}
    <li class="tab-li">
    	<a href="#tab{{setCounter}}-{{item.counter}}" class="tab-label">
        	{module_webapps id="{{contentAppID}}" filter="item" itemId="{{item.itemid}}"}
    	</a>
    </li>
   	{% endfor -%}
  </ul>
  {% for item in set1.items -%}
  <div class="tab-description" id="tab{{setCounter}}-{{item.counter}}">
    {module_webapps id="{{contentAppID}}" filter="item" itemId="{{item.itemid}}" useBackupTemplate="true"}
  </div>
  {% endfor -%}
</div>
{% assign setCounter = setCounter | plus : 1 -%}