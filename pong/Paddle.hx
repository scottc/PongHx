/**
 * ...
 * @author scott
 */

package pong;

import pong.geom.Vector;
import Xinf;

class Paddle extends pong.geom.Rectangle
{
	public var display:Rectangle;
	public var score:Int;
	public var ai:Bool;
	
	public var velocity:Vector;
	
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
		
		score = 0;
		ai = false;
	}
	public function render() {
		display.x = x;
		display.y = y;
	}
	public function move() {
		x += velocity.x;
		y += velocity.y;
	}
}