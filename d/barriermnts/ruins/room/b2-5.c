#include <std.h>
#include "../inherit/ruins.h"
inherit BASE+"l0";

void create() {
    set_monsters(({MON+"cultspirit"}),({1}));
    ::create();
    set_repop(40);
    set_long("%^BLUE%^The corridor widens here, leading off to the east and west into darkness.  The "
"roof reaches high above your head, barely visible within the "
"%^BLACK%^%^BOLD%^shadows%^RESET%^%^BLUE%^ that seem almost alive with movement.  Stone walls surround "
"you on either side, blackened with %^BLACK%^%^BOLD%^shadows%^RESET%^%^BLUE%^ and "
"%^ORANGE%^grime%^BLUE%^.  The floor beneath your feet feels perfectly flat, without rubble or upturned "
"stones to impede your progress, but a thick layer of %^WHITE%^foggy mist%^BLUE%^ around your feet makes "
"it impossible to see.  The silence is absolute down here, hanging thickly in the air around "
"you.%^RESET%^\n");
    set_exits(([
      "north" : ROOMS+"b3-5",
      "west" : ROOMS+"b2-4"
    ]));
}
