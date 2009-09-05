package pong;

import haxe.Timer;

class Game
{
	private var _graphicsTicker:Timer;
	private var _physicsTicker:Timer;
	
	public function new() 
	{
		_physicsTicker = new Timer(25);
		_physicsTicker.run = tick;
		
		_graphicsTicker = new Timer(50);
		_graphicsTicker.run = render;		
	}
	private function tick(){
		//trace("tick");
	}
	private function render(){
		//
	}
	
}