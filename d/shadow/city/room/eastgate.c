//updated the west exit to hook up correctly - it was skipping a room ~Circe~ 7/25/19
#include <std.h>
#include <daemons.h>

inherit CVAULT;

void create() {
    set_monsters( ({ "/d/shadow/city/mon/city_guard" }), ({roll_dice(1,4)+2}) );
    ::create();
    set_terrain(CITY);
    set_travel(PAVED_ROAD);
    set_property("light",2);
    set_property("indoors",1);
    set_short("East Gates of Shadow.");
    set_long(
"%^BOLD%^%^ORANGE%^You are at the East Gates of Shadow.%^RESET%^
%^RESET%^%^ORANGE%^You stand by a Portcullis. It is a stone structure, with strong steel-bound %^CYAN%^gates,%^ORANGE%^ and %^CYAN%^tower%^ORANGE%^ on each side. There are several guard posts here, and they seems to be busy patroling the area. The city of shadow lies west of you, through the %^CYAN%^arch%^MAGENTA%^w%^CYAN%^ay.%^RESET%^
"
        );
    set_exits( ([
                    "west":"/d/shadow/city/room/eastcross",
                    "east":"/d/shadow/virtual/desert/25,0.desert"
                    ]) );
    set_items(([
                   "gate" : "Tall wooden gates. There is no visible way to open them.",
                   "archway":"High archways lead into the walls around the city.",
                   "tower":"The towers loom high above the walls.",
                   "west":"The road heads west into the city."
                   ]));
    set_door("gate", "/d/shadow/virtual/desert/25,0.desert","east",0);
    set_lock_description("gate","lock","This is a huge bar across the giant door.");
    set_door_description("gate","These are two huge solid wooden doors that come together in the middle. They are bound together with giant dwarven forged iron bands.");

    set_open("gate",((string)EVENTS_D->query_time_of_day() != "night"));
    set_smell("default","You smell the brisk fragrance of oak from the gates.");
    set_listen("default","You hear the sounds of bustling people.");
}

void reset() {
    ::reset();
    set_open("gate",((string)EVENTS_D->query_time_of_day() != "night"));
    set_locked("gate", 0);
    if(!present("sign"))
        new("/d/shadow/obj/special/sign_shadow_docks")->move(TO);
}

