<div class="footer">
        <div class="footer-top">
            <div class="container clearfix">
                <div class="copyright pull-left">
                © {{globals.site.dateNow | date: "yyyy"}}, <a href="/">{module_sitename}</a> </div>
                <div class="nav-footer pull-right clearfix hidden-xs hidden-sm">
                    {% if page_url contains "facility-1" %}
                        {module_menu, version="2", menuId="2040584", moduleTemplateGroup="stripped"}
                    {% elseif page_url contains site_url -%}
                        {module_menu, version="2", menuId="1931027", moduleTemplateGroup="stripped"}
                    {% endif -%}
                </div>
            </div>
        </div>
    </div>
</div>