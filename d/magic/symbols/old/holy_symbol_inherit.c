//      Magic Book for Wizard Characters [v2.0]
//      Thorn@Shadowgate
//		converted to holy_symbol in adlib manner for clerical use
//		Tristan@Shadowgate
//      10/10/94 [2.0: 6/8/95]
//      General Wizard Class Items
//		General Cleric
//      magic_book.c
//      holy_symbol.c
//      took god names out of the prayer ending message 12/26/04 Tsera
//      changed symbols to show rangers spells 1-5, and paladins/anti's 1-6 -Tsera
//      changed symbols to query for spell class to allow spells to be 
//      set for one type of class 3/22/05 -Tsera
//      Made wearable by Circe 4/10/05 after approval from T

#include <std.h>
#include <daemons.h>
#include <security.h>
#include <magic.h>
#include <ansi.h>

#define CLS ESC+"[H"+ESC+"[2J"

inherit ARMOUR;

int forget_spell(string str);
void memorize2(string str, int sl, object play);
void set_holy_symbol(string spell);
void remove_spell(string spell);
void set_owner();
void line();
int add_all();
int add_spell(string str);
string query_owner();
int wisdom_bonus(object player, int level);
void set_diety(string diety);
string query_diety();
void set_sphere(string str);
string query_sphere();
void sort();
void sort_two();private void swap(int i, int j);

mapping spells = ([]);
string *magic, owner;
int temp;
string diety, sphere_of_influence,class;


int is_holy_symbol() {
    return 1;
}

void set_owner() {
    //if (interactive(ETO)) {
        owner = ETO->query_name();
    //}
    return;
}

string query_owner() {
    return owner;
}

void set_sphere(string str) {
    sphere_of_influence = str;
}

string query_sphere() {
    return sphere_of_influence;
}

void set_diety(string str) {
    diety = str;
    set_short("A holy symbol of "+capitalize(str));
}

string query_diety() {
    return diety;
}

void create() {
    ::create();
    set_id( ({ "holy symbol","symbol"}) );
    set_name("holy symbol");
    set_short("Holy Symbol");
    //set_property("no offer",1);
    set_property("no animate",1);
    //set_property("no steal",1);
/* changing to allow to stay with the corpse so those being raised from dead (bypasses the church giving it back) aren't then stuck without one  *Styx*  8/29/03
    set_property("death remove", 1);
*/
    set_long("Holy Symbol");
    set_type("ring");
    set_weight(1);
}

int valid_has_cleric_spells() {
    if(ETO->is_class("cleric") 
    || ETO->is_class("paladin")
    || ETO->is_class("antipaladin") 
    || ETO->is_class("ranger")) {
        return 1;
    }
    return 0;
}

void init() {
    ::init();
    if(!living(ETO)) return;
    if (!owner) set_owner();
    if (!query_sphere()) set_sphere((string)(ETO->query_sphere()));
    if (!query_diety()) set_diety((string)(ETO->query_diety()));
    if(((string)ETO->query_name() == owner || 
    (string)ETO->QCN == owner)
    && valid_has_cleric_spells()) {
         set_long(
@SYMBOL
%^CYAN%^
%^CYAN%^        This is a Holy Symbol.
%^CYAN%^                                   %^WHITE%^              /|X|\
%^CYAN%^        This is only useful        %^WHITE%^             ||XOX||
%^CYAN%^        to clerics, rangers,       %^WHITE%^              \|X|/
%^CYAN%^        antipaladins and paladins. %^WHITE%^      /|X|\----|X|----/|X|\
%^CYAN%^                                   %^WHITE%^     ||XOXXXXXXXXXXXXXXXOX||
%^CYAN%^        < Help Symbol >            %^WHITE%^      \|X|/----|X|---\\|X|/
%^CYAN%^        will show the              %^WHITE%^               |X|
%^CYAN%^        available commands.        %^WHITE%^               |X|
%^CYAN%^                                   %^WHITE%^               |X|
%^CYAN%^        Remember to worship        %^WHITE%^              /|X|\
%^CYAN%^        your Diety at the          %^WHITE%^             ||XOX||
%^CYAN%^        church, often!!            %^WHITE%^              \|X|/
SYMBOL
    );    
        add_action("spells", "spells");
        add_action("pray_spell", "pray");
        add_action("forget_spell", "forget");
        add_action("help", "help");
        add_action("report_spells","report");
        add_all();
    }
    else {
         set_long(
@SYMBOL
%^CYAN%^
%^CYAN%^        This is a Holy Symbol.
%^WHITE%^              /|X|\
%^WHITE%^             ||XOX||
%^WHITE%^              \|X|/
%^WHITE%^      /|X|\----|X|----/|X|\
%^WHITE%^     ||XOXXXXXXXXXXXXXXXOX||
%^WHITE%^      \|X|/----|X|---\\|X|/
%^WHITE%^               |X|
%^WHITE%^               |X|
%^WHITE%^               |X|
%^WHITE%^              /|X|\
%^WHITE%^             ||XOX||
%^WHITE%^              \|X|/
SYMBOL
    );
    }
    //add_action("offer","offer");
}

