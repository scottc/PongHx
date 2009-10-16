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
pong.geom.Vector.prototype.clone = function() {
	return new pong.geom.Vector(this.x,this.y);
}
pong.geom.Vector.prototype.crossProduct = function(v) {
	return this.x * v.y - this.y * v.x;
}
pong.geom.Vector.prototype.dotProduct = function(v) {
	return this.x * v.x + this.y * v.y;
}
pong.geom.Vector.prototype.length = function() {
	return Math.sqrt(this.x * this.x + this.y * this.y);
}
pong.geom.Vector.prototype.minus = function(v) {
	return new pong.geom.Vector(this.x - v.x,this.y - v.y);
}
pong.geom.Vector.prototype.multiply = function(n) {
	return new pong.geom.Vector(this.x * n,this.y * n);
}
pong.geom.Vector.prototype.normalize = function(l) {
	if(l == null) l = 1;
	var d = Math.sqrt(this.x * this.x + this.y * this.y);
	if(d == 0) return new pong.geom.Vector(0,0);
	else return new pong.geom.Vector(this.x / d * l,this.y / d * l);
}
pong.geom.Vector.prototype.plus = function(v) {
	return new pong.geom.Vector(this.x + v.x,this.y + v.y);
}
pong.geom.Vector.prototype.set = function(x_,y_) {
	this.x = x_;
	this.y = y_;
}
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
pong.gfx.Label = function(text_) { if( text_ === $_ ) return; {
	if(text_ == null) text_ = "";
	this.element = pong.gfx.Stage.ELEMENT.cloneNode(false);
	this.element.style.position = "absolute";
	this.element.style.background = "none";
	this.element.style.width = "40px";
	this.element.style.color = "#fff";
	this.setText(text_);
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
pong.ui = {}
pong.ui.Mouse = function() { }
pong.ui.Mouse.__name__ = ["pong","ui","Mouse"];
pong.ui.Mouse.initialize = function() {
	js.Lib.document.onmousemove = $closure(pong.ui.Mouse,"mouseMove");
	js.Lib.document.onmousedown = $closure(pong.ui.Mouse,"mousePressed");
}
pong.ui.Mouse.mouseMove = function(e) {
	pong.ui.Mouse.x = (js.Lib.isIE?event.x:e.clientX);
	pong.ui.Mouse.y = (js.Lib.isIE?event.y:e.clientY);
}
pong.ui.Mouse.mousePressed = function(e) {
	null;
}
pong.ui.Mouse.prototype.__class__ = pong.ui.Mouse;
pong.gfx.IDisplayObject = function() { }
pong.gfx.IDisplayObject.__name__ = ["pong","gfx","IDisplayObject"];
pong.gfx.IDisplayObject.prototype.__class__ = pong.gfx.IDisplayObject;
pong.MainMenu = function(p) { if( p === $_ ) return; {
	new pong.Game();
}}
pong.MainMenu.__name__ = ["pong","MainMenu"];
pong.MainMenu.prototype.__class__ = pong.MainMenu;
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
pong.Game = function(width_,height_) { if( width_ === $_ ) return; {
	if(height_ == null) height_ = 300;
	if(width_ == null) width_ = 300;
	this.setWidth(width_);
	this.setHeight(height_);
	this.setFrameRate(60);
	this.setPhysicsRate(60);
	this.setupStage();
	this.newRound();
	this.render();
}}
pong.Game.__name__ = ["pong","Game"];
pong.Game.prototype._backGround = null;
pong.Game.prototype._ball = null;
pong.Game.prototype._frameRate = null;
pong.Game.prototype._graphicsTicker = null;
pong.Game.prototype._height = null;
pong.Game.prototype._leftPaddle = null;
pong.Game.prototype._leftScoreLabel = null;
pong.Game.prototype._physicsRate = null;
pong.Game.prototype._physicsTicker = null;
pong.Game.prototype._rightPaddle = null;
pong.Game.prototype._rightScoreLabel = null;
pong.Game.prototype._stage = null;
pong.Game.prototype._width = null;
pong.Game.prototype._x = null;
pong.Game.prototype._y = null;
pong.Game.prototype.ballPaddleCollision = function(p) {
	if(this._ball.isOverlapping(p)) {
		var newDirection = new pong.geom.Vector((this._ball.x + this._ball.width * 0.5) - (p.x + p.width * 0.5),(this._ball.y + this._ball.height * 0.5) - (p.y + p.height * 0.5));
		this._ball.velocity = newDirection.normalize(this._ball.velocity.length());
	}
}
pong.Game.prototype.doCollisions = function() {
	if(this._leftPaddle.y + this._leftPaddle.height > this.getHeight() - 10) {
		this._leftPaddle.y = this.getHeight() - this._leftPaddle.height - 10;
	}
	if(this._leftPaddle.y < 10) {
		this._leftPaddle.y = 10;
	}
	if(this._rightPaddle.y + this._rightPaddle.height > this.getHeight() - 10) {
		this._rightPaddle.y = this.getHeight() - this._rightPaddle.height - 10;
	}
	if(this._rightPaddle.y < 10) {
		this._rightPaddle.y = 10;
	}
	if(this._ball.y + this._ball.height > this.getHeight() - 10) {
		this._ball.y = this.getHeight() - this._ball.height - 10;
		this._ball.velocity.y *= -1;
	}
	if(this._ball.y < 10) {
		this._ball.y = 10;
		this._ball.velocity.y *= -1;
	}
	if(this._ball.x < -this._ball.width) {
		this._rightScoreLabel.setText(Std.string(++this._rightPaddle.score));
		this.newRound();
	}
	if(this._ball.x > this.getWidth()) {
		this._leftScoreLabel.setText(Std.string(++this._leftPaddle.score));
		this.newRound();
	}
	this.ballPaddleCollision(this._leftPaddle);
	this.ballPaddleCollision(this._rightPaddle);
}
pong.Game.prototype.frameRate = null;
pong.Game.prototype.getFrameRate = function() {
	return this._frameRate;
}
pong.Game.prototype.getHeight = function() {
	return this._height;
}
pong.Game.prototype.getPhysicsRate = function() {
	return this._physicsRate;
}
pong.Game.prototype.getWidth = function() {
	return this._width;
}
pong.Game.prototype.getX = function() {
	return this._x;
}
pong.Game.prototype.getY = function() {
	return this._y;
}
pong.Game.prototype.height = null;
pong.Game.prototype.newRound = function() {
	this._leftPaddle.y = this.getHeight() / 2 - this._leftPaddle.height / 2;
	this._rightPaddle.y = this.getHeight() / 2 - this._rightPaddle.height / 2;
	this._ball.y = this.getHeight() / 2 - this._ball.height / 2;
	this._ball.x = this.getWidth() / 2 - this._ball.width / 2;
	this._ball.velocity.x = this.getWidth() * Math.random() - this.getWidth() * 0.5;
	this._ball.velocity.y = this.getHeight() * Math.random() - this.getHeight() * 0.5;
	this._ball.velocity = this._ball.velocity.normalize(this.getWidth() * 0.01);
}
pong.Game.prototype.physicsRate = null;
pong.Game.prototype.physicsStep = function() {
	if(!this._leftPaddle.ai) {
		this._leftPaddle.y = pong.ui.Mouse.y - this._leftPaddle.height / 2;
	}
	else if(this._ball.velocity.x < 0) this.runAI(this._leftPaddle);
	else this._leftPaddle.velocity.y = 0;
	if(!this._rightPaddle.ai) {
		this._rightPaddle.y = pong.ui.Mouse.y - this._rightPaddle.height / 2;
	}
	else if(this._ball.velocity.x > 0) this.runAI(this._rightPaddle);
	else this._rightPaddle.velocity.y = 0;
	this._leftPaddle.move();
	this._rightPaddle.move();
	this._ball.move();
	this.doCollisions();
}
pong.Game.prototype.render = function() {
	this._ball.render();
	this._leftPaddle.render();
	this._rightPaddle.render();
}
pong.Game.prototype.runAI = function(p) {
	if(p.y + p.height / 2 < this._ball.y + this._ball.height / 2) p.velocity.y = this.getHeight() * 0.01;
	else if(p.y + p.height / 2 > this._ball.y + this._ball.height / 2) p.velocity.y = this.getHeight() * -0.01;
	else p.velocity.y = 0;
}
pong.Game.prototype.setFrameRate = function(v) {
	this._physicsRate = v;
	if(this._physicsTicker != null) this._physicsTicker.stop();
	this._physicsTicker = new haxe.Timer(Math.floor(1000 / this._physicsRate));
	this._physicsTicker.run = $closure(this,"physicsStep");
	return v;
}
pong.Game.prototype.setHeight = function(v) {
	this._height = v;
	return v;
}
pong.Game.prototype.setPhysicsRate = function(v) {
	this._frameRate = v;
	if(this._graphicsTicker != null) this._graphicsTicker.stop();
	this._graphicsTicker = new haxe.Timer(Math.floor(1000 / this._frameRate));
	this._graphicsTicker.run = $closure(this,"render");
	return v;
}
pong.Game.prototype.setWidth = function(v) {
	this._width = v;
	return v;
}
pong.Game.prototype.setX = function(v) {
	this._x = v;
	this._backGround.setX(v);
	return v;
}
pong.Game.prototype.setY = function(v) {
	this._y = v;
	this._backGround.setY(v);
	return v;
}
pong.Game.prototype.setupStage = function() {
	this._stage = pong.gfx.Stage.getInstance();
	this._backGround = new pong.gfx.PongBackground(this.getWidth(),this.getHeight());
	this._stage.add(this._backGround);
	this._ball = new pong.Ball(150,50,this.getWidth() * 0.02,this.getWidth() * 0.02);
	this._leftPaddle = new pong.Paddle(this.getWidth() * 0.05,50,this.getWidth() * 0.02,this.getHeight() * 0.15);
	this._rightPaddle = new pong.Paddle(this.getWidth() * 0.93,50,this.getWidth() * 0.02,this.getHeight() * 0.15);
	this._rightPaddle.ai = true;
	this._stage.add(this._ball.sprite);
	this._stage.add(this._leftPaddle.sprite);
	this._stage.add(this._rightPaddle.sprite);
	this._leftScoreLabel = new pong.gfx.Label();
	this._leftScoreLabel.setText(Std.string(this._leftPaddle.score));
	this._leftScoreLabel.setY(10);
	this._leftScoreLabel.setX(this.getWidth() * 0.5 - 20);
	this._rightScoreLabel = new pong.gfx.Label();
	this._rightScoreLabel.setText(Std.string(this._rightPaddle.score));
	this._rightScoreLabel.setY(10);
	this._rightScoreLabel.setX(this.getWidth() * 0.5 + 10);
	this._stage.add(this._leftScoreLabel);
	this._stage.add(this._rightScoreLabel);
}
pong.Game.prototype.width = null;
pong.Game.prototype.x = null;
pong.Game.prototype.y = null;
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
pong.Paddle = function(x_,y_,width_,height_) { if( x_ === $_ ) return; {
	pong.geom.Rectangle.apply(this,[x_,y_,width_,height_]);
	this.sprite = new pong.gfx.Rectangle(x_,y_,width_,height_);
	this.velocity = new pong.geom.Vector(0,0);
	this.score = 0;
	this.ai = false;
}}
pong.Paddle.__name__ = ["pong","Paddle"];
pong.Paddle.__super__ = pong.geom.Rectangle;
for(var k in pong.geom.Rectangle.prototype ) pong.Paddle.prototype[k] = pong.geom.Rectangle.prototype[k];
pong.Paddle.prototype.ai = null;
pong.Paddle.prototype.move = function() {
	this.x += this.velocity.x;
	this.y += this.velocity.y;
}
pong.Paddle.prototype.render = function() {
	this.sprite.setX(this.x);
	this.sprite.setY(this.y);
}
pong.Paddle.prototype.score = null;
pong.Paddle.prototype.sprite = null;
pong.Paddle.prototype.velocity = null;
pong.Paddle.prototype.__class__ = pong.Paddle;
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
pong.gfx.Rectangle.prototype.color = null;
pong.gfx.Rectangle.prototype.drawRect = function() {
	this.element.style.top = Std.string(this._y) + "px";
	this.element.style.left = Std.string(this._x) + "px";
	this.element.style.background = "#" + StringTools.hex(this._color,6);
	this.element.style.width = Std.string(this._width) + "px";
	this.element.style.height = Std.string(this._height) + "px";
}
pong.gfx.Rectangle.prototype.element = null;
pong.gfx.Rectangle.prototype.getColor = function() {
	return this._color;
}
pong.gfx.Rectangle.prototype.getHeight = function() {
	return this._height;
}
pong.gfx.Rectangle.prototype.getWidth = function() {
	return this._width;
}
pong.gfx.Rectangle.prototype.getX = function() {
	return this._x;
}
pong.gfx.Rectangle.prototype.getY = function() {
	return this._y;
}
pong.gfx.Rectangle.prototype.height = null;
pong.gfx.Rectangle.prototype.setColor = function(v) {
	this._color = v;
	this.element.style.background = "#" + StringTools.hex(this._color,6);
	return v;
}
pong.gfx.Rectangle.prototype.setHeight = function(v) {
	this._height = v;
	this.element.style.height = Std.string(v) + "px";
	return v;
}
pong.gfx.Rectangle.prototype.setWidth = function(v) {
	this._width = v;
	this.element.style.width = Std.string(v) + "px";
	return v;
}
pong.gfx.Rectangle.prototype.setX = function(v) {
	this.element.style.left = Std.string(v) + "px";
	return 0;
}
pong.gfx.Rectangle.prototype.setY = function(v) {
	this.element.style.top = Std.string(v) + "px";
	return 0;
}
pong.gfx.Rectangle.prototype.width = null;
pong.gfx.Rectangle.prototype.x = null;
pong.gfx.Rectangle.prototype.y = null;
pong.gfx.Rectangle.prototype.__class__ = pong.gfx.Rectangle;
pong.gfx.Rectangle.__interfaces__ = [pong.gfx.IDisplayObject];
pong.Ball = function(x_,y_,width_,height_) { if( x_ === $_ ) return; {
	pong.geom.Rectangle.apply(this,[x_,y_,width_,height_]);
	this.sprite = new pong.gfx.Rectangle(x_,y_,width_,height_);
	this.velocity = new pong.geom.Vector(0,0);
	this.acceleration = js.Lib.window.document.body.clientWidth * 0.01;
}}
pong.Ball.__name__ = ["pong","Ball"];
pong.Ball.__super__ = pong.geom.Rectangle;
for(var k in pong.geom.Rectangle.prototype ) pong.Ball.prototype[k] = pong.geom.Rectangle.prototype[k];
pong.Ball.prototype.acceleration = null;
pong.Ball.prototype.move = function() {
	this.velocity.normalize(1 + this.acceleration);
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
	pong.gfx.Stage.ELEMENT = js.Lib.document.getElementById(pong.gfx.Stage.ELEMENT_ID);
	if(pong.gfx.Stage.ELEMENT == null) js.Lib.alert("Unknown element : " + pong.gfx.Stage.ELEMENT_ID);
	this._element = pong.gfx.Stage.ELEMENT.cloneNode(false);
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
pong.gfx.Stage.prototype._displayObjects = null;
pong.gfx.Stage.prototype._element = null;
pong.gfx.Stage.prototype.add = function(object) {
	this._element.appendChild(object.element);
}
pong.gfx.Stage.prototype.__class__ = pong.gfx.Stage;
pong.ui.Keyboard = function(p) { if( p === $_ ) return; {
	null;
}}
pong.ui.Keyboard.__name__ = ["pong","ui","Keyboard"];
pong.ui.Keyboard.prototype.__class__ = pong.ui.Keyboard;
pong.gfx.PongBackground = function(width_,height_) { if( width_ === $_ ) return; {
	pong.gfx.Rectangle.apply(this,[0,0,width_,height_]);
	this.setColor(0);
}}
pong.gfx.PongBackground.__name__ = ["pong","gfx","PongBackground"];
pong.gfx.PongBackground.__super__ = pong.gfx.Rectangle;
for(var k in pong.gfx.Rectangle.prototype ) pong.gfx.PongBackground.prototype[k] = pong.gfx.Rectangle.prototype[k];
pong.gfx.PongBackground.prototype.__class__ = pong.gfx.PongBackground;
pong.Main = function() { }
pong.Main.__name__ = ["pong","Main"];
pong.Main.main = function() {
	pong.ui.Mouse.initialize();
	new pong.MainMenu();
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
pong.ui.Mouse.x = 0;
pong.ui.Mouse.y = 0;
haxe.Timer.arr = new Array();
pong.gfx.Stage.ELEMENT_ID = "pong";
$Main.init = pong.Main.main();
