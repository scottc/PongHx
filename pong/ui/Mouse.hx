package pong.ui;

import Xinf;

class Mouse
{
	//public static var BUTTON:ArrayList<Bool>;
	
	public static var X:Int = 0;
	public static var Y:Int = 0;
	
	public static function initialize() {
		Root.addEventListener( MouseEvent.MOUSE_UP, onMouseUp );
		Root.addEventListener( MouseEvent.MOUSE_DOWN, onMouseDown );
		Root.addEventListener( MouseEvent.MOUSE_MOVE, onMouseMove );
	}
	
	static function onMouseMove( e:MouseEvent )
	{
		X = Math.floor(e.x);
		Y = Math.floor(e.y);
	}
	static function onMouseDown(e:MouseEvent)
	{
		//BUTTON[e.button] = true;
		trace("Mouse " + e.button + " is Down");
	}
	static function onMouseUp(e:MouseEvent )
	{
		//BUTTON[e.button] = false;
		trace("Mouse " + e.button + " is Up");
	}
}