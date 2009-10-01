#include <hxObject.h>

#ifndef INCLUDED_pong_gfx_Stage
#include <pong/gfx/Stage.h>
#endif
namespace pong{
namespace gfx{

Void Stage_obj::__construct()
{
{
	this->drawBackground();
}
;
	return null();
}

Stage_obj::~Stage_obj() { }

Dynamic Stage_obj::__CreateEmpty() { return  new Stage_obj; }
hxObjectPtr<Stage_obj > Stage_obj::__new()
{  hxObjectPtr<Stage_obj > result = new Stage_obj();
	result->__construct();
	return result;}

Dynamic Stage_obj::__Create(DynamicArray inArgs)
{  hxObjectPtr<Stage_obj > result = new Stage_obj();
	result->__construct();
	return result;}

Void Stage_obj::add( Dynamic object){
{
	}
return null();
}


DEFINE_DYNAMIC_FUNC1(Stage_obj,add,(void))

Void Stage_obj::drawBackground( ){
{
	}
return null();
}


DEFINE_DYNAMIC_FUNC0(Stage_obj,drawBackground,(void))

int Stage_obj::width;

int Stage_obj::height;

pong::gfx::Stage Stage_obj::_instance;

pong::gfx::Stage Stage_obj::getInstance( ){
	if (pong::gfx::Stage_obj::_instance == null())
		pong::gfx::Stage_obj::_instance = pong::gfx::Stage_obj::__new();
	return pong::gfx::Stage_obj::_instance;
}


STATIC_DEFINE_DYNAMIC_FUNC0(Stage_obj,getInstance,return )

int Stage_obj::getWidth( ){
	return -1;
}


STATIC_DEFINE_DYNAMIC_FUNC0(Stage_obj,getWidth,return )

int Stage_obj::getHeight( ){
	return -1;
}


STATIC_DEFINE_DYNAMIC_FUNC0(Stage_obj,getHeight,return )


Stage_obj::Stage_obj()
{
}

void Stage_obj::__Mark()
{
}

Dynamic Stage_obj::__Field(const String &inName)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"add",sizeof(wchar_t)*3) ) { return add_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"width",sizeof(wchar_t)*5) ) { return width; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"height",sizeof(wchar_t)*6) ) { return height; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"getWidth",sizeof(wchar_t)*8) ) { return getWidth_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"_instance",sizeof(wchar_t)*9) ) { return _instance; }
		if (!memcmp(inName.__s,L"getHeight",sizeof(wchar_t)*9) ) { return getHeight_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"getInstance",sizeof(wchar_t)*11) ) { return getInstance_dyn(); }
		break;
	case 14:
		if (!memcmp(inName.__s,L"drawBackground",sizeof(wchar_t)*14) ) { return drawBackground_dyn(); }
	}
	return super::__Field(inName);
}

static int __id_width = __hxcpp_field_to_id("width");
static int __id_height = __hxcpp_field_to_id("height");
static int __id__instance = __hxcpp_field_to_id("_instance");
static int __id_getInstance = __hxcpp_field_to_id("getInstance");
static int __id_getWidth = __hxcpp_field_to_id("getWidth");
static int __id_getHeight = __hxcpp_field_to_id("getHeight");
static int __id_add = __hxcpp_field_to_id("add");
static int __id_drawBackground = __hxcpp_field_to_id("drawBackground");


Dynamic Stage_obj::__IField(int inFieldID)
{
	if (inFieldID==__id_width) return width;
	if (inFieldID==__id_height) return height;
	if (inFieldID==__id__instance) return _instance;
	if (inFieldID==__id_getInstance) return getInstance_dyn();
	if (inFieldID==__id_getWidth) return getWidth_dyn();
	if (inFieldID==__id_getHeight) return getHeight_dyn();
	if (inFieldID==__id_add) return add_dyn();
	if (inFieldID==__id_drawBackground) return drawBackground_dyn();
	return super::__IField(inFieldID);
}

Dynamic Stage_obj::__SetField(const String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (!memcmp(inName.__s,L"width",sizeof(wchar_t)*5) ) { width=inValue.Cast<int >();return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"height",sizeof(wchar_t)*6) ) { height=inValue.Cast<int >();return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"_instance",sizeof(wchar_t)*9) ) { _instance=inValue.Cast<pong::gfx::Stage >();return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Stage_obj::__GetFields(Array<String> &outFields)
{
	super::__GetFields(outFields);
};

static String sStaticFields[] = {
	STRING(L"width",5),
	STRING(L"height",6),
	STRING(L"_instance",9),
	STRING(L"getInstance",11),
	STRING(L"getWidth",8),
	STRING(L"getHeight",9),
	String(null()) };

static String sMemberFields[] = {
	STRING(L"add",3),
	STRING(L"drawBackground",14),
	String(null()) };

static void sMarkStatics() {
	MarkMember(Stage_obj::width);
	MarkMember(Stage_obj::height);
	MarkMember(Stage_obj::_instance);
};

Class Stage_obj::__mClass;

void Stage_obj::__register()
{
	Static(__mClass) = RegisterClass(STRING(L"pong.gfx.Stage",14), TCanCast<Stage_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Stage_obj::__boot()
{
	Static(width);
	Static(height);
	Static(_instance);
}

} // end namespace pong
} // end namespace gfx
