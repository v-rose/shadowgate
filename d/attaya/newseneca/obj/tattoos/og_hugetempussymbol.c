#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_weight(0);
	set_ac(0);
	set_type("ring");
	set_property("death keep",1);
	set_property("no animate",1);
	set_name("tattoo");
	set_value(30000);
	set_id(({ "tattoo", " tempus symbol", " flaming sword tattoo", " blood red shield tattoo", " flame shield tattoo", " back tattoo" }));
	set_short("huge Tempus symbol back tattoo");
