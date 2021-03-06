// File created with /daemon/persistent_room_d.c
#include <std.h>

inherit "/cmds/avatar/avatar_room.c";

void create()
{
    ::create();
    set_name("x_whall");
    set_property("indoors",1);
    set_property("light",1);
    set_property("no teleport",1);
    set_terrain("nat cave");
    set_travel("rubble");
    set_climate("temperate");

    set_short("%^RESET%^%^MAGENTA%^West Hall%^BOLD%^%^BLACK%^ of House %^YELLOW%^X%^RESET%^%^ORANGE%^o%^YELLOW%^r%^RESET%^%^ORANGE%^l%^YELLOW%^o%^RESET%^%^ORANGE%^r%^YELLOW%^r%^RESET%^%^ORANGE%^i%^YELLOW%^n%^RESET%^");

    set_long("%^BOLD%^%^BLACK%^The %^RESET%^%^MAGENTA%^West Hall%^BOLD%^%^BLACK%^ of House %^YELLOW%^X%^RESET%^%^ORANGE%^o%^YELLOW%^r%^RESET%^%^ORANGE%^l%^YELLOW%^o%^RESET%^%^ORANGE%^r%^YELLOW%^r%^RESET%^%^ORANGE%^"
	"i%^YELLOW%^n%^BLACK%^ has a large mural of %^RED%^Lolth%^BLACK%^ in spider form on the wall. To the east lies the entrance hall. Northwest appears to be some barracks area and southwest are some shabb"
	"y apartments.%^RESET%^"
	);

    set_smell("default","
You smell the dry air of the caves.");
    set_listen("default","You hear the sound of Drow voices and walking nearby.");

    
set_items(([ 
	"moral" : "The %^RED%^eyes%^RESET%^ of Lolth are on you as you gaze at the mural. Creepy!",
	]));

    set_exits(([ 
		"east" : "/d/av_rooms/myrkul/x_entrance",
		"northwest" : "/d/av_rooms/myrkul/x_barracks",
		"southwest" : "/d/av_rooms/myrkul/x_servant",
	]));

    set_door("gate","/d/av_rooms/myrkul/x_gate","south","spider key","lock");
    add_lock("gate","spider key","lock","This is a strange looking lock that has a key hole resembling a spider.");
    set_locked("gate",1,"lock");
    lock_difficulty("gate",-50,"lock");
    set_open("gate",0);
    set_string("gate","knock","pounds on the");
    set_string("gate","open","The gate opens slowly.");
    set_string("gate","close","The gate swings shut.");
    set_door_description("gate","This is a wrought iron gate with ornamental spikes and bearing a symbol of a spider with dripping yellow venom.");
}