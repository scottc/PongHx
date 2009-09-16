package pong.gfx;


class Stage
{
	public static var width(getWidth, null):Int;
	public static var height(getHeight, null):Int;
	
	#if flash
		private var _sp:flash.display.Sprite;
	#end
	
	public function new(){
	#if flash
		_sp = flash.Lib.current;
		drawBackground();
		//set background color
		//add(new pong.gfx.Rectangle(0, 0, width, height));
	#end
	}
	public function add(object:Dynamic) {
	#if flash
		//_sp = flash.Lib.current;
		_sp.addChild(object);
	#end
	}
	private function drawBackground() {
		#if flash
		var bg:flash.display.Sprite = new flash.display.Sprite();
		bg.graphics.beginFill(0x000000);
		bg.graphics.drawRect(0, 0, width, height);
		bg.graphics.endFill();
		bg.graphics.lineStyle(0, 0xffffff);
		bg.graphics.moveTo(0, 10);
		bg.graphics.lineTo(width, 10);
		bg.graphics.moveTo(0, height - 10);
		bg.graphics.lineTo(width, height - 10);
		bg.graphics.moveTo(width / 2, 10);
		bg.graphics.lineTo(width / 2, height - 10);
		add(bg);
		#end
	}
	
	private static function getWidth():Int{
		#if flash
			return flash.Lib.current.stage.stageWidth;
		#elseif js
			return js.Lib.window.document.body.clientWidth;
		#elseif cpp
			return -1;
		#end
	}
	private static function getHeight():Int{
		#if flash
			return flash.Lib.current.stage.stageHeight;
		#elseif js
			return js.Lib.window.document.body.clientHeight;
		#elseif cpp
			return -1;
		#end
	}
}