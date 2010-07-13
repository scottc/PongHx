package pong.ui;

import Xinf;

class Mouse
{
	static var _BUTTON:Array<Bool> = new Array<Bool>();
	
	public static var X:Int = 0;
	public static var Y:Int = 0;
	
	public static function initialize() {
		Root.addEventListener( MouseEvent.MOUSE_UP, onMouseUp );
		Root.addEventListener( MouseEvent.MOUSE_DOWN, onMouseDown );
		Root.addEventListener( MouseEvent.MOUSE_MOVE, onMouseMove );
	}
	
	private static inline function onMouseMove( e:MouseEvent )
	{
		X = Math.floor(e.x);
		Y = Math.floor(e.y);
	}
	private static inline function onMouseDown(e:MouseEvent)
	{
		_BUTTON[e.button] = true;
	}
	private static inline function onMouseUp(e:MouseEvent )
	{
		_BUTTON[e.button] = false;
	}
	public static inline function isDown(button:Int) {
		if (_BUTTON[button] == true)
			return true;
		return false;
	}
}