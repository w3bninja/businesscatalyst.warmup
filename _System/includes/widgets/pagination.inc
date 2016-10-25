{% comment -%}
	This code was specifically written for a search function pagination. This code is untested in other modules.
	Known bugs: Doesn't accurately lower numbers.
		Reproduction steps: Set 'showNumberOfPages' to 3 and go to page 2
	{% assign showNumberOfPages = 10 -%}
	{% include '/_System/includes/widgets/pagination.inc' -%}
{% endcomment -%}

{% if showNumberOfPages == undefined -%}
	{% assign showNumberOfPages = 10 -%}
{% endif -%}
{% assign totalResults = search_results.pagination.totalItemsCount -%}
{% assign totalPages = search_results.pagination.numberOfPages -%}
{% assign resultsPageNumber = '{module_url, Page}' -%}
{% if resultsPageNumber == '' %}{% assign resultsPageNumber = 1 %}{% endif %}
{% assign resultsPageNumberMinusOne = resultsPageNumber | minus:1 -%}
{% assign resultsPageNumberPlusOne = resultsPageNumber | plus:1 -%}
{% assign resultsSearchUrlString = '/search?CAT_Search=' | append: searchQuery | append:'&A=SiteSearch' -%}
{% assign showNumberOfPagesHalved = showNumberOfPages | divided_by:2 | minus:1 -%}

{% if search_results.pagination.previousPageUrl != null -%}
	{% assign prevLink = resultsSearchUrlString | append:'&Page=' | append: resultsPageNumberMinusOne -%}
{% else -%}
	{% assign prevLink = '' -%}
{% endif -%}

{% if search_results.pagination.nextPageUrl != null -%}
	{% assign nextLink = resultsSearchUrlString | append:'&Page=' | append: resultsPageNumberPlusOne -%}
{% else -%}
	{% assign nextLink = '' -%}
{% endif -%}

{% assign startPages = resultsPageNumber | minus: showNumberOfPagesHalved -%}
{% if startPages < 1 -%}
	{% assign startPages = 1 -%}
{% endif -%}

{% assign endPages = resultsPageNumber | plus: showNumberOfPagesHalved -%}		
{% if endPages >= totalPages -%}
	{% assign endPages = totalPages -%}
{% endif -%}

{% assign pagesCount = endPages | minus: startPages -%}
{% assign pagesDifference = showNumberOfPages | minus: pagesCount -%}
{% if pagesCount < showNumberOfPages -%}
	{% assign startPages2 = startPages | minus: pagesDifference | plus:1 -%}
	{% if startpages2 >= 0 -%}
		{% assign startPages = startPages2 -%}
	{% endif -%}
{% endif -%}

<nav aria-label="Page navigation">
	<ul class="pagination">
		<li{% if prevLink == '' -%} class="disabled"{% endif -%}>
			<a href="{% if prevLink != '' -%}{{prevLink}}{% endif -%}" aria-label="Previous">
				<span aria-hidden="true"><i class="fa fa-chevron-left" aria-hidden="true"></i></span>
			</a>
		</li>
		{% for i in (startPages..totalPages) -%}
			{% assign i = startPages -%}									
			{% if i > endPages and i > showNumberOfPages -%}
				{% break -%}
			{% else -%}
				<li{% if resultsPageNumber == i -%} class="active"{% endif -%}><a href="{{resultsSearchUrlString | append:'&Page=' | append: i }}">{{i}}</a></li>
			{% endif -%}
		{% endfor -%}
		<li{% if nextLink == '' -%} class="disabled"{% endif -%}>
			<a href="{% if nextLink != '' -%}{{nextLink}}{% endif -%}" aria-label="Next">
				<span aria-hidden="true"><i class="fa fa-chevron-right" aria-hidden="true"></i></span>
			</a>
		</li>
	</ul>
</nav>
