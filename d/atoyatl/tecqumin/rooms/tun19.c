#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit TUNBASE;

void create() {
  ::create();

  set_exits( ([ "west" : ROOMS + "tun20" ,
                "northeast" : ROOMS + "tun18"]) );

}
