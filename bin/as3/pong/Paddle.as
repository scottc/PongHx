package pong {
	import pong.geom.Vector;
	import pong.gfx.Rectangle;
	import pong.geom.Rectangle;
	import flash.Boot;
	public class Paddle extends pong.geom.Rectangle {
		public function Paddle(x_ : Number = NaN,y_ : Number = NaN,width_ : Number = NaN,height_ : Number = NaN) : void { if( !flash.Boot.skip_constructor ) {
			super(x_,y_,width_,height_);
			this.sprite = new pong.gfx.Rectangle(x_,y_,width_,height_);
			this.velocity = new pong.geom.Vector(0,0);
			this.score = 0;
			this.ai = false;
		}}
		
		public var sprite : pong.gfx.Rectangle;
		public var score : int;
		public var ai : Boolean;
		public var velocity : pong.geom.Vector;
		public function render() : void {
			this.sprite.x = this.x;
			this.sprite.y = this.y;
		}
		
		public function move() : void {
			this.x += this.velocity.x;
			this.y += this.velocity.y;
		}
		
	}
}