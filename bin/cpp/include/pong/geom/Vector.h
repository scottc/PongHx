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
};

} // end namespace pong
} // end namespace geom

#endif /* INCLUDED_pong_geom_Vector */ 
