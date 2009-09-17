#ifndef INCLUDED_haxe_Timer
#define INCLUDED_haxe_Timer

#include <hxObject.h>

DECLARE_CLASS1(haxe,Timer)
namespace haxe{


class Timer_obj : public virtual hxObject
{
	public:
		typedef hxObject super;
		typedef Timer_obj OBJ_;

	protected:
		Timer_obj();
		Void __construct(int time_ms);

	public:
		static hxObjectPtr<Timer_obj > __new(int time_ms);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(DynamicArray inArgs);
		~Timer_obj();

		DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		String __ToString() const { return STRING(L"Timer",5); }

		Dynamic id;
		virtual Void stop( );
		Dynamic stop_dyn();

		Dynamic run;
		inline Dynamic &run_dyn() {return run; }

		static haxe::Timer delay( Dynamic $t1,int time_ms);
		static Dynamic delay_dyn();

		static double stamp( );
		static Dynamic stamp_dyn();

};

} // end namespace haxe

#endif /* INCLUDED_haxe_Timer */ 
