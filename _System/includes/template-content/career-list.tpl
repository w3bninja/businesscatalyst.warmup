<div class="row">
	<div class="col-sm-12">
    	<h3 title="{{name}} - {{releasedate}}"><a href="{{url}}" title="{{name}} - {{releasedate}}">{{name}}</a></h3>
        <div class="date">Posted on: {{releasedate | date: "MM\\dd\\yyyy" }}</div>
        <div class="text">{{description | strip_html | truncate: 200 }}</div>
        <a href="{{url}}" class="btn btn-primary" title="{{name}} - {{releasedate}}">Read More</a>
    </div>
</div>