//header file for node.c
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifndef NODE_H
#define NODE_H
struct song_node {char artist[100]; char title[100]; char album[100]; char genre[100]; int year; struct song_node *next;};
struct song_node * insert_front(struct song_node * list, char* artist, char* title, char* album, char* genre, int year);
struct song_node * insert_back(struct song_node * list, char* artist, char* title, char* album, char* genre, int year);
int songcmp(struct song_node * a, struct song_node * b);
void print_song_list(struct song_node * list);
void print_node(struct song_node * song);
struct song_node * free_list(struct song_node * list);
struct song_node * insert_alphabetical(struct song_node * list, char* artist, char* title, char* album, char* genre, int year);
struct song_node * find_node(struct song_node * list, char* artist, char* title);
struct song_node * find_artist(struct song_node * list, char * artist);
struct song_node * remove_node(struct song_node * list, char* artist, char* title);
struct song_node * random_finder(struct song_node * list);
#endif
