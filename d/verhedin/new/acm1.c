// Avenue of the Crescent Moon, Verhedin
// Thorn@ShadowGate
// 001027
// New City, Verhedin

#include <std.h>
#include "/d/tsarven/include/southern.h"
#include "/d/verhedin/include/city.h"

inherit ROOM;

void create() {
  room::create();
  set_light(2);
  set_short("%^BOLD%^Avenue of the Crescent Moon, Verhedin%^RESET%^");
  set_long(
@VERHEDIN
%^BOLD%^Avenue of the Crescent Moon, Verhedin%^RESET%^
You are on a wide cobbled street.  Here the street passes though an area
that appears to be quiet and residential.  On both sides, multi-story
homes built close together display colorful awnings over their windows
and the doors and shutters are ornately carved.  Some of the upper
levels have wooden screens over them in a manner often found farther to
the south.

To the northwest, you can see the great Northeast chainhouse tower above
the townhouses on the street.

You can go east or south down the street from here.
VERHEDIN
    );
  set_exits(([
    "east" : VNEW+"acm2",
    "south" : VNEW+"acm0"
   ]));
  set_listen("default","You hear the muted sounds of a busy city.");
  set_smell("default","You pick up the smells of a nearby river.");
  set_items( ([
    "chainhouse" : "The chainhouse appears to be an pentagonal stone tower about 5 stories high with arrow slits and a crenellated roof."
  ]) );
}

void reset(){
	::reset();
}
