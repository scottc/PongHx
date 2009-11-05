package pong;

import Xinf;

class Main 
{
	
	static function main() 
	{
		Root.main();
		
		pong.ui.Mouse.initialize();
		pong.ui.Keyboard.initialize();
		
		new MainMenu();
		
		
	}
	
}