package pong {
	import pong.geom.Vector;
	import pong.gfx.Rectangle;
	import pong.geom.Rectangle;
	import flash.Boot;
	public class Ball extends pong.geom.Rectangle {
		public function Ball(x_ : int = 0,y_ : int = 0,width_ : int = 0,height_ : int = 0) : void { if( !flash.Boot.skip_constructor ) {
			super(x_,y_,width_,height_);
			this.sprite = new pong.gfx.Rectangle(x_,y_,width_,height_);
			this.velocity = new pong.geom.Vector(1,1);
		}}
		
		public var sprite : pong.gfx.Rectangle;
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
