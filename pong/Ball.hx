﻿/**
 * ...
 * @author scott
 */

package pong;

class Ball extends pong.geom.Rectangle
{
	public var sprite:pong.gfx.Rectangle;

	public function new(x_:Int, y_:Int, width_:Int, height_:Int) 
	{
		super(x_, y_, width_, height_);
		sprite = new pong.gfx.Rectangle(x_, y_, width_, height_);
	}
	public function render() {
		sprite.x = x;
		sprite.y = y;
		
		//width = _position.width;
		//height = _position.height;
	}
}