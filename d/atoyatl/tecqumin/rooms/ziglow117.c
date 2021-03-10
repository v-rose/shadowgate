#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_FRONT_LOW;

void create() {
  ::create();
  set_exits( ([ "west" : ROOMS + "ziglow118" ,
	          "east" : ROOMS + "ziglow116"]) );

  set_climb_exits(([
       "climb":({ROOMS + "ziglow213",5,6,20})
  ]));
}

