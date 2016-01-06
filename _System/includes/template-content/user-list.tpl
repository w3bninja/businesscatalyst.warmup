{% assign appID = "31766" %}
{% assign col-class = "col-md-4" %}
<div class="{{col-class}} bio-item">
    <div class="panel panel-default">
        <div class="panel-body">
            {% if this.image != '' %}
                <a href="{{this.url}}"><img src="{{this.image}}?Action=thumbnail&Width=150&Height=150&algorithm=fill_proportional" onerror="this.style.display='none';" class="img-style"></a>
            {% endif %}
            <h4><a href="{{this.url}}">{{this.name}}</a></h4>
            <h5>{{this.["title"]}}</h5>
            {% if this.email != '' %}
             <a class="email btn btn-default" href="mailto:{{this.email}}">Email Me</a>
            {% endif %}
        </div>
    </div>
</div>


{% comment -%}
{% if counter == "1" -%}
<div class="bio-col-head hidden-xs">
    <div class="row">
        <div class="col-sm-6">
            Name & Title
        </div>
        <div class="col-sm-3">
            Phone/Ext
        </div>
        <div class="col-sm-3">
            &nbsp;
        </div>
    </div>
</div>
{% endif -%}
<div class="bio-item">
    <div class="row">
        <div class="col-sm-6">
            <h4>{{this.name}}</h4>
            <h5>{{this.["title"]}}</h5>
        </div>
        <div class="col-sm-3">
            {% if this.phone != '' %}
             <a class="phone" href="tel:{{this.phone}}">{{this.phone}}</a>
            {% else -%}
            N/A
            {% endif %}
        </div>
        <div class="col-sm-3">
            {% if this.email != '' %}
             <a class="email btn btn-default pull-right" href="mailto:{{this.email}}">Email Me</a>
            {% else -%}
                <div class="pull-right">N/A</div>
            {% endif %}
        </div>
    </div>
</div>
{% endcomment -%}