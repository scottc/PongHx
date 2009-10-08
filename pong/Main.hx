package pong;

/**
 * ...
 * @author scott
 */

 import pong.gfx.Stage;

class Main 
{
	
	static function main() 
	{
		pong.ui.Mouse.initialize();//initalise mouse
		//new Game(300, 300);
		//new Game(300, 300);
		//new Game(300, 300);
		new Game(Stage.width, Stage.height);
	}
	
}