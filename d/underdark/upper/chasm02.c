#include <std.h> 
#include "../defs.h" 
inherit INH+"chasmpath"; 

void create(){ 
   ::create(); 
   set_long(""+::query_long()+"\n");
   set_exits(([ 
"north":UPPER"chasm03",
"southeast":UPPER"chasm01",
   ])); 
}