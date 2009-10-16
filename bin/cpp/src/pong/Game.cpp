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
#ifndef INCLUDED_pong_gfx_IDisplayObject
#include <pong/gfx/IDisplayObject.h>
#endif
#ifndef INCLUDED_pong_gfx_Label
#include <pong/gfx/Label.h>
#endif
#ifndef INCLUDED_pong_gfx_PongBackground
#include <pong/gfx/PongBackground.h>
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

Void Game_obj::__construct(Dynamic __o_width_,Dynamic __o_height_)
{
double width_ = __o_width_.Default(300);
double height_ = __o_height_.Default(300);
{
	this->setWidth(width_);
	this->setHeight(height_);
	this->setFrameRate(60);
	this->setPhysicsRate(60);
	this->setupStage();
	this->newRound();
	this->render();
}
;
	return null();
}

Game_obj::~Game_obj() { }

Dynamic Game_obj::__CreateEmpty() { return  new Game_obj; }
hxObjectPtr<Game_obj > Game_obj::__new(Dynamic __o_width_,Dynamic __o_height_)
{  hxObjectPtr<Game_obj > result = new Game_obj();
	result->__construct(__o_width_,__o_height_);
	return result;}

Dynamic Game_obj::__Create(DynamicArray inArgs)
{  hxObjectPtr<Game_obj > result = new Game_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void Game_obj::setupStage( ){
{
		this->_stage = pong::gfx::Stage_obj::getInstance();
		this->_backGround = pong::gfx::PongBackground_obj::__new(this->getWidth(),this->getHeight());
		this->_stage->add(this->_backGround);
		this->_ball = pong::Ball_obj::__new(150,50,this->getWidth() * 0.02,this->getWidth() * 0.02);
		this->_leftPaddle = pong::Paddle_obj::__new(this->getWidth() * 0.05,50,this->getWidth() * 0.02,this->getHeight() * 0.15);
		this->_rightPaddle = pong::Paddle_obj::__new(this->getWidth() * 0.93,50,this->getWidth() * 0.02,this->getHeight() * 0.15);
		this->_rightPaddle->ai = true;
		this->_stage->add(this->_ball->sprite);
		this->_stage->add(this->_leftPaddle->sprite);
		this->_stage->add(this->_rightPaddle->sprite);
		this->_leftScoreLabel = pong::gfx::Label_obj::__new(null());
		this->_leftScoreLabel->text = Std_obj::string(this->_leftPaddle->score);
		this->_leftScoreLabel->y = 10;
		this->_leftScoreLabel->x = this->getWidth() * 0.5 - 20;
		this->_rightScoreLabel = pong::gfx::Label_obj::__new(null());
		this->_rightScoreLabel->text = Std_obj::string(this->_rightPaddle->score);
		this->_rightScoreLabel->y = 10;
		this->_rightScoreLabel->x = this->getWidth() * 0.5 + 10;
		this->_stage->add(this->_leftScoreLabel);
		this->_stage->add(this->_rightScoreLabel);
	}
return null();
}


DEFINE_DYNAMIC_FUNC0(Game_obj,setupStage,(void))

Void Game_obj::newRound( ){
{
		this->_leftPaddle->y = double(this->getHeight()) / double(2) - double(this->_leftPaddle->height) / double(2);
		this->_rightPaddle->y = double(this->getHeight()) / double(2) - double(this->_rightPaddle->height) / double(2);
		this->_ball->y = double(this->getHeight()) / double(2) - double(this->_ball->height) / double(2);
		this->_ball->x = double(this->getWidth()) / double(2) - double(this->_ball->width) / double(2);
		this->_ball->velocity->x = this->getWidth() * Math_obj::random() - this->getWidth() * 0.5;
		this->_ball->velocity->y = this->getHeight() * Math_obj::random() - this->getHeight() * 0.5;
		struct _Function_1{
			static pong::geom::Vector Block( pong::Game_obj *__this)/* DEF (ret block)(not intern) */{
				pong::geom::Vector _g = __this->_ball->velocity;
				double l = __this->getWidth() * 0.01;
				double d = Math_obj::sqrt(_g->x * _g->x + _g->y * _g->y);
				return d == 0 ? Void( pong::geom::Vector_obj::__new(0,0) ) : Void( pong::geom::Vector_obj::__new(double(_g->x) / double(d) * l,double(_g->y) / double(d) * l) );
			}
		};
		this->_ball->velocity = _Function_1::Block(this);
	}
return null();
}


DEFINE_DYNAMIC_FUNC0(Game_obj,newRound,(void))

Void Game_obj::runAI( pong::Paddle p){
{
		if (p->y + double(p->height) / double(2) < this->_ball->y + double(this->_ball->height) / double(2))
			p->velocity->y = this->getHeight() * 0.01;
		else
			if (p->y + double(p->height) / double(2) > this->_ball->y + double(this->_ball->height) / double(2))
			p->velocity->y = this->getHeight() * -0.01;
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
		if (this->_leftPaddle->y + this->_leftPaddle->height > this->getHeight() - 10){
			this->_leftPaddle->y = this->getHeight() - this->_leftPaddle->height - 10;
		}
		if (this->_leftPaddle->y < 10){
			this->_leftPaddle->y = 10;
		}
		if (this->_rightPaddle->y + this->_rightPaddle->height > this->getHeight() - 10){
			this->_rightPaddle->y = this->getHeight() - this->_rightPaddle->height - 10;
		}
		if (this->_rightPaddle->y < 10){
			this->_rightPaddle->y = 10;
		}
		if (this->_ball->y + this->_ball->height > this->getHeight() - 10){
			this->_ball->y = this->getHeight() - this->_ball->height - 10;
			hxMultEq(this->_ball->velocity->y,-1);
		}
		if (this->_ball->y < 10){
			this->_ball->y = 10;
			hxMultEq(this->_ball->velocity->y,-1);
		}
		if (this->_ball->x < -this->_ball->width){
			this->_rightScoreLabel->text = Std_obj::string(++this->_rightPaddle->score);
			this->newRound();
		}
		if (this->_ball->x > this->getWidth()){
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

double Game_obj::getX( ){
	return this->_x;
}


DEFINE_DYNAMIC_FUNC0(Game_obj,getX,return )

double Game_obj::getY( ){
	return this->_y;
}


DEFINE_DYNAMIC_FUNC0(Game_obj,getY,return )

double Game_obj::getWidth( ){
	return this->_width;
}


DEFINE_DYNAMIC_FUNC0(Game_obj,getWidth,return )

double Game_obj::getHeight( ){
	return this->_height;
}


DEFINE_DYNAMIC_FUNC0(Game_obj,getHeight,return )

double Game_obj::setX( double v){
	this->_x = v;
	this->_backGround->setX(v);
	return v;
}


DEFINE_DYNAMIC_FUNC1(Game_obj,setX,return )

double Game_obj::setY( double v){
	this->_y = v;
	this->_backGround->setY(v);
	return v;
}


DEFINE_DYNAMIC_FUNC1(Game_obj,setY,return )

double Game_obj::setWidth( double v){
	this->_width = v;
	return v;
}


DEFINE_DYNAMIC_FUNC1(Game_obj,setWidth,return )

double Game_obj::setHeight( double v){
	this->_height = v;
	return v;
}


DEFINE_DYNAMIC_FUNC1(Game_obj,setHeight,return )

double Game_obj::getFrameRate( ){
	return this->_frameRate;
}


DEFINE_DYNAMIC_FUNC0(Game_obj,getFrameRate,return )

double Game_obj::getPhysicsRate( ){
	return this->_physicsRate;
}


DEFINE_DYNAMIC_FUNC0(Game_obj,getPhysicsRate,return )

double Game_obj::setFrameRate( double v){
	this->_physicsRate = v;
	if (this->_physicsTicker != null())
		this->_physicsTicker->stop();
	this->_physicsTicker = haxe::Timer_obj::__new(Math_obj::floor(double(1000) / double(this->_physicsRate)));
	this->_physicsTicker->run = this->physicsStep_dyn();
	return v;
}


DEFINE_DYNAMIC_FUNC1(Game_obj,setFrameRate,return )

double Game_obj::setPhysicsRate( double v){
	this->_frameRate = v;
	if (this->_graphicsTicker != null())
		this->_graphicsTicker->stop();
	this->_graphicsTicker = haxe::Timer_obj::__new(Math_obj::floor(double(1000) / double(this->_frameRate)));
	this->_graphicsTicker->run = this->render_dyn();
	return v;
}


DEFINE_DYNAMIC_FUNC1(Game_obj,setPhysicsRate,return )


Game_obj::Game_obj()
{
	InitMember(_stage);
	InitMember(_ball);
	InitMember(_leftPaddle);
	InitMember(_rightPaddle);
	InitMember(_leftScoreLabel);
	InitMember(_rightScoreLabel);
	InitMember(_backGround);
	InitMember(_graphicsTicker);
	InitMember(_physicsTicker);
	InitMember(_frameRate);
	InitMember(_physicsRate);
	InitMember(frameRate);
	InitMember(physicsRate);
	InitMember(_x);
	InitMember(x);
	InitMember(_y);
	InitMember(y);
	InitMember(_width);
	InitMember(width);
	InitMember(_height);
	InitMember(height);
}

void Game_obj::__Mark()
{
	MarkMember(_stage);
	MarkMember(_ball);
	MarkMember(_leftPaddle);
	MarkMember(_rightPaddle);
	MarkMember(_leftScoreLabel);
	MarkMember(_rightScoreLabel);
	MarkMember(_backGround);
	MarkMember(_graphicsTicker);
	MarkMember(_physicsTicker);
	MarkMember(_frameRate);
	MarkMember(_physicsRate);
	MarkMember(frameRate);
	MarkMember(physicsRate);
	MarkMember(_x);
	MarkMember(x);
	MarkMember(_y);
	MarkMember(y);
	MarkMember(_width);
	MarkMember(width);
	MarkMember(_height);
	MarkMember(height);
}

Dynamic Game_obj::__Field(const String &inName)
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
		if (!memcmp(inName.__s,L"_ball",sizeof(wchar_t)*5) ) { return _ball; }
		if (!memcmp(inName.__s,L"width",sizeof(wchar_t)*5) ) { return width; }
		if (!memcmp(inName.__s,L"runAI",sizeof(wchar_t)*5) ) { return runAI_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"_stage",sizeof(wchar_t)*6) ) { return _stage; }
		if (!memcmp(inName.__s,L"_width",sizeof(wchar_t)*6) ) { return _width; }
		if (!memcmp(inName.__s,L"height",sizeof(wchar_t)*6) ) { return height; }
		if (!memcmp(inName.__s,L"render",sizeof(wchar_t)*6) ) { return render_dyn(); }
		break;
	case 7:
		if (!memcmp(inName.__s,L"_height",sizeof(wchar_t)*7) ) { return _height; }
		break;
	case 8:
		if (!memcmp(inName.__s,L"newRound",sizeof(wchar_t)*8) ) { return newRound_dyn(); }
		if (!memcmp(inName.__s,L"getWidth",sizeof(wchar_t)*8) ) { return getWidth_dyn(); }
		if (!memcmp(inName.__s,L"setWidth",sizeof(wchar_t)*8) ) { return setWidth_dyn(); }
		break;
	case 9:
		if (!memcmp(inName.__s,L"frameRate",sizeof(wchar_t)*9) ) { return frameRate; }
		if (!memcmp(inName.__s,L"getHeight",sizeof(wchar_t)*9) ) { return getHeight_dyn(); }
		if (!memcmp(inName.__s,L"setHeight",sizeof(wchar_t)*9) ) { return setHeight_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"_frameRate",sizeof(wchar_t)*10) ) { return _frameRate; }
		if (!memcmp(inName.__s,L"setupStage",sizeof(wchar_t)*10) ) { return setupStage_dyn(); }
		break;
	case 11:
		if (!memcmp(inName.__s,L"_leftPaddle",sizeof(wchar_t)*11) ) { return _leftPaddle; }
		if (!memcmp(inName.__s,L"_backGround",sizeof(wchar_t)*11) ) { return _backGround; }
		if (!memcmp(inName.__s,L"physicsRate",sizeof(wchar_t)*11) ) { return physicsRate; }
		if (!memcmp(inName.__s,L"physicsStep",sizeof(wchar_t)*11) ) { return physicsStep_dyn(); }
		break;
	case 12:
		if (!memcmp(inName.__s,L"_rightPaddle",sizeof(wchar_t)*12) ) { return _rightPaddle; }
		if (!memcmp(inName.__s,L"_physicsRate",sizeof(wchar_t)*12) ) { return _physicsRate; }
		if (!memcmp(inName.__s,L"doCollisions",sizeof(wchar_t)*12) ) { return doCollisions_dyn(); }
		if (!memcmp(inName.__s,L"getFrameRate",sizeof(wchar_t)*12) ) { return getFrameRate_dyn(); }
		if (!memcmp(inName.__s,L"setFrameRate",sizeof(wchar_t)*12) ) { return setFrameRate_dyn(); }
		break;
	case 14:
		if (!memcmp(inName.__s,L"_physicsTicker",sizeof(wchar_t)*14) ) { return _physicsTicker; }
		if (!memcmp(inName.__s,L"getPhysicsRate",sizeof(wchar_t)*14) ) { return getPhysicsRate_dyn(); }
		if (!memcmp(inName.__s,L"setPhysicsRate",sizeof(wchar_t)*14) ) { return setPhysicsRate_dyn(); }
		break;
	case 15:
		if (!memcmp(inName.__s,L"_leftScoreLabel",sizeof(wchar_t)*15) ) { return _leftScoreLabel; }
		if (!memcmp(inName.__s,L"_graphicsTicker",sizeof(wchar_t)*15) ) { return _graphicsTicker; }
		break;
	case 16:
		if (!memcmp(inName.__s,L"_rightScoreLabel",sizeof(wchar_t)*16) ) { return _rightScoreLabel; }
		break;
	case 19:
		if (!memcmp(inName.__s,L"ballPaddleCollision",sizeof(wchar_t)*19) ) { return ballPaddleCollision_dyn(); }
	}
	return super::__Field(inName);
}

