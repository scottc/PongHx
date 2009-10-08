package pong {
	import pong.Game;
	import pong.ui.Mouse;
	public class Main {
		static public function main() : void {
			pong.ui.Mouse.initialize();
			new pong.Game();
		}
		
	}
}
