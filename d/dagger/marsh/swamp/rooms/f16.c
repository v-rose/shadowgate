#include <std.h>
#include "../marsh.h"

inherit FINH;

void create() 
{
    ::create();
    set_exits((["northwest": RPATH "f15",
	            "northeast": RPATH "f17",
      ]));
}