static int __id__stage = __hxcpp_field_to_id("_stage");
static int __id__ball = __hxcpp_field_to_id("_ball");
static int __id__leftPaddle = __hxcpp_field_to_id("_leftPaddle");
static int __id__rightPaddle = __hxcpp_field_to_id("_rightPaddle");
static int __id__leftScoreLabel = __hxcpp_field_to_id("_leftScoreLabel");
static int __id__rightScoreLabel = __hxcpp_field_to_id("_rightScoreLabel");
static int __id__backGround = __hxcpp_field_to_id("_backGround");
static int __id__graphicsTicker = __hxcpp_field_to_id("_graphicsTicker");
static int __id__physicsTicker = __hxcpp_field_to_id("_physicsTicker");
static int __id__frameRate = __hxcpp_field_to_id("_frameRate");
static int __id__physicsRate = __hxcpp_field_to_id("_physicsRate");
static int __id_frameRate = __hxcpp_field_to_id("frameRate");
static int __id_physicsRate = __hxcpp_field_to_id("physicsRate");
static int __id__x = __hxcpp_field_to_id("_x");
static int __id_x = __hxcpp_field_to_id("x");
static int __id__y = __hxcpp_field_to_id("_y");
static int __id_y = __hxcpp_field_to_id("y");
static int __id__width = __hxcpp_field_to_id("_width");
static int __id_width = __hxcpp_field_to_id("width");
static int __id__height = __hxcpp_field_to_id("_height");
static int __id_height = __hxcpp_field_to_id("height");
static int __id_setupStage = __hxcpp_field_to_id("setupStage");
static int __id_newRound = __hxcpp_field_to_id("newRound");
static int __id_runAI = __hxcpp_field_to_id("runAI");
static int __id_doCollisions = __hxcpp_field_to_id("doCollisions");
static int __id_ballPaddleCollision = __hxcpp_field_to_id("ballPaddleCollision");
static int __id_physicsStep = __hxcpp_field_to_id("physicsStep");
static int __id_render = __hxcpp_field_to_id("render");
static int __id_getX = __hxcpp_field_to_id("getX");
static int __id_getY = __hxcpp_field_to_id("getY");
static int __id_getWidth = __hxcpp_field_to_id("getWidth");
static int __id_getHeight = __hxcpp_field_to_id("getHeight");
static int __id_setX = __hxcpp_field_to_id("setX");
static int __id_setY = __hxcpp_field_to_id("setY");
static int __id_setWidth = __hxcpp_field_to_id("setWidth");
static int __id_setHeight = __hxcpp_field_to_id("setHeight");
static int __id_getFrameRate = __hxcpp_field_to_id("getFrameRate");
static int __id_getPhysicsRate = __hxcpp_field_to_id("getPhysicsRate");
static int __id_setFrameRate = __hxcpp_field_to_id("setFrameRate");
static int __id_setPhysicsRate = __hxcpp_field_to_id("setPhysicsRate");


