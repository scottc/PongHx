#include <hxObject.h>

#include <pong/Main.h>
#include <pong/gfx/PongBackground.h>
#include <pong/ui/Keyboard.h>
#include <pong/gfx/Stage.h>
#include <pong/Ball.h>
#include <pong/gfx/Rectangle.h>
#include <pong/Paddle.h>
#include <pong/geom/Rectangle.h>
#include <haxe/Timer.h>
#include <pong/Game.h>
#include <Std.h>
#include <pong/MainMenu.h>
#include <pong/ui/Mouse.h>
#include <pong/gfx/Label.h>
#include <pong/geom/Vector.h>

void __boot_all()
{
RegisterResources( GetResources() );
pong::Main_obj::__register();
pong::gfx::PongBackground_obj::__register();
pong::ui::Keyboard_obj::__register();
pong::gfx::Stage_obj::__register();
pong::Ball_obj::__register();
pong::gfx::Rectangle_obj::__register();
pong::Paddle_obj::__register();
pong::geom::Rectangle_obj::__register();
haxe::Timer_obj::__register();
pong::Game_obj::__register();
Std_obj::__register();
pong::MainMenu_obj::__register();
pong::ui::Mouse_obj::__register();
pong::gfx::Label_obj::__register();
pong::geom::Vector_obj::__register();
Std_obj::__init__();
pong::geom::Vector_obj::__boot();
pong::gfx::Label_obj::__boot();
pong::ui::Mouse_obj::__boot();
pong::MainMenu_obj::__boot();
Std_obj::__boot();
pong::Game_obj::__boot();
haxe::Timer_obj::__boot();
pong::geom::Rectangle_obj::__boot();
pong::Paddle_obj::__boot();
pong::gfx::Rectangle_obj::__boot();
pong::Ball_obj::__boot();
pong::gfx::Stage_obj::__boot();
pong::ui::Keyboard_obj::__boot();
pong::gfx::PongBackground_obj::__boot();
pong::Main_obj::__boot();
}

