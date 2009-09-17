package pong;

import haxe.Timer;
import pong.gfx.Stage;
import pong.gfx.Label;
import pong.gfx.Rectangle;

import pong.ui.Keyboard;

class Game
{
	private var _graphicsTicker:Timer;
	private var _physicsTicker:Timer;
	
	private var _stage:Stage;
	
	private var _ball:Ball;
	
	private var _leftPlayer:Player;
	private var _rightPlayer:Player;
	
	private var _leftScoreLabel:Label;
	private var _rightScoreLabel:Label;
	
	public function new() 
	{	
		_physicsTicker = new Timer(25);
		_physicsTicker.run = physicsStep;
		
		_graphicsTicker = new Timer(25);
		_graphicsTicker.run = render;		
		
		setupStage();
		newRound();
		_ball.y -= 100;
	}
	private function setupStage():Void{
		_stage = new Stage();
		
		_ball = new Ball(150, 50, 20, 20);
		
		_leftPlayer = new Player(30, 50, 20, 100);
		_rightPlayer = new Player(Stage.width-50, 50, 20, 100);
		
		_stage.add(_ball.sprite);
		_stage.add(_leftPlayer.sprite);
		_stage.add(_rightPlayer.sprite);
		
		_leftScoreLabel = new Label();
		_leftScoreLabel.text = "0";
		_leftScoreLabel.y = 10;
		_leftScoreLabel.x = Stage.width * 0.5 - 20;
		
		_rightScoreLabel = new Label();
		_rightScoreLabel.text = "0";
		_rightScoreLabel.y = 10;
		_rightScoreLabel.x = Stage.width * 0.5 + 10;
		
		_stage.add(_leftScoreLabel);
		_stage.add(_rightScoreLabel);
	}
	private function newRound():Void {
		//reset player locations
		_leftPlayer.y = Stage.height / 2 - _leftPlayer.height / 2;
		_rightPlayer.y = Stage.height / 2 - _rightPlayer.height / 2;
		
		//reset ball location
		_ball.y = Stage.height / 2 - _ball.height / 2;
		_ball.x = Stage.width / 2 - _ball.width / 2;
	}
	private function runAI(p:Player) {
		//make AI chase ball...
		if (p.y + p.height/2 < _ball.y + _ball.height/2)
			p.velocity.y = 1;
		else if (p.y + p.height/2 > _ball.y + _ball.height/2)
			p.velocity.y = -1;
		else
			p.velocity.y = 0;
	}
	private function doCollisions() {
		//players/walls
		//Stops Left player when reaches Bottom/Top of screen
		if(_leftPlayer.y +_leftPlayer.height > Stage.height -10){
			_leftPlayer.y = Stage.height - _leftPlayer.height -10;
		}
		if (_leftPlayer.y < 10) {
			_leftPlayer.y = 10; 
		}
		
		//Stops Right player when reaches Bottom/Top of screen
		if(_rightPlayer.y +_rightPlayer.height > Stage.height -10){
			_rightPlayer.y = Stage.height - _rightPlayer.height -10;
		}
		if (_rightPlayer.y < 10) {
			_rightPlayer.y = 10; 
		}
				
		//ball/walls
		//Makes ball rebound when ball hits Bottom/Top of Screen
		if (_ball.y + _ball.height > Stage.height -10) {
			_ball.y = Stage.height - _ball.height -10;
			_ball.velocity.y *= -1;
		}
			
		if (_ball.y < 10) {
			_ball.y = 10;
			_ball.velocity.y *= -1;
		}
		//Resets game and Adds 1 to Right/Left Player when ball reaches Left/Right side of Screen
		if (_ball.x < 0 - _ball.width) {
			_rightScoreLabel.text = Std.string(++_rightPlayer.score);//update score and set text
			newRound();
		}
		
		if (_ball.x > Stage.width) {
			_leftScoreLabel.text = Std.string(++_leftPlayer.score);
			newRound();
		}
		
		//check ball vs players
		if (_ball.isOverlapping(_leftPlayer)) {
			_ball.x = _leftPlayer.x + _leftPlayer.width; //cap the ball
			_ball.velocity.x *= -1; //reverse the ball's direction
		}
		if (_ball.isOverlapping(_rightPlayer)) {
			_ball.x = _rightPlayer.x - _ball.width;
			_ball.velocity.x *= -1;
		}
	}
	
	private function physicsStep():Void{
		//IF human, get user input... ELSE run ai
		if (!_leftPlayer.ai){
			//
		}else if (_ball.velocity.x < 0)
			runAI(_leftPlayer);
		else
			_leftPlayer.velocity.y = 0;
			
		if (!_rightPlayer.ai){
			//
		}else if(_ball.velocity.x > 0)
			runAI(_rightPlayer);
		else
			_rightPlayer.velocity.y = 0;
		
		_leftPlayer.move();
		_rightPlayer.move();
		_ball.move();
		
		doCollisions();
	}
	private function render():Void {
		//tell the game objects to render themselves
		_ball.render();
		_leftPlayer.render();
		_rightPlayer.render();
	}
	
}