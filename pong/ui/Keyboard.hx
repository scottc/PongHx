package pong.ui;

import Xinf;

class Keyboard 
{
	private static var _KEY:Hash<Bool> = new Hash<Bool>();
	
	public static function initialize() {
		Root.addEventListener( KeyboardEvent.KEY_DOWN, onKeyDown );
		Root.addEventListener( KeyboardEvent.KEY_UP, onKeyUp );
	}
	private static inline function onKeyDown( e:KeyboardEvent )
	{
		_KEY.set(e.key.toUpperCase() ,true);
	}
	private static inline function onKeyUp( e:KeyboardEvent )
	{
		_KEY.set(e.key.toUpperCase() ,false);
	}
	public static inline function isDown(key:String):Bool {
		if (_KEY.exists(key.toUpperCase()))
			return _KEY.get(key.toUpperCase());
			
		return false;
	}
}