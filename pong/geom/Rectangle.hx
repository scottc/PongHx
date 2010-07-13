package pong.geom;

class Rectangle
{
	public var width:Float;
	public var height:Float;
	public var x:Float;
	public var y:Float;
	
	//constructor
	public function new(x_:Float,y_:Float,width_:Float,height_:Float) 
	{
		x = x_;
		y = y_;
		width = width_;
		height = height_;
	}
	/**
	 * Checks if the rectangle is overlapping another.
	 * @param	rect check agaist this rectangle
	 * @return	Collision status
	 */
	public function isOverlapping(rect:Rectangle):Bool {
		if (
			x < rect.x +rect.width //left
			&& x + width > rect.x //right
			&& y < rect.y +rect.height //top
			&& y + height > rect.y //bottom
			)
			return true;
		return false;
	}
}