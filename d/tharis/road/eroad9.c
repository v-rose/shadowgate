#include <std.h>
#include "../eroad.h"
inherit EROAD;

void create(){
        ::create();
        set_exits(([
                "west":"/d/tharis/road/eroad8",
//                 "south":"/d/tharis/road/south1",
                "east":"/d/tharis/road/eroad10"
        ]));
}
