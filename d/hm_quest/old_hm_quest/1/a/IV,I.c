#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  set_exits( ([
                "south" : MAZEDIR+"1/a/IV,II",
                "west"  : MAZEDIR+"1/a/III,I"
           ]) );
}
