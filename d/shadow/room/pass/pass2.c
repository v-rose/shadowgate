#include <std.h>
#include "../pass.h"
inherit ROOM;

void create(){
    ::create();
   set_terrain(ROCKY);
   set_travel(DIRT_ROAD);
    set_property("light" , 2);
    set_property("indoors" , 0);
    set_short("On Dragon Pass Road");
    set_long(
@MELNMARN
%^BOLD%^You are walking on the Dragon Pass Road.%^RESET%^
%^ORANGE%^To the north of you lie the Charu Mountains. They are very intimidating, looming high in the sky. South of you is the NorthGate to Shadow.
MELNMARN
);

    set_smell("default","You can smell the fresh mountain air.");
    set_listen("default","You can hear the wind blowing through the valleys.");


    set_items(([
	"road":"A new road through the mountains.",
	"mountains":"They are impressive, even from here.",
	]));

    set_exits(([
	"south" : PASSDIR+"pass1",
	"north" : PASSDIR+"passn11"
   	]));
}
