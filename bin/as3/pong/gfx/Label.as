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
		
		protected function getText() : String {
			return "";
		}
		
		protected function setText(v : String) : void {
			null;
		}
		
		protected function getX() : int {
			return 0;
		}
		
		protected function setX(v : int) : void {
			null;
		}
		
		protected function getY() : int {
			return 0;
		}
		
		protected function setY(v : int) : void {
			null;
		}
		
	}
}
