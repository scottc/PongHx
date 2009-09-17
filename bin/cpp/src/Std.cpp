#include <hxObject.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif

Void Std_obj::__construct()
{
	return null();
}

Std_obj::~Std_obj() { }

Dynamic Std_obj::__CreateEmpty() { return  new Std_obj; }
hxObjectPtr<Std_obj > Std_obj::__new()
{  hxObjectPtr<Std_obj > result = new Std_obj();
	result->__construct();
	return result;}

Dynamic Std_obj::__Create(DynamicArray inArgs)
{  hxObjectPtr<Std_obj > result = new Std_obj();
	result->__construct();
	return result;}

void Std_obj::__init__(){
	null();
}


bool Std_obj::is( Dynamic v,Dynamic t){
	return ::__instanceof(v,t);
}


STATIC_DEFINE_DYNAMIC_FUNC2(Std_obj,is,return )

String Std_obj::string( Dynamic s){
	return s == null() ? String( STRING(L"null",4) ) : String( s->__ToString() );
}


STATIC_DEFINE_DYNAMIC_FUNC1(Std_obj,string,return )

int Std_obj::toInt( double x){
	return ::__int__(x);
}


STATIC_DEFINE_DYNAMIC_FUNC1(Std_obj,toInt,return )

Dynamic Std_obj::parseInt( String x){
	{
		if (x == null())
			return null();
		return ::ParseInt(x);
	}
}


STATIC_DEFINE_DYNAMIC_FUNC1(Std_obj,parseInt,return )

double Std_obj::parseFloat( String x){
	return ::ParseFloat(x.__s);
}


STATIC_DEFINE_DYNAMIC_FUNC1(Std_obj,parseFloat,return )

int Std_obj::random( int x){
	return hxMod(::rand(),x);
}


STATIC_DEFINE_DYNAMIC_FUNC1(Std_obj,random,return )


Std_obj::Std_obj()
{
}

void Std_obj::__Mark()
{
}

Dynamic Std_obj::__Field(const String &inName)
{
	switch(inName.length) {
	case 2:
		if (!memcmp(inName.__s,L"is",sizeof(wchar_t)*2) ) { return is_dyn(); }
		break;
	case 3:
		if (!memcmp(inName.__s,L"int",sizeof(wchar_t)*3) ) { return toInt_dyn(); }
		break;
	case 6:
		if (!memcmp(inName.__s,L"string",sizeof(wchar_t)*6) ) { return string_dyn(); }
		if (!memcmp(inName.__s,L"random",sizeof(wchar_t)*6) ) { return random_dyn(); }
		break;
	case 8:
		if (!memcmp(inName.__s,L"parseInt",sizeof(wchar_t)*8) ) { return parseInt_dyn(); }
		break;
	case 10:
		if (!memcmp(inName.__s,L"parseFloat",sizeof(wchar_t)*10) ) { return parseFloat_dyn(); }
	}
	return super::__Field(inName);
}

static int __id_is = __hxcpp_field_to_id("is");
static int __id_string = __hxcpp_field_to_id("string");
static int __id_toInt = __hxcpp_field_to_id("int");
static int __id_parseInt = __hxcpp_field_to_id("parseInt");
static int __id_parseFloat = __hxcpp_field_to_id("parseFloat");
static int __id_random = __hxcpp_field_to_id("random");


Dynamic Std_obj::__IField(int inFieldID)
{
	if (inFieldID==__id_is) return is_dyn();
	if (inFieldID==__id_string) return string_dyn();
	if (inFieldID==__id_toInt) return toInt_dyn();
	if (inFieldID==__id_parseInt) return parseInt_dyn();
	if (inFieldID==__id_parseFloat) return parseFloat_dyn();
	if (inFieldID==__id_random) return random_dyn();
	return super::__IField(inFieldID);
}

Dynamic Std_obj::__SetField(const String &inName,const Dynamic &inValue)
{
	return super::__SetField(inName,inValue);
}

void Std_obj::__GetFields(Array<String> &outFields)
{
	super::__GetFields(outFields);
};

static String sStaticFields[] = {
	STRING(L"is",2),
	STRING(L"string",6),
	STRING(L"int",3),
	STRING(L"parseInt",8),
	STRING(L"parseFloat",10),
	STRING(L"random",6),
	String(null()) };

static String sMemberFields[] = {
	String(null()) };

static void sMarkStatics() {
};

Class Std_obj::__mClass;

void Std_obj::__register()
{
	Static(__mClass) = RegisterClass(STRING(L"Std",3), TCanCast<Std_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics);
}

void Std_obj::__boot()
{
}

