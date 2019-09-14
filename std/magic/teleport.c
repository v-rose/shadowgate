#include <std.h>

int object_can_be_teleported(object teleportee, object destination, int clevel)
{
    if(!objectp(destination)) //I'm going to rant. So I declared a
                              //contract in function definiton,
                              //stating that clearly I expect this to
                              //be an object, yet if I pass anything
                              //but an object into this function, it
                              //still will process it?.. The fuck we
                              //need types for then?
        return 0;
    if(!destination->is_room())
        return 0;
    if (destination->is_flight_room())
        return 0;
    if (teleportee->query_property("teleport proof") -9 + random(20) > clevel )
    {
      return 0;
    } 

    if(destination->query_property("no teleport") ||
       environment(teleportee)->query_property("no teleport"))
        return 0;

    {
        int startpower, endpower;
        startpower = environment(teleportee)->query_property("teleport proof");
        endpower = destination->query_property("teleport proof");
        if((clevel -9 + random (20) < startpower) ||
           (clevel -9 + random (20) < endpower) )
            return 0;
    }
    return 1;
}

object scatter_destination(mixed destination)
{
    string fname;
    string *files;
    object destobj;
    
    fname=base_name(destination);

    files = dir_listing(fname);

    destobj = find_object_or_load(files[random(sizeof(files))]);
    if(!objectp(destobj))
        return 0;
    if(!destobj->is_room())
        return 0;
    return destobj;
}

mixed teleport_object(object invoker, mixed teleportee, mixed destination, int clevel)
{
    object tped, destroom;

    if(stringp(teleportee))
    {
        tped = present(teleportee,invoker);
        if(!objectp(tped))
        {
            write(teleportee+" can't be found");
            return 0;
        }
    }
    else if (objectp(teleportee))
    {
        tped = teleportee;
    }
    else
        return 0;

    if(stringp(destination))
    {
        if(!(destroom = invoker->query_rem_room(destination)))
        {
            tell_object(invoker,"You can't remember "+destination);
            return 0;
        }
    }
    else if (objectp(destination))
    {
        destroom = destination;
    }
    else
        return 0;

    if(!object_can_be_teleported(tped,destroom,clevel))
        return 0;
    
    tped->move_player(destroom);
    
    return destroom;
}

string *dir_listing(string tempfil) {
    string *tmpstor, retval;
    tmpstor=explode(tempfil,"/");
    retval = "/"+implode(tmpstor - ({ tmpstor[sizeof(tmpstor) - 1]}),
                         "/")+"/";
    return map_array(
        get_dir(retval+"*.c"),(:$2+$1:),
        retval);
}
