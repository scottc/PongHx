package pong {
	import pong.Game;
	import flash.display.StageAlign;
	import flash.Lib;
	import pong.ui.Mouse;
	import flash.display.StageScaleMode;
	public class Main {
		static public function main() : void {
			flash.Lib.current.stage.scaleMode = flash.display.StageScaleMode.NO_SCALE;
			flash.Lib.current.stage.align = flash.display.StageAlign.TOP_LEFT;
			pong.ui.Mouse.initialize();
			new pong.Game();
		}
		
	}
}
