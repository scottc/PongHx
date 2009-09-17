package pong {
	import pong.geom.Rectangle;
	import pong.gfx.Rectangle;
	import flash.Boot;
	public class GameObject extends pong.gfx.Rectangle {
		public function GameObject(x_ : int = 0,y_ : int = 0,width_ : int = 0,height_ : int = 0) : void { if( !flash.Boot.skip_constructor ) {
			super(x_,y_,width_,height_);
			this._position = new pong.geom.Rectangle(x_,y_,width_,height_);
		}}
		
		protected var _position : pong.geom.Rectangle;
		public function render() : void {
			this._position.x += 1;
			this.x = this._position.x;
			this.y = this._position.y;
		}
		
	}
}
