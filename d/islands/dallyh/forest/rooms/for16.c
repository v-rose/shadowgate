#include "/d/islands/dallyh/fways.h"
inherit DFOREST;
void create()
{
    ::create();
    set_exits(([
        "east" : FRPATH "for9",
        "northwest" : FRPATH "for17",
    ]));
}
