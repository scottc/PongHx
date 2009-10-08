/**
 * ...
 * @author scott
 */

package pong;

import pong.geom.Vector;

class Ball extends pong.geom.Rectangle
{
	public var sprite:pong.gfx.Rectangle;
	
	public var velocity:Vector;
	
	public var acceleration:Float;

	public function new(x_:Float, y_:Float, width_:Float, height_:Float) 
	{
		super(x_, y_, width_, height_);
		sprite = new pong.gfx.Rectangle(x_, y_, width_, height_);
		
		velocity = new Vector(0, 0);
		acceleration = pong.gfx.Stage.width * 0.01;
	}
	public function render() {
		sprite.x = x;
		sprite.y = y;
	}
	public function move() {
		//velocity.multiply(1 + acceleration);
		velocity.normalize(1 + acceleration);
		
		x += velocity.x;
		y += velocity.y;
	}
}