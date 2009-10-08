#include <hxObject.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_pong_Ball
#include <pong/Ball.h>
#endif
#ifndef INCLUDED_pong_geom_Rectangle
#include <pong/geom/Rectangle.h>
#endif
#ifndef INCLUDED_pong_geom_Vector
#include <pong/geom/Vector.h>
#endif
#ifndef INCLUDED_pong_gfx_Rectangle
#include <pong/gfx/Rectangle.h>
#endif
namespace pong{

Void Ball_obj::__construct(double x_,double y_,double width_,double height_)
{
{
	super::__construct(x_,y_,width_,height_);
	this->sprite = pong::gfx::Rectangle_obj::__new(x_,y_,width_,height_);
	this->velocity = pong::geom::Vector_obj::__new(0,0);
	this->acceleration = 0;
}
;
	return null();
}

Ball_obj::~Ball_obj() { }

Dynamic Ball_obj::__CreateEmpty() { return  new Ball_obj; }
hxObjectPtr<Ball_obj > Ball_obj::__new(double x_,double y_,double width_,double height_)
{  hxObjectPtr<Ball_obj > result = new Ball_obj();
	result->__construct(x_,y_,width_,height_);
	return result;}

Dynamic Ball_obj::__Create(DynamicArray inArgs)
{  hxObjectPtr<Ball_obj > result = new Ball_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Void Ball_obj::render( ){
{
		this->sprite->x = this->x;
		this->sprite->y = this->y;
	}
return null();
}


DEFINE_DYNAMIC_FUNC0(Ball_obj,render,(void))

Void Ball_obj::move( ){
{
		{
			pong::geom::Vector _g = this->velocity;
			double l = 1 + this->acceleration;
			double d = Math_obj::sqrt(_g->x * _g->x + _g->y * _g->y);
			if (d == 0)
				pong::geom::Vector_obj::__new(0,0);
			else
				pong::geom::Vector_obj::__new(double(_g->x) / double(d) * l,double(_g->y) / double(d) * l);
;
		}
		hxAddEq(this->x,this->velocity->x);
		hxAddEq(this->y,this->velocity->y);
	}
return null();
}


DEFINE_DYNAMIC_FUNC0(Ball_obj,move,(void))


Ball_obj::Ball_obj()
{
	InitMember(sprite);
	InitMember(velocity);
	InitMember(acceleration);
}

void Ball_obj::__Mark()
{
	MarkMember(sprite);
	MarkMember(velocity);
	MarkMember(acceleration);
	super::__Mark();
}

Dynamic Ball_obj::__Field(const String &inName)
{
	switch(inName.length) {
	case 4:
		if (!memcmp(inName.__s,L"move",sizeof(wchar_t)*4) ) { return move_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"sprite",sizeof(wchar_t)*6) ) { return sprite; }
		if (!memcmp(inName.__s,L"render",sizeof(wchar_t)*6) ) { return render_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"velocity",sizeof(wchar_t)*8) ) { return velocity; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"acceleration",sizeof(wchar_t)*12) ) { return acceleration; }
	}
	return super::__Field(inName);
}

static int __id_sprite = __hxcpp_field_to_id("sprite");
static int __id_velocity = __hxcpp_field_to_id("velocity");
static int __id_acceleration = __hxcpp_field_to_id("acceleration");
static int __id_render = __hxcpp_field_to_id("render");
static int __id_move = __hxcpp_field_to_id("move");


Dynamic Ball_obj::__IField(int inFieldID)
{
	if (inFieldID==__id_sprite) return sprite;
	if (inFieldID==__id_velocity) return velocity;
	if (inFieldID==__id_acceleration) return acceleration;
	if (inFieldID==__id_render) return render_dyn();
	if (inFieldID==__id_move) return move_dyn();
	return super::__IField(inFieldID);
}

Dynamic Ball_obj::__SetField(const String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 6:
		if (!memcmp(inName.__s,L"sprite",sizeof(wchar_t)*6) ) { sprite=inValue.Cast<pong::gfx::Rectangle >();return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"velocity",sizeof(wchar_t)*8) ) { velocity=inValue.Cast<pong::geom::Vector >();return inValue; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"acceleration",sizeof(wchar_t)*12) ) { acceleration=inValue.Cast<double >();return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Ball_obj::__GetFields(Array<String> &outFields)
{
	outFields->push(STRING(L"sprite",6));
	outFields->push(STRING(L"velocity",8));
	outFields->push(STRING(L"acceleration",12));
	super::__GetFields(outFields);
};

static String sStaticFields[] = {
	String(null()) };

static String sMemberFields[] = {
	STRING(L"sprite",6),
	STRING(L"velocity",8),
	STRING(L"acceleration",12),
	STRING(L"render",6),
	STRING(L"move",4),
	String(null()) };

static void sMarkStatics() {
};

Class Ball_obj::__mClass;

void Ball_obj::__register()
{
	Static(__mClass) = RegisterClass(STRING(L"pong.Ball",9), TCanCast<Ball_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Ball_obj::__boot()
{
}

} // end namespace pong
