#include <std.h>

inherit ROOM;

void place_board()
{
  string which, desc;
  object ob;
  which = "Ridboard";
  desc = "rid";
  if (!objectp(present("board", TO))) {
    ob = new("std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", which }) );
    ob->set_board_id(which);
    ob->set("short", "OOC "+desc+" board");
    ob->set("long", "The ooc board for information about "+desc);
    ob->set_max_posts(150);
    ob->set_location("/d/common/boards/ridboard");
//    ob->set_restricted_read();  // read isn't restricted but posting is
//    ob->set_restricted_post();  // restriction is in the command
    ob->set_ooc_board(1);
    ob->set_no_clean(1);  // so they don't dest while someone is posting, etc.
  }
}

void create(){
    ::create();
    set_no_clean(1);
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no teleport",1);
    set_short("RID board room");
    set_long("Just one of the rooms housing a board.  Nothing more, "
             "nothing less.");
    set_exits( ([ "out" : "/d/dagger/boards_portal", ]) );
    //place_board();
}

void reset() 
{
    ::reset();
    place_board();
}
