package pong.geom {
	import flash.Boot;
	public class Vector {
		public function Vector(x_ : Number = NaN,y_ : Number = NaN) : void { if( !flash.Boot.skip_constructor ) {
			this.x = x_;
			this.y = y_;
		}}
		
		public var x : Number;
		public var y : Number;
		public function clone() : pong.geom.Vector {
			return new pong.geom.Vector(this.x,this.y);
		}
		
		public function set(x_ : Number,y_ : Number) : void {
			this.x = x_;
			this.y = y_;
		}
		
		public function plus(v : pong.geom.Vector) : pong.geom.Vector {
			return new pong.geom.Vector(this.x + v.x,this.y + v.y);
		}
		
		public function minus(v : pong.geom.Vector) : pong.geom.Vector {
			return new pong.geom.Vector(this.x - v.x,this.y - v.y);
		}
		
		public function multiply(n : Number) : pong.geom.Vector {
			return new pong.geom.Vector(this.x * n,this.y * n);
		}
		
		public function dotProduct(v : pong.geom.Vector) : Number {
			return this.x * v.x + this.y * v.y;
		}
		
		public function crossProduct(v : pong.geom.Vector) : Number {
			return this.x * v.y - this.y * v.x;
		}
		
		public function length() : Number {
			return Math.sqrt(this.x * this.x + this.y * this.y);
		}
		
		public function normalize(l : Number = 1) : pong.geom.Vector {
			var d : Number = Math.sqrt(this.x * this.x + this.y * this.y);
			if(d == 0) return new pong.geom.Vector(0,0);
			else return new pong.geom.Vector(this.x / d * l,this.y / d * l);
		}
		
	}
}
