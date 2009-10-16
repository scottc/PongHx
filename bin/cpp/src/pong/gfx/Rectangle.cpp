#include <hxObject.h>

#ifndef INCLUDED_pong_gfx_IDisplayObject
#include <pong/gfx/IDisplayObject.h>
#endif
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

double Rectangle_obj::getX( ){
	return this->_x;
}


DEFINE_DYNAMIC_FUNC0(Rectangle_obj,getX,return )

double Rectangle_obj::getY( ){
	return this->_y;
}


DEFINE_DYNAMIC_FUNC0(Rectangle_obj,getY,return )

int Rectangle_obj::getColor( ){
	return this->_color;
}


DEFINE_DYNAMIC_FUNC0(Rectangle_obj,getColor,return )

double Rectangle_obj::getWidth( ){
	return this->_width;
}


DEFINE_DYNAMIC_FUNC0(Rectangle_obj,getWidth,return )

double Rectangle_obj::getHeight( ){
	return this->_height;
}


DEFINE_DYNAMIC_FUNC0(Rectangle_obj,getHeight,return )

double Rectangle_obj::setWidth( double v){
	this->_width = v;
	return v;
}


DEFINE_DYNAMIC_FUNC1(Rectangle_obj,setWidth,return )

double Rectangle_obj::setHeight( double v){
	this->_height = v;
	return v;
}


DEFINE_DYNAMIC_FUNC1(Rectangle_obj,setHeight,return )

int Rectangle_obj::setColor( int v){
	this->_color = v;
	return v;
}


DEFINE_DYNAMIC_FUNC1(Rectangle_obj,setColor,return )

int Rectangle_obj::setX( double v){
	return 0;
}


DEFINE_DYNAMIC_FUNC1(Rectangle_obj,setX,return )

int Rectangle_obj::setY( double v){
	return 0;
}


DEFINE_DYNAMIC_FUNC1(Rectangle_obj,setY,return )


Rectangle_obj::Rectangle_obj()
{
	InitMember(x);
	InitMember(y);
	InitMember(width);
	InitMember(height);
	InitMember(_color);
	InitMember(color);
	InitMember(_x);
	InitMember(_y);
	InitMember(_width);
	InitMember(_height);
}

void Rectangle_obj::__Mark()
{
	MarkMember(x);
	MarkMember(y);
	MarkMember(width);
	MarkMember(height);
	MarkMember(_color);
	MarkMember(color);
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
	case 4:
		if (!memcmp(inName.__s,L"getX",sizeof(wchar_t)*4) ) { return getX_dyn(); }
		if (!memcmp(inName.__s,L"getY",sizeof(wchar_t)*4) ) { return getY_dyn(); }
		if (!memcmp(inName.__s,L"setX",sizeof(wchar_t)*4) ) { return setX_dyn(); }
		if (!memcmp(inName.__s,L"setY",sizeof(wchar_t)*4) ) { return setY_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"width",sizeof(wchar_t)*5) ) { return width; }
		if (!memcmp(inName.__s,L"color",sizeof(wchar_t)*5) ) { return color; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"height",sizeof(wchar_t)*6) ) { return height; }
		if (!memcmp(inName.__s,L"_color",sizeof(wchar_t)*6) ) { return _color; }
		if (!memcmp(inName.__s,L"_width",sizeof(wchar_t)*6) ) { return _width; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"_height",sizeof(wchar_t)*7) ) { return _height; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"drawRect",sizeof(wchar_t)*8) ) { return drawRect_dyn(); }
		if (!memcmp(inName.__s,L"getColor",sizeof(wchar_t)*8) ) { return getColor_dyn(); }
		if (!memcmp(inName.__s,L"getWidth",sizeof(wchar_t)*8) ) { return getWidth_dyn(); }
		if (!memcmp(inName.__s,L"setWidth",sizeof(wchar_t)*8) ) { return setWidth_dyn(); }
		if (!memcmp(inName.__s,L"setColor",sizeof(wchar_t)*8) ) { return setColor_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"getHeight",sizeof(wchar_t)*9) ) { return getHeight_dyn(); }
		if (!memcmp(inName.__s,L"setHeight",sizeof(wchar_t)*9) ) { return setHeight_dyn(); }
	}
	return super::__Field(inName);
}

