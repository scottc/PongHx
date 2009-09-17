#include <hxObject.h>

#ifndef INCLUDED_haxe_Timer
#include <haxe/Timer.h>
#endif
namespace haxe{

Void Timer_obj::__construct(int time_ms)
{
{
}
;
	return null();
}

Timer_obj::~Timer_obj() { }

Dynamic Timer_obj::__CreateEmpty() { return  new Timer_obj; }
hxObjectPtr<Timer_obj > Timer_obj::__new(int time_ms)
{  hxObjectPtr<Timer_obj > result = new Timer_obj();
	result->__construct(time_ms);
	return result;}

Dynamic Timer_obj::__Create(DynamicArray inArgs)
{  hxObjectPtr<Timer_obj > result = new Timer_obj();
	result->__construct(inArgs[0]);
	return result;}

Void Timer_obj::stop( ){
{
		if (this->id == null())
			return null();
		this->id = null();
	}
return null();
}


DEFINE_DYNAMIC_FUNC0(Timer_obj,stop,(void))

BEGIN_DEFAULT_FUNC(__default_run,Timer_obj)
Void run(){
{
	}
return null();
}
END_LOCAL_FUNC0((void))
END_DEFAULT_FUNC

haxe::Timer Timer_obj::delay( Dynamic $t1,int time_ms){
	Array<Dynamic > f = Array_obj<Dynamic >::__new().Add($t1);
	Array<haxe::Timer > t = Array_obj<haxe::Timer >::__new().Add(haxe::Timer_obj::__new(time_ms));

	BEGIN_LOCAL_FUNC2(_Function_1,Array<haxe::Timer >,t,Array<Dynamic >,f)
	Void run(){
{
			t[0]->stop();
			f->__get(0)();
		}
		return null();
	}
	END_LOCAL_FUNC0((void))

	t[0]->run =  Dynamic(new _Function_1(t,f));
	return t->__get(0);
}


STATIC_DEFINE_DYNAMIC_FUNC2(Timer_obj,delay,return )

double Timer_obj::stamp( ){
	return __time_stamp();
}


STATIC_DEFINE_DYNAMIC_FUNC0(Timer_obj,stamp,return )


Timer_obj::Timer_obj()
{
	InitMember(id);
	run = new __default_run(this);
}

void Timer_obj::__Mark()
{
	MarkMember(id);
	MarkMember(run);
}

Dynamic Timer_obj::__Field(const String &inName)
{
	switch(inName.length) {
	case 2:
		if (!memcmp(inName.__s,L"id",sizeof(wchar_t)*2) ) { return id; }
		break;
	case 3:
		if (!memcmp(inName.__s,L"run",sizeof(wchar_t)*3) ) { return run; }
		break;
	case 4:
		if (!memcmp(inName.__s,L"stop",sizeof(wchar_t)*4) ) { return stop_dyn(); }
		break;
	case 5:
		if (!memcmp(inName.__s,L"delay",sizeof(wchar_t)*5) ) { return delay_dyn(); }
		if (!memcmp(inName.__s,L"stamp",sizeof(wchar_t)*5) ) { return stamp_dyn(); }
	}
	return super::__Field(inName);
}

static int __id_delay = __hxcpp_field_to_id("delay");
static int __id_stamp = __hxcpp_field_to_id("stamp");
static int __id_id = __hxcpp_field_to_id("id");
static int __id_stop = __hxcpp_field_to_id("stop");
static int __id_run = __hxcpp_field_to_id("run");


Dynamic Timer_obj::__IField(int inFieldID)
{
	if (inFieldID==__id_delay) return delay_dyn();
	if (inFieldID==__id_stamp) return stamp_dyn();
	if (inFieldID==__id_id) return id;
	if (inFieldID==__id_stop) return stop_dyn();
	if (inFieldID==__id_run) return run;
	return super::__IField(inFieldID);
}

Dynamic Timer_obj::__SetField(const String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 2:
		if (!memcmp(inName.__s,L"id",sizeof(wchar_t)*2) ) { id=inValue.Cast<Dynamic >();return inValue; }
		break;
	case 3:
		if (!memcmp(inName.__s,L"run",sizeof(wchar_t)*3) ) { run=inValue.Cast<Dynamic >();return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Timer_obj::__GetFields(Array<String> &outFields)
{
	outFields->push(STRING(L"id",2));
	super::__GetFields(outFields);
};

static String sStaticFields[] = {
	STRING(L"delay",5),
	STRING(L"stamp",5),
	String(null()) };

static String sMemberFields[] = {
	STRING(L"id",2),
	STRING(L"stop",4),
	STRING(L"run",3),
	String(null()) };

static void sMarkStatics() {
};

Class Timer_obj::__mClass;

void Timer_obj::__register()
{
	Static(__mClass) = RegisterClass(STRING(L"haxe.Timer",10), TCanCast<Timer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Timer_obj::__boot()
{
}

} // end namespace haxe
