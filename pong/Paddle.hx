/**
 * ...
 * @author scott
 */

package pong;

import flash.display.Sprite;
import pong.geom.Vector;

class Paddle extends pong.geom.Rectangle
{
	public static inline var HUMAN:Int = 0;
	public static inline var EASY_AI:Int = 1;
	public static inline var MEDIUM_AI:Int = 2;
	public static inline var HARD_AI:Int = 3;
	
	public var display:Sprite;
	public var score:Int;
	public var ai:Int;
	
	public var velocity:Vector;
	
	public function new(x_:Float, y_:Float, width_:Float, height_:Float) 
	{
		super(x_, y_, width_, height_);
		display = new pong.display.Rectangle(width_,height_,0xffffff);
		display.x = x_;
		display.y = y_;
		
		velocity = new Vector(0, 0);
		
		score = 0;
		ai = HUMAN;
	}
	public inline function moveUp() {
		//velocity.y -= Root.height*.003;
		velocity.y -= flash.Lib.current.height*.01;
	}
	public inline function moveDown() {
		//velocity.y += Root.height*.003;
		velocity.y += flash.Lib.current.height*.01;
	}
	public inline function followPoint(y_:Float) {
		//velocity.y = y_ - y - height / 2;
		if (y_+flash.Lib.current.height*.01 < y + height / 2)
			moveUp();
		else if(y_-flash.Lib.current.height*.01 > y + height / 2)
			moveDown();
	}
	private inline function decay() {
		velocity.y *= .9;
	}
	public inline function render() {
		//display.x = x;
		display.y = y;
	}
	public inline function move() {
		//decay();
		
		//x = velocity.x;
		y = velocity.y;
	}
}