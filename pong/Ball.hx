/**
 * ...
 * @author scott
 */

package pong;

import flash.display.Sprite;
import pong.geom.Vector;

class Ball extends pong.geom.Rectangle
{
	public var display:Sprite;
	
	public var velocity:Vector;
	
	public var acceleration:Float;

	public function new(x_:Float, y_:Float, width_:Float, height_:Float) 
	{
		super(x_, y_, width_, height_);
		display = new pong.display.Rectangle(width_, height_, 0xffffff);
		display.x = x_;
		display.y = y_;
		
		velocity = new Vector(0, 0);
		acceleration = flash.Lib.current.width * 0.1;
	}
	public inline function render() {
		display.x = x;
		display.y = y;
	}
	public inline function move() {
		//velocity.multiply(1 + acceleration);
		//velocity.normalize(1 + acceleration);
		
		x += velocity.x;
		y += velocity.y;
	}
}