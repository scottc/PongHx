#include <hxObject.h>

#ifndef INCLUDED_pong_geom_Rectangle
#include <pong/geom/Rectangle.h>
#endif
namespace pong{
namespace geom{

Void Rectangle_obj::__construct(double x_,double y_,double width_,double height_)
{
{
	this->x = x_;
	this->y = y_;
	this->width = width_;
	this->height = height_;
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

bool Rectangle_obj::isOverlapping( pong::geom::Rectangle rect){
	if (bool(this->x < rect->x + rect->width) && bool(bool(this->x + this->width > rect->x) && bool(bool(this->y < rect->y + rect->height) && bool(this->y + this->height > rect->y))))
		return true;
	return false;
}


DEFINE_DYNAMIC_FUNC1(Rectangle_obj,isOverlapping,return )


Rectangle_obj::Rectangle_obj()
{
	InitMember(width);
	InitMember(height);
	InitMember(x);
	InitMember(y);
}

void Rectangle_obj::__Mark()
{
	MarkMember(width);
	MarkMember(height);
	MarkMember(x);
	MarkMember(y);
}

Dynamic Rectangle_obj::__Field(const String &inName)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"x",sizeof(wchar_t)*1) ) { return x; }
		if (!memcmp(inName.__s,L"y",sizeof(wchar_t)*1) ) { return y; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"width",sizeof(wchar_t)*5) ) { return width; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"height",sizeof(wchar_t)*6) ) { return height; }
		break;
	case 13:
		if (!memcmp(inName.__s,L"isOverlapping",sizeof(wchar_t)*13) ) { return isOverlapping_dyn(); }
	}
	return super::__Field(inName);
}

static int __id_width = __hxcpp_field_to_id("width");
static int __id_height = __hxcpp_field_to_id("height");
static int __id_x = __hxcpp_field_to_id("x");
static int __id_y = __hxcpp_field_to_id("y");
static int __id_isOverlapping = __hxcpp_field_to_id("isOverlapping");


Dynamic Rectangle_obj::__IField(int inFieldID)
{
	if (inFieldID==__id_width) return width;
	if (inFieldID==__id_height) return height;
	if (inFieldID==__id_x) return x;
	if (inFieldID==__id_y) return y;
	if (inFieldID==__id_isOverlapping) return isOverlapping_dyn();
	return super::__IField(inFieldID);
}

Dynamic Rectangle_obj::__SetField(const String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"x",sizeof(wchar_t)*1) ) { x=inValue.Cast<double >();return inValue; }
		if (!memcmp(inName.__s,L"y",sizeof(wchar_t)*1) ) { y=inValue.Cast<double >();return inValue; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"width",sizeof(wchar_t)*5) ) { width=inValue.Cast<double >();return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"height",sizeof(wchar_t)*6) ) { height=inValue.Cast<double >();return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Rectangle_obj::__GetFields(Array<String> &outFields)
{
	outFields->push(STRING(L"width",5));
	outFields->push(STRING(L"height",6));
	outFields->push(STRING(L"x",1));
	outFields->push(STRING(L"y",1));
	super::__GetFields(outFields);
};

static String sStaticFields[] = {
	String(null()) };

static String sMemberFields[] = {
	STRING(L"width",5),
	STRING(L"height",6),
	STRING(L"x",1),
	STRING(L"y",1),
	STRING(L"isOverlapping",13),
	String(null()) };

static void sMarkStatics() {
};

Class Rectangle_obj::__mClass;

void Rectangle_obj::__register()
{
	Static(__mClass) = RegisterClass(STRING(L"pong.geom.Rectangle",19), TCanCast<Rectangle_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Rectangle_obj::__boot()
{
}

} // end namespace pong
} // end namespace geom
