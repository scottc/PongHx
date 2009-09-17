#ifndef INCLUDED_pong_gfx_Stage
#define INCLUDED_pong_gfx_Stage

#include <hxObject.h>

DECLARE_CLASS2(pong,gfx,Stage)
namespace pong{
namespace gfx{


class Stage_obj : public virtual hxObject
{
	public:
		typedef hxObject super;
		typedef Stage_obj OBJ_;

	protected:
		Stage_obj();
		Void __construct();

	public:
		static hxObjectPtr<Stage_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(DynamicArray inArgs);
		~Stage_obj();

		DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		String __ToString() const { return STRING(L"Stage",5); }

		virtual Void add( Dynamic object);
		Dynamic add_dyn();

		virtual Void drawBackground( );
		Dynamic drawBackground_dyn();

		static int width;
		static int height;
		static int getWidth( );
		static Dynamic getWidth_dyn();

		static int getHeight( );
		static Dynamic getHeight_dyn();

};

} // end namespace pong
} // end namespace gfx

#endif /* INCLUDED_pong_gfx_Stage */ 
