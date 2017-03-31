{module_webapps id="{{appID}}" filter="classified" sortType="weightreverse" itemId="{{classificationID}}" collection="landing-section" template=""}
<div class="pages">
{% for item in landing-section.items -%}
	<div class="page {{item.["Background Color"]|downcase}}" id="{{item.title | downcase|replace:' ','-'}}" style="background-image:url({{item.["Background Image"]}}); background-repeat:no-repeat; background-size:cover;">
		<div class="container text-center">
			<div class="content">
				<h2>{{item.Title}}</h2>
				<h3>{{item.subtitle}}</h3>
				<div class="text">
					{% if item.gallery != '' -%}
					<div class="row">
						<div class="col-sm-6">
							<div class="pager-arrows">
								<a href="#" class="prev" id="prev"><i class="fa fa-angle-left"></i></a>
								<a href="#" class="next" id="next"><i class="fa fa-angle-right"></i></a>
							</div>
							{module_photogallery id="{{item.gallery}}" template="" collection="gallery"}
							<div class="cycle-slideshow" data-cycle-fx="fadeout" data-cycle-log="true" data-cycle-timeout="5000" data-cycle-pause-on-hover="true" data-cycle-prev="#prev" data-cycle-next="#next">
							{% for item in gallery.items -%}
								<img src="{{item.link}}?Action=thumbnail&Width=600&Height=700&algorithm=fill_proportional" class="img-responsive thumbnail">
							{% endfor -%}
							</div>
								
							
						</div>
						<div class="col-sm-6">
						{% endif -%}
							{{item.description}}
						{% if item.gallery != '' -%}
						</div>
					</div>
					{% endif -%}
				</div>
				{% if item.["Webapp Items"] != '' %}
				<div class="row justify-content-center">
					{module_webapps id="{{item.["Webapp Items"]}}" filter="all"}

				</div>
				{% endif -%}
			</div>
		</div>
	</div>
{% endfor -%}
</div>