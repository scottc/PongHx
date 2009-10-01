package pong.gfx {
	import flash.Lib;
	import flash.display.Sprite;
	import flash.Boot;
	public class Stage {
		public function Stage() : void { if( !flash.Boot.skip_constructor ) {
			pong.gfx.Stage._SP = flash.Lib.current;
			this.drawBackground();
		}}
		
		public function add(object : *) : void {
			_SP.addChild(object);
		}
		
		protected function drawBackground() : void {
			var bg : flash.display.Sprite = new flash.display.Sprite();
			bg.graphics.beginFill(0);
			bg.graphics.drawRect(0,0,getWidth(),getHeight());
			bg.graphics.endFill();
			bg.graphics.lineStyle(0,16777215);
			bg.graphics.moveTo(0,10);
			bg.graphics.lineTo(getWidth(),10);
			bg.graphics.moveTo(0,getHeight() - 10);
			bg.graphics.lineTo(getWidth(),getHeight() - 10);
			bg.graphics.moveTo(getWidth() / 2,10);
			bg.graphics.lineTo(getWidth() / 2,getHeight() - 10);
			this.add(bg);
		}
		
		static public function get width() : int { return getWidth(); }
		protected var $width : int;
		static public function get height() : int { return getHeight(); }
		protected var $height : int;
		static protected var _SP : flash.display.Sprite;
		static protected var _instance : pong.gfx.Stage;
		static public function getInstance() : pong.gfx.Stage {
			if(pong.gfx.Stage._instance == null) pong.gfx.Stage._instance = new pong.gfx.Stage();
			return _instance;
		}
		
		static public function getWidth() : int {
			return flash.Lib.current.stage.stageWidth;
		}
		
		static public function getHeight() : int {
			return flash.Lib.current.stage.stageHeight;
		}
		
	}
}
