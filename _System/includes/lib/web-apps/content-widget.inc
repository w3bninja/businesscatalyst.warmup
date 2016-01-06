{% comment -%}
{% assign contentAppID = "34305" -%}
{% assign contentClassID = "702228" -%}
{% assign contentLayout = "accordion" -%}
{% endcomment -%}
{% if setCounter == null -%}
	{% assign setCounter = "0" -%}
{% endif -%}
{module_webapps id="{{tabAppID}}" filter="classified" itemId="{{tabClassID}}" collection="set1" template=""}
<div class="responsiveTabs {{contentLayout | default:'tabs' }}">
  <ul class="tab-nav">
  	{% for item in set1.items -%}
    <li class="tab-li"><a href="#tab{{setCounter}}-{{item.counter}}" class="tab-label">{{item.["Tab Title"]}}</a></li>
   	{% endfor -%}
  </ul>
  {% for item in set1.items -%}
  <div class="tab-description" id="tab{{setCounter}}-{{item.counter}}">
    {{item.description}}
  </div>
  {% endfor -%}
</div>
{% assign setCounter = setCounter | plus : 1 -%}