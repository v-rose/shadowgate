#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_LOW;

void create() {
  ::create();
  set_exits( ([ "north" : ROOMS + "ziglow211" ,
	          "south" : ROOMS + "ziglow209"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid108",5,6,20}),
     "descend":({ROOMS + "ziglow112",5,6,20}),
  ]));

}
