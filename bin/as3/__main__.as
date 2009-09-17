package  {
	import flash.display.MovieClip;
	import pong.Main;
	import flash.Boot;
	public class __main__ extends flash.display.MovieClip {
		public function __main__() {
			new flash.Boot(this);
			pong.Main.main();
		}
	}
}
