<div class="slide" style="background:url({{this.image}}) no-repeat top center; background-size:cover;">
    <div class="slide-inner">
    	<div class="container">
        	<div class="col-md-7">
            	<h1>{{this.name}}<span>{{this.["Sub Text"]}}</span></h1>
            	<div class="text">
                	{tag_description}
                	<a href="{{this.link}}" class="btn btn-primary">
                    	{% if this.["Button Text"] != '' %}
                            {{this.["Button Text"]}}
                        {% else %}
                            Read More
                        {% endif %}
                    </a>
                </div>
            </div>
        </div>
    </div>
</div>