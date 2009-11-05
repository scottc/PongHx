package pong;

import Xinf;

class MainMenu 
{
	//constructor
	public function new() 
	{
		var g = new Game(Root.width, Root.height);

		Root.appendChild(g);
		
		Root.addEventListener( GeometryEvent.STAGE_SCALED,
								function(e:GeometryEvent) {
									g.width = Root.width; g.height = Root.height;
								} );
		
		//var g = new Game(200, 200);
		//g.width = 300;
		//g.height = 300;
		//g.x = 200;
		//g.y = 200;
		//Root.appendChild(g);
	}
}