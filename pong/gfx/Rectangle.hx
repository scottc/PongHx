/**
 * ...
 * @author scott
 */

package pong.gfx;

class Rectangle
#if flash
	extends flash.display.Sprite
#end
{
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
		#elseif cpp
		
		#end
	}
}