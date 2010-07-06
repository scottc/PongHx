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
	}
}