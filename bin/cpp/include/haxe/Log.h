#ifndef INCLUDED_haxe_Log
#define INCLUDED_haxe_Log

#include <hxObject.h>

DECLARE_CLASS1(haxe,Log)
namespace haxe{


class Log_obj : public virtual hxObject
{
	public:
		typedef hxObject super;
		typedef Log_obj OBJ_;

	protected:
		Log_obj();
		Void __construct();

	public:
		static hxObjectPtr<Log_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(DynamicArray inArgs);
		~Log_obj();

		DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		String __ToString() const { return STRING(L"Log",3); }

		static Dynamic trace;
		static inline Dynamic &trace_dyn() {return trace; }

		static Dynamic clear;
		static inline Dynamic &clear_dyn() {return clear; }

};

} // end namespace haxe

#endif /* INCLUDED_haxe_Log */ 
