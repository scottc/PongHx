#ifndef INCLUDED_pong_gfx_Rectangle
#define INCLUDED_pong_gfx_Rectangle

#include <hxObject.h>

DECLARE_CLASS2(pong,gfx,Rectangle)
namespace pong{
namespace gfx{


class Rectangle_obj : public virtual hxObject
{
	public:
		typedef hxObject super;
		typedef Rectangle_obj OBJ_;

	protected:
		Rectangle_obj();
		Void __construct(double x_,double y_,double width_,double height_);

	public:
		static hxObjectPtr<Rectangle_obj > __new(double x_,double y_,double width_,double height_);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(DynamicArray inArgs);
		~Rectangle_obj();

		DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		String __ToString() const { return STRING(L"Rectangle",9); }

		double x;
		double y;
		int _color;
		int color;
		double _x;
		double _y;
		double _width;
		double _height;
		virtual Void drawRect( );
		Dynamic drawRect_dyn();

		virtual double getX( );
		Dynamic getX_dyn();

		virtual double getY( );
		Dynamic getY_dyn();

		virtual int getColor( );
		Dynamic getColor_dyn();

		virtual double getWidth( );
		Dynamic getWidth_dyn();

		virtual double getHeight( );
		Dynamic getHeight_dyn();

		virtual int setColor( int v);
		Dynamic setColor_dyn();

		virtual int setX( double val);
		Dynamic setX_dyn();

		virtual int setY( double val);
		Dynamic setY_dyn();

};

} // end namespace pong
} // end namespace gfx

#endif /* INCLUDED_pong_gfx_Rectangle */ 
