package pong.gfx {
	import pong.gfx.Rectangle;
	import flash.Boot;
	public class PongBackground extends pong.gfx.Rectangle {
		public function PongBackground(width_ : Number = NaN,height_ : Number = NaN) : void { if( !flash.Boot.skip_constructor ) {
			super(0,0,width_,height_);
			this.setColor(0);
		}}
		
	}
}
