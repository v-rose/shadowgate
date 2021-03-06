#include <std.h>
inherit DAEMON;

void create() { ::create(); }

// stats in order: str, dex, con, int, wis, cha
int *min_stats() { return ({ 3, 3, 3, 3, 3, 3 }); }
int *max_stats() { return ({ 18, 18, 18, 18, 18, 18 }); }
int *stat_adj()  { return ({ 0, 0, 0, 0, 0, 0 }); }

// age at which each age cat starts: normal, middle, old, venerable
int *age_brackets() { return ({ 17, 45, 60, 90 }); }

int *restricted_alignments() { return ({}); }

string *restricted_classes() { return ({}); }

int is_restricted() { return 1; } // restricted races by approval



// Stuff needed to replace what was in the old race database

string race_name() { return "kender"; }

int sight_bonus() { return 2; }

// gets used in a forumla based on con to determine actual weight
int weight() { return 7000; }

int fingers() { return 5; }

string *wielding_limbs() { return ({ "right hand", "left hand" }); }

mapping monster_stat_rolls() { return ([ "str" : -2, "con" : -3, "int" : -1, "wis" : 0, "dex" : 9, "cha" : -4 ]); }

int size() { return 1; }

int natural_AC() { return 0; }


string *limbs()
{
    return ({  "head",
               "right arm",
               "right hand",
               "left arm",
               "left hand",
               "left leg",
               "left foot",
               "right leg",
               "right foot",
               "waist",
               "neck" });
}