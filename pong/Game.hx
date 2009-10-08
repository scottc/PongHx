package pong;

import haxe.Timer;
import pong.gfx.Stage;
import pong.gfx.Label;
import pong.gfx.Rectangle;

import pong.geom.Vector;

import pong.ui.Keyboard;
import pong.ui.Mouse;

class Game
{
	private var _graphicsTicker:Timer;
	private var _physicsTicker:Timer;
	
	private var _stage:Stage;
	
	private var _ball:Ball;
	
	private var _leftPaddle:Paddle;
	private var _rightPaddle:Paddle;
	
	private var _leftScoreLabel:Label;
	private var _rightScoreLabel:Label;
	
	private var _id:String;
	
	public function new() 
	{	
		_physicsTicker = new Timer(25);
		_physicsTicker.run = physicsStep;
		
		_graphicsTicker = new Timer(25);
		_graphicsTicker.run = render;		
		
		setupStage();
		newRound();
	}
	private function setupStage():Void {
		_stage = Stage.getInstance();
		
		_ball = new Ball(150, 50, Stage.width*0.02, Stage.width*0.02);
		
		_leftPaddle = new Paddle(Stage.width*0.05, 50, Stage.width*0.02, Stage.height*0.15);
		
		_rightPaddle = new Paddle(Stage.width*0.95, 50, Stage.width*0.02, Stage.height*0.15);
		_rightPaddle.ai = true;
		
		_stage.add(_ball.sprite);
		_stage.add(_leftPaddle.sprite);
		_stage.add(_rightPaddle.sprite);
		
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
		_ball.acceleration = 0.0001;
		
		_ball.velocity.x = Stage.width * Math.random() - Stage.width * 0.5;
		_ball.velocity.y = Stage.height * Math.random() - Stage.height * 0.5;
		
		_ball.velocity = _ball.velocity.normalize(Stage.width * 0.01);
		
		//reset Paddle locations
		_leftPaddle.y = Stage.height / 2 - _leftPaddle.height / 2;
		_rightPaddle.y = Stage.height / 2 - _rightPaddle.height / 2;
		
		//reset ball location
		_ball.y = Stage.height / 2 - _ball.height / 2;
		_ball.x = Stage.width / 2 - _ball.width / 2;
	}
	private function runAI(p:Paddle) {
		//make AI chase ball...
		if (p.y + p.height/2 < _ball.y + _ball.height/2)
			p.velocity.y = Stage.height * 0.01;
		else if (p.y + p.height/2 > _ball.y + _ball.height/2)
			p.velocity.y = Stage.height * -0.01;
		else
			p.velocity.y = 0;
	}
	private function doCollisions() {
		//Paddles/walls
		//Stops Left Paddle when reaches Bottom/Top of screen
		if(_leftPaddle.y +_leftPaddle.height > Stage.height -10){
			_leftPaddle.y = Stage.height - _leftPaddle.height -10;
		}
		if (_leftPaddle.y < 10) {
			_leftPaddle.y = 10; 
		}
		
		//Stops Right Paddle when reaches Bottom/Top of screen
		if(_rightPaddle.y +_rightPaddle.height > Stage.height -10){
			_rightPaddle.y = Stage.height - _rightPaddle.height -10;
		}
		if (_rightPaddle.y < 10) {
			_rightPaddle.y = 10; 
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
		//Resets game and Adds 1 to Right/Left Paddle when ball reaches Left/Right side of Screen
		if (_ball.x < 0 - _ball.width) {
			_rightScoreLabel.text = Std.string(++_rightPaddle.score);//update score and set text
			newRound();
		}
		
		if (_ball.x > Stage.width) {
			_leftScoreLabel.text = Std.string(++_leftPaddle.score);
			newRound();
		}
		
		//check ball vs Paddles
		ballPaddleCollision(_leftPaddle);
		ballPaddleCollision(_rightPaddle);
	}
	private function ballPaddleCollision(p:Paddle) {
		//if collision
		if (_ball.isOverlapping(p)) {
			
			//find new direction
			var newDirection:Vector =
			new Vector(
					(_ball.x + _ball.width * 0.5)-(p.x + p.width * 0.5),
					(_ball.y + _ball.height * 0.5)-(p.y + p.height * 0.5)
			);
			
			//make sure the new vector is the same length aka speed.
			_ball.velocity = newDirection.normalize(_ball.velocity.length());
		}
	}
	private function physicsStep():Void{
		//IF human, get user input... ELSE run ai
		if (!_leftPaddle.ai) {
			_leftPaddle.y = Mouse.y - _leftPaddle.height / 2;
		}else if (_ball.velocity.x < 0)
			runAI(_leftPaddle);
		else
			_leftPaddle.velocity.y = 0;
			
		if (!_rightPaddle.ai){
			_rightPaddle.y = Mouse.y - _rightPaddle.height / 2;
		}else if(_ball.velocity.x > 0)
			runAI(_rightPaddle);
		else
			_rightPaddle.velocity.y = 0;
		
		_leftPaddle.move();
		_rightPaddle.move();
		_ball.move();
		
		doCollisions();
	}
	private function render():Void {
		//tell the game objects to render themselves
		_ball.render();
		_leftPaddle.render();
		_rightPaddle.render();
	}
	
}