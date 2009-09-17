#include <hxObject.h>

#ifndef INCLUDED_pong_ui_Keyboard
#include <pong/ui/Keyboard.h>
#endif
namespace pong{
namespace ui{

Void Keyboard_obj::__construct()
{
{
}
;
	return null();
}

Keyboard_obj::~Keyboard_obj() { }

Dynamic Keyboard_obj::__CreateEmpty() { return  new Keyboard_obj; }
hxObjectPtr<Keyboard_obj > Keyboard_obj::__new()
{  hxObjectPtr<Keyboard_obj > result = new Keyboard_obj();
	result->__construct();
	return result;}

Dynamic Keyboard_obj::__Create(DynamicArray inArgs)
{  hxObjectPtr<Keyboard_obj > result = new Keyboard_obj();
	result->__construct();
	return result;}


Keyboard_obj::Keyboard_obj()
{
}

void Keyboard_obj::__Mark()
{
}

Dynamic Keyboard_obj::__Field(const String &inName)
{
	return super::__Field(inName);
}



Dynamic Keyboard_obj::__IField(int inFieldID)
{
	return super::__IField(inFieldID);
}

Dynamic Keyboard_obj::__SetField(const String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void Keyboard_obj::__GetFields(Array<String> &outFields)
{
	super::__GetFields(outFields);
};

static String sStaticFields[] = {
	String(null()) };

static String sMemberFields[] = {
	String(null()) };

static void sMarkStatics() {
};

Class Keyboard_obj::__mClass;

void Keyboard_obj::__register()
{
	Static(__mClass) = RegisterClass(STRING(L"pong.ui.Keyboard",16), TCanCast<Keyboard_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Keyboard_obj::__boot()
{
}

} // end namespace pong
} // end namespace ui
