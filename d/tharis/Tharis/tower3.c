// /d/tharis/Tharis/tower3.c //
#include <std.h>

inherit ROOM;
void create() {
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("no sticks", 1);
    set_light(2);
    set_indoors(1); 
   set_short("One of the watch Towers");
    set_long(
@OLI
        You are in one of the watch towers along the West Wall.
The room is barren, except for a table and some chairs. The
guards now use this for a lounge and common room. There are often
off duty guards in here.
        There is a staircase to the upper part of the tower.
To the south and to the northeast are the wall.
OLI
    );
   set_smell("default","Your senses are accosted by the normal smells of a city.");
   set_listen("default","The city bustles below you.");
    set_exits(([
"northeast" : "/d/tharis/Tharis/wall7",
"south" : "/d/tharis/Tharis/wall8",
"up":"/d/tharis/Tharis/tower3t",
 ] ));
set_items(([
"table":"The table is cluttered with various papers and a mug or two."
]));
}
void reset(){
  int num;
  int i;
  ::reset();
  if(!present("patrol") && !random(4)) {
    num=random(4);
    for(i=0;i<num;i++){
       new("d/tharis/monsters/wall_patrol")->move(TO);
    }
  }
}