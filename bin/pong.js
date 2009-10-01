$estr = function() { return js.Boot.__string_rec(this,''); }
js = {}
js.Boot = function() { }
js.Boot.__name__ = ["js","Boot"];
js.Boot.__unhtml = function(s) {
	return s.split("&").join("&amp;").split("<").join("&lt;").split(">").join("&gt;");
}
js.Boot.__trace = function(v,i) {
	var msg = (i != null?i.fileName + ":" + i.lineNumber + ": ":"");
	msg += js.Boot.__unhtml(js.Boot.__string_rec(v,"")) + "<br/>";
	var d = document.getElementById("haxe:trace");
	if(d == null) alert("No haxe:trace element defined\n" + msg);
	else d.innerHTML += msg;
}
js.Boot.__clear_trace = function() {
	var d = document.getElementById("haxe:trace");
	if(d != null) d.innerHTML = "";
	else null;
}
js.Boot.__closure = function(o,f) {
	var m = o[f];
	if(m == null) return null;
	var f1 = function() {
		return m.apply(o,arguments);
	}
	f1.scope = o;
	f1.method = m;
	return f1;
}
js.Boot.__string_rec = function(o,s) {
	if(o == null) return "null";
	if(s.length >= 5) return "<...>";
	var t = typeof(o);
	if(t == "function" && (o.__name__ != null || o.__ename__ != null)) t = "object";
	switch(t) {
	case "object":{
		if(o instanceof Array) {
			if(o.__enum__ != null) {
				if(o.length == 2) return o[0];
				var str = o[0] + "(";
				s += "\t";
				{
					var _g1 = 2, _g = o.length;
					while(_g1 < _g) {
						var i = _g1++;
						if(i != 2) str += "," + js.Boot.__string_rec(o[i],s);
						else str += js.Boot.__string_rec(o[i],s);
					}
				}
				return str + ")";
			}
			var l = o.length;
			var i;
			var str = "[";
			s += "\t";
			{
				var _g = 0;
				while(_g < l) {
					var i1 = _g++;
					str += ((i1 > 0?",":"")) + js.Boot.__string_rec(o[i1],s);
				}
			}
			str += "]";
			return str;
		}
		var tostr;
		try {
			tostr = o.toString;
		}
		catch( $e0 ) {
			{
				var e = $e0;
				{
					return "???";
				}
			}
		}
		if(tostr != null && tostr != Object.toString) {
			var s2 = o.toString();
			if(s2 != "[object Object]") return s2;
		}
		var k = null;
		var str = "{\n";
		s += "\t";
		var hasp = (o.hasOwnProperty != null);
		for( var k in o ) { ;
		if(hasp && !o.hasOwnProperty(k)) continue;
		if(k == "prototype" || k == "__class__" || k == "__super__" || k == "__interfaces__") continue;
		if(str.length != 2) str += ", \n";
		str += s + k + " : " + js.Boot.__string_rec(o[k],s);
		}
		s = s.substring(1);
		str += "\n" + s + "}";
		return str;
	}break;
	case "function":{
		return "<function>";
	}break;
	case "string":{
		return o;
	}break;
	default:{
		return String(o);
	}break;
	}
}
js.Boot.__interfLoop = function(cc,cl) {
	if(cc == null) return false;
	if(cc == cl) return true;
	var intf = cc.__interfaces__;
	if(intf != null) {
		var _g1 = 0, _g = intf.length;
		while(_g1 < _g) {
			var i = _g1++;
			var i1 = intf[i];
			if(i1 == cl || js.Boot.__interfLoop(i1,cl)) return true;
		}
	}
	return js.Boot.__interfLoop(cc.__super__,cl);
}
js.Boot.__instanceof = function(o,cl) {
	try {
		if(o instanceof cl) {
			if(cl == Array) return (o.__enum__ == null);
			return true;
		}
		if(js.Boot.__interfLoop(o.__class__,cl)) return true;
	}
	catch( $e1 ) {
		{
			var e = $e1;
			{
				if(cl == null) return false;
			}
		}
	}
	switch(cl) {
	case Int:{
		return Math.ceil(o%2147483648.0) === o;
	}break;
	case Float:{
		return typeof(o) == "number";
	}break;
	case Bool:{
		return o === true || o === false;
	}break;
	case String:{
		return typeof(o) == "string";
	}break;
	case Dynamic:{
		return true;
	}break;
	default:{
		if(o == null) return false;
		return o.__enum__ == cl || (cl == Class && o.__name__ != null) || (cl == Enum && o.__ename__ != null);
	}break;
	}
}
js.Boot.__init = function() {
	js.Lib.isIE = (document.all != null && window.opera == null);
	js.Lib.isOpera = (window.opera != null);
	Array.prototype.copy = Array.prototype.slice;
	Array.prototype.insert = function(i,x) {
		this.splice(i,0,x);
	}
	Array.prototype.remove = (Array.prototype.indexOf?function(obj) {
		var idx = this.indexOf(obj);
		if(idx == -1) return false;
		this.splice(idx,1);
		return true;
	}:function(obj) {
		var i = 0;
		var l = this.length;
		while(i < l) {
			if(this[i] == obj) {
				this.splice(i,1);
				return true;
			}
			i++;
		}
		return false;
	});
	Array.prototype.iterator = function() {
		return { cur : 0, arr : this, hasNext : function() {
			return this.cur < this.arr.length;
		}, next : function() {
			return this.arr[this.cur++];
		}}
	}
	var cca = String.prototype.charCodeAt;
	String.prototype.cca = cca;
	String.prototype.charCodeAt = function(i) {
		var x = cca.call(this,i);
		if(isNaN(x)) return null;
		return x;
	}
	var oldsub = String.prototype.substr;
	String.prototype.substr = function(pos,len) {
		if(pos != null && pos != 0 && len != null && len < 0) return "";
		if(len == null) len = this.length;
		if(pos < 0) {
			pos = this.length + pos;
			if(pos < 0) pos = 0;
		}
		else if(len < 0) {
			len = this.length + len - pos;
		}
		return oldsub.apply(this,[pos,len]);
	}
	$closure = js.Boot.__closure;
}
js.Boot.prototype.__class__ = js.Boot;
pong = {}
pong.geom = {}
pong.geom.Vector = function(x_,y_) { if( x_ === $_ ) return; {
	this.x = x_;
	this.y = y_;
}}
pong.geom.Vector.__name__ = ["pong","geom","Vector"];
pong.geom.Vector.prototype.x = null;
pong.geom.Vector.prototype.y = null;
pong.geom.Vector.prototype.__class__ = pong.geom.Vector;
js.Lib = function() { }
js.Lib.__name__ = ["js","Lib"];
js.Lib.isIE = null;
js.Lib.isOpera = null;
js.Lib.document = null;
js.Lib.window = null;
js.Lib.alert = function(v) {
	alert(js.Boot.__string_rec(v,""));
}
js.Lib.eval = function(code) {
	return eval(code);
}
js.Lib.setErrorHandler = function(f) {
	js.Lib.onerror = f;
}
js.Lib.prototype.__class__ = js.Lib;
pong.gfx = {}
pong.gfx.Label = function(p) { if( p === $_ ) return; {
	this.element = pong.gfx.Stage.ELEMENT.cloneNode(false);
	this.element.style.position = "absolute";
	this.element.style.background = "none";
	this.element.style.width = "40px";
	this.element.style.color = "#fff";
}}
pong.gfx.Label.__name__ = ["pong","gfx","Label"];
pong.gfx.Label.prototype.element = null;
pong.gfx.Label.prototype.getText = function() {
	return this.element.innerHTML;
}
pong.gfx.Label.prototype.getX = function() {
	return 0;
}
pong.gfx.Label.prototype.getY = function() {
	return 0;
}
pong.gfx.Label.prototype.setText = function(v) {
	this.element.innerHTML = v;
	return "";
}
pong.gfx.Label.prototype.setX = function(v) {
	this.element.style.left = Std.string(v);
	return 0;
}
pong.gfx.Label.prototype.setY = function(v) {
	this.element.style.top = Std.string(v);
	return 0;
}
pong.gfx.Label.prototype.text = null;
pong.gfx.Label.prototype.x = null;
pong.gfx.Label.prototype.y = null;
pong.gfx.Label.prototype.__class__ = pong.gfx.Label;
pong.geom.Rectangle = function(x_,y_,width_,height_) { if( x_ === $_ ) return; {
	this.x = x_;
	this.y = y_;
	this.width = width_;
	this.height = height_;
}}
pong.geom.Rectangle.__name__ = ["pong","geom","Rectangle"];
pong.geom.Rectangle.prototype.height = null;
pong.geom.Rectangle.prototype.isOverlapping = function(rect) {
	if(this.x < rect.x + rect.width && this.x + this.width > rect.x && this.y < rect.y + rect.height && this.y + this.height > rect.y) return true;
	return false;
}
pong.geom.Rectangle.prototype.width = null;
pong.geom.Rectangle.prototype.x = null;
pong.geom.Rectangle.prototype.y = null;
pong.geom.Rectangle.prototype.__class__ = pong.geom.Rectangle;
pong.Player = function(x_,y_,width_,height_) { if( x_ === $_ ) return; {
	pong.geom.Rectangle.apply(this,[x_,y_,width_,height_]);
	this.sprite = new pong.gfx.Rectangle(x_,y_,width_,height_);
	this.velocity = new pong.geom.Vector(0,0);
	this.score = 0;
	this.ai = true;
}}
pong.Player.__name__ = ["pong","Player"];
pong.Player.__super__ = pong.geom.Rectangle;
for(var k in pong.geom.Rectangle.prototype ) pong.Player.prototype[k] = pong.geom.Rectangle.prototype[k];
pong.Player.prototype.ai = null;
pong.Player.prototype.move = function() {
	this.x += this.velocity.x;
	this.y += this.velocity.y;
}
pong.Player.prototype.render = function() {
	this.sprite.setX(this.x);
	this.sprite.setY(this.y);
}
pong.Player.prototype.score = null;
pong.Player.prototype.sprite = null;
pong.Player.prototype.velocity = null;
pong.Player.prototype.__class__ = pong.Player;
Std = function() { }
Std.__name__ = ["Std"];
Std["is"] = function(v,t) {
	return js.Boot.__instanceof(v,t);
}
Std.string = function(s) {
	return js.Boot.__string_rec(s,"");
}
Std["int"] = function(x) {
	if(x < 0) return Math.ceil(x);
	return Math.floor(x);
}
Std.parseInt = function(x) {
	var v = parseInt(x);
	if(Math.isNaN(v)) return null;
	return v;
}
Std.parseFloat = function(x) {
	return parseFloat(x);
}
Std.random = function(x) {
	return Math.floor(Math.random() * x);
}
Std.prototype.__class__ = Std;
pong.Game = function(p) { if( p === $_ ) return; {
	this._physicsTicker = new haxe.Timer(25);
	this._physicsTicker.run = $closure(this,"physicsStep");
	this._graphicsTicker = new haxe.Timer(25);
	this._graphicsTicker.run = $closure(this,"render");
	this.setupStage();
	this.newRound();
	this._ball.y -= 100;
}}
pong.Game.__name__ = ["pong","Game"];
pong.Game.prototype._ball = null;
pong.Game.prototype._graphicsTicker = null;
pong.Game.prototype._id = null;
pong.Game.prototype._leftPlayer = null;
pong.Game.prototype._leftScoreLabel = null;
pong.Game.prototype._physicsTicker = null;
pong.Game.prototype._rightPlayer = null;
pong.Game.prototype._rightScoreLabel = null;
pong.Game.prototype._stage = null;
pong.Game.prototype.doCollisions = function() {
	if(this._leftPlayer.y + this._leftPlayer.height > pong.gfx.Stage.getHeight() - 10) {
		this._leftPlayer.y = pong.gfx.Stage.getHeight() - this._leftPlayer.height - 10;
	}
	if(this._leftPlayer.y < 10) {
		this._leftPlayer.y = 10;
	}
	if(this._rightPlayer.y + this._rightPlayer.height > pong.gfx.Stage.getHeight() - 10) {
		this._rightPlayer.y = pong.gfx.Stage.getHeight() - this._rightPlayer.height - 10;
	}
	if(this._rightPlayer.y < 10) {
		this._rightPlayer.y = 10;
	}
	if(this._ball.y + this._ball.height > pong.gfx.Stage.getHeight() - 10) {
		this._ball.y = pong.gfx.Stage.getHeight() - this._ball.height - 10;
		this._ball.velocity.y *= -1;
	}
	if(this._ball.y < 10) {
		this._ball.y = 10;
		this._ball.velocity.y *= -1;
	}
	if(this._ball.x < 0 - this._ball.width) {
		this._rightScoreLabel.setText(Std.string(++this._rightPlayer.score));
		this.newRound();
	}
	if(this._ball.x > pong.gfx.Stage.getWidth()) {
		this._leftScoreLabel.setText(Std.string(++this._leftPlayer.score));
		this.newRound();
	}
	if(this._ball.isOverlapping(this._leftPlayer)) {
		this._ball.x = this._leftPlayer.x + this._leftPlayer.width;
		this._ball.velocity.x *= -1;
	}
	if(this._ball.isOverlapping(this._rightPlayer)) {
		this._ball.x = this._rightPlayer.x - this._ball.width;
		this._ball.velocity.x *= -1;
	}
}
pong.Game.prototype.newRound = function() {
	this._leftPlayer.y = pong.gfx.Stage.getHeight() / 2 - this._leftPlayer.height / 2;
	this._rightPlayer.y = pong.gfx.Stage.getHeight() / 2 - this._rightPlayer.height / 2;
	this._ball.y = pong.gfx.Stage.getHeight() / 2 - this._ball.height / 2;
	this._ball.x = pong.gfx.Stage.getWidth() / 2 - this._ball.width / 2;
}
pong.Game.prototype.physicsStep = function() {
	if(!this._leftPlayer.ai) null;
	else if(this._ball.velocity.x < 0) this.runAI(this._leftPlayer);
	else this._leftPlayer.velocity.y = 0;
	if(!this._rightPlayer.ai) null;
	else if(this._ball.velocity.x > 0) this.runAI(this._rightPlayer);
	else this._rightPlayer.velocity.y = 0;
	this._leftPlayer.move();
	this._rightPlayer.move();
	this._ball.move();
	this.doCollisions();
}
pong.Game.prototype.render = function() {
	this._ball.render();
	this._leftPlayer.render();
	this._rightPlayer.render();
}
pong.Game.prototype.runAI = function(p) {
	if(p.y + p.height / 2 < this._ball.y + this._ball.height / 2) p.velocity.y = 1;
	else if(p.y + p.height / 2 > this._ball.y + this._ball.height / 2) p.velocity.y = -1;
	else p.velocity.y = 0;
}
pong.Game.prototype.setupStage = function() {
	this._stage = pong.gfx.Stage.getInstance();
	this._ball = new pong.Ball(150,50,20,20);
	this._leftPlayer = new pong.Player(30,50,20,100);
	this._rightPlayer = new pong.Player(pong.gfx.Stage.getWidth() - 50,50,20,100);
	this._stage.add(this._ball.sprite);
	this._stage.add(this._leftPlayer.sprite);
	this._stage.add(this._rightPlayer.sprite);
	this._leftScoreLabel = new pong.gfx.Label();
	this._leftScoreLabel.setText("0");
	this._leftScoreLabel.setY(10);
	this._leftScoreLabel.setX(pong.gfx.Stage.getWidth() * 0.5 - 20);
	this._rightScoreLabel = new pong.gfx.Label();
	this._rightScoreLabel.setText("0");
	this._rightScoreLabel.setY(10);
	this._rightScoreLabel.setX(pong.gfx.Stage.getWidth() * 0.5 + 10);
	this._stage.add(this._leftScoreLabel);
	this._stage.add(this._rightScoreLabel);
}
pong.Game.prototype.__class__ = pong.Game;
haxe = {}
haxe.Timer = function(time_ms) { if( time_ms === $_ ) return; {
	this.id = haxe.Timer.arr.length;
	haxe.Timer.arr[this.id] = this;
	this.timerId = window.setInterval("haxe.Timer.arr[" + this.id + "].run();",time_ms);
}}
haxe.Timer.__name__ = ["haxe","Timer"];
haxe.Timer.delay = function(f,time_ms) {
	var t = new haxe.Timer(time_ms);
	t.run = function() {
		t.stop();
		f();
	}
	return t;
}
haxe.Timer.stamp = function() {
	return Date.now().getTime() / 1000;
}
haxe.Timer.prototype.id = null;
haxe.Timer.prototype.run = function() {
	null;
}
haxe.Timer.prototype.stop = function() {
	if(this.id == null) return;
	window.clearInterval(this.timerId);
	haxe.Timer.arr[this.id] = null;
	if(this.id > 100 && this.id == haxe.Timer.arr.length - 1) {
		var p = this.id - 1;
		while(p >= 0 && haxe.Timer.arr[p] == null) p--;
		haxe.Timer.arr = haxe.Timer.arr.slice(0,p + 1);
	}
	this.id = null;
}
haxe.Timer.prototype.timerId = null;
haxe.Timer.prototype.__class__ = haxe.Timer;
StringTools = function() { }
StringTools.__name__ = ["StringTools"];
StringTools.urlEncode = function(s) {
	return encodeURIComponent(s);
}
StringTools.urlDecode = function(s) {
	return decodeURIComponent(s.split("+").join(" "));
}
StringTools.htmlEscape = function(s) {
	return s.split("&").join("&amp;").split("<").join("&lt;").split(">").join("&gt;");
}
StringTools.htmlUnescape = function(s) {
	return s.split("&gt;").join(">").split("&lt;").join("<").split("&amp;").join("&");
}
StringTools.startsWith = function(s,start) {
	return (s.length >= start.length && s.substr(0,start.length) == start);
}
StringTools.endsWith = function(s,end) {
	var elen = end.length;
	var slen = s.length;
	return (slen >= elen && s.substr(slen - elen,elen) == end);
}
StringTools.isSpace = function(s,pos) {
	var c = s.charCodeAt(pos);
	return (c >= 9 && c <= 13) || c == 32;
}
StringTools.ltrim = function(s) {
	var l = s.length;
	var r = 0;
	while(r < l && StringTools.isSpace(s,r)) {
		r++;
	}
	if(r > 0) return s.substr(r,l - r);
	else return s;
}
StringTools.rtrim = function(s) {
	var l = s.length;
	var r = 0;
	while(r < l && StringTools.isSpace(s,l - r - 1)) {
		r++;
	}
	if(r > 0) {
		return s.substr(0,l - r);
	}
	else {
		return s;
	}
}
StringTools.trim = function(s) {
	return StringTools.ltrim(StringTools.rtrim(s));
}
StringTools.rpad = function(s,c,l) {
	var sl = s.length;
	var cl = c.length;
	while(sl < l) {
		if(l - sl < cl) {
			s += c.substr(0,l - sl);
			sl = l;
		}
		else {
			s += c;
			sl += cl;
		}
	}
	return s;
}
StringTools.lpad = function(s,c,l) {
	var ns = "";
	var sl = s.length;
	if(sl >= l) return s;
	var cl = c.length;
	while(sl < l) {
		if(l - sl < cl) {
			ns += c.substr(0,l - sl);
			sl = l;
		}
		else {
			ns += c;
			sl += cl;
		}
	}
	return ns + s;
}
StringTools.replace = function(s,sub,by) {
	return s.split(sub).join(by);
}
StringTools.hex = function(n,digits) {
	var neg = false;
	if(n < 0) {
		neg = true;
		n = -n;
	}
	var s = n.toString(16);
	s = s.toUpperCase();
	if(digits != null) while(s.length < digits) s = "0" + s;
	if(neg) s = "-" + s;
	return s;
}
StringTools.prototype.__class__ = StringTools;
pong.gfx.Rectangle = function(x_,y_,width_,height_) { if( x_ === $_ ) return; {
	this._color = 16777215;
	this._x = x_;
	this._y = y_;
	this._width = width_;
	this._height = height_;
	this.element = pong.gfx.Stage.ELEMENT.cloneNode(false);
	this.element.style.position = "absolute";
	this.drawRect();
}}
pong.gfx.Rectangle.__name__ = ["pong","gfx","Rectangle"];
pong.gfx.Rectangle.prototype._color = null;
pong.gfx.Rectangle.prototype._height = null;
pong.gfx.Rectangle.prototype._width = null;
pong.gfx.Rectangle.prototype._x = null;
pong.gfx.Rectangle.prototype._y = null;
pong.gfx.Rectangle.prototype.drawRect = function() {
	this.element.style.top = Std.string(this._y) + "px";
	this.element.style.left = Std.string(this._x) + "px";
	this.element.style.background = "#" + StringTools.hex(this._color,6);
	this.element.style.width = Std.string(this._width) + "px";
	this.element.style.height = Std.string(this._height) + "px";
}
pong.gfx.Rectangle.prototype.element = null;
pong.gfx.Rectangle.prototype.getX = function() {
	return 0;
}
pong.gfx.Rectangle.prototype.getY = function() {
	return 0;
}
pong.gfx.Rectangle.prototype.setX = function(val) {
	this.element.style.left = Std.string(val) + "px";
	return 0;
}
pong.gfx.Rectangle.prototype.setY = function(val) {
	this.element.style.top = Std.string(val) + "px";
	return 0;
}
pong.gfx.Rectangle.prototype.x = null;
pong.gfx.Rectangle.prototype.y = null;
pong.gfx.Rectangle.prototype.__class__ = pong.gfx.Rectangle;
pong.Ball = function(x_,y_,width_,height_) { if( x_ === $_ ) return; {
	pong.geom.Rectangle.apply(this,[x_,y_,width_,height_]);
	this.sprite = new pong.gfx.Rectangle(x_,y_,width_,height_);
	this.velocity = new pong.geom.Vector(1,1);
}}
pong.Ball.__name__ = ["pong","Ball"];
pong.Ball.__super__ = pong.geom.Rectangle;
for(var k in pong.geom.Rectangle.prototype ) pong.Ball.prototype[k] = pong.geom.Rectangle.prototype[k];
pong.Ball.prototype.move = function() {
	this.x += this.velocity.x;
	this.y += this.velocity.y;
}
pong.Ball.prototype.render = function() {
	this.sprite.setX(this.x);
	this.sprite.setY(this.y);
}
pong.Ball.prototype.sprite = null;
pong.Ball.prototype.velocity = null;
pong.Ball.prototype.__class__ = pong.Ball;
pong.gfx.Stage = function(p) { if( p === $_ ) return; {
	pong.gfx.Stage.ELEMENT = js.Lib.document.getElementById(pong.gfx.Stage._ID);
	if(pong.gfx.Stage.ELEMENT == null) js.Lib.alert("Unknown element : " + pong.gfx.Stage._ID);
	this.drawBackground();
}}
pong.gfx.Stage.__name__ = ["pong","gfx","Stage"];
pong.gfx.Stage.width = null;
pong.gfx.Stage.height = null;
pong.gfx.Stage.ELEMENT = null;
pong.gfx.Stage._instance = null;
pong.gfx.Stage.getInstance = function() {
	if(pong.gfx.Stage._instance == null) pong.gfx.Stage._instance = new pong.gfx.Stage();
	return pong.gfx.Stage._instance;
}
pong.gfx.Stage.getWidth = function() {
	return js.Lib.window.document.body.clientWidth;
}
pong.gfx.Stage.getHeight = function() {
	return js.Lib.window.document.body.clientHeight;
}
pong.gfx.Stage.prototype.add = function(object) {
	pong.gfx.Stage.ELEMENT.appendChild(object.element);
}
pong.gfx.Stage.prototype.drawBackground = function() {
	pong.gfx.Stage.ELEMENT.style.background = "#000000";
	pong.gfx.Stage.ELEMENT.style.border = "0";
	pong.gfx.Stage.ELEMENT.style.padding = "0";
	pong.gfx.Stage.ELEMENT.style.margin = "0";
	pong.gfx.Stage.ELEMENT.style.display = "block";
	pong.gfx.Stage.ELEMENT.style.width = "100%";
	pong.gfx.Stage.ELEMENT.style.height = "100%";
	pong.gfx.Stage.ELEMENT.style.position = "absolute";
	pong.gfx.Stage.ELEMENT.style.top = "0px";
	pong.gfx.Stage.ELEMENT.style.left = "0px";
	pong.gfx.Stage.ELEMENT.style.overflow = "hidden";
}
pong.gfx.Stage.prototype.__class__ = pong.gfx.Stage;
pong.ui = {}
pong.ui.Keyboard = function(p) { if( p === $_ ) return; {
	null;
}}
pong.ui.Keyboard.__name__ = ["pong","ui","Keyboard"];
pong.ui.Keyboard.prototype.__class__ = pong.ui.Keyboard;
pong.Main = function() { }
pong.Main.__name__ = ["pong","Main"];
pong.Main.main = function() {
	new pong.Game();
}
pong.Main.prototype.__class__ = pong.Main;
IntIter = function(min,max) { if( min === $_ ) return; {
	this.min = min;
	this.max = max;
}}
IntIter.__name__ = ["IntIter"];
IntIter.prototype.hasNext = function() {
	return this.min < this.max;
}
IntIter.prototype.max = null;
IntIter.prototype.min = null;
IntIter.prototype.next = function() {
	return this.min++;
}
IntIter.prototype.__class__ = IntIter;
$Main = function() { }
$Main.__name__ = ["@Main"];
$Main.prototype.__class__ = $Main;
$_ = {}
js.Boot.__res = {}
js.Boot.__init();
{
	Date.now = function() {
		return new Date();
	}
	Date.fromTime = function(t) {
		var d = new Date();
		d["setTime"](t);
		return d;
	}
	Date.fromString = function(s) {
		switch(s.length) {
		case 8:{
			var k = s.split(":");
			var d = new Date();
			d["setTime"](0);
			d["setUTCHours"](k[0]);
			d["setUTCMinutes"](k[1]);
			d["setUTCSeconds"](k[2]);
			return d;
		}break;
		case 10:{
			var k = s.split("-");
			return new Date(k[0],k[1] - 1,k[2],0,0,0);
		}break;
		case 19:{
			var k = s.split(" ");
			var y = k[0].split("-");
			var t = k[1].split(":");
			return new Date(y[0],y[1] - 1,y[2],t[0],t[1],t[2]);
		}break;
		default:{
			throw "Invalid date format : " + s;
		}break;
		}
	}
	Date.prototype["toString"] = function() {
		var date = this;
		var m = date.getMonth() + 1;
		var d = date.getDate();
		var h = date.getHours();
		var mi = date.getMinutes();
		var s = date.getSeconds();
		return date.getFullYear() + "-" + ((m < 10?"0" + m:"" + m)) + "-" + ((d < 10?"0" + d:"" + d)) + " " + ((h < 10?"0" + h:"" + h)) + ":" + ((mi < 10?"0" + mi:"" + mi)) + ":" + ((s < 10?"0" + s:"" + s));
	}
	Date.prototype.__class__ = Date;
	Date.__name__ = ["Date"];
}
{
	js.Lib.document = document;
	js.Lib.window = window;
	onerror = function(msg,url,line) {
		var f = js.Lib.onerror;
		if( f == null )
			return false;
		return f(msg,[url+":"+line]);
	}
}
{
	String.prototype.__class__ = String;
	String.__name__ = ["String"];
	Array.prototype.__class__ = Array;
	Array.__name__ = ["Array"];
	Int = { __name__ : ["Int"]}
	Dynamic = { __name__ : ["Dynamic"]}
	Float = Number;
	Float.__name__ = ["Float"];
	Bool = { __ename__ : ["Bool"]}
	Class = { __name__ : ["Class"]}
	Enum = { }
	Void = { __ename__ : ["Void"]}
}
{
	Math.NaN = Number["NaN"];
	Math.NEGATIVE_INFINITY = Number["NEGATIVE_INFINITY"];
	Math.POSITIVE_INFINITY = Number["POSITIVE_INFINITY"];
	Math.isFinite = function(i) {
		return isFinite(i);
	}
	Math.isNaN = function(i) {
		return isNaN(i);
	}
	Math.__name__ = ["Math"];
}
js.Lib.onerror = null;
haxe.Timer.arr = new Array();
pong.gfx.Stage._ID = "pong";
$Main.init = pong.Main.main();