Dynamic Game_obj::__IField(int inFieldID)
{
	if (inFieldID==__id__stage) return _stage;
	if (inFieldID==__id__ball) return _ball;
	if (inFieldID==__id__leftPaddle) return _leftPaddle;
	if (inFieldID==__id__rightPaddle) return _rightPaddle;
	if (inFieldID==__id__leftScoreLabel) return _leftScoreLabel;
	if (inFieldID==__id__rightScoreLabel) return _rightScoreLabel;
	if (inFieldID==__id__backGround) return _backGround;
	if (inFieldID==__id__graphicsTicker) return _graphicsTicker;
	if (inFieldID==__id__physicsTicker) return _physicsTicker;
	if (inFieldID==__id__frameRate) return _frameRate;
	if (inFieldID==__id__physicsRate) return _physicsRate;
	if (inFieldID==__id_frameRate) return frameRate;
	if (inFieldID==__id_physicsRate) return physicsRate;
	if (inFieldID==__id__x) return _x;
	if (inFieldID==__id_x) return x;
	if (inFieldID==__id__y) return _y;
	if (inFieldID==__id_y) return y;
	if (inFieldID==__id__width) return _width;
	if (inFieldID==__id_width) return width;
	if (inFieldID==__id__height) return _height;
	if (inFieldID==__id_height) return height;
	if (inFieldID==__id_setupStage) return setupStage_dyn();
	if (inFieldID==__id_newRound) return newRound_dyn();
	if (inFieldID==__id_runAI) return runAI_dyn();
	if (inFieldID==__id_doCollisions) return doCollisions_dyn();
	if (inFieldID==__id_ballPaddleCollision) return ballPaddleCollision_dyn();
	if (inFieldID==__id_physicsStep) return physicsStep_dyn();
	if (inFieldID==__id_render) return render_dyn();
	if (inFieldID==__id_getX) return getX_dyn();
	if (inFieldID==__id_getY) return getY_dyn();
	if (inFieldID==__id_getWidth) return getWidth_dyn();
	if (inFieldID==__id_getHeight) return getHeight_dyn();
	if (inFieldID==__id_setX) return setX_dyn();
	if (inFieldID==__id_setY) return setY_dyn();
	if (inFieldID==__id_setWidth) return setWidth_dyn();
	if (inFieldID==__id_setHeight) return setHeight_dyn();
	if (inFieldID==__id_getFrameRate) return getFrameRate_dyn();
	if (inFieldID==__id_getPhysicsRate) return getPhysicsRate_dyn();
	if (inFieldID==__id_setFrameRate) return setFrameRate_dyn();
	if (inFieldID==__id_setPhysicsRate) return setPhysicsRate_dyn();
	return super::__IField(inFieldID);
}