int add_all() {
    string *all_spells,spellgod,classtype,all,from;
    int x;

    all_spells = get_dir("/cmds/priest/*.c");
    for (x=0 ; x < sizeof(all_spells); x++) {
        spellgod = ("/cmds/priest/"+all_spells[x])->query_diety();
        if(spellgod == "me" || spellgod == query_diety() || wizardp(ETO)) {
            if( ("/cmds/priest/"+all_spells[x])->is_restricted_to_class(ETO->query_classes()) ){
            all_spells[x] = replace_string(all_spells[x],"_","",1);
            all_spells[x] = replace_string(all_spells[x],".c","",1);
            all_spells[x] = replace_string(all_spells[x],"_"," ");
            add_spell(all_spells[x]);
            }
        }
    }
    return 1;
}


int report_spells(string str){
    int i, j;
    mapping spells, level;
    string *k, *k2;
    if (!str) {
        return 0;
    }
    if (str != "cleric spells") {
        return 0;
    }
    spells = TP->query_all_cl_memorized();
    k = keys(spells);
    for (i=0;i<sizeof(k);i++) {
        level = spells[k[i]];
        k2=keys(level);
        for (j=0;j<sizeof(k2);j++) {
            TP->force_me("say I currently have "+k2[j]+" memorized "+level[k2[j]]+" times.");
        }
        
    }
    return 1;
}

int add_spell(string str) {
    int level,j;
    string str2;

    if (!str) return 1;
    str=lower_case(str);
    
    if (TP->is_class("ranger"))
        j = 6;
    if (TP->is_class("paladin") || TP->is_class("antipaladin"))
        j = 7;
    if (TP->is_class("cleric"))
        j = 8;

    str2="/cmds/priest/_"+replace_string(str," ","_")+".c";
    if (file_exists(str2)) {
        if (catch(level=str2->query_spell_level()))
            return 0;
        if (level < j)
            set_holy_symbol(str);
    }
    return 1;
}

void set_holy_symbol(string spell) {
    string spell_file;
    int spell_level;

    if (!spells) spells = ([]);
    if (spell) {
        spell_file="/cmds/priest/_"+replace_string(spell," ","_")+".c";
        if (file_exists(spell_file)) {
            spell_level=spell_file->query_spell_level();
            if (!spell_level) return;
            if (!spell) return;
            spells[spell] = spell_level;
            return 1;
        }
        return 0;
    }
    return 0;
}

int remove_spell(string spell) {
    if (!spell) return 1;
    map_delete(spells, spell);
    return 1;
}

int query_holy_symbol(string spell) {
    return spells[spell];
}

