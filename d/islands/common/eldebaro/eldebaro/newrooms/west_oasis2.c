#include <std.h>
#include "../area_stuff.h"

inherit WESTOASIS;

void create()
{
    ::create();
    set_exits(([
        "south" : ELROOMSW+"3",
        "east" : ELROOMSW+"5",
        "north" : ELROOMSW+"1",
    ]));
}
