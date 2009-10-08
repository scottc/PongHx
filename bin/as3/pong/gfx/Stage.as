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
			this.drawBackground();
		}}
		
		protected var _displayObjects : Array;
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
		
		protected function resizeObjects() : void {
			{
				var _g : int = 0, _g1 : Array = this._displayObjects;
				while(_g < _g1.length) {
					var i : * = _g1[_g];
					++_g;
					this._displayObjects[i].width *= 1;
					this._displayObjects[i].height *= 1;
				}
			}
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
