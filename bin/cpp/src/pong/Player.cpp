#include <hxObject.h>

#ifndef INCLUDED_pong_Player
#include <pong/Player.h>
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

Void Player_obj::__construct(int x_,int y_,int width_,int height_)
{
{
	super::__construct(x_,y_,width_,height_);
	this->sprite = pong::gfx::Rectangle_obj::__new(x_,y_,width_,height_);
	this->velocity = pong::geom::Vector_obj::__new(0,0);
	this->score = 0;
	this->ai = true;
}
;
	return null();
}

Player_obj::~Player_obj() { }

Dynamic Player_obj::__CreateEmpty() { return  new Player_obj; }
hxObjectPtr<Player_obj > Player_obj::__new(int x_,int y_,int width_,int height_)
{  hxObjectPtr<Player_obj > result = new Player_obj();
	result->__construct(x_,y_,width_,height_);
	return result;}

Dynamic Player_obj::__Create(DynamicArray inArgs)
{  hxObjectPtr<Player_obj > result = new Player_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Void Player_obj::render( ){
{
		this->sprite->x = this->x;
		this->sprite->y = this->y;
	}
return null();
}


DEFINE_DYNAMIC_FUNC0(Player_obj,render,(void))

Void Player_obj::move( ){
{
		hxAddEq(this->x,this->velocity->x);
		hxAddEq(this->y,this->velocity->y);
	}
return null();
}


DEFINE_DYNAMIC_FUNC0(Player_obj,move,(void))


Player_obj::Player_obj()
{
	InitMember(sprite);
	InitMember(score);
	InitMember(ai);
	InitMember(velocity);
}

void Player_obj::__Mark()
{
	MarkMember(sprite);
	MarkMember(score);
	MarkMember(ai);
	MarkMember(velocity);
	super::__Mark();
}

Dynamic Player_obj::__Field(const String &inName)
{
	switch(inName.length) {
	case 2:
		if (!memcmp(inName.__s,L"ai",sizeof(wchar_t)*2) ) { return ai; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"move",sizeof(wchar_t)*4) ) { return move_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"score",sizeof(wchar_t)*5) ) { return score; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"sprite",sizeof(wchar_t)*6) ) { return sprite; }
		if (!memcmp(inName.__s,L"render",sizeof(wchar_t)*6) ) { return render_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"velocity",sizeof(wchar_t)*8) ) { return velocity; }
	}
	return super::__Field(inName);
}

static int __id_sprite = __hxcpp_field_to_id("sprite");
static int __id_score = __hxcpp_field_to_id("score");
static int __id_ai = __hxcpp_field_to_id("ai");
static int __id_velocity = __hxcpp_field_to_id("velocity");
static int __id_render = __hxcpp_field_to_id("render");
static int __id_move = __hxcpp_field_to_id("move");


Dynamic Player_obj::__IField(int inFieldID)
{
	if (inFieldID==__id_sprite) return sprite;
	if (inFieldID==__id_score) return score;
	if (inFieldID==__id_ai) return ai;
	if (inFieldID==__id_velocity) return velocity;
	if (inFieldID==__id_render) return render_dyn();
	if (inFieldID==__id_move) return move_dyn();
	return super::__IField(inFieldID);
}

Dynamic Player_obj::__SetField(const String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 2:
		if (!memcmp(inName.__s,L"ai",sizeof(wchar_t)*2) ) { ai=inValue.Cast<bool >();return inValue; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"score",sizeof(wchar_t)*5) ) { score=inValue.Cast<int >();return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"sprite",sizeof(wchar_t)*6) ) { sprite=inValue.Cast<pong::gfx::Rectangle >();return inValue; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"velocity",sizeof(wchar_t)*8) ) { velocity=inValue.Cast<pong::geom::Vector >();return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Player_obj::__GetFields(Array<String> &outFields)
{
	outFields->push(STRING(L"sprite",6));
	outFields->push(STRING(L"score",5));
	outFields->push(STRING(L"ai",2));
	outFields->push(STRING(L"velocity",8));
	super::__GetFields(outFields);
};

static String sStaticFields[] = {
	String(null()) };

static String sMemberFields[] = {
	STRING(L"sprite",6),
	STRING(L"score",5),
	STRING(L"ai",2),
	STRING(L"velocity",8),
	STRING(L"render",6),
	STRING(L"move",4),
	String(null()) };

static void sMarkStatics() {
};

Class Player_obj::__mClass;

void Player_obj::__register()
{
	Static(__mClass) = RegisterClass(STRING(L"pong.Player",11), TCanCast<Player_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Player_obj::__boot()
{
}

} // end namespace pong
