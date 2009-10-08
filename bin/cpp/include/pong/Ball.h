#ifndef INCLUDED_pong_Ball
#define INCLUDED_pong_Ball

#include <hxObject.h>

#include <pong/geom/Rectangle.h>
DECLARE_CLASS1(pong,Ball)
DECLARE_CLASS2(pong,geom,Rectangle)
DECLARE_CLASS2(pong,geom,Vector)
DECLARE_CLASS2(pong,gfx,Rectangle)
namespace pong{


class Ball_obj : public pong::geom::Rectangle_obj
{
	public:
		typedef pong::geom::Rectangle_obj super;
		typedef Ball_obj OBJ_;

	protected:
		Ball_obj();
		Void __construct(double x_,double y_,double width_,double height_);

	public:
		static hxObjectPtr<Ball_obj > __new(double x_,double y_,double width_,double height_);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(DynamicArray inArgs);
		~Ball_obj();

		DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		String __ToString() const { return STRING(L"Ball",4); }

		pong::gfx::Rectangle sprite;
		pong::geom::Vector velocity;
		double acceleration;
		virtual Void render( );
		Dynamic render_dyn();

		virtual Void move( );
		Dynamic move_dyn();

};

} // end namespace pong

#endif /* INCLUDED_pong_Ball */ 
