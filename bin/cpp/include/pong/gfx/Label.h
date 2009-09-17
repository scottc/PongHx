#ifndef INCLUDED_pong_gfx_Label
#define INCLUDED_pong_gfx_Label

#include <hxObject.h>

DECLARE_CLASS2(pong,gfx,Label)
namespace pong{
namespace gfx{


class Label_obj : public virtual hxObject
{
	public:
		typedef hxObject super;
		typedef Label_obj OBJ_;

	protected:
		Label_obj();
		Void __construct();

	public:
		static hxObjectPtr<Label_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(DynamicArray inArgs);
		~Label_obj();

		DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		String __ToString() const { return STRING(L"Label",5); }

		String text;
		double x;
		double y;
		virtual String getText( );
		Dynamic getText_dyn();

		virtual Void setText( String v);
		Dynamic setText_dyn();

		virtual int getX( );
		Dynamic getX_dyn();

		virtual Void setX( int v);
		Dynamic setX_dyn();

		virtual int getY( );
		Dynamic getY_dyn();

		virtual Void setY( int v);
		Dynamic setY_dyn();

};

} // end namespace pong
} // end namespace gfx

#endif /* INCLUDED_pong_gfx_Label */ 
