//pathway28.c - Path through Lothwaite.  Circe 3/19/04
#include <std.h>
#include "../lothwaite.h"
inherit TOWNPATH;

void create(){
   ::create();
   set_long( ::query_long()+"  This seems to be the main pathway through the town.  "+
      "The path runs straight here for awhile to the west, while it leads over a "+
      "bridge and out of town to the southeast.\n");
   add_item("bridge","This thick wooden bridge was made of logs left in the "+
      "rough and packed with mud.  The river moving beneath it is about twenty "+
      "feet wide and moves swiftly.");
   add_item("river","The river looks very deep and frigid this high up in the mountains.");
   set_exits(([
      "west" : PATHEXIT"pathway26",
      "southeast" : PATHEXIT"pathway29",
   ]));
}