//tymora_badge.c - Standard faith item for tymora
#include <std.h>
inherit ARMOUR;

void create() {
  ::create();
  set_name("tymora badge");                        
  set_id(({"badge","tymora badge","coin","simple silver coin","silver coin","clasp"}));
  set_short("A simple silver coin");   
  set_long("This simple silver coin has been fashioned "+
     "with the image of a young woman's smiling face upon "+
     "it.  It is fantastically detailed and highly polished.  "+
     "The coin has been affixed to a sturdy pin that would "+
     "pierce the strongest materials, or it may be "+
     "worn as a cloak clasp.");
  set_lore("This brooch is granted to followers of Tymora who have "+
     "proven their faith and dedication to their goddess.");
  set_property("lore difficulty",10);
  set_type("ring");
  set_ac(0);  
  set_weight(1);
  set_value(125);
  set_limbs(({"torso"}));
  set_property("enchantment",1);
  set_wear((:TO,"wearme":));      
  set_remove((:TO,"unwearme":));
}

int wearme(){
   if((string)ETO->query_diety() == "tymora"){
      tell_object(ETO,"You feel the blessings of Tymora as you wear the clasp.");
      return 1;
   }
   else{
      tell_object(ETO,"The clasp stings your chest as you try to take what is not meant for you!");
      set_property("magic",1);
      ETO->do_damage("torso",random(10)+10);
      ETO->add_attacker(TO);
      ETO->continue_attack();
      ETO->remove_attacker(TO);
      remove_property("magic");
      return 0;
   }
}

int unwearme(){
   tell_object(ETO,"You feel a pang of regret as you remove the clasp.");
   return 1;
}
