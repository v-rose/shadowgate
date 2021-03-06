#include <std.h>
inherit ROOM;

void create()
{
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
  set_property("light", 0);
  set_property("indoors", 1);
  set_short("A Hall of Tapestries");
  set_long("%^BOLD%^%^WHITE%^Well, I must say adventurer, you are a most persistant "
           "individual. And smart as well! Now let us see if you can figure "
           "your way to the next floor from here. As you can see, "
           "there are no exits here. The room is rather plain and would be exceptionally "
           "dull if it weren't for the fact that a single %^MAGENTA%^tapestry%^BOLD%^%^WHITE%^ hangs "
           "on each wall.%^RESET%^\n");
  set_smell("default", "It smells rather clean on this floor.");
  set_listen("default", "Your breathing is the only thing that breaks the silence.");
  set_items( ([
     "tapestry 1" : "You see a room identical to this one.",
     "tapestry 2" : "You see a room identical to this one.",
     "tapestry 3" : "You see a room identical to this one.",
     "tapestry 4" : "You see a room identical to this one."
]) );
  set_exits( ([
     "west" : "/d/koenig/town/tower26",
     "south" : "/d/koenig/town/tower26"
]) );
  set_invis_exits( ({"west", "south"}) );
}
void init() {
  ::init();
  add_action("enter_tapestry", "enter");
  add_action("lift_tapestry", "lift");
}
  int enter_tapestry(string str) {
  if(str=="tapestry 1") {
  write("You feel a shift in reality and find yourself in another room.");
  say(TPQCN+" enters a tapestry and disappears.");
  set_items( ([
     "tapestry 1" : "You see "+TPQCN+" in a room identical to this one."
]) );
  TP->move_player("/d/koenig/town/tower25");
  return 1;
}
  if(str=="tapestry 2") {
  write("You feel a shift in reality and find yourself in another room.");
  say(TPQCN+" enters a tapestry and disappears.");
  set_items( ([
     "tapestry 2" : "You see "+TPQCN+" in a room identical to this one."
]) );
  TP->move_player("/d/koenig/town/tower27");
  return 1;
}
  if(str=="tapestry 3") {
  write("You can not enter this one!");
  say(TPQCN+" looks foolish as they run into the wall in an attempt to enter the tapestry.");
  return 1;
}
  if(str=="tapestry 4") {
  write("You can not enter this one!");
  say(TPQCN+" looks foolish as they run into the wall in an attempt to enter the tapestry.");
  return 1;
}
  return 0;
}
 int lift_tapestry(string str) {
  if(str=="tapestry 1") {
  write("You can not lift this one!");
  say(TPQCN+" tries to lift the tapestry and fails.");
  return 1;
}
  if(str=="tapestry 2") {
  write("You can not lift this one!");
  say(TPQCN+" tries to lift the tapestry and fails.");
  return 1;
}
  if(str=="tapestry 3") {
  write("You discover an exit leading south.");
  say(TPQCN+" lifts athe tapestry and finds something.");
  return 1;
}
  if(str=="tapestry 4") {
  write("You discover an exit leading west.");
  say(TPQCN+" lifts the tapestry and finds something.");
  return 1;
}
  return 0;
}
