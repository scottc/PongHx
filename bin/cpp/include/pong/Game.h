#ifndef INCLUDED_pong_Game
#define INCLUDED_pong_Game

#include <hxObject.h>

DECLARE_CLASS1(haxe,Timer)
DECLARE_CLASS1(pong,Ball)
DECLARE_CLASS1(pong,Game)
DECLARE_CLASS1(pong,Paddle)
DECLARE_CLASS2(pong,geom,Rectangle)
DECLARE_CLASS2(pong,gfx,Label)
DECLARE_CLASS2(pong,gfx,Stage)
namespace pong{


class Game_obj : public virtual hxObject
{
	public:
		typedef hxObject super;
		typedef Game_obj OBJ_;

	protected:
		Game_obj();
		Void __construct();

	public:
		static hxObjectPtr<Game_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(DynamicArray inArgs);
		~Game_obj();

		DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		String __ToString() const { return STRING(L"Game",4); }

		haxe::Timer _graphicsTicker;
		haxe::Timer _physicsTicker;
		pong::gfx::Stage _stage;
		pong::Ball _ball;
		pong::Paddle _leftPaddle;
		pong::Paddle _rightPaddle;
		pong::gfx::Label _leftScoreLabel;
		pong::gfx::Label _rightScoreLabel;
		String _id;
		virtual Void setupStage( );
		Dynamic setupStage_dyn();

		virtual Void newRound( );
		Dynamic newRound_dyn();

		virtual Void runAI( pong::Paddle p);
		Dynamic runAI_dyn();

		virtual Void doCollisions( );
		Dynamic doCollisions_dyn();

		virtual Void physicsStep( );
		Dynamic physicsStep_dyn();

		virtual Void render( );
		Dynamic render_dyn();

};

} // end namespace pong

#endif /* INCLUDED_pong_Game */ 
