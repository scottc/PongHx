package pong {
	import pong.geom.Vector;
	import pong.Paddle;
	import pong.gfx.Label;
	import pong.ui.Mouse;
	import pong.gfx.Stage;
	import pong.Ball;
	import haxe.Timer;
	import flash.Boot;
	public class Game {
		public function Game() : void { if( !flash.Boot.skip_constructor ) {
			this._physicsTicker = new haxe.Timer(25);
			this._physicsTicker.run = this.physicsStep;
			this._graphicsTicker = new haxe.Timer(25);
			this._graphicsTicker.run = this.render;
			this.setupStage();
			this.newRound();
		}}
		
		protected var _graphicsTicker : haxe.Timer;
		protected var _physicsTicker : haxe.Timer;
		protected var _stage : pong.gfx.Stage;
		protected var _ball : pong.Ball;
		protected var _leftPaddle : pong.Paddle;
		protected var _rightPaddle : pong.Paddle;
		protected var _leftScoreLabel : pong.gfx.Label;
		protected var _rightScoreLabel : pong.gfx.Label;
		protected var _id : String;
		protected function setupStage() : void {
			this._stage = pong.gfx.Stage.getInstance();
			this._ball = new pong.Ball(150,50,pong.gfx.Stage.getWidth() * 0.02,pong.gfx.Stage.getWidth() * 0.02);
			this._leftPaddle = new pong.Paddle(pong.gfx.Stage.getWidth() * 0.05,50,pong.gfx.Stage.getWidth() * 0.02,pong.gfx.Stage.getHeight() * 0.15);
			this._rightPaddle = new pong.Paddle(pong.gfx.Stage.getWidth() * 0.95,50,pong.gfx.Stage.getWidth() * 0.02,pong.gfx.Stage.getHeight() * 0.15);
			this._rightPaddle.ai = true;
			this._stage.add(this._ball.sprite);
			this._stage.add(this._leftPaddle.sprite);
			this._stage.add(this._rightPaddle.sprite);
			this._leftScoreLabel = new pong.gfx.Label();
			this._leftScoreLabel.text = "0";
			this._leftScoreLabel.y = 10;
			this._leftScoreLabel.x = pong.gfx.Stage.getWidth() * 0.5 - 20;
			this._rightScoreLabel = new pong.gfx.Label();
			this._rightScoreLabel.text = "0";
			this._rightScoreLabel.y = 10;
			this._rightScoreLabel.x = pong.gfx.Stage.getWidth() * 0.5 + 10;
			this._stage.add(this._leftScoreLabel);
			this._stage.add(this._rightScoreLabel);
		}
		
		protected function newRound() : void {
			this._ball.acceleration = 0.0001;
			this._ball.velocity.x = pong.gfx.Stage.getWidth() * -0.01;
			this._ball.velocity.y = pong.gfx.Stage.getHeight() * 0.01;
			this._leftPaddle.y = pong.gfx.Stage.getHeight() / 2 - this._leftPaddle.height / 2;
			this._rightPaddle.y = pong.gfx.Stage.getHeight() / 2 - this._rightPaddle.height / 2;
			this._ball.y = pong.gfx.Stage.getHeight() / 2 - this._ball.height / 2;
			this._ball.x = pong.gfx.Stage.getWidth() / 2 - this._ball.width / 2;
		}
		
		protected function runAI(p : pong.Paddle) : void {
			if(p.y + p.height / 2 < this._ball.y + this._ball.height / 2) p.velocity.y = pong.gfx.Stage.getHeight() * 0.01;
			else if(p.y + p.height / 2 > this._ball.y + this._ball.height / 2) p.velocity.y = pong.gfx.Stage.getHeight() * -0.01;
			else p.velocity.y = 0;
		}
		
		protected function doCollisions() : void {
			if(this._leftPaddle.y + this._leftPaddle.height > pong.gfx.Stage.getHeight() - 10) {
				this._leftPaddle.y = pong.gfx.Stage.getHeight() - this._leftPaddle.height - 10;
			}
			if(this._leftPaddle.y < 10) {
				this._leftPaddle.y = 10;
			}
			if(this._rightPaddle.y + this._rightPaddle.height > pong.gfx.Stage.getHeight() - 10) {
				this._rightPaddle.y = pong.gfx.Stage.getHeight() - this._rightPaddle.height - 10;
			}
			if(this._rightPaddle.y < 10) {
				this._rightPaddle.y = 10;
			}
			if(this._ball.y + this._ball.height > pong.gfx.Stage.getHeight() - 10) {
				this._ball.y = pong.gfx.Stage.getHeight() - this._ball.height - 10;
				this._ball.velocity.y *= -1;
			}
			if(this._ball.y < 10) {
				this._ball.y = 10;
				this._ball.velocity.y *= -1;
			}
			if(this._ball.x < 0 - this._ball.width) {
				this._rightScoreLabel.text = Std.string(++this._rightPaddle.score);
				this.newRound();
			}
			if(this._ball.x > pong.gfx.Stage.getWidth()) {
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
		
	}
}
