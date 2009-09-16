package pong.gfx;

class Label
#if flash
	extends flash.text.TextField
#end
{
	//private var _text:String;
	
	//public var text(getText,null):String;
	//public var x(getX,null):Int;
	//public var y(getY,null):Int;
	
	//constuctor
	public function new(){
		super();
	}
	
	//getters and setters
	private function getText():String{
		return "";
	}
	private function setText(v:String){
		//v = v;
	}
	
	private function getX():Int{
		return 0;
	}
	private function setX(v:Int){
		//v = v;
	}
	
	private function getY():Int{
		return 0;
	}
	private function setY(v:Int){
		//v = v;
	}
}