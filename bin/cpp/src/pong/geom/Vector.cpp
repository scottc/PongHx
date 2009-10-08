#include <hxObject.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
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

pong::geom::Vector Vector_obj::clone( ){
	return pong::geom::Vector_obj::__new(this->x,this->y);
}


DEFINE_DYNAMIC_FUNC0(Vector_obj,clone,return )

Void Vector_obj::set( double x_,double y_){
{
		this->x = x_;
		this->y = y_;
	}
return null();
}


DEFINE_DYNAMIC_FUNC2(Vector_obj,set,(void))

pong::geom::Vector Vector_obj::plus( pong::geom::Vector v){
	return pong::geom::Vector_obj::__new(this->x + v->x,this->y + v->y);
}


DEFINE_DYNAMIC_FUNC1(Vector_obj,plus,return )

pong::geom::Vector Vector_obj::minus( pong::geom::Vector v){
	return pong::geom::Vector_obj::__new(this->x - v->x,this->y - v->y);
}


DEFINE_DYNAMIC_FUNC1(Vector_obj,minus,return )

pong::geom::Vector Vector_obj::multiply( double n){
	return pong::geom::Vector_obj::__new(this->x * n,this->y * n);
}


DEFINE_DYNAMIC_FUNC1(Vector_obj,multiply,return )

double Vector_obj::dotProduct( pong::geom::Vector v){
	return this->x * v->x + this->y * v->y;
}


DEFINE_DYNAMIC_FUNC1(Vector_obj,dotProduct,return )

double Vector_obj::crossProduct( pong::geom::Vector v){
	return this->x * v->y - this->y * v->x;
}


DEFINE_DYNAMIC_FUNC1(Vector_obj,crossProduct,return )

double Vector_obj::length( ){
	return Math_obj::sqrt(this->x * this->x + this->y * this->y);
}


DEFINE_DYNAMIC_FUNC0(Vector_obj,length,return )

pong::geom::Vector Vector_obj::normalize( Dynamic __o_l){
double l = __o_l.Default(1);
{
		double d = Math_obj::sqrt(this->x * this->x + this->y * this->y);
		if (d == 0)
			return pong::geom::Vector_obj::__new(0,0);
		else
			return pong::geom::Vector_obj::__new(double(this->x) / double(d) * l,double(this->y) / double(d) * l);
;
	}
}


DEFINE_DYNAMIC_FUNC1(Vector_obj,normalize,return )


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
		break;
	case 3:
		if (!memcmp(inName.__s,L"set",sizeof(wchar_t)*3) ) { return set_dyn(); }
		break;
	case 4:
		if (!memcmp(inName.__s,L"plus",sizeof(wchar_t)*4) ) { return plus_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"clone",sizeof(wchar_t)*5) ) { return clone_dyn(); }
		if (!memcmp(inName.__s,L"minus",sizeof(wchar_t)*5) ) { return minus_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"length",sizeof(wchar_t)*6) ) { return length_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"multiply",sizeof(wchar_t)*8) ) { return multiply_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"normalize",sizeof(wchar_t)*9) ) { return normalize_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"dotProduct",sizeof(wchar_t)*10) ) { return dotProduct_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"crossProduct",sizeof(wchar_t)*12) ) { return crossProduct_dyn(); }
	}
	return super::__Field(inName);
}

static int __id_x = __hxcpp_field_to_id("x");
static int __id_y = __hxcpp_field_to_id("y");
static int __id_clone = __hxcpp_field_to_id("clone");
static int __id_set = __hxcpp_field_to_id("set");
static int __id_plus = __hxcpp_field_to_id("plus");
static int __id_minus = __hxcpp_field_to_id("minus");
static int __id_multiply = __hxcpp_field_to_id("multiply");
static int __id_dotProduct = __hxcpp_field_to_id("dotProduct");
static int __id_crossProduct = __hxcpp_field_to_id("crossProduct");
static int __id_length = __hxcpp_field_to_id("length");
static int __id_normalize = __hxcpp_field_to_id("normalize");


Dynamic Vector_obj::__IField(int inFieldID)
{
	if (inFieldID==__id_x) return x;
	if (inFieldID==__id_y) return y;
	if (inFieldID==__id_clone) return clone_dyn();
	if (inFieldID==__id_set) return set_dyn();
	if (inFieldID==__id_plus) return plus_dyn();
	if (inFieldID==__id_minus) return minus_dyn();
	if (inFieldID==__id_multiply) return multiply_dyn();
	if (inFieldID==__id_dotProduct) return dotProduct_dyn();
	if (inFieldID==__id_crossProduct) return crossProduct_dyn();
	if (inFieldID==__id_length) return length_dyn();
	if (inFieldID==__id_normalize) return normalize_dyn();
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
	STRING(L"clone",5),
	STRING(L"set",3),
	STRING(L"plus",4),
	STRING(L"minus",5),
	STRING(L"multiply",8),
	STRING(L"dotProduct",10),
	STRING(L"crossProduct",12),
	STRING(L"length",6),
	STRING(L"normalize",9),
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
