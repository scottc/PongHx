/**
 * ...
 * @author scott
 */

package pong.geom;

class Vector 
{
	public var x:Float;
	public var y:Float;
	public function new(x_:Float, y_:Float) 
	{
		x = x_; 
		y = y_;
	}
	public inline function clone() {
		return new Vector(x,y);
	}
	public inline function set(x_:Float, y_:Float) {
		x = x_;
		y = y_;
	}
	public inline function plus(v:Vector) {
		return new Vector(x + v.x, y + v.y);
	}
	public inline function minus(v:Vector):Vector{
		return new Vector(x - v.x, y - v.y);
	}
	public inline function multiply(n:Float):Vector{
		return new Vector(x * n, y * n);
	}
	public inline function dotProduct(v:Vector) {
		return x * v.x + y * v.y;
	}
	public inline function crossProduct(v:Vector) {
		return x * v.y - y * v.x;
	}
	public inline function length() {
		return Math.sqrt(x * x + y * y);
	}
	public inline function normalize(l:Float = 1) {
		var d:Float = Math.sqrt(x * x + y * y);
		if (d == 0)
			return new Vector(0, 0);
		else
		return new Vector(x / d * l, y / d * l);
	}
}