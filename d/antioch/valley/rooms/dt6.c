
#include "../valley.h"
inherit DTRAIL;

void create()
{
  ::create();
   set_exits( ([
   "southwest" : ROOMS+"dt5",
   "east" : ROOMS+"dt7",
   ]) );
}
