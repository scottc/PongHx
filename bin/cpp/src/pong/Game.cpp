#include <hxObject.h>

#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_haxe_Timer
#include <haxe/Timer.h>
#endif
#ifndef INCLUDED_pong_Ball
#include <pong/Ball.h>
#endif
#ifndef INCLUDED_pong_Game
#include <pong/Game.h>
#endif
#ifndef INCLUDED_pong_Paddle
#include <pong/Paddle.h>
#endif
#ifndef INCLUDED_pong_geom_Rectangle
#include <pong/geom/Rectangle.h>
#endif
#ifndef INCLUDED_pong_geom_Vector
#include <pong/geom/Vector.h>
#endif
#ifndef INCLUDED_pong_gfx_Label
#include <pong/gfx/Label.h>
#endif
#ifndef INCLUDED_pong_gfx_Rectangle
#include <pong/gfx/Rectangle.h>
#endif
#ifndef INCLUDED_pong_gfx_Stage
#include <pong/gfx/Stage.h>
#endif
#ifndef INCLUDED_pong_ui_Mouse
#include <pong/ui/Mouse.h>
#endif
namespace pong{

Void Game_obj::__construct()
{
{
	this->_physicsTicker = haxe::Timer_obj::__new(25);
	this->_physicsTicker->run = this->physicsStep_dyn();
	this->_graphicsTicker = haxe::Timer_obj::__new(25);
	this->_graphicsTicker->run = this->render_dyn();
	this->setupStage();
	this->newRound();
}
;
	return null();
}

Game_obj::~Game_obj() { }

Dynamic Game_obj::__CreateEmpty() { return  new Game_obj; }
hxObjectPtr<Game_obj > Game_obj::__new()
{  hxObjectPtr<Game_obj > result = new Game_obj();
	result->__construct();
	return result;}

Dynamic Game_obj::__Create(DynamicArray inArgs)
{  hxObjectPtr<Game_obj > result = new Game_obj();
	result->__construct();
	return result;}

Void Game_obj::setupStage( ){
{
		this->_stage = pong::gfx::Stage_obj::getInstance();
		this->_ball = pong::Ball_obj::__new(150,50,pong::gfx::Stage_obj::getWidth() * 0.02,pong::gfx::Stage_obj::getWidth() * 0.02);
		this->_leftPaddle = pong::Paddle_obj::__new(pong::gfx::Stage_obj::getWidth() * 0.05,50,pong::gfx::Stage_obj::getWidth() * 0.02,pong::gfx::Stage_obj::getHeight() * 0.15);
		this->_rightPaddle = pong::Paddle_obj::__new(pong::gfx::Stage_obj::getWidth() * 0.95,50,pong::gfx::Stage_obj::getWidth() * 0.02,pong::gfx::Stage_obj::getHeight() * 0.15);
		this->_rightPaddle->ai = true;
		this->_stage->add(this->_ball->sprite);
		this->_stage->add(this->_leftPaddle->sprite);
		this->_stage->add(this->_rightPaddle->sprite);
		this->_leftScoreLabel = pong::gfx::Label_obj::__new();
		this->_leftScoreLabel->text = STRING(L"0",1);
		this->_leftScoreLabel->y = 10;
		this->_leftScoreLabel->x = pong::gfx::Stage_obj::getWidth() * 0.5 - 20;
		this->_rightScoreLabel = pong::gfx::Label_obj::__new();
		this->_rightScoreLabel->text = STRING(L"0",1);
		this->_rightScoreLabel->y = 10;
		this->_rightScoreLabel->x = pong::gfx::Stage_obj::getWidth() * 0.5 + 10;
		this->_stage->add(this->_leftScoreLabel);
		this->_stage->add(this->_rightScoreLabel);
	}
return null();
}


DEFINE_DYNAMIC_FUNC0(Game_obj,setupStage,(void))

Void Game_obj::newRound( ){
{
		this->_ball->acceleration = 0.0001;
		this->_ball->velocity->x = pong::gfx::Stage_obj::getWidth() * Math_obj::random() - pong::gfx::Stage_obj::getWidth() * 0.5;
		this->_ball->velocity->y = pong::gfx::Stage_obj::getHeight() * Math_obj::random() - pong::gfx::Stage_obj::getHeight() * 0.5;
		struct _Function_1{
			static pong::geom::Vector Block( pong::Game_obj *__this)/* DEF (ret block)(not intern) */{
				pong::geom::Vector _g = __this->_ball->velocity;
				double l = pong::gfx::Stage_obj::getWidth() * 0.01;
				double d = Math_obj::sqrt(_g->x * _g->x + _g->y * _g->y);
				return d == 0 ? Void( pong::geom::Vector_obj::__new(0,0) ) : Void( pong::geom::Vector_obj::__new(double(_g->x) / double(d) * l,double(_g->y) / double(d) * l) );
			}
		};
		this->_ball->velocity = _Function_1::Block(this);
		this->_leftPaddle->y = double(pong::gfx::Stage_obj::getHeight()) / double(2) - double(this->_leftPaddle->height) / double(2);
		this->_rightPaddle->y = double(pong::gfx::Stage_obj::getHeight()) / double(2) - double(this->_rightPaddle->height) / double(2);
		this->_ball->y = double(pong::gfx::Stage_obj::getHeight()) / double(2) - double(this->_ball->height) / double(2);
		this->_ball->x = double(pong::gfx::Stage_obj::getWidth()) / double(2) - double(this->_ball->width) / double(2);
	}
return null();
}


DEFINE_DYNAMIC_FUNC0(Game_obj,newRound,(void))

Void Game_obj::runAI( pong::Paddle p){
{
		if (p->y + double(p->height) / double(2) < this->_ball->y + double(this->_ball->height) / double(2))
			p->velocity->y = pong::gfx::Stage_obj::getHeight() * 0.01;
		else
			if (p->y + double(p->height) / double(2) > this->_ball->y + double(this->_ball->height) / double(2))
			p->velocity->y = pong::gfx::Stage_obj::getHeight() * -0.01;
		else
			p->velocity->y = 0;
;
;
	}
return null();
}


DEFINE_DYNAMIC_FUNC1(Game_obj,runAI,(void))

Void Game_obj::doCollisions( ){
{
		if (this->_leftPaddle->y + this->_leftPaddle->height > pong::gfx::Stage_obj::getHeight() - 10){
			this->_leftPaddle->y = pong::gfx::Stage_obj::getHeight() - this->_leftPaddle->height - 10;
		}
		if (this->_leftPaddle->y < 10){
			this->_leftPaddle->y = 10;
		}
		if (this->_rightPaddle->y + this->_rightPaddle->height > pong::gfx::Stage_obj::getHeight() - 10){
			this->_rightPaddle->y = pong::gfx::Stage_obj::getHeight() - this->_rightPaddle->height - 10;
		}
		if (this->_rightPaddle->y < 10){
			this->_rightPaddle->y = 10;
		}
		if (this->_ball->y + this->_ball->height > pong::gfx::Stage_obj::getHeight() - 10){
			this->_ball->y = pong::gfx::Stage_obj::getHeight() - this->_ball->height - 10;
			hxMultEq(this->_ball->velocity->y,-1);
		}
		if (this->_ball->y < 10){
			this->_ball->y = 10;
			hxMultEq(this->_ball->velocity->y,-1);
		}
		if (this->_ball->x < 0 - this->_ball->width){
			this->_rightScoreLabel->text = Std_obj::string(++this->_rightPaddle->score);
			this->newRound();
		}
		if (this->_ball->x > pong::gfx::Stage_obj::getWidth()){
			this->_leftScoreLabel->text = Std_obj::string(++this->_leftPaddle->score);
			this->newRound();
		}
		this->ballPaddleCollision(this->_leftPaddle);
		this->ballPaddleCollision(this->_rightPaddle);
	}
return null();
}


DEFINE_DYNAMIC_FUNC0(Game_obj,doCollisions,(void))

Void Game_obj::ballPaddleCollision( pong::Paddle p){
{
		if (this->_ball->isOverlapping(p)){
			pong::geom::Vector newDirection = pong::geom::Vector_obj::__new((this->_ball->x + this->_ball->width * 0.5) - (p->x + p->width * 0.5),(this->_ball->y + this->_ball->height * 0.5) - (p->y + p->height * 0.5));
			struct _Function_1{
				static pong::geom::Vector Block( pong::Game_obj *__this,pong::geom::Vector &newDirection)/* DEF (ret block)(not intern) */{
					struct _Function_2{
						static double Block( pong::Game_obj *__this)/* DEF (ret block)(not intern) */{
							pong::geom::Vector _g = __this->_ball->velocity;
							return Math_obj::sqrt(_g->x * _g->x + _g->y * _g->y);
						}
					};
					double l = _Function_2::Block(__this);
					double d = Math_obj::sqrt(newDirection->x * newDirection->x + newDirection->y * newDirection->y);
					return d == 0 ? Void( pong::geom::Vector_obj::__new(0,0) ) : Void( pong::geom::Vector_obj::__new(double(newDirection->x) / double(d) * l,double(newDirection->y) / double(d) * l) );
				}
			};
			this->_ball->velocity = _Function_1::Block(this,newDirection);
		}
	}
return null();
}


DEFINE_DYNAMIC_FUNC1(Game_obj,ballPaddleCollision,(void))

Void Game_obj::physicsStep( ){
{
		if (!this->_leftPaddle->ai){
			this->_leftPaddle->y = pong::ui::Mouse_obj::y - double(this->_leftPaddle->height) / double(2);
		}
		else
			if (this->_ball->velocity->x < 0)
			this->runAI(this->_leftPaddle);
		else
			this->_leftPaddle->velocity->y = 0;
;
;
		if (!this->_rightPaddle->ai){
			this->_rightPaddle->y = pong::ui::Mouse_obj::y - double(this->_rightPaddle->height) / double(2);
		}
		else
			if (this->_ball->velocity->x > 0)
			this->runAI(this->_rightPaddle);
		else
			this->_rightPaddle->velocity->y = 0;
;
;
		this->_leftPaddle->move();
		this->_rightPaddle->move();
		this->_ball->move();
		this->doCollisions();
	}
return null();
}


DEFINE_DYNAMIC_FUNC0(Game_obj,physicsStep,(void))

Void Game_obj::render( ){
{
		this->_ball->render();
		this->_leftPaddle->render();
		this->_rightPaddle->render();
	}
return null();
}


DEFINE_DYNAMIC_FUNC0(Game_obj,render,(void))


Game_obj::Game_obj()
{
	InitMember(_graphicsTicker);
	InitMember(_physicsTicker);
	InitMember(_stage);
	InitMember(_ball);
	InitMember(_leftPaddle);
	InitMember(_rightPaddle);
	InitMember(_leftScoreLabel);
	InitMember(_rightScoreLabel);
	InitMember(_id);
}

void Game_obj::__Mark()
{
	MarkMember(_graphicsTicker);
	MarkMember(_physicsTicker);
	MarkMember(_stage);
	MarkMember(_ball);
	MarkMember(_leftPaddle);
	MarkMember(_rightPaddle);
	MarkMember(_leftScoreLabel);
	MarkMember(_rightScoreLabel);
	MarkMember(_id);
}

Dynamic Game_obj::__Field(const String &inName)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"_id",sizeof(wchar_t)*3) ) { return _id; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"_ball",sizeof(wchar_t)*5) ) { return _ball; }
		if (!memcmp(inName.__s,L"runAI",sizeof(wchar_t)*5) ) { return runAI_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"_stage",sizeof(wchar_t)*6) ) { return _stage; }
		if (!memcmp(inName.__s,L"render",sizeof(wchar_t)*6) ) { return render_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"newRound",sizeof(wchar_t)*8) ) { return newRound_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"setupStage",sizeof(wchar_t)*10) ) { return setupStage_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"_leftPaddle",sizeof(wchar_t)*11) ) { return _leftPaddle; }
		if (!memcmp(inName.__s,L"physicsStep",sizeof(wchar_t)*11) ) { return physicsStep_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"_rightPaddle",sizeof(wchar_t)*12) ) { return _rightPaddle; }
		if (!memcmp(inName.__s,L"doCollisions",sizeof(wchar_t)*12) ) { return doCollisions_dyn(); }
		break;
	case 14:
		if (!memcmp(inName.__s,L"_physicsTicker",sizeof(wchar_t)*14) ) { return _physicsTicker; }
		break;
	case 15:
		if (!memcmp(inName.__s,L"_graphicsTicker",sizeof(wchar_t)*15) ) { return _graphicsTicker; }
		if (!memcmp(inName.__s,L"_leftScoreLabel",sizeof(wchar_t)*15) ) { return _leftScoreLabel; }
		break;
	case 16:
		if (!memcmp(inName.__s,L"_rightScoreLabel",sizeof(wchar_t)*16) ) { return _rightScoreLabel; }
		break;
	case 19:
		if (!memcmp(inName.__s,L"ballPaddleCollision",sizeof(wchar_t)*19) ) { return ballPaddleCollision_dyn(); }
	}
	return super::__Field(inName);
}

