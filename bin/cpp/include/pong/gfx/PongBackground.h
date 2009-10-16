#ifndef INCLUDED_pong_gfx_PongBackground
#define INCLUDED_pong_gfx_PongBackground

#include <hxObject.h>

#include <pong/gfx/Rectangle.h>
DECLARE_CLASS2(pong,gfx,IDisplayObject)
DECLARE_CLASS2(pong,gfx,PongBackground)
DECLARE_CLASS2(pong,gfx,Rectangle)
namespace pong{
namespace gfx{


class PongBackground_obj : public pong::gfx::Rectangle_obj
{
	public:
		typedef pong::gfx::Rectangle_obj super;
		typedef PongBackground_obj OBJ_;

	protected:
		PongBackground_obj();
		Void __construct(double width_,double height_);

	public:
		static hxObjectPtr<PongBackground_obj > __new(double width_,double height_);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(DynamicArray inArgs);
		~PongBackground_obj();

		DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark();
		String __ToString() const { return STRING(L"PongBackground",14); }

};

} // end namespace pong
} // end namespace gfx

#endif /* INCLUDED_pong_gfx_PongBackground */ 
