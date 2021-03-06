#include <std.h>
inherit ROOM;

void create(){
  ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
set_property("light", 2);
  set_short("A Street in Daggerdale.");
  set("day long",
@GIL
%^ORANGE%^You are on South Thorn Lane.
The street runs North and South from here.
There is an alchemist's shop to the West.
A metal pole holds an unlit lantern aloft here.
The high city wall lies to the East of the street.
GIL
);
  set("night long",
@GIL
%^YELLOW%^You are on South Thorn Lane.
The street runs North and South from here.
There is an alchemist's shop to the West.
A metal pole here holds a lit lantern aloft and brightens the night.
The high city wall lies to the East of the street.
GIL
);
set_smell("default", "You catch the scent of an alchemist's potions brewing.");
set_listen("default", "You can hear the sounds of villagers.");
  set_items(([
"pole" : "It's made of steel and holds a lantern to light the darkness",
"street" : "It's made of clean polished cobblestones.",
"lantern" : "It's a large oil lantern with crystal glass windows.",
"building" : "It's made of perfectly carved granite blocks, it's Dwarven stone work.",
"wall" : "It's 50 foot tall and made from huge polished granite blocks.",
]));

  set_exits(([
"north" : "/d/dagger/Daggerdale/streets/street25",
"south" : "/d/dagger/Daggerdale/streets/street12",
"west" : "/d/dagger/Daggerdale/shops/alchemistshop",
     ]));
}
void reset(){
::reset();
if(!present("lantern pole")){
new("/d/dagger/Daggerdale/streets/items/objs/lantern_pole.c")->move(TO);
}
}
