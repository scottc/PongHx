package pong;

import haxe.Timer;
import pong.gfx.Stage;
import pong.gfx.Label;
import pong.gfx.Rectangle;
import pong.gfx.PongBackground;

import pong.geom.Vector;

import pong.ui.Keyboard;
import pong.ui.Mouse;

class Game
{
	private var _stage:Stage;
	
	private var _ball:Ball;
	
	private var _leftPaddle:Paddle;
	private var _rightPaddle:Paddle;
	
	private var _leftScoreLabel:Label;
	private var _rightScoreLabel:Label;
	
	private var _backGround:PongBackground;
	
	private var _graphicsTicker:Timer;
	private var _physicsTicker:Timer;
	
	private var _frameRate:Float;
	private var _physicsRate:Float;
	public var frameRate(getFrameRate, setFrameRate):Float;//target frames per second
	public var physicsRate(getFrameRate, setPhysicsRate):Float;//target physics steps per second
	
	private var _x:Float; public var x(getX, setX):Float;
	private var _y:Float; public var y(getY, setY):Float;
	
	private var _width:Float; public var width(getWidth, setWidth):Float;
	private var _height:Float; public var height(getHeight, setHeight):Float;
	
	public function new(?width_:Float = 300, ?height_:Float = 300) 
	{	
		width = width_;
		height = height_;
		
		frameRate = 60;
		physicsRate = 60;
		
		setupStage();
		newRound();
		render();
	}
	private function setupStage():Void {
		_stage = Stage.getInstance();
		
		_backGround = new PongBackground(width, height);
		
		_stage.add(_backGround);
		
		_ball = new Ball(150, 50, width*0.02, width*0.02);
		
		_leftPaddle = new Paddle(width*0.05, 50, width*0.02, height*0.15);
		
		_rightPaddle = new Paddle(width*0.93, 50, width*0.02, height*0.15);
		_rightPaddle.ai = true;
		
		_stage.add(_ball.sprite);
		_stage.add(_leftPaddle.sprite);
		_stage.add(_rightPaddle.sprite);
		
		_leftScoreLabel = new Label();
		_leftScoreLabel.text = Std.string(_leftPaddle.score);
		_leftScoreLabel.y = 10;
		_leftScoreLabel.x = width * 0.5 - 20;
		
		_rightScoreLabel = new Label();
		_rightScoreLabel.text = Std.string(_rightPaddle.score);
		_rightScoreLabel.y = 10;
		_rightScoreLabel.x = width * 0.5 + 10;
		
		_stage.add(_leftScoreLabel);
		_stage.add(_rightScoreLabel);
	}
	private function newRound():Void {
		//reset Paddle locations
		_leftPaddle.y = height / 2 - _leftPaddle.height / 2;
		_rightPaddle.y = height / 2 - _rightPaddle.height / 2;
		
		//reset ball location
		_ball.y = height / 2 - _ball.height / 2;
		_ball.x = width / 2 - _ball.width / 2;
		
		//give ball new random direction
		_ball.velocity.x = width * Math.random() - width * 0.5;
		_ball.velocity.y = height * Math.random() - height * 0.5;
		
		//set the ball's speed
		_ball.velocity = _ball.velocity.normalize(width * 0.01);
	}
	private function runAI(p:Paddle) {
		//make AI chase ball...
		if (p.y + p.height/2 < _ball.y + _ball.height/2)
			p.velocity.y = height * 0.01;
		else if (p.y + p.height/2 > _ball.y + _ball.height/2)
			p.velocity.y = height * -0.01;
		else
			p.velocity.y = 0;
	}
	private function doCollisions() {
		//Paddles/walls
		//Stops Left Paddle when reaches Bottom/Top of screen
		if(_leftPaddle.y +_leftPaddle.height > height -10){
			_leftPaddle.y = height - _leftPaddle.height -10;
		}
		if (_leftPaddle.y < 10) {
			_leftPaddle.y = 10; 
		}
		
		//Stops Right Paddle when reaches Bottom/Top of screen
		if(_rightPaddle.y +_rightPaddle.height > height -10){
			_rightPaddle.y = height - _rightPaddle.height -10;
		}
		if (_rightPaddle.y < 10) {
			_rightPaddle.y = 10; 
		}
				
		//ball/walls
		//Makes ball rebound when ball hits Bottom/Top of Screen
		if (_ball.y + _ball.height > height -10) {
			_ball.y = height - _ball.height -10;
			_ball.velocity.y *= -1;
		}
			
		if (_ball.y < 10) {
			_ball.y = 10;
			_ball.velocity.y *= -1;
		}
		//Resets game and Adds 1 to Right/Left Paddle when ball reaches Left/Right side of Screen
		if (_ball.x < -_ball.width) {
			_rightScoreLabel.text = Std.string(++_rightPaddle.score);//update score and set text
			newRound();
		}
		
		if (_ball.x > width) {
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
		//get user input
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
		
		//move objects
		_leftPaddle.move();
		_rightPaddle.move();
		_ball.move();
		
		//do collisions
		doCollisions();
	}
	private function render():Void {
		//tell the game objects to render themselves
		_ball.render();
		_leftPaddle.render();
		_rightPaddle.render();
	}
	
	
	
	private function getX():Float { return _x; }
	private function getY():Float { return _y; }
	private function getWidth():Float { return _width; }
	private function getHeight():Float { return _height; }
	
	private function setX(v:Float) {
		_x = v;
		_backGround.x = v;
		return v;
	}
	private function setY(v:Float) {
		_y = v;
		_backGround.y = v;
		return v;
	}
	private function setWidth(v:Float) {
		_width = v;
		//_backGround.width = v;
		return v;
	}
	private function setHeight(v:Float) {
		_height = v;
		//_backGround.height = v;
		return v;
	}
	
	private function getFrameRate():Float { return _frameRate; }
	private function getPhysicsRate():Float { return _physicsRate; }
	
	private function setFrameRate(v:Float) {
		_physicsRate = v;
		if(_physicsTicker != null)_physicsTicker.stop();
		_physicsTicker = new Timer(Math.floor(1000 / _physicsRate));// 1 sec / framerate = ms needed, per frame.
		_physicsTicker.run = physicsStep;
		return v;
	}
	private function setPhysicsRate(v:Float) {
		_frameRate = v;
		if(_graphicsTicker != null)_graphicsTicker.stop();
		_graphicsTicker = new Timer(Math.floor(1000 / _frameRate));
		_graphicsTicker.run = render;
		return v;
	}
}