package pong;

import flash.events.Event;
import nme.Lib;

class MainMenu 
{
	//constructor
	public function new() 
	{	
		pong.ui.Mouse.initialize();
		pong.ui.Keyboard.initialize();
		
		var game = new Game(550, 400);//Lib.current.width, Lib.current.height);
		
		Lib.current.addChild(game);
		
		Lib.current.addEventListener( Event.RESIZE,
								function(e:Event) {
									game.width = Lib.current.width;
									game.height = Lib.current.height;
									trace(Lib.current.height);
								} );
									
		#if !flash
		Lib.current.addChild(new nme.display.FPS());
		#end
	}
}