//amphisbeana.c

#include "summoned_monster.h"

inherit WEAPONLESS;

void create(){
	::create();
	set_name("amphisbaena");
	set_id(({"amphisbaena","Amphisbaena","snake"}));
	set_short("snake");
	set_long(
@OLI
	This odd snake has heads at both end of its body. Inside
each of the mouths you notice terrible fangs, you recognize that 
the poison of this snake is terribly deadly.
OLI
	);
	set_hd(8,1);
	set_hp(40);
	set_body_type("snake");
	add_limb("tail's head","tail",0,0,0);
	add_limb("tail's mouth","tail's head",0,0,0);
	set_damage(1,3);
	set_attacks_num(2);
	set_attack_limbs(({"mouth","tail's mouth"}));
	set_hit_funcs((["mouth":(:TO,"poison":),"tail's mouth":(:TO,"poison":)]));
	set_nat_weapon_type("piercing");
	set_gender("male");
	set_race("snake");
        set_exp(100);
	set_alignment(5);
	set_overall_ac(3);
}

int poison(object targ)
{
    if(!objectp(TO)) { return 0; }
	tell_object(targ,"%^BOLD%^%^RED%^The bite of this snake sends fear through you body!\n");
	//if("daemon/saving_d"->saving_throw(targ, "paralyzation_poison_death",3))
    if(userp(targ) || targ->fort_save(TO->query_level()))
		return 0;
	
	tell_object(targ,"%^BOLD%^%^RED%^You feel the horrid poison filter into your blood. Death is at hand!");
        return 1000;
}
