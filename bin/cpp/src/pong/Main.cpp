#include <hxObject.h>

#ifndef INCLUDED_pong_Game
#include <pong/Game.h>
#endif
#ifndef INCLUDED_pong_Main
#include <pong/Main.h>
#endif
#ifndef INCLUDED_pong_gfx_Stage
#include <pong/gfx/Stage.h>
#endif
#ifndef INCLUDED_pong_ui_Mouse
#include <pong/ui/Mouse.h>
#endif
namespace pong{

Void Main_obj::__construct()
{
	return null();
}

Main_obj::~Main_obj() { }

Dynamic Main_obj::__CreateEmpty() { return  new Main_obj; }
hxObjectPtr<Main_obj > Main_obj::__new()
{  hxObjectPtr<Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

Dynamic Main_obj::__Create(DynamicArray inArgs)
{  hxObjectPtr<Main_obj > result = new Main_obj();
	result->__construct();
	return result;}

Void Main_obj::main( ){
{
		pong::ui::Mouse_obj::initialize();
		pong::Game_obj::__new(pong::gfx::Stage_obj::getWidth(),pong::gfx::Stage_obj::getHeight());
	}
return null();
}


STATIC_DEFINE_DYNAMIC_FUNC0(Main_obj,main,(void))


Main_obj::Main_obj()
{
}

void Main_obj::__Mark()
{
}

Dynamic Main_obj::__Field(const String &inName)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"main",sizeof(wchar_t)*4) ) { return main_dyn(); }
	}
	return super::__Field(inName);
}

static int __id_main = __hxcpp_field_to_id("main");


Dynamic Main_obj::__IField(int inFieldID)
{
	if (inFieldID==__id_main) return main_dyn();
	return super::__IField(inFieldID);
}

Dynamic Main_obj::__SetField(const String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void Main_obj::__GetFields(Array<String> &outFields)
{
	super::__GetFields(outFields);
};

static String sStaticFields[] = {
	STRING(L"main",4),
	String(null()) };

static String sMemberFields[] = {
	String(null()) };

static void sMarkStatics() {
};

Class Main_obj::__mClass;

void Main_obj::__register()
{
	Static(__mClass) = RegisterClass(STRING(L"pong.Main",9), TCanCast<Main_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Main_obj::__boot()
{
}

} // end namespace pong
