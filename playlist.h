#ifndef PLAYLIST_H
#define PLAYLIST_H

void list_playlists();
void create_playlist(char * name);
int err();
void write_to_playlist(char * name, struct song_node* song_list);
void play_playlist(char * filename);
#endif
