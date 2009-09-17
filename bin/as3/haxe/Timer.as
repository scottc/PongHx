package haxe {
	import flash.Lib;
	import flash.utils.clearInterval;
	import flash.utils.setInterval;
	import flash.Boot;
	public class Timer {
		public function Timer(time_ms : int = 0) : void { if( !flash.Boot.skip_constructor ) {
			var me : haxe.Timer = this;
			this.id = flash.utils.setInterval(function() : void {
				me.run();
			},time_ms);
		}}
		
		protected var id : *;
		public function stop() : void {
			if(this.id == null) return;
			flash.utils.clearInterval(this.id);
			this.id = null;
		}
		
		public var run : Function = function() : void {
			null;
		}
		static public function delay(f : Function,time_ms : int) : haxe.Timer {
			var t : haxe.Timer = new haxe.Timer(time_ms);
			t.run = function() : void {
				t.stop();
				f();
			}
			return t;
		}
		
		static public function stamp() : Number {
			return flash.Lib._getTimer() / 1000;
		}
		
	}
}
