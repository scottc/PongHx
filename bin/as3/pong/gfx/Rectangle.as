package pong.gfx {
	import flash.display.Sprite;
	import flash.Boot;
	public class Rectangle extends flash.display.Sprite {
		public function Rectangle(x_ : Number = NaN,y_ : Number = NaN,width_ : Number = NaN,height_ : Number = NaN) : void { if( !flash.Boot.skip_constructor ) {
			this._color = 16777215;
			this._x = x_;
			this._y = y_;
			this._width = width_;
			this._height = height_;
			super();
			this.drawRect();
		}}
		
		protected var _color : int;
		protected var _x : Number;
		protected var _y : Number;
		protected var _width : Number;
		protected var _height : Number;
		protected function drawRect() : void {
			this.graphics.clear();
			this.graphics.beginFill(this._color);
			this.graphics.drawRect(0,0,this._width,this._height);
			this.graphics.endFill();
			this.x = this._x;
			this.y = this._y;
		}
		
	}
}
