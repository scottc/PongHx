#ifndef INCLUDED_pong_Paddle
#define INCLUDED_pong_Paddle

#include <hxObject.h>

#include <pong/geom/Rectangle.h>
DECLARE_CLASS1(pong,Paddle)
DECLARE_CLASS2(pong,geom,Rectangle)
DECLARE_CLASS2(pong,geom,Vector)
DECLARE_CLASS2(pong,gfx,IDisplayObject)
DECLARE_CLASS2(pong,gfx,Rectangle)
namespace pong{


class Paddle_obj : public pong::geom::Rectangle_obj
{
	public:
		typedef pong::geom::Rectangle_obj super;
		typedef Paddle_obj OBJ_;

	protected:
		Paddle_obj();
		Void __construct(double x_,double y_,double width_,double height_);

	public:
		static hxObjectPtr<Paddle_obj > __new(double x_,double y_,double width_,double height_);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(DynamicArray inArgs);
		~Paddle_obj();

		DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		String __ToString() const { return STRING(L"Paddle",6); }

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

#endif /* INCLUDED_pong_Paddle */ 
