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
	
	private var _displayObjects:Array<Dynamic>;
	
	#if flash
	private static var _SP:Sprite;
	#elseif js
		public static var ELEMENT:HtmlDom;
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
			flash.Lib.current.stage.scaleMode = flash.display.StageScaleMode.NO_SCALE;
			flash.Lib.current.stage.align     = flash.display.StageAlign.TOP_LEFT;
			_SP = flash.Lib.current;
		#elseif js
			ELEMENT = js.Lib.document.getElementById(_ID);
			if( ELEMENT == null )
				js.Lib.alert("Unknown element : " + _ID);
		#end
	}
	public function add(object:Dynamic) {
		//_displayObjects.push(object);
		#if flash
			_SP.addChild(object);
		#elseif js
			ELEMENT.appendChild(object.element);
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