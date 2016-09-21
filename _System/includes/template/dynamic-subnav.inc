{% comment -%}
<!--@formatter:off-->
<!--
    This will loop three levels into the menu structure, and render the
    sidebar with the appropriate "(un)selected item" markup.
    NB: As `globals.get.ID` is not available in In-Context Editing,
    this does not work in ICE mode. You may consider using
    [this javascript-based helper]()
    to dynamically bring a working copy into ICE mode from the front-end.
    Calling tag looks like:
        {module_menu render="collection" menuId="1422388" template="/_System/Apps/site-assets/public/assets/partials/side-nav.tpl" collection="sideNav"}
    Toggle item behaviour with:
    * # `suppress-from-side-nav` (id field)
      If this string is present in the `Item ID Name` field of a top-level
      item, this item (and its descendants) will not appear in the side nav.
    Item schema:
        {
          "id": 685779,
          "parentId": -1,
          "label": "Lateral Irrigators",
          "tooltip": "",
          "url": "/lateral-irrigators",
          "targetFrame": "",
          "image": "",
          "imageOver": "",
          "imageSelected": "",
          "idName": "",
          "css": "",
          "cssOver": "",
          "cssSelected": "",
          "width": "",
          "height": "",
          "items":  [ ... ]
        },
-->
{% endcomment -%}
<!--globals.get: {{ globals | json | escape }}-->
{% assign activeMenuItemIds = "" -%}
{% assign outermostNavItem_L1 = null -%}
{% assign outermostNavItem_L2 = null -%}
{% for i in items %}
    {% assign itemUrlLength = i.url | size -%}
    {% assign currentPath = globals.get.ID | slice: 0, itemUrlLength | downcase -%}
    {% assign itemPath = i.url | downcase -%}
    {% if currentPath == itemPath  -%}
        {% assign activeMenuItemIds = activeMenuItemIds | append: i.id | append: "," -%}
    {% endif -%}
    {% for j in i.items -%}
        {% assign itemUrlLength = j.url | size -%}
        {% assign currentPath = globals.get.ID | slice: 0, itemUrlLength | downcase -%}
        {% assign itemPath = j.url | downcase -%}
        {% if currentPath == itemPath  -%}
            {% assign activeMenuItemIds = activeMenuItemIds | append: i.id | append: "," -%}
            {% assign activeMenuItemIds = activeMenuItemIds | append: j.id | append: "," -%}
            {% assign outermostNavItem_L1 = i.id -%}
        {% endif -%}
        {% for k in j.items -%}
            {% assign itemUrlLength = k.url | size -%}
            {% assign currentPath = globals.get.ID | slice: 0, itemUrlLength -%}
            {% assign itemPath = k.url | downcase -%}
            {% if currentPath == itemPath  -%}
                {% assign activeMenuItemIds = activeMenuItemIds | append: i.id | append: "," -%}
                {% assign activeMenuItemIds = activeMenuItemIds | append: j.id | append: "," -%}
                {% assign activeMenuItemIds = activeMenuItemIds | append: k.id | append: "," -%}
                {% assign outermostNavItem_L1 = i.id -%}
                {% assign outermostNavItem_L2 = j.id -%}
            {% endif -%}
        {% endfor -%}
    {% endfor -%}
{% endfor -%}
{% assign activeMenuItemIdsArray = activeMenuItemIds | split: "," -%}
<!--outermostNavItem_L1: `{{ outermostNavItem_L1 }}`-->
<!--outermostNavItem_L2: `{{ outermostNavItem_L2 }}`-->
<pre class="hidden" title="activeMenuItemIdsArray"><code>{{ activeMenuItemIdsArray | json | escape }}</code></pre>
<!-- BEGIN: LAYOUT/SIDEBARS/SIDEBAR-MENU-1 -->
<div class="c-sidebar-menu-toggler">
    <h3 class="c-title c-font-uppercase c-font-bold">Navigation</h3>
    <a href="javascript:;" class="c-content-toggler" data-toggle="collapse" data-target="#sidebar-menu-1">
        <span class="c-line"></span>
        <span class="c-line"></span>
        <span class="c-line"></span>
    </a>
