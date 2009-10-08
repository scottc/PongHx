package pong {
	import pong.geom.Vector;
	import pong.gfx.Rectangle;
	import pong.geom.Rectangle;
	import flash.Boot;
	public class Ball extends pong.geom.Rectangle {
		public function Ball(x_ : Number = NaN,y_ : Number = NaN,width_ : Number = NaN,height_ : Number = NaN) : void { if( !flash.Boot.skip_constructor ) {
			super(x_,y_,width_,height_);
			this.sprite = new pong.gfx.Rectangle(x_,y_,width_,height_);
			this.velocity = new pong.geom.Vector(0,0);
			this.acceleration = 0;
		}}
		
		public var sprite : pong.gfx.Rectangle;
		public var velocity : pong.geom.Vector;
		public var acceleration : Number;
		public function render() : void {
			this.sprite.x = this.x;
			this.sprite.y = this.y;
		}
		
		public function move() : void {
			this.velocity.normalize(1 + this.acceleration);
			this.x += this.velocity.x;
			this.y += this.velocity.y;
		}
		
	}
}
