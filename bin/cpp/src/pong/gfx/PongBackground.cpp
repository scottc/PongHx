#include <hxObject.h>

#ifndef INCLUDED_pong_gfx_PongBackground
#include <pong/gfx/PongBackground.h>
#endif
#ifndef INCLUDED_pong_gfx_Rectangle
#include <pong/gfx/Rectangle.h>
#endif
namespace pong{
namespace gfx{

Void PongBackground_obj::__construct(double width_,double height_)
{
{
	super::__construct(0,0,width_,height_);
	this->setColor(0);
}
;
	return null();
}

PongBackground_obj::~PongBackground_obj() { }

Dynamic PongBackground_obj::__CreateEmpty() { return  new PongBackground_obj; }
hxObjectPtr<PongBackground_obj > PongBackground_obj::__new(double width_,double height_)
{  hxObjectPtr<PongBackground_obj > result = new PongBackground_obj();
	result->__construct(width_,height_);
	return result;}

Dynamic PongBackground_obj::__Create(DynamicArray inArgs)
{  hxObjectPtr<PongBackground_obj > result = new PongBackground_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}


PongBackground_obj::PongBackground_obj()
{
}

void PongBackground_obj::__Mark()
{
	super::__Mark();
}

Dynamic PongBackground_obj::__Field(const String &inName)
{
	return super::__Field(inName);
}



Dynamic PongBackground_obj::__IField(int inFieldID)
{
	return super::__IField(inFieldID);
}

Dynamic PongBackground_obj::__SetField(const String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void PongBackground_obj::__GetFields(Array<String> &outFields)
{
	super::__GetFields(outFields);
};

static String sStaticFields[] = {
	String(null()) };

static String sMemberFields[] = {
	String(null()) };

static void sMarkStatics() {
};

Class PongBackground_obj::__mClass;

void PongBackground_obj::__register()
{
	Static(__mClass) = RegisterClass(STRING(L"pong.gfx.PongBackground",23), TCanCast<PongBackground_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void PongBackground_obj::__boot()
{
}

} // end namespace pong
} // end namespace gfx
