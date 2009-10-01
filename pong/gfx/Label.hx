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
		public var element:HtmlDom;
	
		public var text(getText,setText):String;
		public var x(getX,setX):Float;
		public var y(getY,setY):Float;		
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
			element = Stage.ELEMENT.cloneNode(false);
			element.style.position = "absolute";
			element.style.background = "none";
			element.style.width = "40px";
			element.style.color = "#fff";
		#end
	}
	
	//getters and setters
	public function getText():String{
		#if js
			return element.innerHTML;
		#else
			return "";
		#end
	}
	public function setText(v:String){
		#if js
			element.innerHTML = v;
		#else
			var foo:String = v;
		#end
		return "";
	}
	
	public function getX():Float{
		#if js
			//return _div.style.left;
		#else
			return 0;
		#end
		return 0;
	}
	public function setX(v:Float) {
		#if js
			element.style.left = Std.string(v);
		#end
		return 0;
	}
	
	public function getY():Float {
		#if js
			//return _div.style.top;
		#end
		return 0;
	}
	public function setY(v:Float) {
		#if js
			element.style.top = Std.string(v);
		#end
		return 0;
	}
}