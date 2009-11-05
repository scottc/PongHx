package pong.ui;

import Xinf;

class Keyboard 
{
	public static function initialize() {
		Root.addEventListener( KeyboardEvent.KEY_DOWN, onKeyDown );
		Root.addEventListener( KeyboardEvent.KEY_UP, onKeyUp );
	}
	static function onKeyDown( e:KeyboardEvent )
	{
		//KEY[e.key] = true;
		trace("Keyboard " + /*e.key +*/ " is Down");
	}
	static function onKeyUp( e:KeyboardEvent )
	{
		//KEY[e.key] = false;
		trace("Keyboard " + /*e.key +*/ " is Up");
	}
}