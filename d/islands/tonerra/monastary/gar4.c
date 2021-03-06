//gar1.c

#include <std.h>
#include "/d/islands/tonerra/areadefs.h"

inherit ROOM;

int unlocked;

void create(){
   ::create();
   set_terrain(GARDEN);
   set_travel(FOOT_PATH);

   set_short("Garden in the monastery");
   set_property("light",2);
   set_long(
@OLI
   %^BOLD%^%^GREEN%^This is the garden in the monastery%^RESET%^
%^RESET%^%^GREEN%^This is a peaceful spot. A path of %^BOLD%^%^BLACK%^shale%^RESET%^%^GREEN%^ leads deeper into the
small garden. The monks must spend remarkable amounts of time
perfecting the landscape. Sculpted %^BOLD%^bushes%^RESET%^%^GREEN%^ and %^BOLD%^grand trees%^RESET%^%^GREEN%^ rise
around you. The world really does seem to slow and harmonize here.
You see %^CYAN%^four columns%^GREEN%^ in the garden. One here with you, one to the south,
one to the west, and one to the southwest.%^RESET%^
OLI
   );
   set_items(([
      "column":(:TO,"lookFun":),
      "trees":"These magnificent creatures are ancient. They out date anything here.",
      "bushes":"These bushes have been sculpted but seem natural as if the cutters brough out the nature of the bush.",
      "inset":"This elongated carving looks like it something should be inserted into it.",
   ]));
   set_exits(([
      "east":MONASTERY+"hall8",
      "southwest":MONASTERY+"gar5",
      "west":MONASTERY+"gar3",
   ]));
   set_invis_exits(({"east"}));
}

void lookFun(){
   tell_room(TO,"%^BOLD%^%^CYAN%^"+TPQCN+" looks over the column and becomes entranced.",TP);
   write(
@OLI
   You see visions of the monks stretching and dodging. They run quickly in
   and out of your vision. They jump and dodge in mock combat. The amazing
   movement and speed bring to life the very nature of their martial skills.
OLI
   );
   write("You shake off the vision and you notice that there is a inset in the column.");


}

void init(){
   ::init();

   add_action("insert","insert");
}

int insert(string str){
   object ob;
   if(!str || (str != "crystal" && str != "dexterity")){
      return notify_fail("Insert what?\n");
   }

   if(unlocked){
      return notify_fail("The inset has been filled.");
   }

   if(!present(str,TP)){
      return notify_fail("That is not here.\n");
   }

   if(!ob = present("dexterity crystal",TP)){
      return notify_fail("That item will not insert here.\n");
   }

   tell_room(TO,"%^BLUE%^The room shakes as "+TPQCN+" inserts the crystal.",TP);
   write("%^BLUE%^The room shakes as you insert the crystal.");
   ob->remove();
   keep_rooms(TO_KEEP); // needed so the memory cleaner doesn't wipe them before a player finishes.
   unlocked = 1;
   return 1;
}

int query_unlocked(){
   return unlocked;
}

void reset(){
   ::reset();

   tell_room(TO,"%^BLUE%^The room shakes as things are returned.");
   unlocked = 0;
}
