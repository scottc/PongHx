package pong;

//import js.Lib;
//import gfx.Rectangle;

/**
 * ...
 * @author scott
 */

class Main 
{
	
	static function main() 
	{
		#if flash
			flash.Lib.current.stage.scaleMode = flash.display.StageScaleMode.NO_SCALE;
			flash.Lib.current.stage.align     = flash.display.StageAlign.TOP_LEFT;
		#end
		new Game();
	}
	
}