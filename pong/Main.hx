package pong;

import Xinf;

class Main 
{
	
	static function main() 
	{
		pong.ui.Mouse.initialize();
		pong.ui.Keyboard.initialize();
		
		Root.main();
		
		new MainMenu();
	}
	
}