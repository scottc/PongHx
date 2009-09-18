/**
 * ...
 * @author scott
 */

package pong.gfx;

#if js
	import js.Dom;
#end

class Rectangle
#if flash
	extends flash.display.Sprite
#end
{
	#if flash
	#elseif js
		private var _div:HtmlDom;
	
		public var x:Float;
		public var y:Float;
	#else
		public var x:Float;
		public var y:Float;
	#end

	private var _color:Int;
	
	private var _x:Float;
	private var _y:Float;
	private var _width:Float;
	private var _height:Float;
	//constructor
	public function new(x_:Float,y_:Float,width_:Float,height_:Float) 
	{
		_color = 0xffffff;
		
		_x = x_;
		_y = y_;
		_width = width_;
		_height = height_;
		
		#if flash
			super();
			drawRect();
		#elseif js
			_div = _div.cloneNode(false);
			_div.style.position = "absolute";
			drawRect();
		#elseif cpp
			
		#end
	}
	private function drawRect() {
		#if flash
			graphics.clear();
			graphics.beginFill(_color);
			graphics.drawRect(0,0,_width,_height);
			graphics.endFill();
			x = _x;
			y = _y;
		#elseif js
			_div.style.top = Std.string(_y)+"px";
			_div.style.left = Std.string(_x)+"px";
			_div.style.background = "#"+StringTools.hex(_color,6);
			_div.style.width = Std.string(_width)+"px";
			_div.style.height = Std.string(_height)+"px";
		#elseif cpp
		
		#end
	}
}