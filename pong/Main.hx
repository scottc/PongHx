package pong;

import Xinf;

class Main 
{
	
	static function main() 
	{
		pong.ui.Stage.initialize();
		pong.ui.Mouse.initialize();
		pong.ui.Keyboard.initialize();
		
		new MainMenu();
		
		Root.main();
	}
	
}