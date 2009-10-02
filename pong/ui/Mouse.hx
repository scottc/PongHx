/**
 * ...
 * @author scott
 */

package pong.ui;

#if flash
	import flash.display.Sprite;
	import flash.events.MouseEvent;
#end


class Mouse
{
	public static var x:Int = 0;
	public static var y:Int = 0;
	
	private static var _instance:Mouse;
	
	/**
	 * Singleton pattern
	 * @return The Instance of this class.
	 */
	public static function getInstance():Mouse {
	if (_instance == null) _instance = new Mouse();
		return _instance;
	}
	
	public function new() 
	{
		#if js
			untyped js.Lib.document.onmousemove = mouseMove;
			js.Lib.document.onmousedown = mousePressed;
		#elseif flash
			flash.Lib.current.addEventListener(MouseEvent.MOUSE_MOVE, mouseMove);
		#end
	}
	
	static function mouseMove( ?e )
	{
		#if js
		x = if ( js.Lib.isIE ) untyped event.x; else e.clientX;
		y = if ( js.Lib.isIE ) untyped event.y; else e.clientY;
		#elseif flash
		x = e.stageX;
		y = e.stageY;
		#end
	}
	static function mousePressed(?e)
	{

	}
}