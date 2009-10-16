package pong {
	import pong.Game;
	import flash.Boot;
	public class MainMenu {
		public function MainMenu() : void { if( !flash.Boot.skip_constructor ) {
			new pong.Game();
		}}
		
	}
}
