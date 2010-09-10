package pong.ui;

import flash.events.MouseEvent;
import nme.Lib;

class Mouse
{
	static var _BUTTON:Array<Bool> = new Array<Bool>();
	
	public static var X:Int = 0;
	public static var Y:Int = 0;
	
	public static function initialize() {
		Lib.current.addEventListener( MouseEvent.MOUSE_UP, onMouseUp );
		Lib.current.addEventListener( MouseEvent.MOUSE_DOWN, onMouseDown );
		Lib.current.addEventListener( MouseEvent.MOUSE_MOVE, onMouseMove );
	}
	
	private static inline function onMouseMove( e:MouseEvent )
	{
		X = Math.floor(e.stageX);
		Y = Math.floor(e.stageY);
	}
	private static inline function onMouseDown(e:MouseEvent)
	{
		trace(e);
		_BUTTON[0] = true;
	}
	private static inline function onMouseUp(e:MouseEvent )
	{
		_BUTTON[0] = false;
	}
	public static inline function isDown(button:Int) {
		if (_BUTTON[0] == true)
			return true;
		return false;
	}
}