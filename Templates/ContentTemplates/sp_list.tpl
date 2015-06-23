
<div class="item service">
    <div class="content-header">
    {% if this.["Sub Services"] != '' %}
        <h3 id="{{this.name}}" name="{{this.name}}">{{this.name}}</h3>
    {% else %}
        <h3><a href="{{this.url}}">{{this.name}}</a></h3>
    {% endif %}
    </div>
    <div class="content-inner">
        <div class="row">
            <div class="col-md-12">
                <div class="row service-item">
                	{% if this.image != '' %}
                    <div class="col-md-5 logo pull-right">
                        <img src="{{this.image}}?Action=thumbnail&Width=350&Height=250&algorithm=fill_proportional" onerror="this.style.display='none';" class="img-style img-responsive">
                    </div>
                    {% endif %}
                    <div class="{% if this.image != '' %}col-md-7{% endif %}">
                        
                        <div class="hidden-xs hidden-sm hidden-md">{{description}}</div>
                        <div class="hidden-xs">
                        	{% if this.["Sub Services"] != '' %}
                                <div class="services-nav">{{this.["Sub Services"]}}</div>
                            {% endif %}
                        </div>
                        <div class="hidden-lg hidden-md hidden-sm">
                            <a class="btn btn-gray btn-top-control" data-toggle="collapse" href="#{{this.itemid}}" aria-expanded="false" aria-controls="collapseExample">
                              {{this.name}}
                            </a>
                            <div class="collapse" id="{{this.itemid}}">
                                {% if this.["Sub Services"] != '' %}
                                    <div class="services-nav">{{this.["Sub Services"]}}</div>
                                {% endif %}
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>
</div>

<style>
.services-nav .nav-img{display:none!important;}
.services-nav {width:100%;}
.services-nav a:before{content: "\f0da"; position:absolute; right:10px; top:24px; display: inline-block; font: normal normal normal 14px/1 FontAwesome; font-size: inherit; text-rendering: auto; -webkit-font-smoothing: antialiased; -moz-osx-font-smoothing: grayscale; transform: translate(0, 0);}
</style>