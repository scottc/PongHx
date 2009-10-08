package pong {
	import pong.geom.Vector;
	import pong.Paddle;
	import pong.gfx.Label;
	import pong.ui.Mouse;
	import pong.gfx.Stage;
	import pong.Ball;
	import pong.gfx.PongBackground;
	import haxe.Timer;
	import flash.Boot;
	public class Game {
		public function Game(width_ : Number = 300,height_ : Number = 300) : void { if( !flash.Boot.skip_constructor ) {
			this.setWidth(width_);
			this.setHeight(height_);
			this.setFrameRate(60);
			this.setPhysicsRate(60);
			this.setupStage();
			this.newRound();
			this.render();
		}}
		
		protected var _stage : pong.gfx.Stage;
		protected var _ball : pong.Ball;
		protected var _leftPaddle : pong.Paddle;
		protected var _rightPaddle : pong.Paddle;
		protected var _leftScoreLabel : pong.gfx.Label;
		protected var _rightScoreLabel : pong.gfx.Label;
		protected var _graphicsTicker : haxe.Timer;
		protected var _physicsTicker : haxe.Timer;
		protected var _frameRate : Number;
		protected var _physicsRate : Number;
		public function get frameRate() : Number { return getFrameRate(); }
		public function set frameRate( __v : Number ) : void { setFrameRate(__v); }
		protected var $frameRate : Number;
		public function get physicsRate() : Number { return getFrameRate(); }
		public function set physicsRate( __v : Number ) : void { setPhysicsRate(__v); }
		protected var $physicsRate : Number;
		protected var _x : Number;
		public function get x() : Number { return getX(); }
		public function set x( __v : Number ) : void { setX(__v); }
		protected var $x : Number;
		protected var _y : Number;
		public function get y() : Number { return getY(); }
		public function set y( __v : Number ) : void { setY(__v); }
		protected var $y : Number;
		protected var _width : Number;
		public function get width() : Number { return getWidth(); }
		public function set width( __v : Number ) : void { setWidth(__v); }
		protected var $width : Number;
		protected var _height : Number;
		public function get height() : Number { return getHeight(); }
		public function set height( __v : Number ) : void { setHeight(__v); }
		protected var $height : Number;
		protected function setupStage() : void {
			this._stage = pong.gfx.Stage.getInstance();
			this._stage.add(new pong.gfx.PongBackground(this.getWidth(),this.getHeight()));
			this._ball = new pong.Ball(150,50,this.getWidth() * 0.02,this.getWidth() * 0.02);
			this._leftPaddle = new pong.Paddle(this.getWidth() * 0.05,50,this.getWidth() * 0.02,this.getHeight() * 0.15);
			this._rightPaddle = new pong.Paddle(this.getWidth() * 0.93,50,this.getWidth() * 0.02,this.getHeight() * 0.15);
			this._rightPaddle.ai = true;
			this._stage.add(this._ball.sprite);
			this._stage.add(this._leftPaddle.sprite);
			this._stage.add(this._rightPaddle.sprite);
			this._leftScoreLabel = new pong.gfx.Label();
			this._leftScoreLabel.text = "0";
			this._leftScoreLabel.y = 10;
			this._leftScoreLabel.x = this.getWidth() * 0.5 - 20;
			this._rightScoreLabel = new pong.gfx.Label();
			this._rightScoreLabel.text = "0";
			this._rightScoreLabel.y = 10;
			this._rightScoreLabel.x = this.getWidth() * 0.5 + 10;
			this._stage.add(this._leftScoreLabel);
			this._stage.add(this._rightScoreLabel);
		}
		
		protected function newRound() : void {
			this._leftPaddle.y = this.getHeight() / 2 - this._leftPaddle.height / 2;
			this._rightPaddle.y = this.getHeight() / 2 - this._rightPaddle.height / 2;
			this._ball.y = this.getHeight() / 2 - this._ball.height / 2;
			this._ball.x = this.getWidth() / 2 - this._ball.width / 2;
			this._ball.velocity.x = this.getWidth() * Math.random() - this.getWidth() * 0.5;
			this._ball.velocity.y = this.getHeight() * Math.random() - this.getHeight() * 0.5;
			this._ball.velocity = this._ball.velocity.normalize(this.getWidth() * 0.01);
		}
		
		protected function runAI(p : pong.Paddle) : void {
			if(p.y + p.height / 2 < this._ball.y + this._ball.height / 2) p.velocity.y = this.getHeight() * 0.01;
			else if(p.y + p.height / 2 > this._ball.y + this._ball.height / 2) p.velocity.y = this.getHeight() * -0.01;
			else p.velocity.y = 0;
		}
		
		protected function doCollisions() : void {
			if(this._leftPaddle.y + this._leftPaddle.height > this.getHeight() - 10) {
				this._leftPaddle.y = this.getHeight() - this._leftPaddle.height - 10;
			}
			if(this._leftPaddle.y < 10) {
				this._leftPaddle.y = 10;
			}
			if(this._rightPaddle.y + this._rightPaddle.height > this.getHeight() - 10) {
				this._rightPaddle.y = this.getHeight() - this._rightPaddle.height - 10;
			}
			if(this._rightPaddle.y < 10) {
				this._rightPaddle.y = 10;
			}
			if(this._ball.y + this._ball.height > this.getHeight() - 10) {
				this._ball.y = this.getHeight() - this._ball.height - 10;
				this._ball.velocity.y *= -1;
			}
			if(this._ball.y < 10) {
				this._ball.y = 10;
				this._ball.velocity.y *= -1;
			}
			if(this._ball.x < -this._ball.width) {
				this._rightScoreLabel.text = Std.string(++this._rightPaddle.score);
				this.newRound();
			}
			if(this._ball.x > this.getWidth()) {
				this._leftScoreLabel.text = Std.string(++this._leftPaddle.score);
				this.newRound();
			}
			this.ballPaddleCollision(this._leftPaddle);
			this.ballPaddleCollision(this._rightPaddle);
		}
		
		protected function ballPaddleCollision(p : pong.Paddle) : void {
			if(this._ball.isOverlapping(p)) {
				var newDirection : pong.geom.Vector = new pong.geom.Vector((this._ball.x + this._ball.width * 0.5) - (p.x + p.width * 0.5),(this._ball.y + this._ball.height * 0.5) - (p.y + p.height * 0.5));
				this._ball.velocity = newDirection.normalize(this._ball.velocity.length());
			}
		}
		
		protected function physicsStep() : void {
			if(!this._leftPaddle.ai) {
				this._leftPaddle.y = pong.ui.Mouse.y - this._leftPaddle.height / 2;
			}
			else if(this._ball.velocity.x < 0) this.runAI(this._leftPaddle);
			else this._leftPaddle.velocity.y = 0;
			if(!this._rightPaddle.ai) {
				this._rightPaddle.y = pong.ui.Mouse.y - this._rightPaddle.height / 2;
			}
			else if(this._ball.velocity.x > 0) this.runAI(this._rightPaddle);
			else this._rightPaddle.velocity.y = 0;
			this._leftPaddle.move();
			this._rightPaddle.move();
			this._ball.move();
			this.doCollisions();
		}
		
		protected function render() : void {
			this._ball.render();
			this._leftPaddle.render();
			this._rightPaddle.render();
		}
		
		public function getX() : Number {
			return this._x;
		}
		
		public function getY() : Number {
			return this._y;
		}
		
		public function getWidth() : Number {
			return this._width;
		}
		
		public function getHeight() : Number {
			return this._height;
		}
		
		public function setX(v : Number) : Number {
			this._x = v;
			return v;
		}
		
		public function setY(v : Number) : Number {
			this._y = v;
			return v;
		}
		
		public function setWidth(v : Number) : Number {
			this._width = v;
			return v;
		}
		
		public function setHeight(v : Number) : Number {
			this._height = v;
			return v;
		}
		
		public function getFrameRate() : Number {
			return this._frameRate;
		}
		
		protected function getPhysicsRate() : Number {
			return this._physicsRate;
		}
		
		public function setFrameRate(v : Number) : Number {
			this._physicsRate = v;
			if(this._physicsTicker != null) this._physicsTicker.stop();
			this._physicsTicker = new haxe.Timer(Math.floor(1000 / this._physicsRate));
			this._physicsTicker.run = this.physicsStep;
			return v;
		}
		
		public function setPhysicsRate(v : Number) : Number {
			this._frameRate = v;
			if(this._graphicsTicker != null) this._graphicsTicker.stop();
			this._graphicsTicker = new haxe.Timer(Math.floor(1000 / this._frameRate));
			this._graphicsTicker.run = this.render;
			return v;
		}
		
	}
}
