<div class="footer">
        <div class="footer-top">
            <div class="container clearfix">
                <div class="copyright pull-left">
                © {{globals.site.dateNow | date: "yyyy"}}, <a href="/">{module_sitename}</a> </div>
                <div class="nav-footer pull-right clearfix hidden-xs hidden-sm">
                    {% assign menu-type-value ="stripped" -%}
        			{% include "/_System/includes/template/menu.inc" -%}
                </div>
            </div>
        </div>
    </div>
</div>
<a href="#" class="btn btn-default back-to-top"><i class="fa fa-chevron-up"></i></a>