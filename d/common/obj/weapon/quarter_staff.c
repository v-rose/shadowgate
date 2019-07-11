#include <std.h>

inherit "/std/weapon";

create() {
    ::create();
    set_id(({ "staff", "quarter","quarter staff","shillelagh",
        "wooden staff", "fine wooden staff", "quarter_staff" }));
    set_name("quarter staff");
    set_short("A wooden quarter staff");
    set_long(
   "This is a sturdy six foot long wooden staff.  It has bands of metal "
   "tightened around its far edges and along its length to afford it more "
   "support.  A staff is a traveling tool has many uses and the street "
   "thugs are aware enough of one to keep away from them."
    );
    set_wc(2,4);
    set_large_wc(2,5);
    set_weight(4);
    set_size(3);
    set("value", 3);   
    set_type("magebludgeon");
    set_prof_type("staff");
   set_weapon_speed(4);
   set_weapon_prof("simple");
   set_property("repairtype",({"woodwork"}));
   
   set_critical_threat_range(1);
   set_critical_hit_multiplier(2);
   set_damage_type("bludgeoning");
}
