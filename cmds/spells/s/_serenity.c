#include <std.h>
#include <daemons.h>
#include <spell.h>
#include <magic.h>


inherit SPELL;

void create() {
    ::create();
    set_spell_name("serenity");
    set_spell_level(([ "mage" : 6, "cleric" : 5, "bard" : 4, "psion" : 6 ]));
    set_spell_sphere("enchantment_charm");
    set_discipline("telepath");
    set_syntax("cast CLASS serenity");
    set_damage_desc("mental");
    set_description("This spell sends a serene song into mind of everyone present. Those who attack you will feel mental pain of overcoming contradiction. Strong-willed will shrug this song off.");
    splash_spell(1);
    set_save("will");
}

void spell_effect(int prof){
    object *attackers;
    int i,admg;
    attackers = caster->query_attackers();
    attackers = filter_array(attackers, "is_non_immortal",FILTERS_D);
    attackers = target_filter(attackers);

    tell_object(caster,"%^MAGENTA%^You send a serene song into minds of everyone present.%^RESET%^");
    tell_room(place,"%^MAGENTA%^"+caster->QCN+" sends a serene song into your mind.%^RESET%^",({caster}));
    if(!sizeof(attackers)){
        dest_effect();
        return;
    }

    for(i=0;i<sizeof(attackers);i++){
        if(!objectp(attackers[i])) continue;
        define_base_damage(0);
        admg=sdamage;
        if(do_save(target))
            continue;
        tell_object(attackers[i],"%^MAGENTA%^Your head hurts as you try to overcome the song while attacking "+caster->QCN+"!%^RESET%^");
        tell_room(place,"%^MAGENTA%^"+attackers[i]->QCN+" twitches with pain.%^RESET%^",({attackers[i]}));
        damage_targ(attackers[i],attackers[i]->return_target_limb(),admg,"mental");
    }
    spell_successful();
    dest_effect();
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
