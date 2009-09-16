package pong;

import haxe.Timer;
import pong.gfx.Stage;
import pong.gfx.Label;
import pong.gfx.Rectangle;

import pong.ui.Keyboard;

import flash.display.Sprite;

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
		
		_leftPlayer = new Player(50, 50, 20, 100);
		_rightPlayer = new Player(300, 50, 20, 100);
		
		_stage.add(_ball.sprite);
		_stage.add(_leftPlayer.sprite);
		_stage.add(_rightPlayer.sprite);
		
		_leftScoreLabel = new Label();
		_leftScoreLabel.y = 50;
		_leftScoreLabel.x = Stage.width * 0.5 - 100;
		
		_rightScoreLabel = new Label();
		_rightScoreLabel.y = 50;
		_rightScoreLabel.x = Stage.width * 0.5 + 10;
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
		//check players vs walls
		if(_leftPlayer.y +_leftPlayer.height > Stage.height){
			//cap the player
			_leftPlayer.y = Stage.height - _leftPlayer.height;
			}
		if (_leftPlayer.y < 0) {
			_leftPlayer.y = 0; 
		}
		
		if(_rightPlayer.y +_rightPlayer.height > Stage.height){
				_rightPlayer.y = Stage.height - _rightPlayer.height;
			}
		if (_rightPlayer.y < 0) {
			_rightPlayer.y = 0; 
		}
				
		//check ball vs wall
		if (_ball.y + _ball.height > Stage.height) {
			_ball.y = Stage.height - _ball.height;
			_ball.velocity.y = -1;
			}
			
		if (_ball.y < 0) {
			_ball.y = 0;
			_ball.velocity.y = 1;
		}
		
		if (_ball.x < 0 - _ball.width) {
			_rightPlayer.score += 1;
			newRound();
		}
		
		if (_ball.x > Stage.width) {
			_leftPlayer.score += 1;
			newRound();
		}
		
		//check ball vs players

	}
	private function physicsStep():Void{
		//IF human, get user input... ELSE run ai
		if (!_leftPlayer.ai){
			//
		}else if (true)
			runAI(_leftPlayer);
			
		if (!_rightPlayer.ai){
			//
		}else if(_ball.velocity.x > 0)
			runAI(_rightPlayer);
		
		
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
		
		//update the text frields..
		_leftScoreLabel.text = Std.string(_leftPlayer.score);
		_rightScoreLabel.text = Std.string(_rightPlayer.score);
	}
	
}