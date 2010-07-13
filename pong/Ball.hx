/**
 * ...
 * @author scott
 */

package pong;

import pong.geom.Vector;
import Xinf;

class Ball extends pong.geom.Rectangle
{
	public var display:Rectangle;
	
	public var velocity:Vector;
	
	public var acceleration:Float;

	public function new(x_:Float, y_:Float, width_:Float, height_:Float) 
	{
		super(x_, y_, width_, height_);
		display = new Rectangle( {
								x: x_,
								y: y_,
								width: width_,
								height: height_,
								fill: Paint.RGBColor(1,1,1)
			});
		
		velocity = new Vector(0, 0);
		acceleration = Root.width * 0.1;
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