#ifndef INCLUDED_pong_MainMenu
#define INCLUDED_pong_MainMenu

#include <hxObject.h>

DECLARE_CLASS1(pong,MainMenu)
namespace pong{


class MainMenu_obj : public virtual hxObject
{
	public:
		typedef hxObject super;
		typedef MainMenu_obj OBJ_;

	protected:
		MainMenu_obj();
		Void __construct();

	public:
		static hxObjectPtr<MainMenu_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(DynamicArray inArgs);
		~MainMenu_obj();

		DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		String __ToString() const { return STRING(L"MainMenu",8); }

};

} // end namespace pong

#endif /* INCLUDED_pong_MainMenu */ 
