﻿/**
 * ...
 * @author scott
 */

package pong;

import pong.geom.Vector;

class Paddle extends pong.geom.Rectangle
{
	public var sprite:pong.gfx.Rectangle;
	public var score:Int;
	public var ai:Bool;
	
	public var velocity:Vector;
	
	public function new(x_:Float, y_:Float, width_:Float, height_:Float) 
	{
		super(x_, y_, width_, height_);
		sprite = new pong.gfx.Rectangle(x_, y_, width_, height_);
		
		velocity = new Vector(0, 0);
		
		score = 0;
		ai = false;
	}
	public function render() {
		sprite.x = x;
		sprite.y = y;
	}
	public function move() {
		x += velocity.x;
		y += velocity.y;
	}
}