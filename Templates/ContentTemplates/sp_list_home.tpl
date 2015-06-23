<div class="item service col-md-4">
    <div class="content-inner">
        <div class="row service-item">
        	<div class="col-md-12 col-sm-6">
                {% if this.image != '' %}
                    <img src="{{this.image}}?Action=thumbnail&Width=350&Height=180&algorithm=fill_proportional" onerror="this.style.display='none';" class="img-responsive">
                {% endif %}
            </div>
            <div class="col-md-12 col-sm-6">
                <h3><a href="/services#{{this.name}}">{{this.name}}</a></h3>
                {tag_description, 150}
                <a href="/services#{{this.name}}" class="btn btn-yellow">{{this.name}}</a>
            </div>
        </div>
    </div>
</div>