static int __id__graphicsTicker = __hxcpp_field_to_id("_graphicsTicker");
static int __id__physicsTicker = __hxcpp_field_to_id("_physicsTicker");
static int __id__stage = __hxcpp_field_to_id("_stage");
static int __id__ball = __hxcpp_field_to_id("_ball");
static int __id__leftPaddle = __hxcpp_field_to_id("_leftPaddle");
static int __id__rightPaddle = __hxcpp_field_to_id("_rightPaddle");
static int __id__leftScoreLabel = __hxcpp_field_to_id("_leftScoreLabel");
static int __id__rightScoreLabel = __hxcpp_field_to_id("_rightScoreLabel");
static int __id__id = __hxcpp_field_to_id("_id");
static int __id_setupStage = __hxcpp_field_to_id("setupStage");
static int __id_newRound = __hxcpp_field_to_id("newRound");
static int __id_runAI = __hxcpp_field_to_id("runAI");
static int __id_doCollisions = __hxcpp_field_to_id("doCollisions");
static int __id_ballPaddleCollision = __hxcpp_field_to_id("ballPaddleCollision");
static int __id_physicsStep = __hxcpp_field_to_id("physicsStep");
static int __id_render = __hxcpp_field_to_id("render");


Dynamic Game_obj::__IField(int inFieldID)
{
	if (inFieldID==__id__graphicsTicker) return _graphicsTicker;
	if (inFieldID==__id__physicsTicker) return _physicsTicker;
	if (inFieldID==__id__stage) return _stage;
	if (inFieldID==__id__ball) return _ball;
	if (inFieldID==__id__leftPaddle) return _leftPaddle;
	if (inFieldID==__id__rightPaddle) return _rightPaddle;
	if (inFieldID==__id__leftScoreLabel) return _leftScoreLabel;
	if (inFieldID==__id__rightScoreLabel) return _rightScoreLabel;
	if (inFieldID==__id__id) return _id;
	if (inFieldID==__id_setupStage) return setupStage_dyn();
	if (inFieldID==__id_newRound) return newRound_dyn();
	if (inFieldID==__id_runAI) return runAI_dyn();
	if (inFieldID==__id_doCollisions) return doCollisions_dyn();
	if (inFieldID==__id_ballPaddleCollision) return ballPaddleCollision_dyn();
	if (inFieldID==__id_physicsStep) return physicsStep_dyn();
	if (inFieldID==__id_render) return render_dyn();
	return super::__IField(inFieldID);
}

