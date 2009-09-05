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
	private var _width:Int;
	private var _height:Int;
	private var _x:Int;
	private var _y:Int;
	private var _color:UInt;
	
	//constructor
	public function new() 
	{
		#if js
		
		#elseif flash
			//flash.display.Sprite
		#elseif cpp
		
		#end
	}
	
	private function render() {
		
	}
	
	//getters and setters
	//width
	public var width(getWidth, setWidth):Int;
	private function getWidth():Int {
		return _width;
	}
	private function setWidth(v:Int):Int {
		_width = v;
		return v;
	}
	//height
	public var height(getHeight, setHeight):Int;
		private function getHeight():Int {
		return _height;
	}
	private function setHeight(v:Int):Int {
		_height = v;
		return v;
	}
	//color
	public var color(getColor, setColor):UInt;
		private function getColor():UInt {
		return _color;
	}
	private function setColor(v:UInt):UInt {
		_color = v;
		return v;
	}
	//x
	public var x(getX, setX):Int;
		private function getX():Int {
		return _x;
	}
	private function setX(v:Int):Int {
		_x = v;
		return v;
	}
	//y
	public var y(getY, setY):Int;
		private function getY():Int {
		return _y;
	}
	private function setY(v:Int):Int {
		_y = v;
		return v;
	}
	
}