//	Written by Melnmarn@ShadowGate on 3 feb 1995.
//	Players command to list all players online. will filter out 
//	elders and above from wizards and players, as well as filter
//	out wiz's from the mortals.
//


#include <std.h>
#include <objects.h>
#include <dirs.h>
#include <daemons.h>
#include <config.h>
#define PFILE "/tmp/players.list"

inherit OB_USER;
mapping player_info;
string * playersReal;

void showem();

void create(){
	seteuid(getuid());
}

int cmd_players(string str) {
    int debug;
    string *players,name,who,*alpha,melnmarn,lastcall,party;
    string alias,theclass,race;
    object ob;
    int total,inc,level,line,my_level;
    string month,temp;
    int day,year,plines,hold; 
    mapping play;
  write(geteuid());
   playersReal = ({});
	if(str){
		if(str == "rebuild") {
			rm("/tmp/players.list");
		}	
	}
        if(file_exists("/tmp/players.list")) {
		showem();
        	return 1;
	}
       if(str == "debug") debug = 1;
	hold = to_int(TP->getenv("LINES")); 
	plines = (hold > 0) ? hold - 3 : 17;
	play = ([]);
	alpha = ({"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z" });
	players = get_dir("/adm/save/users/" + alpha[0] + "/*.o");
	for(inc = 1; inc < sizeof(alpha);inc ++){
		if(get_dir("/adm/save/users/" + alpha[inc] + "/*.o") == 0 ) 
			continue;
		players += get_dir("/adm/save/users/" + alpha[inc] + "/*.o");
	}
	total = sizeof(players);
	line = 0;
	for(inc = 0;inc < total;inc++){
		sscanf(players[inc],"%s.o",name);
		if(debug == 1) write("Trying .....'"+name+"'!");
		who = sprintf("%s/%s/%s", "/adm/save/users", name[0..0], name);
		ob = find_player(name);
		restore_object(who);
      if(!stringp(query_name()) )  tell_object(find_player("tristan"),""+who);
        if(objectp(ob)) {
  write("ob valid "+ob->query_name());
           alias = capitalize(ob->query_name());
       }
        else { alias = capitalize(query_name());
        }
                if(ob) theclass = ob->query_class_string();
               else theclass = query_class_string();
		if(!theclass) theclass = "child";
		if(sscanf(theclass,"%s-%*s",temp)) theclass = "Multi";
		if(sscanf(theclass,"%s-%*s-%*s",temp)) theclass = "Multi";
 		if(ob) level = ob->query_level();
		else level = query_level();
        if(level < 10) continue;
 		if(ob) party = (ob->query_party() == 0) ? party = "" : party = "P";
		else party = (query_party() == 0) ? party = "" : party = "P";
		if(ob) race = ob->query_race();
		else race = query_race();
 		if(!race) race = "Alien";
		if(ob) {
			if(!query_heart_beat(ob))
				lastcall = "%^RED%^NetDead";
			else lastcall = "%^RED%^Online";
		} else {
			sscanf(last_on,"%*s %s %d %*s %d",month,day,year);
			lastcall = sprintf("%s %02d %d",month, day, year);
		}
		play[players[inc]] = ({alias,theclass,level,race,lastcall,party});
	}
	player_info = play;
   playersReal = keys(player_info);
     playersReal = sort_array(playersReal, "sortem", TO);
	
	write_file(PFILE,"\n\nPlayer          Class          Level     Race         Last Time Online\n");
	write_file(PFILE,"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
     total = sizeof(playersReal);
	for(inc = 0,line = 0;inc < total;inc++){
		if(( player_info[playersReal[inc]][2] >= 1500) && (!archp(TP)));
		else if(( player_info[playersReal[inc]][2] >= 500) && (!wizardp(TP)));
		else{ write_file(PFILE,sprintf("%-15s %-15s %4d %1s   %-15s   %s\n",
		player_info[playersReal[inc]][0],capitalize(player_info[playersReal[inc]][1]),player_info[playersReal[inc]][2],player_info[playersReal[inc]][5],capitalize(player_info[playersReal[inc]][3]),player_info[playersReal[inc]][4]));
		line ++;
		}
	}
	write_file(PFILE,"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
        showem();
return 1;
}

int showem(){
	TP->more(PFILE);
	return 1;
}
int sortem( string one,string two ){
	return ( player_info[two][2] - player_info[one][2] );
}
void help(){
	write( @MELNMARN
Syntax: <players>

	The Players command will show all players who are on the
	ShadowGate Mud, whether they are online or not. If the 
	Player is online, it will indicate that they are online.
	If a player is a member of a party, a 'P' will show after 
	that players level. Shows some general information about 
	each player.
MELNMARN
);
}
