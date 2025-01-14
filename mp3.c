#include "library.h"
#include "node.h"
#include "id3v2lib-dev/include/id3v2lib.h" //https://github.com/larsbs/id3v2lib
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
    ID3v2_Tag* tag = ID3v2_read_tag("mp3/imaginaerum/02. Nightwish - Storytime.mp3");
    ID3v2_TextFrame* artist_frame = ID3v2_Tag_get_artist_frame(tag);
    //printf("artist: %s", artist_frame->frames);
}
