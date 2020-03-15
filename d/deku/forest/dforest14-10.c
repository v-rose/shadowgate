#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"15-10",
       "east" : F_ROOMS"13-10",
       "north" : F_ROOMS"14-11",
       "south" : F_ROOMS"14-9",
       "southeast" : F_ROOMS"13-9",
       "southwest" : F_ROOMS"15-9",
       "northeast" : F_ROOMS"13-11",
       "northwest" : F_ROOMS"15-11",
    ] ));
}
