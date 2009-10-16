package pong.gfx {
	import flash.display.Sprite;
	import flash.Boot;
	import pong.gfx.IDisplayObject;
	public class Rectangle extends flash.display.Sprite implements pong.gfx.IDisplayObject{
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
		public function get color() : int { return getColor(); }
		public function set color( __v : int ) : void { setColor(__v); }
		protected var $color : int;
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
		
		public function getX() : Number {
			return this._x;
		}
		
		public function getY() : Number {
			return this._y;
		}
		
		public function getColor() : int {
			return this._color;
		}
		
		public function getWidth() : Number {
			return this._width;
		}
		
		public function getHeight() : Number {
			return this._height;
		}
		
		public function setWidth(v : Number) : Number {
			this._width = v;
			return v;
		}
		
		public function setHeight(v : Number) : Number {
			this._height = v;
			return v;
		}
		
		public function setColor(v : int) : int {
			this._color = v;
			this.graphics.clear();
			this.graphics.beginFill(this._color);
			this.graphics.drawRect(0,0,this._width,this._height);
			this.graphics.endFill();
			return v;
		}
		
		public function setX(v : Number) : int {
			return 0;
		}
		
		public function setY(v : Number) : int {
			return 0;
		}
		
	}
}
