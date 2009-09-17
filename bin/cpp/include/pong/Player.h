#ifndef INCLUDED_pong_Player
#define INCLUDED_pong_Player

#include <hxObject.h>

#include <pong/geom/Rectangle.h>
DECLARE_CLASS1(pong,Player)
DECLARE_CLASS2(pong,geom,Rectangle)
DECLARE_CLASS2(pong,geom,Vector)
DECLARE_CLASS2(pong,gfx,Rectangle)
namespace pong{


class Player_obj : public pong::geom::Rectangle_obj
{
	public:
		typedef pong::geom::Rectangle_obj super;
		typedef Player_obj OBJ_;

	protected:
		Player_obj();
		Void __construct(int x_,int y_,int width_,int height_);

	public:
		static hxObjectPtr<Player_obj > __new(int x_,int y_,int width_,int height_);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(DynamicArray inArgs);
		~Player_obj();

		DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		String __ToString() const { return STRING(L"Player",6); }

		pong::gfx::Rectangle sprite;
		int score;
		bool ai;
		pong::geom::Vector velocity;
		virtual Void render( );
		Dynamic render_dyn();

		virtual Void move( );
		Dynamic move_dyn();

};

} // end namespace pong

#endif /* INCLUDED_pong_Player */ 
