package pong;

import haxe.Timer;
import pong.gfx.Stage;

class Game
{
	private var _graphicsTicker:Timer;
	private var _physicsTicker:Timer;
	
	private var _stage:Stage;
	
	public function new() 
	{
		_stage = new Stage();
	
		_physicsTicker = new Timer(25);
		_physicsTicker.run = tick;
		
		_graphicsTicker = new Timer(50);
		_graphicsTicker.run = render;		
	}
	private function tick(){
		//trace(Stage.height);
	}
	private function render(){
		//
	}
	
}