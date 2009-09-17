#include <hxObject.h>

#ifndef INCLUDED_pong_geom_Vector
#include <pong/geom/Vector.h>
#endif
namespace pong{
namespace geom{

Void Vector_obj::__construct(double x_,double y_)
{
{
	this->x = x_;
	this->y = y_;
}
;
	return null();
}

Vector_obj::~Vector_obj() { }

Dynamic Vector_obj::__CreateEmpty() { return  new Vector_obj; }
hxObjectPtr<Vector_obj > Vector_obj::__new(double x_,double y_)
{  hxObjectPtr<Vector_obj > result = new Vector_obj();
	result->__construct(x_,y_);
	return result;}

Dynamic Vector_obj::__Create(DynamicArray inArgs)
{  hxObjectPtr<Vector_obj > result = new Vector_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}


Vector_obj::Vector_obj()
{
	InitMember(x);
	InitMember(y);
}

void Vector_obj::__Mark()
{
	MarkMember(x);
	MarkMember(y);
}

Dynamic Vector_obj::__Field(const String &inName)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"x",sizeof(wchar_t)*1) ) { return x; }
		if (!memcmp(inName.__s,L"y",sizeof(wchar_t)*1) ) { return y; }
	}
	return super::__Field(inName);
}

static int __id_x = __hxcpp_field_to_id("x");
static int __id_y = __hxcpp_field_to_id("y");


Dynamic Vector_obj::__IField(int inFieldID)
{
	if (inFieldID==__id_x) return x;
	if (inFieldID==__id_y) return y;
	return super::__IField(inFieldID);
}

Dynamic Vector_obj::__SetField(const String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 1:
		if (!memcmp(inName.__s,L"x",sizeof(wchar_t)*1) ) { x=inValue.Cast<double >();return inValue; }
		if (!memcmp(inName.__s,L"y",sizeof(wchar_t)*1) ) { y=inValue.Cast<double >();return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Vector_obj::__GetFields(Array<String> &outFields)
{
	outFields->push(STRING(L"x",1));
	outFields->push(STRING(L"y",1));
	super::__GetFields(outFields);
};

static String sStaticFields[] = {
	String(null()) };

static String sMemberFields[] = {
	STRING(L"x",1),
	STRING(L"y",1),
	String(null()) };

static void sMarkStatics() {
};

Class Vector_obj::__mClass;

void Vector_obj::__register()
{
	Static(__mClass) = RegisterClass(STRING(L"pong.geom.Vector",16), TCanCast<Vector_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Vector_obj::__boot()
{
}

} // end namespace pong
} // end namespace geom
