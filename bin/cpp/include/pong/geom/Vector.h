#ifndef INCLUDED_pong_geom_Vector
#define INCLUDED_pong_geom_Vector

#include <hxObject.h>

DECLARE_CLASS2(pong,geom,Vector)
namespace pong{
namespace geom{


class Vector_obj : public virtual hxObject
{
	public:
		typedef hxObject super;
		typedef Vector_obj OBJ_;

	protected:
		Vector_obj();
		Void __construct(double x_,double y_);

	public:
		static hxObjectPtr<Vector_obj > __new(double x_,double y_);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(DynamicArray inArgs);
		~Vector_obj();

		DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		String __ToString() const { return STRING(L"Vector",6); }

		double x;
		double y;
		virtual pong::geom::Vector clone( );
		Dynamic clone_dyn();

		virtual Void set( double x_,double y_);
		Dynamic set_dyn();

		virtual pong::geom::Vector plus( pong::geom::Vector v);
		Dynamic plus_dyn();

		virtual pong::geom::Vector minus( pong::geom::Vector v);
		Dynamic minus_dyn();

		virtual pong::geom::Vector multiply( double n);
		Dynamic multiply_dyn();

		virtual double dotProduct( pong::geom::Vector v);
		Dynamic dotProduct_dyn();

		virtual double crossProduct( pong::geom::Vector v);
		Dynamic crossProduct_dyn();

		virtual double length( );
		Dynamic length_dyn();

		virtual pong::geom::Vector normalize( Dynamic l);
		Dynamic normalize_dyn();

};

} // end namespace pong
} // end namespace geom

#endif /* INCLUDED_pong_geom_Vector */ 
