AjaxPro.Request.prototype = {
          url: null,
          callback: null,
          onLoading: AjaxPro.noOperation,
          onError: AjaxPro.noOperation,
          onTimeout: AjaxPro.noOperation,
          onStateChanged: AjaxPro.noOperation,
          args: null,
          context: null,
          isRunning: false,
          abort: function() {
                    if(this.timeoutTimer != null) {
                              clearTimeout(this.timeoutTimer);
                    }
                    if(this.xmlHttp) {
                              this.xmlHttp.onreadystatechange = AjaxPro.noOperation;
                              this.xmlHttp.abort();
                    }
                    if(this.isRunning) {
                              this.isRunning = false;
                              this.onLoading(false);
                    }
          },
          dispose: function() {
                    this.abort();
          },
          getEmptyRes: function() {
                    return {
                              error: null,
                              value: null,
                              request: {method:this.method, args:this.args},
                              context: this.context,
                              duration: this.duration
                    };
          },
          endRequest: function(res) {
                    this.abort();
                    if(res.error != null) {
                              this.onError(res.error, this);
                    }
 
 
                    if(typeof this.callback == "function") {
                              this.callback(res, this);
                    }
          },
          mozerror: function() {
                    if(this.timeoutTimer != null) {
                              clearTimeout(this.timeoutTimer);
                    }
                    var res = this.getEmptyRes();
                    res.error = {Message:"Unknown",Type:"ConnectFailure",Status:0};
                    this.endRequest(res);
          },
          doStateChange: function() {
                    this.onStateChanged(this.xmlHttp.readyState, this);
 
 
                    if(this.xmlHttp.readyState != 4 || !this.isRunning) {
                              return;
                    }
 
 
                    this.duration = new Date().getTime() - this.__start;
 
 
                    if(this.timeoutTimer != null) {
                              clearTimeout(this.timeoutTimer);
                    }
 
 
                    var res = this.getEmptyRes();
                    if(this.xmlHttp.status == 200 && this.xmlHttp.statusText == "OK") {
                              res = this.createResponse(res);
                    } else {
                              res = this.createResponse(res, true);
                              res.error = {Message:this.xmlHttp.statusText,Type:"ConnectFailure",Status:this.xmlHttp.status};
                    }
 
                    this.endRequest(res);
          },
          createResponse: function(r, noContent) {
                    if(!noContent) {
                              var responseText = "" + this.xmlHttp.responseText;
 
 
                              if(AjaxPro.cryptProvider != null && typeof AjaxPro.cryptProvider == "function") {
                                        responseText = AjaxPro.cryptProvider.decrypt(responseText);
                              }
 
 
                              if(this.xmlHttp.getResponseHeader("Content-Type") == "text/xml") {
                                        r.value = this.xmlHttp.responseXML;
                              } else {
                                        if(responseText != null && responseText.trim().length > 0) {
                                                  r.json = responseText;
                                                  eval("r.value = " + responseText + "*" + "/");
                                        }
                              }
                    }
                    /* if(this.xmlHttp.getResponseHeader("X-" + AjaxPro.ID + "-Cache") == "server") {
                              r.isCached = true;
                    } */
                    return r;
          },
          timeout: function() {
                    this.duration = new Date().getTime() - this.__start;
                    var r = this.onTimeout(this.duration, this);
                    if(typeof r == "undefined" || r != false) {
                              this.abort();
                    } else {
                              this.timeoutTimer = setTimeout(this.timeout.bind(this), AjaxPro.timeoutPeriod);
                    }
          },
          invoke: function(method, args, callback, context) {
                    this.__start = new Date().getTime();
 
 
                    if(this.xmlHttp == null) {
                              this.xmlHttp = new XMLHttpRequest();
                    }
 
 
                    this.isRunning = true;
                    this.method = method;
                    this.args = args;
                    this.callback = callback;
                    this.context = context;
 
                    var async = typeof(callback) == "function" && callback != AjaxPro.noOperation;
 
                    if(async) {
                              if(MS.Browser.isIE) {
                                        this.xmlHttp.onreadystatechange = this.doStateChange.bind(this);
                              } else {
                                        this.xmlHttp.onload = this.doStateChange.bind(this);
                                        this.xmlHttp.onerror = this.mozerror.bind(this);
                              }
                              this.onLoading(true);
                    }
 
                    var json = AjaxPro.toJSON(args) + "";
                    if(AjaxPro.cryptProvider != null) {
                              json = AjaxPro.cryptProvider.encrypt(json);
                    }
 
                    this.xmlHttp.open("POST", this.url, async);
                    this.xmlHttp.setRequestHeader("Content-Type", "text/plain; charset=utf-8");
                    this.xmlHttp.setRequestHeader("X-" + AjaxPro.ID + "-Method", method);
 
                    if(AjaxPro.token != null && AjaxPro.token.length > 0) {
                              this.xmlHttp.setRequestHeader("X-" + AjaxPro.ID + "-Token", AjaxPro.token);
                    }
 
 
                    if(!MS.Browser.isIE) {
                              //this.xmlHttp.setRequestHeader("Connection", "close");                    // Mozilla Bug #246651
                    }
 
 
                    this.timeoutTimer = setTimeout(this.timeout.bind(this), AjaxPro.timeoutPeriod);
 
 
                    try{ this.xmlHttp.send(json); }catch(e){}          // IE offline exception
 
 
                    if(!async) {
                              return this.createResponse({error: null,value: null});
                    }
 
 
                    return true;
          }
};