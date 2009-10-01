#include <hxObject.h>

#ifndef INCLUDED_pong_gfx_Label
#include <pong/gfx/Label.h>
#endif
namespace pong{
namespace gfx{

Void Label_obj::__construct()
{
{
}
;
	return null();
}

Label_obj::~Label_obj() { }

Dynamic Label_obj::__CreateEmpty() { return  new Label_obj; }
hxObjectPtr<Label_obj > Label_obj::__new()
{  hxObjectPtr<Label_obj > result = new Label_obj();
	result->__construct();
	return result;}

Dynamic Label_obj::__Create(DynamicArray inArgs)
{  hxObjectPtr<Label_obj > result = new Label_obj();
	result->__construct();
	return result;}

String Label_obj::getText( ){
	return STRING(L"",0);
}


DEFINE_DYNAMIC_FUNC0(Label_obj,getText,return )

String Label_obj::setText( String v){
	String foo = v;
	return STRING(L"",0);
}


DEFINE_DYNAMIC_FUNC1(Label_obj,setText,return )

double Label_obj::getX( ){
	return 0;
	return 0;
}


DEFINE_DYNAMIC_FUNC0(Label_obj,getX,return )

int Label_obj::setX( double v){
	return 0;
}


DEFINE_DYNAMIC_FUNC1(Label_obj,setX,return )

double Label_obj::getY( ){
	return 0;
}


DEFINE_DYNAMIC_FUNC0(Label_obj,getY,return )

int Label_obj::setY( double v){
	return 0;
}


DEFINE_DYNAMIC_FUNC1(Label_obj,setY,return )


Label_obj::Label_obj()
{
	InitMember(text);
	InitMember(x);
	InitMember(y);
}

void Label_obj::__Mark()
{
	MarkMember(text);
	MarkMember(x);
	MarkMember(y);
}

Dynamic Label_obj::__Field(const String &inName)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"x",sizeof(wchar_t)*1) ) { return x; }
		if (!memcmp(inName.__s,L"y",sizeof(wchar_t)*1) ) { return y; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"text",sizeof(wchar_t)*4) ) { return text; }
		if (!memcmp(inName.__s,L"getX",sizeof(wchar_t)*4) ) { return getX_dyn(); }
		if (!memcmp(inName.__s,L"setX",sizeof(wchar_t)*4) ) { return setX_dyn(); }
		if (!memcmp(inName.__s,L"getY",sizeof(wchar_t)*4) ) { return getY_dyn(); }
		if (!memcmp(inName.__s,L"setY",sizeof(wchar_t)*4) ) { return setY_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"getText",sizeof(wchar_t)*7) ) { return getText_dyn(); }
		if (!memcmp(inName.__s,L"setText",sizeof(wchar_t)*7) ) { return setText_dyn(); }
	}
	return super::__Field(inName);
}

static int __id_text = __hxcpp_field_to_id("text");
static int __id_x = __hxcpp_field_to_id("x");
static int __id_y = __hxcpp_field_to_id("y");
static int __id_getText = __hxcpp_field_to_id("getText");
static int __id_setText = __hxcpp_field_to_id("setText");
static int __id_getX = __hxcpp_field_to_id("getX");
static int __id_setX = __hxcpp_field_to_id("setX");
static int __id_getY = __hxcpp_field_to_id("getY");
static int __id_setY = __hxcpp_field_to_id("setY");


Dynamic Label_obj::__IField(int inFieldID)
{
	if (inFieldID==__id_text) return text;
	if (inFieldID==__id_x) return x;
	if (inFieldID==__id_y) return y;
	if (inFieldID==__id_getText) return getText_dyn();
	if (inFieldID==__id_setText) return setText_dyn();
	if (inFieldID==__id_getX) return getX_dyn();
	if (inFieldID==__id_setX) return setX_dyn();
	if (inFieldID==__id_getY) return getY_dyn();
	if (inFieldID==__id_setY) return setY_dyn();
	return super::__IField(inFieldID);
}

Dynamic Label_obj::__SetField(const String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"x",sizeof(wchar_t)*1) ) { x=inValue.Cast<double >();return inValue; }
		if (!memcmp(inName.__s,L"y",sizeof(wchar_t)*1) ) { y=inValue.Cast<double >();return inValue; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"text",sizeof(wchar_t)*4) ) { text=inValue.Cast<String >();return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Label_obj::__GetFields(Array<String> &outFields)
{
	outFields->push(STRING(L"text",4));
	outFields->push(STRING(L"x",1));
	outFields->push(STRING(L"y",1));
	super::__GetFields(outFields);
};

static String sStaticFields[] = {
	String(null()) };

static String sMemberFields[] = {
	STRING(L"text",4),
	STRING(L"x",1),
	STRING(L"y",1),
	STRING(L"getText",7),
	STRING(L"setText",7),
	STRING(L"getX",4),
	STRING(L"setX",4),
	STRING(L"getY",4),
	STRING(L"setY",4),
	String(null()) };

static void sMarkStatics() {
};

Class Label_obj::__mClass;

void Label_obj::__register()
{
	Static(__mClass) = RegisterClass(STRING(L"pong.gfx.Label",14), TCanCast<Label_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Label_obj::__boot()
{
}

} // end namespace pong
} // end namespace gfx
