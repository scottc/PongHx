package pong.gfx;


#if js
	import js.Dom;
#elseif flash
	import flash.display.Sprite;
#end

class Stage
{
	public static var width(getWidth, null):Int;
	public static var height(getHeight, null):Int;
	
	#if flash
		private var _sp:Sprite;
	#elseif js
		private var _div:HtmlDom;
		private static var _ID:String = "pong";
	#end
	
	
	private static var _instance:Stage;
	
	/**
	 * Singleton pattern
	 * @return The Instance of this class.
	 */
	public static function getInstance():Stage {
	if (_instance == null) _instance = new Stage();
		return _instance;
	}
	
	public function new(){
		#if flash
			_sp = flash.Lib.current;
		#elseif js
			_div = js.Lib.document.getElementById(_ID);
			if( _div == null )
				js.Lib.alert("Unknown element : "+_ID);
		#end
		drawBackground();
	}
	public function add(object:Dynamic) {
		#if flash
			_sp.addChild(object);
		#elseif js
			_div.appendChild(object);
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
		#elseif js
			_div.style.background = "#000000";
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