package pong.gfx;

class Label
#if flash
	extends flash.text.TextField
#end
{
	#if flash
	#else
	public var text:String;
	public var x:Float;
	public var y:Float;
	#end
	
	
	//constuctor
	public function new() {
		#if flash
			super();
			textColor = 0xffffff;
			width = 40;
			selectable = false;
		#end
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