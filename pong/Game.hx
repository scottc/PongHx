package pong;

import haxe.Timer;

import Xinf;

import pong.geom.Vector;

import pong.ui.Keyboard;
import pong.ui.Mouse;

class Game extends Group
{
	//private var _stage:Stage;
	
	private var _ball:Ball;
	
	private var _leftPaddle:Paddle;
	private var _rightPaddle:Paddle;
	
	private var _leftScoreLabel:Text;
	private var _rightScoreLabel:Text;
	
	private var _backGround:Rectangle;
	
	private var _graphicsTicker:Timer;
	private var _physicsTicker:Timer;
	
	private var _frameRate:Float;
	private var _physicsRate:Float;
	//public var frameRate(getFrameRate, setFrameRate):Float;//target frames per second
	public var physicsRate(getPhysicsRate, setPhysicsRate):Float;//target physics steps per second
	
	private var _x:Float; public var x(getX, setX):Float;
	private var _y:Float; public var y(getY, setY):Float;
	
	private var _width:Float; public var width(getWidth, setWidth):Float;
	private var _height:Float; public var height(getHeight, setHeight):Float;
	
	private var _pause:Bool; public var pause(getPause, setPause):Bool;
	
	public function new(?width_:Float = 300, ?height_:Float = 300) 
	{	
		super();
		
		_pause = false;
		
		_x = 0;
		_y = 0;
		
		_width = width_;
		_height = height_;
		
		//frameRate = 60;
		Root.addEventListener( FrameEvent.ENTER_FRAME, render);
		physicsRate = 60;
		
		setupStage();
		newRound();
		render();
	}
	private function setupStage():Void {
		//background
		_backGround = new Rectangle( {
							width: _width,
							height: _height,
							fill: Paint.RGBColor(0.1,0.1,0.1)
						});
		appendChild(_backGround);
		
		_ball = new Ball(150, 50, _width*0.02, _width*0.02);
		
		_leftPaddle = new Paddle(_width*0.05, 50, _width*0.02, _height*0.15);
		
		_rightPaddle = new Paddle(_width*0.93, 50, _width*0.02, _height*0.15);
		_rightPaddle.ai = Paddle.EASY_AI;
		
		appendChild(_ball.display);
		appendChild(_leftPaddle.display);
		appendChild(_rightPaddle.display);
		
		_leftScoreLabel = new Text({fill:"white"});
		_leftScoreLabel.text = Std.string(_leftPaddle.score);
		_leftScoreLabel.y = 10 + _y;
		_leftScoreLabel.x = _width * 0.5 - 20 + _x;
		appendChild(_leftScoreLabel);
		
		_rightScoreLabel = new Text({fill:"white"});
		_rightScoreLabel.text = Std.string(_rightPaddle.score);
		_rightScoreLabel.y = 10 + _y;
		_rightScoreLabel.x = _width * 0.5 + 10 + _x;
		appendChild(_rightScoreLabel);
	}
	private function newRound():Void {
		//reset Paddle locations
		_leftPaddle.y = _height / 2 - _leftPaddle.height / 2;
		_rightPaddle.y = _height / 2 - _rightPaddle.height / 2;
		
		//reset ball location
		_ball.y = _height / 2 - _ball.height / 2;
		_ball.x = _width / 2 - _ball.width / 2;
		
		//give ball new random direction
		_ball.velocity.x = _width * Math.random() - _width * 0.5;
		_ball.velocity.y = _height * Math.random() - _height * 0.5;
		
		//set the ball's speed
		_ball.velocity = _ball.velocity.normalize(_width * 0.01);
	}
	private inline function runAI(p:Paddle) {
		//make AI chase ball...
		p.followPoint(_ball.y + Math.random()*100-50);
	}
	private function doCollisions() {
		//Paddles/walls
		//Stops Left Paddle when reaches Bottom/Top of screen
		if(_leftPaddle.y +_leftPaddle.height > _height -10){
			_leftPaddle.y = _height - _leftPaddle.height -10;
		}
		if (_leftPaddle.y < 10) {
			_leftPaddle.y = 10; 
		}
		
		//Stops Right Paddle when reaches Bottom/Top of screen
		if(_rightPaddle.y +_rightPaddle.height > _height -10){
			_rightPaddle.y = _height - _rightPaddle.height -10;
		}
		if (_rightPaddle.y < 10) {
			_rightPaddle.y = 10; 
		}
				
		//ball/walls
		//Makes ball rebound when ball hits Bottom/Top of Screen
		if (_ball.y + _ball.height > _height -10) {
			_ball.y = _height - _ball.height -10;
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
		
		if (_ball.x > _width) {
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
	private function physicsStep():Void {
		
		switch(_leftPaddle.ai) {
			case Paddle.HUMAN:
				_leftPaddle.followPoint(Mouse.Y);
				/*
				if (Keyboard.isDown("UP"))
					_leftPaddle.moveUp();
				else if (Keyboard.isDown("DOWN"))
					_leftPaddle.moveDown();
					*/
				
			case Paddle.EASY_AI:
				runAI(_leftPaddle);
			case Paddle.MEDIUM_AI:
				runAI(_leftPaddle);
			case Paddle.HARD_AI:
				runAI(_leftPaddle);
			default:
				runAI(_leftPaddle);
		}
		
		switch(_rightPaddle.ai) {
			case Paddle.HUMAN:
				_rightPaddle.followPoint(Mouse.Y);
			case Paddle.EASY_AI:
				runAI(_rightPaddle);
			case Paddle.MEDIUM_AI:
				runAI(_rightPaddle);
			case Paddle.HARD_AI:
				runAI(_rightPaddle);
			default:
				runAI(_rightPaddle);
		}
		
		
		//move objects
		_leftPaddle.move();
		_rightPaddle.move();
		_ball.move();
		
		//do collisions
		doCollisions();
	}
	private function render(?e:FrameEvent = null):Void {
		_ball.display.x = _ball.x + _x;
		_ball.display.y = _ball.y + _y;
		
		_leftPaddle.display.x = _leftPaddle.x + _x;
		_leftPaddle.display.y = _leftPaddle.y + _y;
		
		_rightPaddle.display.x = _rightPaddle.x + _x;
		_rightPaddle.display.y = _rightPaddle.y + _y;
	}
	
	private inline function getX():Float { return _x; }
	private inline function getY():Float { return _y; }
	private inline function getWidth():Float { return _width; }
	private inline function getHeight():Float { return _height; }
	
	private function setX(v:Float) {
		_x = v;
		
		_backGround.x = _x;
		_rightScoreLabel.x = _width * 0.5 + 10 + _x;
		_leftScoreLabel.x = _width * 0.5 - 20 + _x;
		
		
		return v;
	}
	private function setY(v:Float) {
		_y = v;
		
		_backGround.y = _y;
		_leftScoreLabel.y = 10 + _y;
		_rightScoreLabel.y = 10 + _y;
		
		return v;
	}
	private inline function setWidth(v:Float) {
		_width = v;
		
		_backGround.width = v;
		_rightScoreLabel.x = _width * 0.5 + 10 + _x;
		_leftScoreLabel.x = _width * 0.5 - 20 + _x;
		_leftPaddle.x = _width * 0.05;
		_rightPaddle.x = _width * 0.93;
		return v;
	}
	private inline function setHeight(v:Float) {
		_height = v;
		
		_backGround.height = v;
		_rightScoreLabel.x = _width * 0.5 + 10 + _x;
		_leftScoreLabel.x = _width * 0.5 - 20 + _x;
		
		return v;
	}
	private inline function getPause():Bool {
		return _pause;
	}
	private function setPause(v:Bool) {
		_pause = v;
		if(_pause)
			_physicsTicker.stop();
		else
			_physicsTicker.run = physicsStep;
		return v;
	}
	//private inline function getFrameRate():Float { return _frameRate; }
	private inline function getPhysicsRate():Float { return _physicsRate; }
	
	private function setPhysicsRate(v:Float) {
		_physicsRate = v;
		if(_physicsTicker != null)_physicsTicker.stop();
		_physicsTicker = new Timer(Math.floor(1000 / _physicsRate));// 1 sec / framerate = ms needed, per frame.
		_physicsTicker.run = physicsStep;
		return v;
	}/*
	private function setFrameRate(v:Float) {
		_frameRate = v;
		if(_graphicsTicker != null)_graphicsTicker.stop();
		_graphicsTicker = new Timer(Math.floor(1000 / _frameRate));
		//_graphicsTicker.run = render;
		return v;
	}*/
}