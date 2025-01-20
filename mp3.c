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

int read_yr(char* path){
    char txtname[256];
    snprintf(txtname, sizeof(txtname), "%s/year.txt", path);
    printf("%s\n", txtname);
    FILE *file = fopen(txtname, "r");
    int output=0;
    fscanf(file, "%d", &output);
    fclose(file);
    return output;
}

struct song_node * insert_from_mp3(struct song_node * list, char* album_name){
    int year = 0;
    char * path;
    snprintf(path, strlen(album_name) + 5, "mp3/%s", album_name);
    //since reading year doesn't work for some reason, i added it to the folders manually lol
    year = read_yr(path);
    
    struct dirent *entry;
    DIR *dir = opendir(path);
    while ((entry = readdir(dir)) != NULL) {
        int len = strlen(entry->d_name);
        char *name;
        snprintf(name, strlen(path) + strlen(entry->d_name) +2, "%s/%s", path, entry->d_name);
        
        if (len>4 && strcmp(entry->d_name + len - 4, ".mp3") == 0) { //if mp3 file
            ID3v2_Tag* tag = ID3v2_read_tag(name);
            list = insert_alphabetical(list, (ID3v2_Tag_get_artist_frame(tag)->data->text), (ID3v2_Tag_get_title_frame(tag)->data->text), (ID3v2_Tag_get_album_frame(tag)->data->text), (ID3v2_Tag_get_genre_frame(tag)->data->text), year);
            ID3v2_Tag_free(tag);
        }
    }
    
    return list;
}