</div>
    <ul class="c-sidebar-menu collapse nav-level__1st" id="sidebar-menu-1"
        data-pull-copy-for-ice-mode-from-id="sidebar-menu-1"
        data-ice-tooltip="menu-generic"
        data-itemid="{{ menuId }}">
        
        {% if items %}
            {% for i in items %}
                {% unless i.idName contains "suppress-from-side-nav" -%}
                    {% unless outermostNavItem_L1 and outermostNavItem_L1 != i.id -%}
                        {% assign itemId = i.id | append: "" -%}
                        {% if activeMenuItemIdsArray contains itemId -%}
                            {% assign activeIndicators = "c-active c-open" -%}
                        {% else -%}
                            {% assign activeIndicators = "" -%}
                        {% endif -%}
                        <li class="{{ i.class }} c-dropdown {{ activeIndicators }}" data-menu-item-id="{{ i.id }}">
                            {% if i.items -%}
                                {% if outermostNavItem_L2 and outermostNavItem_L2 != empty -%}
                                    <a href="javascript:;" class="c-toggler hidden">
                                        {{ i.label }}
                                    </a>
                                {% else -%}
                                    <a href="javascript:;" class="c-toggler">
                                        {{ i.label }}
                                    </a>
                                {% endif -%}
                            {% else -%}
                                <a href="{{ i.url }}" class="">
                                    {{ i.label }}
                                </a>
                            {% endif -%}
                            {% if i.items %}
                                <ul class="nav-level__2nd c-dropdown-menu collapse">
                                    {% for j in i.items %}
                                        {% unless outermostNavItem_L2 and outermostNavItem_L2 != j.id -%}
                                            {% assign itemId = j.id | append: "" -%}
                                            {% if activeMenuItemIdsArray contains itemId -%}
                                                {% assign activeIndicators = "c-active c-open" -%}
                                                <!--active item id: {{ itemid }}-->
                                            {% else -%}
                                                {% assign activeIndicators = "" -%}
                                            {% endif -%}
                                            <li class="dropdown-submenu c-dropdown {{ j.class }} {{ activeIndicators }}"
                                                data-menu-item-id="{{ j.id }}">
                                                {% if j.items -%}
                                                    {% if outermostNavItem_L2 == j.id -%}
                                                        <a href="javascript:;" class="surrogate-top-level-sidenav-item">
                                                            {{ j.label }}
                                                        </a>
                                                    {% else -%}
                                                        <a href="javascript:;" class="c-toggler">
                                                            {{ j.label }}
                                                        </a>
                                                    {% endif -%}
                                                {% else -%}
                                                    <a href="{{ j.url }}" class="">
                                                        {{ j.label }}
                                                    </a>
                                                {% endif -%}
                                                {% if j.items %}
                                                    <ul class="nav-level__3rd c-dropdown-menu collapse">
                                                        {% for k in j.items %}
                                                            {% assign itemId = k.id | append: "" -%}
                                                            {% if activeMenuItemIdsArray contains itemId -%}
                                                                {% assign activeIndicators = "c-active c-open" -%}
                                                            {% else -%}
                                                                {% assign activeIndicators = "" -%}
                                                            {% endif -%}
                                                            <li class="dropdown-submenu c-dropdown {{ k.class }} {{ activeIndicators }}"
                                                                data-menu-item-id="{{ i.id }}">
                                                                <a href="{{ k.url }}">{{ k.label }}</a>
                                                            </li>
                                                        {% endfor %}
                                                    </ul>
                                                {% endif %}
                                            </li>
                                        {% endunless -%}
                                    {% endfor %}
                                </ul>
                            {% endif %}
                        </li>
                    {% endunless -%}
                {% endunless -%}
            {% endfor %}
        {% endif %}
    </ul>
<!-- END: LAYOUT/SIDEBARS/SIDEBAR-MENU-1 -->