Dynamic Game_obj::__SetField(const String &inName,const Dynamic &inValue)
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
		if (!memcmp(inName.__s,L"_ball",sizeof(wchar_t)*5) ) { _ball=inValue.Cast<pong::Ball >();return inValue; }
		if (!memcmp(inName.__s,L"width",sizeof(wchar_t)*5) ) { width=inValue.Cast<double >();return inValue; }
		break;
	case 6:
		if (!memcmp(inName.__s,L"_stage",sizeof(wchar_t)*6) ) { _stage=inValue.Cast<pong::gfx::Stage >();return inValue; }
		if (!memcmp(inName.__s,L"_width",sizeof(wchar_t)*6) ) { _width=inValue.Cast<double >();return inValue; }
		if (!memcmp(inName.__s,L"height",sizeof(wchar_t)*6) ) { height=inValue.Cast<double >();return inValue; }
		break;
	case 7:
		if (!memcmp(inName.__s,L"_height",sizeof(wchar_t)*7) ) { _height=inValue.Cast<double >();return inValue; }
		break;
	case 9:
		if (!memcmp(inName.__s,L"frameRate",sizeof(wchar_t)*9) ) { frameRate=inValue.Cast<double >();return inValue; }
		break;
	case 10:
		if (!memcmp(inName.__s,L"_frameRate",sizeof(wchar_t)*10) ) { _frameRate=inValue.Cast<double >();return inValue; }
		break;
	case 11:
		if (!memcmp(inName.__s,L"_leftPaddle",sizeof(wchar_t)*11) ) { _leftPaddle=inValue.Cast<pong::Paddle >();return inValue; }
		if (!memcmp(inName.__s,L"_backGround",sizeof(wchar_t)*11) ) { _backGround=inValue.Cast<pong::gfx::PongBackground >();return inValue; }
		if (!memcmp(inName.__s,L"physicsRate",sizeof(wchar_t)*11) ) { physicsRate=inValue.Cast<double >();return inValue; }
		break;
	case 12:
		if (!memcmp(inName.__s,L"_rightPaddle",sizeof(wchar_t)*12) ) { _rightPaddle=inValue.Cast<pong::Paddle >();return inValue; }
		if (!memcmp(inName.__s,L"_physicsRate",sizeof(wchar_t)*12) ) { _physicsRate=inValue.Cast<double >();return inValue; }
		break;
	case 14:
		if (!memcmp(inName.__s,L"_physicsTicker",sizeof(wchar_t)*14) ) { _physicsTicker=inValue.Cast<haxe::Timer >();return inValue; }
		break;
	case 15:
		if (!memcmp(inName.__s,L"_leftScoreLabel",sizeof(wchar_t)*15) ) { _leftScoreLabel=inValue.Cast<pong::gfx::Label >();return inValue; }
		if (!memcmp(inName.__s,L"_graphicsTicker",sizeof(wchar_t)*15) ) { _graphicsTicker=inValue.Cast<haxe::Timer >();return inValue; }
		break;
	case 16:
		if (!memcmp(inName.__s,L"_rightScoreLabel",sizeof(wchar_t)*16) ) { _rightScoreLabel=inValue.Cast<pong::gfx::Label >();return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Game_obj::__GetFields(Array<String> &outFields)
{
	outFields->push(STRING(L"_stage",6));
	outFields->push(STRING(L"_ball",5));
	outFields->push(STRING(L"_leftPaddle",11));
	outFields->push(STRING(L"_rightPaddle",12));
	outFields->push(STRING(L"_leftScoreLabel",15));
	outFields->push(STRING(L"_rightScoreLabel",16));
	outFields->push(STRING(L"_backGround",11));
	outFields->push(STRING(L"_graphicsTicker",15));
	outFields->push(STRING(L"_physicsTicker",14));
	outFields->push(STRING(L"_frameRate",10));
	outFields->push(STRING(L"_physicsRate",12));
	outFields->push(STRING(L"frameRate",9));
	outFields->push(STRING(L"physicsRate",11));
	outFields->push(STRING(L"_x",2));
	outFields->push(STRING(L"x",1));
	outFields->push(STRING(L"_y",2));
	outFields->push(STRING(L"y",1));
	outFields->push(STRING(L"_width",6));
	outFields->push(STRING(L"width",5));
	outFields->push(STRING(L"_height",7));
	outFields->push(STRING(L"height",6));
	super::__GetFields(outFields);
};

static String sStaticFields[] = {
	String(null()) };

static String sMemberFields[] = {
	STRING(L"_stage",6),
	STRING(L"_ball",5),
	STRING(L"_leftPaddle",11),
	STRING(L"_rightPaddle",12),
	STRING(L"_leftScoreLabel",15),
	STRING(L"_rightScoreLabel",16),
	STRING(L"_backGround",11),
	STRING(L"_graphicsTicker",15),
	STRING(L"_physicsTicker",14),
	STRING(L"_frameRate",10),
	STRING(L"_physicsRate",12),
	STRING(L"frameRate",9),
	STRING(L"physicsRate",11),
	STRING(L"_x",2),
	STRING(L"x",1),
	STRING(L"_y",2),
	STRING(L"y",1),
	STRING(L"_width",6),
	STRING(L"width",5),
	STRING(L"_height",7),
	STRING(L"height",6),
	STRING(L"setupStage",10),
	STRING(L"newRound",8),
	STRING(L"runAI",5),
	STRING(L"doCollisions",12),
	STRING(L"ballPaddleCollision",19),
	STRING(L"physicsStep",11),
	STRING(L"render",6),
	STRING(L"getX",4),
	STRING(L"getY",4),
	STRING(L"getWidth",8),
	STRING(L"getHeight",9),
	STRING(L"setX",4),
	STRING(L"setY",4),
	STRING(L"setWidth",8),
	STRING(L"setHeight",9),
	STRING(L"getFrameRate",12),
	STRING(L"getPhysicsRate",14),
	STRING(L"setFrameRate",12),
	STRING(L"setPhysicsRate",14),
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
