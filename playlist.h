#ifndef PLAYLIST_H
#define PLAYLIST_H

void list_playlists();
void create_playlist(char * name);
int err();
struct song_node * write_to_playlist(char * name, struct song_node* song_list);
void play_playlist(char * filename);
struct song_node* read_from_playlist(char * name);
void add_song(char * filename);
void remove_song(char * filename);
void shuffle_playlist(char * filename);
void alphabetical_playlist(char * filename);
void reverse_playlist(char * filename);
#endif
