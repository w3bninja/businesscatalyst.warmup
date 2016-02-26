{% comment -%}
{% assign calendarAppID = "" -%}
{% assign calendarClassID = "" -%}
{% include "/_System/includes/widgets/calendar/calendar.inc" -%}
{% endcomment -%}

{% assign calendarAppID = calendarAppID | default: "" -%}
{% assign calendarClassID = calendarClassID | default: "" -%}

{% capture pageID %}{module_oid}{% endcapture %}
{% capture output %}
	{% if calendarClassID != '' -%}
	classified
		{module_webapps render="item" id="{{calendarAppID}}" filter="classified" itemId="{{calendarClassID}}" template="/_System/includes/widgets/calendar/json.inc"}
	{% else -%}
	not classified
		{module_webapps render="item" id="{{calendarAppID}}" filter="all" template="/_System/includes/widgets/calendar/json.inc"}
	{% endif -%}
{% endcapture %}

{% assign output = output | remove: "  " | strip -%}


{% if output == '' -%}
No Calendar Events Available
{% else -%}
<link href='//cdnjs.cloudflare.com/ajax/libs/fullcalendar/2.4.0/fullcalendar.min.css' rel='stylesheet' />

<script type="text/javascript" src="//cdnjs.cloudflare.com/ajax/libs/moment.js/2.9.0/moment.min.js"></script>
<script type="text/javascript" src="//cdnjs.cloudflare.com/ajax/libs/fullcalendar/2.4.0/fullcalendar.min.js"></script>
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
				{{output}}
			]
		});
		
		$(window).resize(function() {
			setTimeout(function() {fullCalendarResizer();}, 0);
		});
		$(window).trigger('resize');
	
		function fullCalendarResizer() {
			if ($(window).width() < 514){
				$('#calendar').fullCalendar('changeView', 'agendaDay');
			} else {
				$('#calendar').fullCalendar('changeView', 'month');
			}
		}
		
		
	});
</script>
<div id="calendar"></div>
{% endif -%}