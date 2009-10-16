#ifndef INCLUDED_pong_Game
#define INCLUDED_pong_Game

#include <hxObject.h>

DECLARE_CLASS1(haxe,Timer)
DECLARE_CLASS1(pong,Ball)
DECLARE_CLASS1(pong,Game)
DECLARE_CLASS1(pong,Paddle)
DECLARE_CLASS2(pong,geom,Rectangle)
DECLARE_CLASS2(pong,gfx,IDisplayObject)
DECLARE_CLASS2(pong,gfx,Label)
DECLARE_CLASS2(pong,gfx,PongBackground)
DECLARE_CLASS2(pong,gfx,Rectangle)
DECLARE_CLASS2(pong,gfx,Stage)
namespace pong{


class Game_obj : public virtual hxObject
{
	public:
		typedef hxObject super;
		typedef Game_obj OBJ_;

	protected:
		Game_obj();
		Void __construct(Dynamic __o_width_,Dynamic __o_height_);

	public:
		static hxObjectPtr<Game_obj > __new(Dynamic __o_width_,Dynamic __o_height_);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(DynamicArray inArgs);
		~Game_obj();

		DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		String __ToString() const { return STRING(L"Game",4); }

		pong::gfx::Stage _stage;
		pong::Ball _ball;
		pong::Paddle _leftPaddle;
		pong::Paddle _rightPaddle;
		pong::gfx::Label _leftScoreLabel;
		pong::gfx::Label _rightScoreLabel;
		pong::gfx::PongBackground _backGround;
		haxe::Timer _graphicsTicker;
		haxe::Timer _physicsTicker;
		double _frameRate;
		double _physicsRate;
		double frameRate;
		double physicsRate;
		double _x;
		double x;
		double _y;
		double y;
		double _width;
		double width;
		double _height;
		double height;
		virtual Void setupStage( );
		Dynamic setupStage_dyn();

		virtual Void newRound( );
		Dynamic newRound_dyn();

		virtual Void runAI( pong::Paddle p);
		Dynamic runAI_dyn();

		virtual Void doCollisions( );
		Dynamic doCollisions_dyn();

		virtual Void ballPaddleCollision( pong::Paddle p);
		Dynamic ballPaddleCollision_dyn();

		virtual Void physicsStep( );
		Dynamic physicsStep_dyn();

		virtual Void render( );
		Dynamic render_dyn();

		virtual double getX( );
		Dynamic getX_dyn();

		virtual double getY( );
		Dynamic getY_dyn();

		virtual double getWidth( );
		Dynamic getWidth_dyn();

		virtual double getHeight( );
		Dynamic getHeight_dyn();

		virtual double setX( double v);
		Dynamic setX_dyn();

		virtual double setY( double v);
		Dynamic setY_dyn();

		virtual double setWidth( double v);
		Dynamic setWidth_dyn();

		virtual double setHeight( double v);
		Dynamic setHeight_dyn();

		virtual double getFrameRate( );
		Dynamic getFrameRate_dyn();

		virtual double getPhysicsRate( );
		Dynamic getPhysicsRate_dyn();

		virtual double setFrameRate( double v);
		Dynamic setFrameRate_dyn();

		virtual double setPhysicsRate( double v);
		Dynamic setPhysicsRate_dyn();

};

} // end namespace pong

#endif /* INCLUDED_pong_Game */ 
