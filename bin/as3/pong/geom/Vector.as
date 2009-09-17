package pong.geom {
	import flash.Boot;
	public class Vector {
		public function Vector(x_ : Number = NaN,y_ : Number = NaN) : void { if( !flash.Boot.skip_constructor ) {
			this.x = x_;
			this.y = y_;
		}}
		
		public var x : Number;
		public var y : Number;
	}
}
