package pong {
	import pong.MainMenu;
	import pong.ui.Mouse;
	public class Main {
		static public function main() : void {
			pong.ui.Mouse.initialize();
			new pong.MainMenu();
		}
		
	}
}
