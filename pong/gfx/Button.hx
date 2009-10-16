package pong.gfx;

class Button extends Label
{
	public var function:Void;
	
	public function new(?text_:String = "",?function_:Void) 
	{
		super(text_);
		function = function_;
		//backgroundColor = 0xff0000;
		//borderThickness = 1;
		//borderColor = 0x00ff00;
	}
	
}