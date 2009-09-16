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

	public function new(x_:Int, y_:Int, width_:Int, height_:Int) 
	{
		super(x_, y_, width_, height_);
		sprite = new pong.gfx.Rectangle(x_, y_, width_, height_);
		
		velocity = new Vector(1, 1);
	}
	public function render() {
		sprite.x = x;
		sprite.y = y;
		
		//width = _position.width;
		//height = _position.height;
	}
	public function move() {
		x += velocity.x;
		y += velocity.y;
	}
}