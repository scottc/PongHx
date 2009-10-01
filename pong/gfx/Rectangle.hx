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
		public var element:HtmlDom;
	
		public var x(getX,setX):Float;
		public var y(getY,setY):Float;
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
			element = Stage.ELEMENT.cloneNode(false);
			element.style.position = "absolute";
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
			element.style.top = Std.string(_y)+"px";
			element.style.left = Std.string(_x)+"px";
			element.style.background = "#"+StringTools.hex(_color,6);
			element.style.width = Std.string(_width)+"px";
			element.style.height = Std.string(_height)+"px";
		#elseif cpp
		
		#end
	}
	#if js
	public function getX():Float { return 0; }
	public function setX(val:Float){
		element.style.left = Std.string(val) + "px";
		return 0;
	}
	public function getY():Float { return 0; }
	public function setY(val:Float){
		element.style.top = Std.string(val) + "px";
		return 0;
	}
	#end
}