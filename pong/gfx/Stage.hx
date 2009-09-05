package pong.gfx;


class Stage
#if flash
	extends flash.display.Sprite
#end
{
	public static var width(getWidth, null):Int;
	public static var height(getHeight, null):Int;
	
	public function new(){
	#if flash
		super();
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