#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        //"north" : ELROOMSD+"52",
        "east" : ELROOMSD+"82",
        //"south" : ELROOMSD+"64",
        "west" : ELROOMSD+"80",
        
    ]));
}
