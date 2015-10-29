{% comment -%}MENU{% endcomment -%}
{% assign menu-type = menu-type | default: "stripped" -%}
{% assign menu-type-value = menu-type-value | default: "stripped" -%}
{% if menu-type == menu-type-value -%}
	{% assign menu-type = menu-type -%}
{% else -%}
	{% assign menu-type = menu-type-value   -%}
{% endif -%}


{module_menu, version="2", menuId="{{menu_id | default: "1931027"}}", moduleTemplateGroup="{{menu-type}}"}