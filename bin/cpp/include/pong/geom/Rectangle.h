#ifndef INCLUDED_pong_geom_Rectangle
#define INCLUDED_pong_geom_Rectangle

#include <hxObject.h>

DECLARE_CLASS2(pong,geom,Rectangle)
namespace pong{
namespace geom{


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

		double width;
		double height;
		double x;
		double y;
		virtual bool isOverlapping( pong::geom::Rectangle rect);
		Dynamic isOverlapping_dyn();

};

} // end namespace pong
} // end namespace geom

#endif /* INCLUDED_pong_geom_Rectangle */ 