int spells(string str) {
    int x, temp1;
    string tmp, Gtype;

    if (!str) str = "by name";
    if (sscanf(str, "by %s", Gtype) != 1) Gtype = "name";

    tmp = ({});
      if((!(TP->is_class("cleric") || TP->is_class("paladin") || TP->is_class("antipaladin") || TP->is_class("ranger") ) || wizardp(TP)) ) {
        tell_object(TP, "This symbol has no meaning to you. ");
        return 1;
    }

    magic = keys(spells);
    tell_object(TP, "\n%^BOLD%^%^CYAN%^This is "+owner+"'s holy symbol.  Its god allows the following spells:");
    line();
    tell_object(TP, "%^MAGENTA%^"+arrange_string("Spell:", 30) + arrange_string("Level:", 10)+"* Memorized:");
    line();

    if (Gtype != "level") sort();
    else sort_two();

    for (x = 0; x < sizeof(magic);x++) {
        if (!temp1 = TP->query_cl_memorized(magic[x]))
            temp1 = 0;
        tmp += ({"%^CYAN%^%^BOLD%^"+arrange_string(magic[x], 30)+"%^RESET%^%^CYAN%^"+arrange_string(spells[magic[x]], 10)+temp1});
    }
    TP->more(tmp);
    line();
    return 1;
}

int pray_spell(string str) {
    int sl, rst;

    if (TP->query_bound() || TP->query_unconscious()) {
        TP->send_paralyzed_message("info",TP);
        return 1;
    }
    if (!(int)TP->query_guild_level("cleric") )
        return notify_fail("Only users with magical abilities may pray for spells!\n");
    if (TP->query_paralyzed())
        return notify_fail(TP->query_paralyze_message());
    if (!str)
        return notify_fail("Pray for what?\n");
    if (query_diety() != (string)ETO->query_diety())
        return notify_fail("This holy symbol did not come from your diety, you cannot pray for spells with it!\n");
    if (!sl = query_holy_symbol(str))
        return notify_fail("Your god will not grant any such spell!\n");
    if ( sizeof(TP->query_attackers()) > 0 )
        return notify_fail("You cannot pray for spells while in battle!\n");
    if (TP->query_property("berserked"))
        return tell_object(TP,"Your berserker rage won't give you the peace needed.");

    if (sl > 5) {
        if (ETP->query_property("blessed")) {
            if ((string)ETP->query_property("blessed") != (string)TP->query_diety()) {
                tell_object(TP,"You may not pray in this room for that spell, please bless the room to bring your god's presence to it.");
                return 1;
            }
        } else {
            tell_object(TP,"You may not pray in this room for that spell, please bless the room to bring your god's presence to it.");
            return 1;
        }
    }

    rst = TP->can_memorize_cl(str);

    if (rst == TOO_MANY)
        return notify_fail("You have prayed for all of the spells that you are allowed at this level.\n");
    if (rst == SPELL_RESTRICTED)
        return notify_fail("Your god has taken the power of that spell from you.\n");
    if (rst == NOT_WISE)
        return notify_fail("You do not have the wisdom to control that spell.\n");
    if (rst != MEM_OK)
        return notify_fail("You cannot pray for that spell.\n");

    tell_object(TP, "You kneel before your symbol and your god and start to pray for the spell of "+str+".  This may take awhile.");
    tell_object(TP, "Hit <RETURN> to cancel memorizing...");
    tell_room(environment(TP), TPQCN+" kneels before "+TP->query_possessive()+" holy symbol and starts praying to "+TP->query_possessive()+" god.", TP);
    temp = sl * MEMORIZE_DELAY;
    call_out("flip", 2, str, temp, TP);
  // temp above was sl. I changed it to be like the wizards...
  //Garrett.
    input_to("check_activity", 1);
//    TP->set_paralyzed(temp);
      TP->setAdminBlock();
    return 1;        
}

int check_activity(string str) {
    if (remove_call_out("flip") != -1) {
         tell_player(TP, "You interrupt praying to do something else!\n");
//        TP->remove_paralyzed();
        TP->removeAdminBlock();
        return 1;
    }
    return 1;
}

void flip(string str, int sl, object play) {
    if (random(8) == 0) {
        tell_object(play,"You feel the power of your god.");
        tell_room(environment(play),play->query_cap_name()+" wavers a second before you.",play);
    }
    temp -= 2;
    if (temp > 0)
        call_out("flip", 2, str, sl, play);
    else {
        memorize2(str, sl, play);
        temp = 0;
        return 1;
    }
}

