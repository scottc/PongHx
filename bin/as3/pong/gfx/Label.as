package pong.gfx {
	import flash.text.TextField;
	import flash.Boot;
	public class Label extends flash.text.TextField {
		public function Label(text_ : String = "") : void { if( !flash.Boot.skip_constructor ) {
			super();
			this.textColor = 16777215;
			this.width = 40;
			this.selectable = false;
			this.text = text_;
		}}
		
		public function getText() : String {
			return "";
		}
		
		public function setText(v : String) : String {
			var foo : String = v;
			return "";
		}
		
		public function getX() : Number {
			return 0;
			return 0;
		}
		
		public function setX(v : Number) : int {
			return 0;
		}
		
		public function getY() : Number {
			return 0;
		}
		
		public function setY(v : Number) : int {
			return 0;
		}
		
	}
}
