//Coded by Bane//
#include <std.h>
inherit "/d/laerad/cavern1/special/croom_cavern.c";
void create()
{
    set_monsters(({ "/d/laerad/mon/illithid2", "/d/laerad/mon/fungus" }), ({ 1, 1 }));
    ::create();
    set_repop(90);
    set_short("Laerad caverns");
    set_property("indoors", 1);
    set_property("light", 2);
    set_smell("default", "The air is surprisingly clean and refreshing.");
    set_listen("default", "You can hear the trickling of the stream.");
    set_exits(([
                   "north" : "/d/laerad/cavern1/cav043",
                   "west" : "/d/laerad/cavern1/cav048",
                   "east" : "/d/laerad/cavern1/cav047",
                   "southwest" : "/d/laerad/cavern1/cav045",
                   "northeast" : "/d/laerad/cavern1/cav046"
               ]));
}

void reset()
{
    ::reset();
/* changing to be controlled by CROOM
    if(!present("illithid")){
    new("/d/laerad/mon/illithid2")->move(this_object());
    }
    if(!present("fungus")){
    new("/d/laerad/mon/fungus")->move(this_object());
    }
 */
}
