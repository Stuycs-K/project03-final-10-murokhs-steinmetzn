#ifndef MP_H
#define MP_H
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
struct song_node * insert_from_mp3(struct song_node * list, char* album_name);
#endif
