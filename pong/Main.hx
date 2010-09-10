package pong;

import nme.Lib;

class Main 
{
	static function main() 
	{
		#if flash
			new MainMenu();
		#else
			Lib.create(function(){new MainMenu();},550,400,60,0xffffff,(1*Lib.HARDWARE) | Lib.RESIZABLE);
		#end
	}
}