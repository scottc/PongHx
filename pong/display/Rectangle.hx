/**
 * ...
 * @author Scott Campbell
 */

package pong.display;

class Rectangle extends flash.display.Sprite
{

	public function new(width_:Float, height_:Float, color_:Int) 
	{
		super();
		graphics.beginFill(color_);
		graphics.drawRect(0, 0, width_, height_);
		trace(color_);
	}
	
}