#ifndef INCLUDED_pong_ui_Mouse
#define INCLUDED_pong_ui_Mouse

#include <hxObject.h>

DECLARE_CLASS2(pong,ui,Mouse)
namespace pong{
namespace ui{


class Mouse_obj : public virtual hxObject
{
	public:
		typedef hxObject super;
		typedef Mouse_obj OBJ_;

	protected:
		Mouse_obj();
		Void __construct();

	public:
		static hxObjectPtr<Mouse_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(DynamicArray inArgs);
		~Mouse_obj();

		DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		String __ToString() const { return STRING(L"Mouse",5); }

		static int x;
		static int y;
		static Void initialize( );
		static Dynamic initialize_dyn();

		static Void mouseMove( Dynamic e);
		static Dynamic mouseMove_dyn();

		static Void mousePressed( Dynamic e);
		static Dynamic mousePressed_dyn();

};

} // end namespace pong
} // end namespace ui

#endif /* INCLUDED_pong_ui_Mouse */ 
