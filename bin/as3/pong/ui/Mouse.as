package pong.ui {
	import flash.Lib;
	import flash.events.MouseEvent;
	public class Mouse {
		static public var x : int = 0;
		static public var y : int = 0;
		static public function initialize() : void {
			flash.Lib.current.addEventListener(flash.events.MouseEvent.MOUSE_MOVE,pong.ui.Mouse.mouseMove);
		}
		
		static protected function mouseMove(e : * = null) : void {
			pong.ui.Mouse.x = e.stageX;
			pong.ui.Mouse.y = e.stageY;
		}
		
		static protected function mousePressed(e : * = null) : void {
			null;
		}
		
	}
}
