#include <hxObject.h>

#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
namespace haxe{

Void Log_obj::__construct()
{
	return null();
}

Log_obj::~Log_obj() { }

Dynamic Log_obj::__CreateEmpty() { return  new Log_obj; }
hxObjectPtr<Log_obj > Log_obj::__new()
{  hxObjectPtr<Log_obj > result = new Log_obj();
	result->__construct();
	return result;}

Dynamic Log_obj::__Create(DynamicArray inArgs)
{  hxObjectPtr<Log_obj > result = new Log_obj();
	result->__construct();
	return result;}

BEGIN_DEFAULT_FUNC(__default_trace,Log_obj)
Void run(Dynamic v,Dynamic infos){
{
		__trace(v,infos);
	}
return null();
}
END_LOCAL_FUNC2((void))
END_DEFAULT_FUNC

Dynamic Log_obj::trace;

BEGIN_DEFAULT_FUNC(__default_clear,Log_obj)
Void run(){
{
	}
return null();
}
END_LOCAL_FUNC0((void))
END_DEFAULT_FUNC

Dynamic Log_obj::clear;


Log_obj::Log_obj()
{
}

void Log_obj::__Mark()
{
}

Dynamic Log_obj::__Field(const String &inName)
{
	switch(inName.length) {
	case 5:
		if (!memcmp(inName.__s,L"trace",sizeof(wchar_t)*5) ) { return trace; }
		if (!memcmp(inName.__s,L"clear",sizeof(wchar_t)*5) ) { return clear; }
	}
	return super::__Field(inName);
}

static int __id_trace = __hxcpp_field_to_id("trace");
static int __id_clear = __hxcpp_field_to_id("clear");


Dynamic Log_obj::__IField(int inFieldID)
{
	if (inFieldID==__id_trace) return trace;
	if (inFieldID==__id_clear) return clear;
	return super::__IField(inFieldID);
}

Dynamic Log_obj::__SetField(const String &inName,const Dynamic &inValue)
{
	switch(inName.length) {
	case 5:
		if (!memcmp(inName.__s,L"trace",sizeof(wchar_t)*5) ) { trace=inValue.Cast<Dynamic >();return inValue; }
		if (!memcmp(inName.__s,L"clear",sizeof(wchar_t)*5) ) { clear=inValue.Cast<Dynamic >();return inValue; }
	}
	return super::__SetField(inName,inValue);
}

void Log_obj::__GetFields(Array<String> &outFields)
{
	super::__GetFields(outFields);
};

static String sStaticFields[] = {
	STRING(L"trace",5),
	STRING(L"clear",5),
	String(null()) };

static String sMemberFields[] = {
	String(null()) };

static void sMarkStatics() {
	MarkMember(Log_obj::trace);
	MarkMember(Log_obj::clear);
};

Class Log_obj::__mClass;

void Log_obj::__register()
{
	Static(__mClass) = RegisterClass(STRING(L"haxe.Log",8), TCanCast<Log_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Log_obj::__boot()
{
	Static(trace) = new __default_trace;

	Static(clear) = new __default_clear;

}

} // end namespace haxe
