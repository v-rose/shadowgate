#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"36-2",
       "east" : F_ROOMS"34-2",
       "north" : F_ROOMS"35-3",
       "south" : F_ROOMS"35-1",
       "southeast" : F_ROOMS"34-1",
       "southwest" : F_ROOMS"36-1",
       "northeast" : F_ROOMS"34-3",
       "northwest" : F_ROOMS"36-3",
    ] ));
}
