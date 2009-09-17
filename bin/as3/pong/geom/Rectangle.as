package pong.geom {
	import flash.Boot;
	public class Rectangle {
		public function Rectangle(x_ : Number = NaN,y_ : Number = NaN,width_ : Number = NaN,height_ : Number = NaN) : void { if( !flash.Boot.skip_constructor ) {
			this.x = x_;
			this.y = y_;
			this.width = width_;
			this.height = height_;
		}}
		
		public var width : Number;
		public var height : Number;
		public var x : Number;
		public var y : Number;
		public function isOverlapping(rect : pong.geom.Rectangle) : Boolean {
			if(this.x < rect.x + rect.width && this.x + this.width > rect.x && this.y < rect.y + rect.height && this.y + this.height > rect.y) return true;
			return false;
		}
		
	}
}
