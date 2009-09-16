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