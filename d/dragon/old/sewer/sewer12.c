#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    room::create();
    set_property("light",0);
    set_property("indoors",1);
    set_short("Sanctuary Sewers");
    set_long("%^RED%^%^BOLD%^
These are the disgusting sewers under the city of Sanctuary.  They are
filled with many strange objects.  The tunnel stretches toward the east 
and toward the west.  The dark walls are covered with disgusting slime 
mold from the many decades of sewage that flowed within here.
    ");
    set_exits(([
       "east" : "/d/dragon/sewer/sewer11",
       "west" : "/d/dragon/sewer/sewer13"
    ] ));
    set_items(([
       "sewers":"The disgusting tunnels of waste under Sanctuary."
    ] ));
}
