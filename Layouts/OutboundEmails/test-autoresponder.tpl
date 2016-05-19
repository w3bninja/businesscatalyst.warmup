<pre>{{form | json}}</pre>

<table>
	<tbody>
		{% for item in form %}
			<tr>
				<td>{{item.['FirstName']}}</td>
				<td>{{item.['LastName']}}</td>
				<td>{{item.['EmailAddress']}}</td>
			</tr>	
		{% endfor %}
	</tbody>
</table>