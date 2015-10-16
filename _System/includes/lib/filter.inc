{% comment %}

	NAME: Filter
	VERSION: 0.2.0
	LAST UPDATED: Oct 1, 2015
	DESCRIPTION: Filters items in a module.
	AUTHOR: Scott B Reynolds - http://www.thrise.com/about.htm
	RIGHTS: This library item may NOT be used, shared, replicated, sold, or modified without written permission from Author.
	NOTE: THIS FILE AND ITS CONTENTS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THIS FILE OR THE USE OR OTHER DEALINGS IN THIS FILE.
	
	#INSTRUCTIONS:
	
	The following applies to all examples.
	
	-- Save this file as "filter.inc" in a folder called "lib". The path should look like... "_System/includes/lib/filter.inc"
	-- Using the examples below copy and paste the markup on a page where you want the output to render.
	-- The include needs to be the last line in all examples. The order of variables don't matter.
	-- In examples replace "xxxxx" with appropriate id or name (see examples for specific instructions).
	-- Unless a custom template is assigned, the module's default list layout is used.
	-- To speed up rendering, add one of the following html comments to your list layouts (read RENDERING sections):
	---- When rendering as an item (default) add to end of list layout:	 <!--/#/lib/#/-->
	---- When rendering as a collection add immediately before the end of the forloop (in list layout):	 <!--/#/{{item.itemid}}/#/-->
			
	
	--------------------------------------------
	
	#1 VARIABLE
		Filter a module by field name using liquid markup variable:
		-- Use the exact field name for the filter-fieldNames value (not case-sensitive).
		-- By default filter-fieldValues is case-sensitive.
		-- For web apps, the value for filter-ids can be either the id or web app name.
		
		{% assign filter-fieldNames = "xxxxx" -%}
		{% assign filter-fieldValues = "xxxxx" -%}
		{% assign filter-ids = "xxxxx" -%}
		{% include "/_System/includes/lib/filter.inc" -%}
	
	--------------------------------------------
	
	#2 PARAMETER
		Filter a module by a parameter in the url:
		-- Same principles apply as above in #1, except add the field name & values in url: example.com/test?fieldValues=xxxxx&fieldNames=xxxxx
		-- For web apps, the value for filter-ids can be either the id or web app name.
		
		{% assign filter-ids = "xxxxx" -%}
		{% include "/_System/includes/lib/filter.inc" -%}
		
	--------------------------------------------
	
	#3 CATEGORY
		Filter items in a module from a category:
		-- Replace filter-itemIds value with the category name or id. Use quotes (") around the category id.
	
		{% assign filter-filters = "classified" -%}
		{% assign filter-itemIds = "xxxxx" -%}
		{% assign filter-fieldNames = "xxxxx" -%}
		{% assign filter-fieldValues = "xxxxx" -%}
		{% assign filter-ids = "xxxxx" -%}
		{% include "/_System/includes/lib/filter.inc" -%}
		
	--------------------------------------------
	
	#4 TEMPLATE
		Use a custom template for the module.
		-- Replace filter-templates value with the path to your custom template.
		-- Use quotes (") around the path.
		-- Don't include a template if you are going to use the module's default list view.
	
		{% assign filter-templates = "/path-to-your-template.tpl" -%}
		{% assign filter-fieldNames = "xxxxx" -%}
		{% assign filter-fieldValues = "xxxxx" -%}
		{% assign filter-ids = "xxxxx" -%}
		{% include "/_System/includes/lib/filter.inc" -%}
		
	--------------------------------------------
	
	#9 NUMBER OF RESULTS IN COLLECTION
		Control the total number of total items added to the collection (to be filtered).
		-- Replace filter-moduleResults value with the maximum number of items to be added to the collection. The default max is 500.
	
		{% assign filter-moduleResults = xx -%}
		{% assign filter-fieldNames = "xxxxx" -%}
		{% assign filter-fieldValues = "xxxxx" -%}
		{% assign filter-ids = "xxxxx" -%}
		{% include "/_System/includes/lib/filter.inc" -%}
		
	--------------------------------------------
	
	#16 RENDER AS AN ITEM (DEFAULT)
		Render a module as an item, not a collection
		-- Include the following html comment at the end of the list layout: <!--/#/lib/#/-->
		-- By including the html comment, the list will render a lot faster.
		-- Learn more about the render parameter --> http://docs.businesscatalyst.com/developers#!/liquid/render-parameter
		-- Since this is the default, there is no need to include the filter-renders variable.
	
		{% assign filter-fieldNames = "xxxxx" -%}
		{% assign filter-fieldValues = "xxxxx" -%}
		{% assign filter-ids = "xxxxx" -%}
		{% include "/_System/includes/lib/filter.inc" -%}
		
	--------------------------------------------
	
	#17 RENDER AS COLLECTION
		Render a module as a collection, instead of the default: "item".
		-- Learn more about the render parameter --> http://docs.businesscatalyst.com/developers#!/liquid/render-parameter
		-- Must include the following html comment immediately before the closing loop tag (in list layout): <!--/lib/{{item.itemid}}/lib/-->
	
        {% assign sort-renders = "collection" -%}
		{% assign filter-fieldNames = "xxxxx" -%}
		{% assign filter-fieldValues = "xxxxx" -%}
		{% assign filter-ids = "xxxxx" -%}
		{% include "/_System/includes/lib/filter.inc" -%}
		
	--------------------------------------------
	
	#18 SORT TYPE
		Output the modules by their sort type.
		-- Types available: alphabetical (default), date (newest to oldest), datereverse (oldest to newest), weightreverse, comments.
		-- Example below is using will change the sort type from alpha to displaying items by release date (oldest to newest).
	
        {% assign sort-sortTypes = "datereverse" -%}
		{% assign filter-fieldNames = "xxxxx" -%}
		{% assign filter-fieldValues = "xxxxx" -%}
		{% assign filter-ids = "xxxxx" -%}
		{% include "/_System/includes/lib/filter.inc" -%}
		
	--------------------------------------------
	--------------------------------------------

{% endcomment -%}
{% assign filter-errorMessage = "Error: 'filter-ids' or 'filter-modules' needs to be assigned." -%}{% if filter-ids or filter-modules -%}{% assign sortTypeDefault = sortTypeDefault | default: "name" -%}{% assign filter-ids = filter-ids | split: ',' -%}{% assign filter-itemIds = globals.get.itemids | default: filter-itemIds | default: "" | split: ',' -%}{% assign filter-filters = globals.get.filters | default: filter-filters | default: "all" | split: ',' -%}{% assign filter-modules = globals.get.modules | default: filter-modules | default: "webapp" | split: ',' -%}{% assign filter-sortTypes = filter-sortTypes | default: filter-sortTypes | default: "ALPHABETICAL" | split: ',' -%}{% assign filter-dateFormat = globals.get.dateformat | default: filter-dateFormat | default: "yyyy-MM-ddThh:mm:ss" -%}{% assign filter-moduleResults = globals.get.moduleResults | default: filter-moduleResults | default: "500" | split: ',' -%}{% assign filter-renders = filter-renders | default: "item" | split: ',' -%}{% assign filter-hideEmptyMessage = filter-hideEmptyMessage | default: "true" -%}{% assign filter-indicatorFirst = filter-indicatorFirst | default: "<!--/#/" -%}{% assign filter-indicatorID = filter-indicatorID | default: "lib" -%}{% assign filter-indicatorLast = filter-indicatorLast | default: "/#/-->" -%}{% assign filter-indicator = filter-indicatorFirst | append: filter-indicatorID | append: filter-indicatorLast -%}{% assign filter-dataIndicator = filter-dataIndicator | default: "###" -%}{% assign filter-dataSeparator = filter-dataSeparator | default: "%%%" -%}{% assign filter-noTemplate = filter-noTemplate | default: "false" -%}{% assign filter-itemCount = 0 -%}{% capture sortCapture -%}{% endcapture -%}{% assign filter-templates = filter-templates | default: "-1" | split: ',' -%}{% assign filter-fieldNames = globals.get.fieldNames | default: filter-fieldNames | default: "" -%}{% assign filter-fieldValues = globals.get.fieldValues | default: filter-fieldValues | default: "" -%}{% assign filter-data = filter-fieldNames | split: ',' -%}{% if filter-ids -%}{% assign filter-loopNum = filter-ids | size | minus: 1 -%}{% elsif filter-modules -%}{% assign filter-loopNum = filter-modules | size | minus: 1 -%}{% endif -%}{% for i in (0..filter-loopNum) -%}{% assign filter-module = filter-modules[i] | strip -%}{% assign filter-render = filter-renders[i] | strip -%}{% assign filter-template = filter-templates[i] | strip -%}{% assign filter-itemId = filter-itemIds[i] | strip -%}{% assign filter-moduleResult = filter-moduleResults[i] | strip -%}{% assign filter-sortType = filter-sortTypes[i] | strip -%}{% assign filter-filter = filter-filters[i]|strip -%}{% assign filter-collectionIndex = i | convert: "string" -%}{% assign filter-collection = "filter-collection" | append: filter-collectionIndex -%}{% assign filter-id = filter-ids[i] | strip -%}{% capture sortModuleCapture -%}{% if filter-module == "media" -%}{module_literature render="{{filter-render}}" filter="{{filter-filter}}" collection="{{filter-collection}}" template="{{filter-template}}"}{% elsif filter-module == "news" -%}{module_announcement render="{{filter-render}}" filter="{{filter-filter}}" itemid="{{filter-itemId}}" noTemplate="{{filter-noTemplate}}" sortType="{{filter-sortType}}" collection="{{filter-collection}}" template="{{filter-template}}"}{% else -%}{module_webapps id="{{filter-id}}" filter="{{filter-filter}}" itemId="{{filter-itemId}}" resultsPerPage="{{filter-moduleResult}}" hideEmptyMessage="{{filter-hideEmptyMessage}}" collection="{{filter-collection}}" sortType="{{filter-sortType}}" render="{{filter-render}}" template="{{filter-template}}"}{% endif -%}{% endcapture -%}{% for p in filter-data -%}{% assign filter-dataPart = p | strip -%}{% assign filter-doubleDataSeparator = filter-dataIndicator | append: " " | append: filter-dataSeparator | append: filter-dataIndicator -%}{% assign filter-datum = this.[filter-collection].items | map: filter-dataPart | join: filter-doubleDataSeparator -%}{% case forloop.index0 -%}{% when 0 -%}{% assign filter-dataString0 = filter-dataString0 | default: "" | append: " " | append: filter-dataSeparator | append: filter-dataIndicator | append: filter-datum -%}{% when 1 -%}{% assign filter-dataString1 = filter-dataString1 | default: "" | append: filter-dataIndicator | append: filter-datum -%}{% when 2 -%}{% assign filter-dataString2 = filter-dataString2 | default: "" | append: filter-dataIndicator | append: filter-datum -%}{% when 3 -%}{% assign filter-dataString3 = filter-dataString3 | default: "" | append: filter-dataIndicator | append: filter-datum -%}{% when 4 -%}{% assign filter-dataString4 = filter-dataString4 | default: "" | append: filter-dataIndicator | append: filter-datum -%}{% when 5 -%}{% assign filter-dataString5 = filter-dataString5 | default: "" | append: filter-dataIndicator | append: filter-datum -%}{% when 6 -%}{% assign filter-dataString6 = filter-dataString6 | default: "" | append: filter-dataIndicator | append: filter-datum -%}{% when 7 -%}{% assign filter-dataString7 = filter-dataString7 | default: "" | append: filter-dataIndicator | append: filter-datum -%}{% when 8 -%}{% assign filter-dataString8 = filter-dataString8 | default: "" | append: filter-dataIndicator | append: filter-datum -%}{% when 9 -%}{% assign filter-dataString9 = filter-dataString9 | default: "" | append: filter-dataIndicator | append: filter-datum -%}{% endcase -%}{% endfor -%}{% if sortModuleCapture contains filter-indicator -%}{% if filter-module == "media" or filter-module == "news"  -%}{% assign filter-thisCapturedIds = this.[filter-collection].items | map: 'id' | join: "," -%}{% else -%}{% assign filter-thisCapturedIds = this.[filter-collection].items | map: 'itemid' | join: "," -%}{% endif -%}{% assign filter-capturedIds = filter-capturedIds | default: "" | append: "," | append: filter-thisCapturedIds -%}{% if this.[filter-collection].pagination != 1 -%}{% assign filter-splitter = '<ul id="webapp33720pagination" class="pagination webapp">' -%}{% assign filter-combinedModule = sortModuleCapture | split: filter-indicator | last -%}{% assign sortModuleCapture = sortModuleCapture | remove: filter-combinedModule -%}{% endif -%}{% capture sortCapture -%}{{sortCapture}}{{sortModuleCapture}}{% endcapture -%}{% elsif filter-render == "collection" -%}{% assign filter-moduleCapture = sortModuleCapture | split: filter-indicatorLast -%}{% for c in filter-moduleCapture -%}{% assign filter-moduleCapturedParts = c | split: filter-indicatorFirst -%}{% assign filter-moduleCapturedId = filter-moduleCapturedParts[1] -%}{% assign filter-moduleCapturedItem = filter-moduleCapturedParts[0] -%}{% unless forloop.last -%}{% assign filter-capturedIds = filter-capturedIds | append: "," | append: filter-moduleCapturedId -%}{% assign filter-allCapturedItems = filter-allCapturedItems | default: "" | append: filter-moduleCapturedItem | append: filter-indicator -%}{% endunless -%}{% endfor -%}{% capture sortCapture -%}{{sortCapture}}{{filter-allCapturedItems}}{% endcapture -%}{% else -%}{% capture sortCapture -%}{{sortCapture}}{% if filter-module == "media" or filter-module == "news" -%}{% assign filter-thisCapturedIds = this.[filter-collection].items | map: 'id' | join: "," -%}{% else -%}{% assign filter-thisCapturedIds = this.[filter-collection].items | map: 'itemid' | join: "," -%}{% endif -%}{% assign filter-capturedIds = filter-capturedIds | append: "," | append: filter-thisCapturedIds -%}{% if filter-module == "media" -%}{% for item in this.[filter-collection].items -%}{module_literature filter="item" itemid="{{item.id}}" template="{{filter-template}}"}{% endfor -%}{% elsif filter-module == "news" -%}{% for item in this.[filter-collection].items -%}{module_announcement filter="item" itemid="{{item.id}}" noTemplate="{{filter-noTemplate}}" template="{{filter-template}}"}{% endfor -%}{% else -%}{% for item in this.[filter-collection].items -%}{module_webapps id="{{filter-id}}" filter="item" itemId="{{item.itemid}}" sortType="{{filter-sortType}}" resultsPerPage="{{filter-moduleResult}}" hideEmptyMessage="true" template="{{filter-template}}"}{{filter-indicator}}{% endfor -%}{% endif -%}{% endcapture -%}{% endif -%}{% endfor -%}{% for i in (0..filter-loopNum) -%}{% assign filter-module = filter-modules[i] | strip -%}{% assign filter-collectionIndex = i | convert: "string" -%}{% assign filter-collection = "filter-collection" | append: filter-collectionIndex -%}{% endfor -%}{% assign filter-combined = sortCapture | split: filter-indicator -%}{% assign filter-size = filter-combined | size | minus: 1 -%}{% assign filter-size0 = filter-size | minus: 1 -%}{% assign filter-total0 = filter-itemCount | minus: 1 -%}{% if filter-fieldNames == "" -%}{{filter-combined}}{% else -%}{% assign filter-dataString0 = filter-dataString0 | append: filter-dataIndicator | append: " " -%}{% assign start = -1 -%}{% assign filter-splitter = filter-dataIndicator | append: filter-fieldValues | append: filter-dataIndicator -%}{% assign test = filter-dataString0 | split: filter-splitter -%}{% assign testSize = test | size | minus: 1 -%}{% for i in test limit: testSize -%}{% assign iSplit = i | split: filter-dataSeparator -%}{% assign iSplitSize = iSplit | size -%}{% assign start = start | plus: iSplitSize -%}{% assign startString = start | convert: "string" -%}{% assign spots = spots | default: "" | append: filter-dataIndicator | append: startString -%}{% endfor -%}{% assign spots = spots | replace_first: filter-dataIndicator,"" | split: filter-dataIndicator -%}{% assign spotsSize = spots | size -%}{% for i in spots -%}{% assign var = i | convert: "number" -%}{{filter-combined[var]}}{% endfor -%}{% endif -%}{% else -%}<p>{{filter-errorMessage}}</p>{% endif -%}
