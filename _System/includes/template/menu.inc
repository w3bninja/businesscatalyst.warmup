{% comment -%}
{% assign menu-sub-only = "true" -%}
{% assign showMenuParentTitle = "true" -%}
{% assign menu-type-value ="accordion" -%}
{% assign menuCustom = "true" -%}
{% include "/_System/includes/template/menu.inc" -%}
{% endcomment -%}

{% comment -%}MENU{% endcomment -%}
{% assign menu-type = menu-type | default: "stripped" -%}
{% assign menu-type-value = menu-type-value | default: "stripped" -%}
{% if menu-type == menu-type-value -%}
	{% assign menu-type = menu-type -%}
{% else -%}
	{% assign menu-type = menu-type-value   -%}
{% endif -%}


{% if menuCustom == "true" -%}
	{% capture page_url -%}{module_pageaddress}{% endcapture -%}
	{% capture is_home -%}http://{module_sitehost}/{% endcapture -%}
	{module_menu, version="2", menuId="{{menu_id | default: "1931027"}}", moduleTemplateGroup="{{menu-type}}" collection="menu" template=""}
    
    
    
    {% if menu-type-value == "stripped" -%}
    	{% assign menuClasses = menuClasses | default: "nav navbar-default nav-justified" -%}
        <div class="navigation hidden-xs">
		<div class="navigation-inner main-nav clearfix">
        <div id="Menu">
    {% else -%}
    	{% assign menuClasses = "nav-accordion nav nav-pills nav-stacked" -%}
        <div class="nav-accordion-outer">
    {% endif -%}
    
	{% comment -%}SET CURRENT PARENT URL{% endcomment -%}
   	{% assign currentURL = page_url | remove: is_home | prepend: "/" -%}
	{% assign currentURLParent = currentURL | split: "/" -%}
	{% assign currentURLParent = currentURLParent | join: "","" -%}
	{% for urlPiece in currentURLParent -%}
    	{% if forloop.first -%}
       		{% assign currentParentURL = urlPiece | prepend: "/" | downcase -%}
            {% assign currentParentName = urlPiece | capitalize | split: "-" | join: " " -%}
        {% endif -%}
	{% endfor -%}
	
	
	{% comment -%}CUSTOM MENU{% endcomment -%}
    {% if showMenuParentTitle == "true" -%}
    	<h2>{{currentParentName}}</h2>
    {% endif -%}
    {% for item in menu.items -%}
    	{% assign index = forloop.index0 -%}
		{% if menu-sub-only != "true" -%}
			{% if forloop.first -%}<ul class="{{menuClasses}}">{% endif -%}
			<li{% if currentURL == item.url -%} class="active" {% endif -%}><a href="{{item.url}}">{{item.label}}</a>
		{% endif -%}
        
        
        {% if menu-type-value == "stripped" -%}
        	{% for subitem in menu.items[forloop.index0].items -%}
                {% if forloop.first -%}<ul{% if menu-sub-only == "true" or menu-type-value == "stripped" -%} class="{{menuClasses}}"{% endif -%}>{% endif -%}
                {% if subitem.parentId == item.id -%}
                    {% assign subindex = forloop.index0 -%}
                    <li{% if currentURL == subitem.url -%} class="active" {% endif -%}><a href="{{subitem.url}}"{% if subitem.items.size > 0 -%} class="subs"{% endif -%}>{{subitem.label}}{% if subitem.items.size > 0 -%}<i class="fa fa-chevron-right"></i>{% endif -%}</a>
                        {% for subsubitem in menu.items[index].items[forloop.index0].items -%}
                            {% assign subsubindex = forloop.index0 -%}
                            {% if forloop.first -%}<ul{% if menu-type-value == "stripped" -%} class="{{menuClasses}}"{% endif -%}>{% endif -%}
                            <li{% if currentURL == subsubitem.url -%} class="active" {% endif -%}><a href="{{subsubitem.url}}">{{subsubitem.label}}</a></li>
                            {% if forloop.last -%}</ul>{% endif -%}
                        {% endfor -%}
                    </li>
                {% endif -%}
                {% if forloop.last -%}</ul>{% endif -%}
            {% endfor -%}
        {% else -%}
            {% if currentParentURL == item.url -%}
                {% for subitem in menu.items[forloop.index0].items -%}
                    {% if forloop.first -%}<ul{% if menu-sub-only == "true" or menu-type-value == "stripped" -%} class="{{menuClasses}}"{% endif -%}>{% endif -%}
                    {% if subitem.parentId == item.id -%}
                        {% assign subindex = forloop.index0 -%}
                        <li{% if currentURL == subitem.url -%} class="active" {% endif -%}><a href="{{subitem.url}}"{% if subitem.items.size > 0 -%} class="subs"{% endif -%}>{{subitem.label}}{% if subitem.items.size > 0 -%}<i class="fa fa-chevron-down"></i>{% endif -%}</a>
                            {% for subsubitem in menu.items[index].items[forloop.index0].items -%}
                                {% assign subsubindex = forloop.index0 -%}
                                {% if forloop.first -%}<ul{% if menu-type-value == "stripped" -%} class="{{menuClasses}}"{% endif -%}>{% endif -%}
                                <li{% if currentURL == subsubitem.url -%} class="active" {% endif -%}><a href="{{subsubitem.url}}">{{subsubitem.label}}</a></li>
                                {% if forloop.last -%}</ul>{% endif -%}
                            {% endfor -%}
                        </li>
                    {% endif -%}
                    {% if forloop.last -%}</ul>{% endif -%}
                {% endfor -%}
            {% endif -%}
        {% endif -%}
        
        
        
		
        
		{% if forloop.last -%}</ul>{% endif -%}
		{% if menu-sub-only != "true" -%}
			</li>
		{% endif -%}
		
    {% endfor -%}
     {% if menu-type-value == "stripped" -%}
    	{% assign menuClasses = "nav navbar-default nav-justified" -%}
        </div>
        </div>
        </div>
    {% else -%}
    	</div>
    {% endif -%}
    </div>
    
{% else -%}
	{module_menu, version="2", menuId="{{menu_id | default: "1931027"}}", moduleTemplateGroup="{{menu-type}}"}
{% endif -%}