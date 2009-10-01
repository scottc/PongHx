package pong.gfx {
	import flash.text.TextField;
	import flash.Boot;
	public class Label extends flash.text.TextField {
		public function Label() : void { if( !flash.Boot.skip_constructor ) {
			super();
			this.textColor = 16777215;
			this.width = 40;
			this.selectable = false;
		}}
		
		public function getText() : String {
			return "";
		}
		
		public function setText(v : String) : void {
			var foo : String = v;
		}
		
		public function getX() : int {
			return 0;
		}
		
		public function setX(v : Number) : void {
			null;
		}
		
		public function getY() : void {
			null;
		}
		
		public function setY(v : Number) : void {
			null;
		}
		
	}
}
