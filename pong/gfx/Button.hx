package pong.gfx;

class Button extends Label
{
	public var object:Void;
	public var function:String;
	public var args:Array<Dynamic>;
	
	public function new(?text_:String = "", object_:Void, function_:String, ?args_:Array<Dynamic>) 
	{
		super(text_);
		object = object_;
		function = function_;
		args = args_;
		
		//backgroundColor = 0xff0000;
		//borderThickness = 1;
		//borderColor = 0x00ff00;
	}
	private function execFunction() {
		Reflect.callMethod(object, function, args);
	}
	
}