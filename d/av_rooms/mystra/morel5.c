// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("morel5");
    set_property("indoors",0);
    set_property("light",3);
    set_property("no teleport",1);
    set_terrain("city");
    set_travel("paved road");
    set_climate("temperate");

    set_short("%^GREEN%^Morel Street%^RESET%^");

    set_long("%^GREEN%^Morel Street %^MAGENTA%^is alive with energy at this end of the road.  To the east the castle gates grow nearer.  A few shops are nearby but the main travel on this road is for business with "
	"local and country government.%^RESET%^"
	);

    set_smell("default","
%^CYAN%^Must and decay penetrate the air%^RESET%^");
    set_listen("default","%^BOLD%^%^YELLOW%^Business chatter and galloping horses find your ears%^RESET%^");


    set_exits(([ 
		"northeast" : "/d/av_rooms/mystra/castle1",
		"west" : "/d/av_rooms/mystra/morel4",
	]));

}