void memorize2(string str, int sl, object play) {
    play->set_cl_memorized(str, 1);
//    TP->remove_paralyzed();
        play->removeAdminBlock();
    tell_room(environment(play),play->query_cap_name()+" finishes praying to "+TP->query_possessive()+" god.",play);
    tell_object(play, "You have now finished praying for the spell of "+str+".\nHit <RETURN> to continue...");
}

int forget_spell(string str) {
    int temp, sl;
    int *in_mind;

    if (!sl = query_holy_symbol(str))
        return notify_fail("That spell does not exist to forget! ["+str+"]\n");

    TP->set_cast_type("priest");

    if (!TP->forget_cl_memorized(str))
        return notify_fail("The spell, \""+str+"\" is not in your memory!\n");
    else
        tell_object(TP, "The spell, \""+str+"\" has been forgotten successfully!");

    return 1;
}

void line() {
    write("%^BLUE%^-----------------------------------------------------------------------");
}


int offer(string str) {
    if (id(str)) {
        tell_object(TP, "%^BOLD%^No offering holy symbols!");
        return 1;
    }
    return 0;
}

int help(string str) {
    int x, calc;
    string tmp;
    int level, *in_mind;

    if (!str)
        return 0;
    if (str != "holy symbol" &&
        str != "holy_symbol" &&
        str != "symbol")
        return 0;

    if ( !interactive(TP) || (!TP->is_class("cleric") && !TP->is_class("paladin") && !TP->is_class("antipaladin")&& !TP->is_class("ranger") && !wizardp(TP)))
        return 0;

    //tell_object(TP, CLS);
    tell_object(TP, "Holy symbols are the gifts of the gods to their followers.");
    tell_object(TP, "With your holy symbol you can:");
    tell_object(TP, "%^YELLOW%^<pray>%^RESET%^ spells");
    tell_object(TP, "%^YELLOW%^<forget>%^RESET%^ spells");
    tell_object(TP, "%^YELLOW%^<spells>%^RESET%^    Will list spells your god offers");
    tell_object(TP, "%^YELLOW%^<spells by level>%^RESET%^    Will list spells your god offers, sorted by spell level");


    if (TP->query_guild_level("cleric")) {
        line();
        in_mind = allocate(10);
        if (TP->is_class("cleric")){
            level = TP->query_class_level("cleric");
            in_mind = (int)CLERIC_CALCS->query_max_spell_array(level, "cleric", TP->query_stats("wisdom"));
        }
        if (TP->is_class("paladin")){
            level = TP->query_class_level("paladin");
            in_mind = (int)CLERIC_CALCS->query_max_spell_array(level, "paladin", 10);
        }
        if (TP->is_class("antipaladin")){
            level = TP->query_class_level("antipaladin");
            in_mind = (int)CLERIC_CALCS->query_max_spell_array(level, "antipaladin", 10);
        }
        if (TP->is_class("ranger")){
            level = TP->query_class_level("ranger");
            in_mind = (int)CLERIC_CALCS->query_max_spell_array(level, "ranger", 10);
        }

        if (level < 0 ) level = 0;
        tell_object(TP, "%^MAGENTA%^"+arrange_string("Spell level:", 18)+"Number allowed:      Prepared:     [Your level: "+level+"]");
        line();
        
        for (x = 0; x < 7;x++) {
            tmp = in_mind[x];
            if(!tmp) tmp = "0";
            tell_object(TP, "%^CYAN%^"+arrange_string((x+1), 18) + arrange_string(tmp,21) + TP->query_num_cl_spells_level(x+1));
        }

        line();
    }
    return 1;
}

void sort() {
    int i,j;

    for (j=0;j<sizeof(magic);j++)
        for (i=sizeof(magic)-1;i>j;i--) {
            if (magic[i] < magic[i-1]) {
                swap(i-1,i);
            }
        }
}

private void swap(int i, int j) {
    string tmp;

    tmp = magic[i];
    magic[i]=magic[j];
    magic[j]=tmp;
}

void sort_two() {
    int i,j;

    for (j=0;j<sizeof(magic);j++)
        for (i=sizeof(magic)-1;i>j;i--) {
            if (spells[magic[i]] < spells[magic[i-1]]) {
                swap(i-1,i);
            }
        }
}

