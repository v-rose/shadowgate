//Coded by Bane//
#include <std.h>
inherit "/d/laerad/plains_base.c";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/plains/plains10",
	"east":"/d/laerad/plains/plains33",
	"south":"/d/laerad/plains/plains21",
	"north":"/d/laerad/plains/plains19"
    ]) );
}
