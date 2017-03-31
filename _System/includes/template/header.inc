<div class="nav-mobile cbp-spmenu cbp-spmenu-vertical cbp-spmenu-left">
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
    <div class="header">
    	<div class="header-top">
            <div class="clearfix">
                <div class="pull-right hidden-xs text-right">
	                <div class="pull-left">
                    	<div class="phone pull-left">Toll Free: {module_contentholder name="Phone Number"}</div>
                        <div class="pull-left">{module_contentholder name="Social Links"}</div>
                        <div class="pull-left">{% include "/_System/includes/template/login.inc" -%}</div>
                    </div>
                    <div class="pull-right">              	
                    {% assign searchID = "4425" -%}
                    {% assign resultsPageID = "18679764" -%}
					{% assign searchUsage = "template" -%}
                    {% include "/_System/includes/widgets/search.inc" -%}
                    </div>
                </div>
            </div>
        </div>
        <div class="header-bottom sticky">
           <div class="container">
                <div class="row">
                   	
                    <div class="col-xs-12 col-sm-2">
                    	<div class="row">
                    		<div class="col-xs-3 hidden-sm hidden-md hidden-lg">
                    		<div class="mobile-navigation pull-left hidden-sm hidden-md hidden-lg">
								<a class="nav-mobile-control btn btn-secondary toggle-menu menu-left push-body"><i class="fa fa-bars"></i></a>
							</div>
							</div>
							<div class="logo col-xs-6 col-sm-12">
								<h1 title="{{site_name}}">
									<a href="{{site_domain}}" title="{{site_name}}">
										<img src="/assets/img/logo.png" class="img-responsive">
									</a>
								</h1>
							</div>
                   			<div class="col-xs-3 hidden-sm hidden-md hidden-lg">
                   				<a href="tel:{module_contentholder name="Phone Number"}" class="btn btn-secondary pull-right"><i class="fa fa-phone"></i></a>
                   			</div>
                    	</div>
                    	
                    </div>
                    <div class="col-xs-12 col-sm-10">
                        <div class="row">
                            <div class="col-sm-11">
                                {% assign menu-sub-only = "false" -%}
                                {% assign showMenuParentTitle = "false" -%}
                                {% assign menu-type-value ="stripped" -%}
                                {% assign menuCustom = "false" -%}
                                {% assign menu_id = "1931027" -%}
                                {% assign menuClasses = "nav navbar-default nav-justified" -%}
                                {% include "/_System/includes/template/menu.inc" -%}
                                
                            </div>
                            
                            <div class="col-sm-1 pull-right">
                                {% include "/_System/includes/shop/cart-summary.inc" -%}
                            </div>
                        </div>
                    </div>
                </div>
            </div>
           
           
           
           
           
           
           
           
           
           
        </div>
    </div>
    {% if page_url == is_home %}{% else -%}<div class="page-header text-center"><h2>{module_pagename}</h2></div>{% endif -%}
