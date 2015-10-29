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
        <div class="col-md-9 header-text">
        	<div class="phone pull-left">
                <span class="hidden-xs">Toll Free: (800) 401–4277</span>
                {% include "/_System/includes/template/login.inc" -%}
                <a href="tel:1-800-401-4277" class="pull-right btn btn-primary hidden-sm hidden-md hidden-lg toggle-menu menu-right push-body"><i class="fa fa-phone"></i></a>
                <a class="nav-mobile-control btn btn-primary pull-right hidden-sm hidden-md hidden-lg toggle-menu menu-right push-body"><i class="fa fa-bars"></i></a>
            </div>
        </div>
    </div>
    <div class="navigation col-md-12 hidden-xs">
        <div class="container navigation-inner main-nav clearfix">
        	{% assign menu-type-value ="stripped" -%}
           {% include "/_System/includes/template/menu.inc" -%}
        </div>
    </div>
</div>
{% if page_url == site_domain %}<div class="page-header"></div>{% endif -%}
