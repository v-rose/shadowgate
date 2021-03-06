// level 1 corridors

#include <std.h>
#include "../inherit/ruins.h"
inherit ROOM;

void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_property("light",0);
    set_name("Darkened corridor of an abandoned building");
    set_short("%^BLACK%^%^BOLD%^Darkened corridor of an abandoned building%^RESET%^");
    set_smell("default","Age-old dust fills the air, tickling at your nose.");
    set_listen("default","You can hear the faint scratching of claws on stone.");
    set_items(([
      "floor" : "%^ORANGE%^The floor is solid and level beneath your feet, though a thick layer of "
"%^BLACK%^%^BOLD%^dirt%^RESET%^%^ORANGE%^ and %^BLACK%^%^BOLD%^dust%^RESET%^%^ORANGE%^ covers it, making "
"it nearly impossible to see the original floor beneath.  In a few spots you can see the remains of what "
"were probably rather ornate patternings upon the floor, somehow still preserved beneath the "
"grime.%^RESET%^",
      ({"walls","wall"}) : "%^ORANGE%^The walls rise high on either side of you, crafted of strong "
"stone, and darkened by decades of %^BLACK%^%^BOLD%^dirt%^RESET%^%^ORANGE%^ and "
"%^BLUE%^weathering%^ORANGE%^.  In a few places, however, you can still make out the markings of "
"patterns along the walls, as if they have been somehow preserved over the ages.%^RESET%^",
      ({"dirt","dust"}) : "%^ORANGE%^A thick layer of %^BLACK%^%^BOLD%^dust%^RESET%^%^ORANGE%^ coats "
"every visible surface.  The building has probably been abandoned for a long time.%^RESET%^",
      "roof" : "%^ORANGE%^The roof reaches high above your head, shrouded in %^BLACK%^%^BOLD%^shadows%^RESET%^%^ORANGE%^ and %^BLACK%^%^BOLD%^dust%^RESET%^%^ORANGE%^.  Ornate bordering from nearby walls traces along the ceiling's edges.%^RESET%^"
    ]));
}
