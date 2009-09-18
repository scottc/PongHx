package pong.gfx;

#if js
	import js.Dom;
#end

class Label
#if flash
	extends flash.text.TextField
#end
{
	#if flash
	#elseif js
		private var _div:HtmlDom;
	
		public var text/*(getText,setText)*/:String;
		public var x/*(getX,setX)*/:Float;
		public var y/*(getY,setY)*/:Float;		
	#else
		public var text:String;
		public var x:Float;
		public var y:Float;
	#end
	
	
	//constuctor
	public function new() {
		#if flash
			super();
			textColor = 0xffffff;
			width = 40;
			selectable = false;
		#elseif js
			_div = _div.cloneNode(false);
			_div.style.position = "absolute";
			_div.style.width = "40px";
			_div.style.color = "#fff";
		#end
	}
	
	//getters and setters
	public function getText() {
		#if js
			return _div.innerHTML;
		#else
			return "";
		#end
	}
	public function setText(v:String){
		#if js
			_div.innerHTML = v;
		#else
			var foo:String = v;
		#end
	}
	
	public function getX() {
		#if js
			return _div.style.left;
		#else
			return 0;
		#end
	}
	public function setX(v:Float) {
		#if js
			_div.style.left = Std.string(v);
		#end
	}
	
	public function getY() {
		#if js
			return _div.style.top;
		#end
	}
	public function setY(v:Float) {
		#if js
			_div.style.top = Std.string(v);
		#end
	}
}