package pong.ui;

import Xinf;

class Keyboard 
{
	public static var KEY:Array<Bool> = new Array<Bool>();
	
	public static var UP_ARROW:Int = 38;
	public static var DOWN_ARROW:Int = 40;
	
	public static function initialize() {
		Root.addEventListener( KeyboardEvent.KEY_DOWN, onKeyDown );
		Root.addEventListener( KeyboardEvent.KEY_UP, onKeyUp );
	}
	static function onKeyDown( e:KeyboardEvent )
	{
		KEY[e.code] = true;
		trace("Keyboard " + e.code + " is Down");
	}
	static function onKeyUp( e:KeyboardEvent )
	{
		KEY[e.code] = false;
		trace("Keyboard " + e.code + " is Up");
	}
}