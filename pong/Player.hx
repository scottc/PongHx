/**
 * ...
 * @author scott
 */

package pong;

import pong.geom.Vector;

class Player extends pong.geom.Rectangle
{
	public var sprite:pong.gfx.Rectangle;
	public var score:Int;
	public var ai:Bool;
	
	public var velocity:Vector;
	
	public function new(x_:Int, y_:Int, width_:Int, height_:Int) 
	{
		super(x_, y_, width_, height_);
		sprite = new pong.gfx.Rectangle(x_, y_, width_, height_);
		
		velocity = new Vector(0,0);
		
		score = 0;
		ai = false;
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