package pong {
	import pong.gfx.Label;
	import pong.ui.Mouse;
	import pong.gfx.Stage;
	import pong.Ball;
	import haxe.Timer;
	import flash.Boot;
	import pong.Player;
	public class Game {
		public function Game() : void { if( !flash.Boot.skip_constructor ) {
			this._physicsTicker = new haxe.Timer(25);
			this._physicsTicker.run = this.physicsStep;
			this._graphicsTicker = new haxe.Timer(25);
			this._graphicsTicker.run = this.render;
			this.setupStage();
			this.newRound();
			this._ball.y -= 100;
		}}
		
		protected var _graphicsTicker : haxe.Timer;
		protected var _physicsTicker : haxe.Timer;
		protected var _stage : pong.gfx.Stage;
		protected var _ball : pong.Ball;
		protected var _leftPlayer : pong.Player;
		protected var _rightPlayer : pong.Player;
		protected var _leftScoreLabel : pong.gfx.Label;
		protected var _rightScoreLabel : pong.gfx.Label;
		protected var _id : String;
		protected function setupStage() : void {
			this._stage = pong.gfx.Stage.getInstance();
			this._ball = new pong.Ball(150,50,20,20);
			this._ball.velocity.x = pong.gfx.Stage.getWidth() * 0.005;
			this._ball.velocity.y = pong.gfx.Stage.getHeight() * 0.005;
			this._leftPlayer = new pong.Player(30,50,20,100);
			this._rightPlayer = new pong.Player(pong.gfx.Stage.getWidth() - 50,50,20,100);
			this._rightPlayer.ai = true;
			this._stage.add(this._ball.sprite);
			this._stage.add(this._leftPlayer.sprite);
			this._stage.add(this._rightPlayer.sprite);
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
			this._leftPlayer.y = pong.gfx.Stage.getHeight() / 2 - this._leftPlayer.height / 2;
			this._rightPlayer.y = pong.gfx.Stage.getHeight() / 2 - this._rightPlayer.height / 2;
			this._ball.y = pong.gfx.Stage.getHeight() / 2 - this._ball.height / 2;
			this._ball.x = pong.gfx.Stage.getWidth() / 2 - this._ball.width / 2;
		}
		
		protected function runAI(p : pong.Player) : void {
			if(p.y + p.height / 2 < this._ball.y + this._ball.height / 2) p.velocity.y = pong.gfx.Stage.getHeight() * 0.005;
			else if(p.y + p.height / 2 > this._ball.y + this._ball.height / 2) p.velocity.y = -pong.gfx.Stage.getHeight() * 0.005;
			else p.velocity.y = 0;
		}
		
		protected function doCollisions() : void {
			if(this._leftPlayer.y + this._leftPlayer.height > pong.gfx.Stage.getHeight() - 10) {
				this._leftPlayer.y = pong.gfx.Stage.getHeight() - this._leftPlayer.height - 10;
			}
			if(this._leftPlayer.y < 10) {
				this._leftPlayer.y = 10;
			}
			if(this._rightPlayer.y + this._rightPlayer.height > pong.gfx.Stage.getHeight() - 10) {
				this._rightPlayer.y = pong.gfx.Stage.getHeight() - this._rightPlayer.height - 10;
			}
			if(this._rightPlayer.y < 10) {
				this._rightPlayer.y = 10;
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
				this._rightScoreLabel.text = Std.string(++this._rightPlayer.score);
				this.newRound();
			}
			if(this._ball.x > pong.gfx.Stage.getWidth()) {
				this._leftScoreLabel.text = Std.string(++this._leftPlayer.score);
				this.newRound();
			}
			if(this._ball.isOverlapping(this._leftPlayer)) {
				this._ball.x = this._leftPlayer.x + this._leftPlayer.width;
				this._ball.velocity.x *= -1;
			}
			if(this._ball.isOverlapping(this._rightPlayer)) {
				this._ball.x = this._rightPlayer.x - this._ball.width;
				this._ball.velocity.x *= -1;
			}
		}
		
		protected function physicsStep() : void {
			if(!this._leftPlayer.ai) {
				this._leftPlayer.y = pong.ui.Mouse.y - this._leftPlayer.height / 2;
			}
			else if(this._ball.velocity.x < 0) this.runAI(this._leftPlayer);
			else this._leftPlayer.velocity.y = 0;
			if(!this._rightPlayer.ai) {
				this._rightPlayer.y = pong.ui.Mouse.y - this._rightPlayer.height / 2;
			}
			else if(this._ball.velocity.x > 0) this.runAI(this._rightPlayer);
			else this._rightPlayer.velocity.y = 0;
			this._leftPlayer.move();
			this._rightPlayer.move();
			this._ball.move();
			this.doCollisions();
		}
		
		protected function render() : void {
			this._ball.render();
			this._leftPlayer.render();
			this._rightPlayer.render();
		}
		
	}
}
