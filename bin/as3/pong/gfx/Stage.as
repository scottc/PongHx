package pong.gfx {
	import flash.display.StageAlign;
	import flash.Lib;
	import flash.display.Sprite;
	import flash.display.StageScaleMode;
	import flash.Boot;
	public class Stage {
		public function Stage() : void { if( !flash.Boot.skip_constructor ) {
			flash.Lib.current.stage.scaleMode = flash.display.StageScaleMode.NO_SCALE;
			flash.Lib.current.stage.align = flash.display.StageAlign.TOP_LEFT;
			pong.gfx.Stage._SP = flash.Lib.current;
		}}
		
		protected var _displayObjects : Array;
		public function add(object : *) : void {
			_SP.addChild(object);
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
