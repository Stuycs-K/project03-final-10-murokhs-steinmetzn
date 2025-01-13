#include "library.h"
#include "node.h"
#include <string.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

struct song_node * insert_from_mp3(struct song_node * list, char* album_name){
    //for every song in album_name folder
        //get mp3 metadata (use libid3tag library)
        //use insert_alphabetical
}