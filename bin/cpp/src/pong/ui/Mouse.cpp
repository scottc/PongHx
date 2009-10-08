#include <hxObject.h>

#ifndef INCLUDED_pong_ui_Mouse
#include <pong/ui/Mouse.h>
#endif
namespace pong{
namespace ui{

Void Mouse_obj::__construct()
{
	return null();
}

Mouse_obj::~Mouse_obj() { }

Dynamic Mouse_obj::__CreateEmpty() { return  new Mouse_obj; }
hxObjectPtr<Mouse_obj > Mouse_obj::__new()
{  hxObjectPtr<Mouse_obj > result = new Mouse_obj();
	result->__construct();
	return result;}

Dynamic Mouse_obj::__Create(DynamicArray inArgs)
{  hxObjectPtr<Mouse_obj > result = new Mouse_obj();
	result->__construct();
	return result;}

int Mouse_obj::x;

int Mouse_obj::y;

Void Mouse_obj::initialize( ){
{
	}
return null();
}


STATIC_DEFINE_DYNAMIC_FUNC0(Mouse_obj,initialize,(void))

Void Mouse_obj::mouseMove( Dynamic e){
{
	}
return null();
}


STATIC_DEFINE_DYNAMIC_FUNC1(Mouse_obj,mouseMove,(void))

Void Mouse_obj::mousePressed( Dynamic e){
{
	}
return null();
}


STATIC_DEFINE_DYNAMIC_FUNC1(Mouse_obj,mousePressed,(void))


Mouse_obj::Mouse_obj()
{
}

void Mouse_obj::__Mark()
{
}

Dynamic Mouse_obj::__Field(const String &inName)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"x",sizeof(wchar_t)*1) ) { return x; }
		if (!memcmp(inName.__s,L"y",sizeof(wchar_t)*1) ) { return y; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"mouseMove",sizeof(wchar_t)*9) ) { return mouseMove_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"initialize",sizeof(wchar_t)*10) ) { return initialize_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"mousePressed",sizeof(wchar_t)*12) ) { return mousePressed_dyn(); }
	}
	return super::__Field(inName);
}

static int __id_x = __hxcpp_field_to_id("x");
static int __id_y = __hxcpp_field_to_id("y");
static int __id_initialize = __hxcpp_field_to_id("initialize");
static int __id_mouseMove = __hxcpp_field_to_id("mouseMove");
static int __id_mousePressed = __hxcpp_field_to_id("mousePressed");


Dynamic Mouse_obj::__IField(int inFieldID)
{
	if (inFieldID==__id_x) return x;
	if (inFieldID==__id_y) return y;
	if (inFieldID==__id_initialize) return initialize_dyn();
	if (inFieldID==__id_mouseMove) return mouseMove_dyn();
	if (inFieldID==__id_mousePressed) return mousePressed_dyn();
	return super::__IField(inFieldID);
}

Dynamic Mouse_obj::__SetField(const String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"x",sizeof(wchar_t)*1) ) { x=inValue.Cast<int >();return inValue; }
		if (!memcmp(inName.__s,L"y",sizeof(wchar_t)*1) ) { y=inValue.Cast<int >();return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Mouse_obj::__GetFields(Array<String> &outFields)
{
	super::__GetFields(outFields);
};

static String sStaticFields[] = {
	STRING(L"x",1),
	STRING(L"y",1),
	STRING(L"initialize",10),
	STRING(L"mouseMove",9),
	STRING(L"mousePressed",12),
	String(null()) };

static String sMemberFields[] = {
	String(null()) };

static void sMarkStatics() {
	MarkMember(Mouse_obj::x);
	MarkMember(Mouse_obj::y);
};

Class Mouse_obj::__mClass;

void Mouse_obj::__register()
{
	Static(__mClass) = RegisterClass(STRING(L"pong.ui.Mouse",13), TCanCast<Mouse_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Mouse_obj::__boot()
{
	Static(x) = 0;
	Static(y) = 0;
}

} // end namespace pong
} // end namespace ui