static int __id_x = __hxcpp_field_to_id("x");
static int __id_y = __hxcpp_field_to_id("y");
static int __id_width = __hxcpp_field_to_id("width");
static int __id_height = __hxcpp_field_to_id("height");
static int __id__color = __hxcpp_field_to_id("_color");
static int __id_color = __hxcpp_field_to_id("color");
static int __id__x = __hxcpp_field_to_id("_x");
static int __id__y = __hxcpp_field_to_id("_y");
static int __id__width = __hxcpp_field_to_id("_width");
static int __id__height = __hxcpp_field_to_id("_height");
static int __id_drawRect = __hxcpp_field_to_id("drawRect");
static int __id_getX = __hxcpp_field_to_id("getX");
static int __id_getY = __hxcpp_field_to_id("getY");
static int __id_getColor = __hxcpp_field_to_id("getColor");
static int __id_getWidth = __hxcpp_field_to_id("getWidth");
static int __id_getHeight = __hxcpp_field_to_id("getHeight");
static int __id_setWidth = __hxcpp_field_to_id("setWidth");
static int __id_setHeight = __hxcpp_field_to_id("setHeight");
static int __id_setColor = __hxcpp_field_to_id("setColor");
static int __id_setX = __hxcpp_field_to_id("setX");
static int __id_setY = __hxcpp_field_to_id("setY");


Dynamic Rectangle_obj::__IField(int inFieldID)
{
	if (inFieldID==__id_x) return x;
	if (inFieldID==__id_y) return y;
	if (inFieldID==__id_width) return width;
	if (inFieldID==__id_height) return height;
	if (inFieldID==__id__color) return _color;
	if (inFieldID==__id_color) return color;
	if (inFieldID==__id__x) return _x;
	if (inFieldID==__id__y) return _y;
	if (inFieldID==__id__width) return _width;
	if (inFieldID==__id__height) return _height;
	if (inFieldID==__id_drawRect) return drawRect_dyn();
	if (inFieldID==__id_getX) return getX_dyn();
	if (inFieldID==__id_getY) return getY_dyn();
	if (inFieldID==__id_getColor) return getColor_dyn();
	if (inFieldID==__id_getWidth) return getWidth_dyn();
	if (inFieldID==__id_getHeight) return getHeight_dyn();
	if (inFieldID==__id_setWidth) return setWidth_dyn();
	if (inFieldID==__id_setHeight) return setHeight_dyn();
	if (inFieldID==__id_setColor) return setColor_dyn();
	if (inFieldID==__id_setX) return setX_dyn();
	if (inFieldID==__id_setY) return setY_dyn();
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
	case 5:
		if (!memcmp(inName.__s,L"width",sizeof(wchar_t)*5) ) { width=inValue.Cast<double >();return inValue; }
		if (!memcmp(inName.__s,L"color",sizeof(wchar_t)*5) ) { color=inValue.Cast<int >();return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"height",sizeof(wchar_t)*6) ) { height=inValue.Cast<double >();return inValue; }
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
	outFields->push(STRING(L"width",5));
	outFields->push(STRING(L"height",6));
	outFields->push(STRING(L"_color",6));
	outFields->push(STRING(L"color",5));
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
	STRING(L"width",5),
	STRING(L"height",6),
	STRING(L"_color",6),
	STRING(L"color",5),
	STRING(L"_x",2),
	STRING(L"_y",2),
	STRING(L"_width",6),
	STRING(L"_height",7),
	STRING(L"drawRect",8),
	STRING(L"getX",4),
	STRING(L"getY",4),
	STRING(L"getColor",8),
	STRING(L"getWidth",8),
	STRING(L"getHeight",9),
	STRING(L"setWidth",8),
	STRING(L"setHeight",9),
	STRING(L"setColor",8),
	STRING(L"setX",4),
	STRING(L"setY",4),
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
