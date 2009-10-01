#include <hxObject.h>

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
#ifndef INCLUDED_pong_Player
#include <pong/Player.h>
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
	hxSubEq(this->_ball->y,100);
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
		this->_ball = pong::Ball_obj::__new(150,50,20,20);
		this->_leftPlayer = pong::Player_obj::__new(30,50,20,100);
		this->_rightPlayer = pong::Player_obj::__new(pong::gfx::Stage_obj::getWidth() - 50,50,20,100);
		this->_stage->add(this->_ball->sprite);
		this->_stage->add(this->_leftPlayer->sprite);
		this->_stage->add(this->_rightPlayer->sprite);
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
		this->_leftPlayer->y = double(pong::gfx::Stage_obj::getHeight()) / double(2) - double(this->_leftPlayer->height) / double(2);
		this->_rightPlayer->y = double(pong::gfx::Stage_obj::getHeight()) / double(2) - double(this->_rightPlayer->height) / double(2);
		this->_ball->y = double(pong::gfx::Stage_obj::getHeight()) / double(2) - double(this->_ball->height) / double(2);
		this->_ball->x = double(pong::gfx::Stage_obj::getWidth()) / double(2) - double(this->_ball->width) / double(2);
	}
return null();
}


DEFINE_DYNAMIC_FUNC0(Game_obj,newRound,(void))

Void Game_obj::runAI( pong::Player p){
{
		if (p->y + double(p->height) / double(2) < this->_ball->y + double(this->_ball->height) / double(2))
			p->velocity->y = 1;
		else
			if (p->y + double(p->height) / double(2) > this->_ball->y + double(this->_ball->height) / double(2))
			p->velocity->y = -1;
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
		if (this->_leftPlayer->y + this->_leftPlayer->height > pong::gfx::Stage_obj::getHeight() - 10){
			this->_leftPlayer->y = pong::gfx::Stage_obj::getHeight() - this->_leftPlayer->height - 10;
		}
		if (this->_leftPlayer->y < 10){
			this->_leftPlayer->y = 10;
		}
		if (this->_rightPlayer->y + this->_rightPlayer->height > pong::gfx::Stage_obj::getHeight() - 10){
			this->_rightPlayer->y = pong::gfx::Stage_obj::getHeight() - this->_rightPlayer->height - 10;
		}
		if (this->_rightPlayer->y < 10){
			this->_rightPlayer->y = 10;
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
			this->_rightScoreLabel->text = Std_obj::string(++this->_rightPlayer->score);
			this->newRound();
		}
		if (this->_ball->x > pong::gfx::Stage_obj::getWidth()){
			this->_leftScoreLabel->text = Std_obj::string(++this->_leftPlayer->score);
			this->newRound();
		}
		if (this->_ball->isOverlapping(this->_leftPlayer)){
			this->_ball->x = this->_leftPlayer->x + this->_leftPlayer->width;
			hxMultEq(this->_ball->velocity->x,-1);
		}
		if (this->_ball->isOverlapping(this->_rightPlayer)){
			this->_ball->x = this->_rightPlayer->x - this->_ball->width;
			hxMultEq(this->_ball->velocity->x,-1);
		}
	}
return null();
}


DEFINE_DYNAMIC_FUNC0(Game_obj,doCollisions,(void))

Void Game_obj::physicsStep( ){
{
		if (!this->_leftPlayer->ai){
		}
		else
			if (this->_ball->velocity->x < 0)
			this->runAI(this->_leftPlayer);
		else
			this->_leftPlayer->velocity->y = 0;
;
;
		if (!this->_rightPlayer->ai){
		}
		else
			if (this->_ball->velocity->x > 0)
			this->runAI(this->_rightPlayer);
		else
			this->_rightPlayer->velocity->y = 0;
;
;
		this->_leftPlayer->move();
		this->_rightPlayer->move();
		this->_ball->move();
		this->doCollisions();
	}
return null();
}


DEFINE_DYNAMIC_FUNC0(Game_obj,physicsStep,(void))

Void Game_obj::render( ){
{
		this->_ball->render();
		this->_leftPlayer->render();
		this->_rightPlayer->render();
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
	InitMember(_leftPlayer);
	InitMember(_rightPlayer);
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
	MarkMember(_leftPlayer);
	MarkMember(_rightPlayer);
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
		if (!memcmp(inName.__s,L"_leftPlayer",sizeof(wchar_t)*11) ) { return _leftPlayer; }
		if (!memcmp(inName.__s,L"physicsStep",sizeof(wchar_t)*11) ) { return physicsStep_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"_rightPlayer",sizeof(wchar_t)*12) ) { return _rightPlayer; }
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
	}
	return super::__Field(inName);
}

static int __id__graphicsTicker = __hxcpp_field_to_id("_graphicsTicker");
static int __id__physicsTicker = __hxcpp_field_to_id("_physicsTicker");
static int __id__stage = __hxcpp_field_to_id("_stage");
static int __id__ball = __hxcpp_field_to_id("_ball");
static int __id__leftPlayer = __hxcpp_field_to_id("_leftPlayer");
static int __id__rightPlayer = __hxcpp_field_to_id("_rightPlayer");
static int __id__leftScoreLabel = __hxcpp_field_to_id("_leftScoreLabel");
static int __id__rightScoreLabel = __hxcpp_field_to_id("_rightScoreLabel");
static int __id__id = __hxcpp_field_to_id("_id");
static int __id_setupStage = __hxcpp_field_to_id("setupStage");
static int __id_newRound = __hxcpp_field_to_id("newRound");
static int __id_runAI = __hxcpp_field_to_id("runAI");
static int __id_doCollisions = __hxcpp_field_to_id("doCollisions");
static int __id_physicsStep = __hxcpp_field_to_id("physicsStep");
static int __id_render = __hxcpp_field_to_id("render");


Dynamic Game_obj::__IField(int inFieldID)
{
	if (inFieldID==__id__graphicsTicker) return _graphicsTicker;
	if (inFieldID==__id__physicsTicker) return _physicsTicker;
	if (inFieldID==__id__stage) return _stage;
	if (inFieldID==__id__ball) return _ball;
	if (inFieldID==__id__leftPlayer) return _leftPlayer;
	if (inFieldID==__id__rightPlayer) return _rightPlayer;
	if (inFieldID==__id__leftScoreLabel) return _leftScoreLabel;
	if (inFieldID==__id__rightScoreLabel) return _rightScoreLabel;
	if (inFieldID==__id__id) return _id;
	if (inFieldID==__id_setupStage) return setupStage_dyn();
	if (inFieldID==__id_newRound) return newRound_dyn();
	if (inFieldID==__id_runAI) return runAI_dyn();
	if (inFieldID==__id_doCollisions) return doCollisions_dyn();
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
		if (!memcmp(inName.__s,L"_leftPlayer",sizeof(wchar_t)*11) ) { _leftPlayer=inValue.Cast<pong::Player >();return inValue; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"_rightPlayer",sizeof(wchar_t)*12) ) { _rightPlayer=inValue.Cast<pong::Player >();return inValue; }
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
	outFields->push(STRING(L"_leftPlayer",11));
	outFields->push(STRING(L"_rightPlayer",12));
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
	STRING(L"_leftPlayer",11),
	STRING(L"_rightPlayer",12),
	STRING(L"_leftScoreLabel",15),
	STRING(L"_rightScoreLabel",16),
	STRING(L"_id",3),
	STRING(L"setupStage",10),
	STRING(L"newRound",8),
	STRING(L"runAI",5),
	STRING(L"doCollisions",12),
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
