#include <std.h>

inherit LRWEAPON;

void create(){
    ::create();
    set_id(({"shurikens"}));
    set_name("shurikens");
    set_short("A stack of shurikens");
    set_long(
        "This is a stack of throwing all-edges knives known as shurikens."
        );
    set_prof_type("staff");
    set_weight(1);
    set_type("piercing");
    set_decay_rate(100);
    set_range(2,4,8);
    set_ammo("shuriken");
    set_lr_prof_type("sling");
    set_weapon_prof("exotic");
    set_lr_type("piercing");
    set_size(1);
    set_wc(1,4);
    set_large_wc(1,4);
    set_value(3);
    set_rate_of_fire(2);
    set_weapon_speed(2);
}