Dynamic Game_obj::__SetField(const String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 3:
		if (!memcmp(inName.__s,L"_id",sizeof(wchar_t)*3) ) { _id=inValue.Cast<String >();return inValue; }
		break;
	case 5:
		if (!memcmp(inName.__s,L"_ball",sizeof(wchar_t)*5) ) { _ball=inValue.Cast<pong::Ball >();return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"_stage",sizeof(wchar_t)*6) ) { _stage=inValue.Cast<pong::gfx::Stage >();return inValue; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"_leftPaddle",sizeof(wchar_t)*11) ) { _leftPaddle=inValue.Cast<pong::Paddle >();return inValue; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"_rightPaddle",sizeof(wchar_t)*12) ) { _rightPaddle=inValue.Cast<pong::Paddle >();return inValue; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"_physicsTicker",sizeof(wchar_t)*14) ) { _physicsTicker=inValue.Cast<haxe::Timer >();return inValue; }
		break;
	case 15:
		if (!memcmp(inName.__s,L"_graphicsTicker",sizeof(wchar_t)*15) ) { _graphicsTicker=inValue.Cast<haxe::Timer >();return inValue; }
		if (!memcmp(inName.__s,L"_leftScoreLabel",sizeof(wchar_t)*15) ) { _leftScoreLabel=inValue.Cast<pong::gfx::Label >();return inValue; }
		break;
	case 16:
		if (!memcmp(inName.__s,L"_rightScoreLabel",sizeof(wchar_t)*16) ) { _rightScoreLabel=inValue.Cast<pong::gfx::Label >();return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Game_obj::__GetFields(Array<String> &outFields)
{
	outFields->push(STRING(L"_graphicsTicker",15));
	outFields->push(STRING(L"_physicsTicker",14));
	outFields->push(STRING(L"_stage",6));
	outFields->push(STRING(L"_ball",5));
	outFields->push(STRING(L"_leftPaddle",11));
	outFields->push(STRING(L"_rightPaddle",12));
	outFields->push(STRING(L"_leftScoreLabel",15));
	outFields->push(STRING(L"_rightScoreLabel",16));
	outFields->push(STRING(L"_id",3));
	super::__GetFields(outFields);
};

static String sStaticFields[] = {
	String(null()) };

static String sMemberFields[] = {
	STRING(L"_graphicsTicker",15),
	STRING(L"_physicsTicker",14),
	STRING(L"_stage",6),
	STRING(L"_ball",5),
	STRING(L"_leftPaddle",11),
	STRING(L"_rightPaddle",12),
	STRING(L"_leftScoreLabel",15),
	STRING(L"_rightScoreLabel",16),
	STRING(L"_id",3),
	STRING(L"setupStage",10),
	STRING(L"newRound",8),
	STRING(L"runAI",5),
	STRING(L"doCollisions",12),
	STRING(L"ballPaddleCollision",19),
	STRING(L"physicsStep",11),
	STRING(L"render",6),
	String(null()) };

static void sMarkStatics() {
};

Class Game_obj::__mClass;

void Game_obj::__register()
{
	Static(__mClass) = RegisterClass(STRING(L"pong.Game",9), TCanCast<Game_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Game_obj::__boot()
{
}

} // end namespace pong
