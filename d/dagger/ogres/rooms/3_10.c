#include <std.h>
#include "../ogres.h"

inherit STORAGE"3rd.c";

void create(){
   ::create();
   set_exits(([
      "east" : ROOMS"ogremaze1",
      "west" : ROOMS"3_9",
   ]));

}
