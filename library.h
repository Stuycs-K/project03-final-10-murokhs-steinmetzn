//library header
#ifndef LIBRARY_H
#define LIBRARY_H
struct song_node ** init();
char to_index(char letter);
void add(struct song_node ** library, char* artist, char* title, char* album, char* genre, int year);
struct song_node * search_song(struct song_node ** library, char* artist, char* title );
struct song_node * search_artist(struct song_node ** library, char* artist );
void print_letter(struct song_node ** library, char letter);
void print_artist(struct song_node ** library, char* artist);
void print_library(struct song_node ** library);
void shuffle (struct song_node ** library, int n);
int delete_song(struct song_node ** library, char* artist, char* title );
int reset(struct song_node ** library);
#endif
