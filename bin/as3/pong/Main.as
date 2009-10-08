package pong {
	import pong.Game;
	import pong.gfx.Stage;
	import pong.ui.Mouse;
	public class Main {
		static public function main() : void {
			pong.ui.Mouse.initialize();
			new pong.Game(pong.gfx.Stage.getWidth(),pong.gfx.Stage.getHeight());
		}
		
	}
}
