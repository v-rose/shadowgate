#include <std.h>
inherit "/d/common/obj/armour/leather";

void create() {
    ::create();
    //set_name("sleather");
    //set("id", ({ "leather","leather armor", "armor", "armour" }) );
    set_short("A small suit of leather armor");
    //set("long", 
    //  "This armor is made of leather, hardened in boiling oil and then "
    //  "shaped into breastplate and shoulder protectors. The rest of the "
    //  "suit is made of softer, more flexable materials."
    //);
    set_size(1);
   // set_weight(15);
   // set("value", 5);
   // set_type("leather");
   // set_limbs( ({ "torso" }) );
   // set_ac(2);
}

int is_metal() { return 0; }
