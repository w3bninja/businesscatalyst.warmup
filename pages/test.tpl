	@{{this[2]}}@
	
	@{{this.test | json}}@
	@{{this.test.id | json}}@
	@{{this.test.name.['first_name'] | json}}@

	
	
	@{{this['test']['id']}}@
	
	
<div>{{this.description}}</div>
<ul>
	@{{this['test']['id']}}@

	
	{{doughnut.['first_name']}}
	{{doughnut.docs[2].['first_name']}}
	{{doughnut.docs[2].['first_name']}}
	{{doughnut.docs[2].['first_name']}}
	



<hr>

<div>{{this.description}}</div>
<ul>
	{% for doughnut in this.doughnuts %}
    <li id={{doughnut.id}} type={{doughnut.type}}>
        {% if doughnut.price == 0 %}
            Free!
		{% else %}
            Price: ${{doughnut.price}}
        {% endif %}
    </li>
    {% endfor %}
</ul>


