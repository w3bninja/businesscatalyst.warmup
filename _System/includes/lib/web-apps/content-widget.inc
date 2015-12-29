{% comment -%}
{% assign tabAppID = "34305" -%}
{% assign tabClassID = "702228" -%}
{% endcomment -%}

{module_webapps id="{{tabAppID}}" filter="classified" itemId="{{tabClassID}}" collection="set1" template=""}
<div class="responsiveTabs">
  <ul class="tab-nav">
  	{% for item in set1.items -%}
    <li class="tab-li"><a href="#tab-{{item.counter}}" class="tab-label">{{item.["Tab Title"]}}</a></li>
   	{% endfor -%}
  </ul>
  {% for item in set1.items -%}
  <div class="tab-description" id="tab-{{item.counter}}">
    {{item.description}}
  </div>
  {% endfor -%}
</div>
