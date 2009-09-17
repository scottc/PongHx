#ifndef INCLUDED_pong_ui_Keyboard
#define INCLUDED_pong_ui_Keyboard

#include <hxObject.h>

DECLARE_CLASS2(pong,ui,Keyboard)
namespace pong{
namespace ui{


class Keyboard_obj : public virtual hxObject
{
	public:
		typedef hxObject super;
		typedef Keyboard_obj OBJ_;

	protected:
		Keyboard_obj();
		Void __construct();

	public:
		static hxObjectPtr<Keyboard_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(DynamicArray inArgs);
		~Keyboard_obj();

		DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		String __ToString() const { return STRING(L"Keyboard",8); }

};

} // end namespace pong
} // end namespace ui

#endif /* INCLUDED_pong_ui_Keyboard */ 
