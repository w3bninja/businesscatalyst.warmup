(function(){
	$(function(){
		init();

		function init(){
			caseInsensitiveContains();
			$('[data-search-key]').each(function(){
				var $form = $(this);
				var key = $form.attr('data-search-key');

				var searchMap = {};

				if(typeof key === 'undefined') key = '';
				var inputs = $form.find('input,select,textarea');
				inputs.on('change keyup',function(e){
					
					var searchEl = $(e.target);
					if(searchEl.val().trim() === ''){
						delete searchMap[searchEl.prop('name')];
					}else{
						searchMap[searchEl.prop('name')] = searchEl.val();
					}
					
					var domElements = $('[data-search-filter="'+key+'"]').removeClass('hidden');
					var domElementsToHide = domElements.filter(function(){
						var el = $(this);
						var searchVals = Object.keys(searchMap).map(function(x){return searchMap[x];});
						
						if(searchVals.length < 1) return false;

						for(var i = 0;i < searchVals.length; i++){
							var search = searchVals[i];
							if(el.find(':caseinsensitivecontains("'+search+'")').length > 0){
								return false;
							}
						}
						return true;//only return true if the element does NOT contain search criteria. We're marking what to hide, not what to show.
					});
					domElementsToHide.addClass('hidden');
				});
			});
		}

		function caseInsensitiveContains(){
			//this code snippet is unlicensed and requires no attribution
			//https://css-tricks.com/license/
			$.expr[":"].caseinsensitivecontains = $.expr.createPseudo(function(arg) {
			    return function( elem ) {
			        return $(elem).text().toUpperCase().indexOf(arg.toUpperCase()) >= 0;
			    };
			});
		}
	});
})();