package pong.ui;

import flash.events.KeyboardEvent;
import nme.Lib;

class Keyboard 
{
	private static var _KEY:Hash<Bool> = new Hash<Bool>();
	
	public static function initialize() {
		Lib.current.addEventListener( KeyboardEvent.KEY_DOWN, onKeyDown );
		Lib.current.addEventListener( KeyboardEvent.KEY_UP, onKeyUp );
	}
	private static inline function onKeyDown( e:KeyboardEvent )
	{
		trace(e);
		_KEY.set(String.fromCharCode(e.charCode).toUpperCase() ,true);
	}
	private static inline function onKeyUp( e:KeyboardEvent )
	{
		_KEY.set(String.fromCharCode(e.charCode).toUpperCase() ,false);
	}
	public static inline function isDown(key:String):Bool {
		if (_KEY.exists(key.toUpperCase()))
			return _KEY.get(key.toUpperCase());
			
		return false;
	}
}