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
#include "id3v2lib-dev/include/id3v2lib.h" //https://github.com/larsbs/id3v2lib
#include "id3v2lib-dev/include/modules/frame_header.h"
#include "id3v2lib-dev/include/modules/frame_ids.h"
#include "id3v2lib-dev/include/modules/frame_list.h"
#include "id3v2lib-dev/include/modules/frame.h"
#include "id3v2lib-dev/include/modules/frames/apic_frame.h"
#include "id3v2lib-dev/include/modules/frames/comment_frame.h"
#include "id3v2lib-dev/include/modules/frames/text_frame.h"
#include "id3v2lib-dev/include/modules/picture_types.h"
#include "id3v2lib-dev/include/modules/tag_header.h"
#include "id3v2lib-dev/include/modules/tag.h"
#include "id3v2lib-dev/include/modules/utils.h"

struct song_node * insert_from_mp3(struct song_node * list, char* album_name){
    //for every song in album_name folder
        //get mp3 metadata (use libid3tag library)
        //use insert_alphabetical
    ID3v2_Tag* tag = ID3v2_read_tag("mp3/imaginaerum/02. Nightwish - Storytime.mp3");
    ID3v2_TextFrame* artist_frame = ID3v2_Tag_get_artist_frame(tag);
    char* artist;
    strcpy(artist, artist_frame->data->text);
    printf("%s\n", artist);
    ID3v2_TextFrame* album_frame = ID3v2_Tag_get_album_frame(tag);
    char* album;
    strcpy(album, album_frame->data->text);
    printf("%s\n", album);
}
