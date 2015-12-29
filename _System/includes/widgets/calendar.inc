{% capture pageID %}{module_oid}{% endcapture %}

{% capture output %}
	{% if pageID contains '16696467' %}
		{% comment %}
			/schedule-events
			{module_contentholder,4116979}
			{module_contentholder name="Calendar Full"}
		{% endcomment %}

		{module_webapps render="item" id="30633" filter="all" template="/Layouts/WebApps/Events/list_backup_new.html"}
	{% elsif pageID contains '16828418' %}	
		{% comment %}
			/schedules/schedule
			{module_contentholder name="Calendar Schedule"}
		{% endcomment %}

		{module_webapps render="item" id="30633" filter="classified" itemId="645276" template="/Layouts/WebApps/Events/list_backup_new.html"}
	{% elsif pageID contains '16828410' %}
		{% comment %}
			/schedules/events-1
			{module_contentholder name="Calendar Events"}
		{% endcomment %}

		{module_webapps render="item" id="30633" filter="classified" itemId="645277" template="/Layouts/WebApps/Events/list_backup_new.html"}
	{% else %}
		No calendar IDs found
	{% endif %}
{% endcapture %}

<script>
	$(document).ready(function() {
		$('#calendar').fullCalendar({
			header: {
				left: 'prev,next today',
				center: 'title',
				right: 'month,basicWeek,agendaDay'
			},
			buttonIcons: {
				prev: 'prev fa fa-chevron-left',
    			next: 'next fa fa-chevron-right',
			},
			editable: false,
			eventLimit: true, // allow "more" link when too many events
			windowResize: function(view) {
				if ($(window).width() < 514){
					$('#calendar').fullCalendar('changeView', 'agendaDay');
				} else {
					$('#calendar').fullCalendar('changeView', 'month');
				}
			},
			eventRender: function(event, element, view){
				if (typeof event.ranges === 'undefined' || !event.ranges.length)
					return true;
					
				if (isRecurringAndEndDateless(event)) {
					event.ranges[0].end = new Date(864000000000000);					
				}

				var start = moment(event.start);
				var end = !!event.end ? moment(event.end) : moment(event.start).endOf('day');
				var rangeStart = moment(event.ranges[0].start);
				var rangeEnd = !!event.ranges[0].end ? moment(event.ranges[0].end).add(1, 'days') : moment(event.ranges[0].start).endOf('day');
				
				return (event.ranges.filter(function(range){
					return (start.isBefore(rangeEnd) && end.isAfter(rangeStart));
				}).length)>0;
				
				function isRecurringAndEndDateless(e) {
					return !!e.ranges[0].start === true  &&
						   !!e.ranges[0].end   === false &&
						   !!e.dow             === true  &&
						   !!e.dow.length      === true;
				}	
			},
			events: [
				{{output | remove: "  " | strip }}
			]
		});
	});
</script>
<div id="calendar"></div>