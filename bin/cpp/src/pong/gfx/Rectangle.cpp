#include <hxObject.h>

#ifndef INCLUDED_pong_gfx_Rectangle
#include <pong/gfx/Rectangle.h>
#endif
namespace pong{
namespace gfx{

Void Rectangle_obj::__construct(double x_,double y_,double width_,double height_)
{
{
	this->_color = 16777215;
	this->_x = x_;
	this->_y = y_;
	this->_width = width_;
	this->_height = height_;
}
;
	return null();
}

Rectangle_obj::~Rectangle_obj() { }

Dynamic Rectangle_obj::__CreateEmpty() { return  new Rectangle_obj; }
hxObjectPtr<Rectangle_obj > Rectangle_obj::__new(double x_,double y_,double width_,double height_)
{  hxObjectPtr<Rectangle_obj > result = new Rectangle_obj();
	result->__construct(x_,y_,width_,height_);
	return result;}

Dynamic Rectangle_obj::__Create(DynamicArray inArgs)
{  hxObjectPtr<Rectangle_obj > result = new Rectangle_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Void Rectangle_obj::drawRect( ){
{
	}
return null();
}


DEFINE_DYNAMIC_FUNC0(Rectangle_obj,drawRect,(void))


Rectangle_obj::Rectangle_obj()
{
	InitMember(x);
	InitMember(y);
	InitMember(_color);
	InitMember(_x);
	InitMember(_y);
	InitMember(_width);
	InitMember(_height);
}

void Rectangle_obj::__Mark()
{
	MarkMember(x);
	MarkMember(y);
	MarkMember(_color);
	MarkMember(_x);
	MarkMember(_y);
	MarkMember(_width);
	MarkMember(_height);
}

Dynamic Rectangle_obj::__Field(const String &inName)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"x",sizeof(wchar_t)*1) ) { return x; }
		if (!memcmp(inName.__s,L"y",sizeof(wchar_t)*1) ) { return y; }
		break;
	case 2:
		if (!memcmp(inName.__s,L"_x",sizeof(wchar_t)*2) ) { return _x; }
		if (!memcmp(inName.__s,L"_y",sizeof(wchar_t)*2) ) { return _y; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"_color",sizeof(wchar_t)*6) ) { return _color; }
		if (!memcmp(inName.__s,L"_width",sizeof(wchar_t)*6) ) { return _width; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"_height",sizeof(wchar_t)*7) ) { return _height; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"drawRect",sizeof(wchar_t)*8) ) { return drawRect_dyn(); }
	}
	return super::__Field(inName);
}

static int __id_x = __hxcpp_field_to_id("x");
static int __id_y = __hxcpp_field_to_id("y");
static int __id__color = __hxcpp_field_to_id("_color");
static int __id__x = __hxcpp_field_to_id("_x");
static int __id__y = __hxcpp_field_to_id("_y");
static int __id__width = __hxcpp_field_to_id("_width");
static int __id__height = __hxcpp_field_to_id("_height");
static int __id_drawRect = __hxcpp_field_to_id("drawRect");


Dynamic Rectangle_obj::__IField(int inFieldID)
{
	if (inFieldID==__id_x) return x;
	if (inFieldID==__id_y) return y;
	if (inFieldID==__id__color) return _color;
	if (inFieldID==__id__x) return _x;
	if (inFieldID==__id__y) return _y;
	if (inFieldID==__id__width) return _width;
	if (inFieldID==__id__height) return _height;
	if (inFieldID==__id_drawRect) return drawRect_dyn();
	return super::__IField(inFieldID);
}

Dynamic Rectangle_obj::__SetField(const String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"x",sizeof(wchar_t)*1) ) { x=inValue.Cast<double >();return inValue; }
		if (!memcmp(inName.__s,L"y",sizeof(wchar_t)*1) ) { y=inValue.Cast<double >();return inValue; }
		break;
	case 2:
		if (!memcmp(inName.__s,L"_x",sizeof(wchar_t)*2) ) { _x=inValue.Cast<double >();return inValue; }
		if (!memcmp(inName.__s,L"_y",sizeof(wchar_t)*2) ) { _y=inValue.Cast<double >();return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"_color",sizeof(wchar_t)*6) ) { _color=inValue.Cast<int >();return inValue; }
		if (!memcmp(inName.__s,L"_width",sizeof(wchar_t)*6) ) { _width=inValue.Cast<double >();return inValue; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"_height",sizeof(wchar_t)*7) ) { _height=inValue.Cast<double >();return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Rectangle_obj::__GetFields(Array<String> &outFields)
{
	outFields->push(STRING(L"x",1));
	outFields->push(STRING(L"y",1));
	outFields->push(STRING(L"_color",6));
	outFields->push(STRING(L"_x",2));
	outFields->push(STRING(L"_y",2));
	outFields->push(STRING(L"_width",6));
	outFields->push(STRING(L"_height",7));
	super::__GetFields(outFields);
};

static String sStaticFields[] = {
	String(null()) };

static String sMemberFields[] = {
	STRING(L"x",1),
	STRING(L"y",1),
	STRING(L"_color",6),
	STRING(L"_x",2),
	STRING(L"_y",2),
	STRING(L"_width",6),
	STRING(L"_height",7),
	STRING(L"drawRect",8),
	String(null()) };

static void sMarkStatics() {
};

Class Rectangle_obj::__mClass;

void Rectangle_obj::__register()
{
	Static(__mClass) = RegisterClass(STRING(L"pong.gfx.Rectangle",18), TCanCast<Rectangle_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Rectangle_obj::__boot()
{
}

} // end namespace pong
} // end namespace gfx
