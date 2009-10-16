#include <hxObject.h>

#ifndef INCLUDED_pong_Game
#include <pong/Game.h>
#endif
#ifndef INCLUDED_pong_MainMenu
#include <pong/MainMenu.h>
#endif
namespace pong{

Void MainMenu_obj::__construct()
{
{
	pong::Game_obj::__new(null(),null());
}
;
	return null();
}

MainMenu_obj::~MainMenu_obj() { }

Dynamic MainMenu_obj::__CreateEmpty() { return  new MainMenu_obj; }
hxObjectPtr<MainMenu_obj > MainMenu_obj::__new()
{  hxObjectPtr<MainMenu_obj > result = new MainMenu_obj();
	result->__construct();
	return result;}

Dynamic MainMenu_obj::__Create(DynamicArray inArgs)
{  hxObjectPtr<MainMenu_obj > result = new MainMenu_obj();
	result->__construct();
	return result;}


MainMenu_obj::MainMenu_obj()
{
}

void MainMenu_obj::__Mark()
{
}

Dynamic MainMenu_obj::__Field(const String &inName)
{
	return super::__Field(inName);
}



Dynamic MainMenu_obj::__IField(int inFieldID)
{
	return super::__IField(inFieldID);
}

Dynamic MainMenu_obj::__SetField(const String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void MainMenu_obj::__GetFields(Array<String> &outFields)
{
	super::__GetFields(outFields);
};

static String sStaticFields[] = {
	String(null()) };

static String sMemberFields[] = {
	String(null()) };

static void sMarkStatics() {
};

Class MainMenu_obj::__mClass;

void MainMenu_obj::__register()
{
	Static(__mClass) = RegisterClass(STRING(L"pong.MainMenu",13), TCanCast<MainMenu_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void MainMenu_obj::__boot()
{
}

} // end namespace pong
