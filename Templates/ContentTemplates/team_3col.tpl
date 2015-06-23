<div class="col-md-4 bio-item">
	{% if this.image != '' %}
    	<a href="{{this.url}}"><img src="{{this.image}}?Action=thumbnail&Width=150&Height=150&algorithm=fill_proportional" onerror="this.style.display='none';" class="img-style"></a>
    {% endif %}
    <h4><a href="{{this.url}}">{{this.name}}</a></h4>
    <h5>{{this.["title"]}}</h5>
    {% if this.email != '' %}
     <a class="email btn btn-default" href="mailto:{{this.email}}">Email Me</a>
    {% endif %}
</div>