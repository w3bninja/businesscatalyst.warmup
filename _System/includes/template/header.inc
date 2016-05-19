<div class="nav-mobile cbp-spmenu cbp-spmenu-vertical cbp-spmenu-right">
    <div class="search">
        <form name="catsearchform11819" method="post" action="/Default.aspx?SiteSearchID=3896&amp;PageID=16462607">
            <div class="input-group">
                <input class="form-control" type="text" name="CAT_Search" id="CAT_Search" placeholder="Search">
                <span class="input-group-addon"><input type="submit" value=""><i class="fa fa-search"></i></span>
            </div>
        </form>
    </div>

    {% assign menu-type-value ="Accordion" -%}
    {% include "/_System/includes/template/menu.inc" -%}

</div>
<div class="bg">
<div class="header-line"></div>


<div class="header clearfix">
	<div class="container">
        <div class="col-md-3"><div class="logo"><a href="{{site_domain}}" title="{{site_name}}">{{site_name}}</a></div></div>
        <div class="col-md-9">
        	<div class="row">
            	<div class="col-sm-4 hidden-xs">
                	{module_contentholder name="Phone Number"}
                    {module_contentholder name="Social Links"}
                </div>
                <div class="col-sm-4">
                    {% assign searchID = "4425" -%}
                    {% assign resultsPageID = "18679764" -%}
                    {% include "/_System/includes/widgets/search.inc" -%}
                </div>
                <div class="col-sm-4">
                	{% include "/_System/includes/template/login.inc" -%}
					{% include "/_System/includes/shop/cart-summary.inc" -%}
                    <a href="tel:1-800-401-4277" class="pull-right btn btn-primary hidden-sm hidden-md hidden-lg toggle-menu menu-right push-body"><i class="fa fa-phone"></i></a>
                    <a class="nav-mobile-control btn btn-primary pull-right hidden-sm hidden-md hidden-lg toggle-menu menu-right push-body"><i class="fa fa-bars"></i></a>
                </div>
            </div>
        </div>
    </div>
    <div class="container">
        {% assign menu-sub-only = "false" -%}
		{% assign showMenuParentTitle = "false" -%}
		{% assign menu-type-value ="stripped" -%}
		{% assign menuCustom = "false" -%}
		{% assign menu_id = "1931027" -%}
		{% assign menuClasses = "nav navbar-default nav-justified" -%}
		{% include "/_System/includes/template/menu.inc" -%}
    </div>
        
</div>
{% if page_url == is_home %}{% else -%}<div class="page-header"></div>{% endif -%}
