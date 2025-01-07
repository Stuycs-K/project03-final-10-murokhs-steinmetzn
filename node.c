#include "node.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct song_node * insert_front(struct song_node * list, char* artist, char* title, char* album, char* genre, int year){
  struct song_node*m = (struct song_node*) malloc(sizeof(struct song_node));
  strcpy(m->artist, artist);
  strcpy(m->title, title);
  strcpy(m->album, album);
  strcpy(m->genre, genre);
  m->year = year;
  m->next = list;
  return m;
}
void print_song_list(struct song_node * list){
  if(list!=NULL){
    int i=0;
    printf("[ ");
    while(list!=NULL){
      printf("{%s, %s}", list->artist, list->title);
      list = list->next;
      i++;
      if (list!=NULL){
        printf(" | ");
      }
    }
    printf(" ]\n");
  }
}

void print_node(struct song_node * song){
  printf("{%s, %s, %s, %s, %d}", song->artist, song->title, song->album, song->genre, song->year);
}

int songcmp(struct song_node * a, struct song_node * b) { //if a>b, +1;if a<b, -1
  char *x = malloc(strlen(a->artist) + 1);
  strcpy(x, a->artist);
  char *y = malloc(strlen(b->artist) + 1);
  strcpy(y, b->artist);
  int cmp = strcasecmp(x,y);
  free(x);
  free(y);
  if (cmp!=0) {
    return cmp;
  }
  char *m = malloc(strlen(a->title) + 1);
  strcpy(m, a->title);
  char *n = malloc(strlen(b->title) + 1);
  strcpy(n, b->title);
  free(m);
  free(n);
  return strcasecmp(m,n);
}

struct song_node * insert_alphabetical(struct song_node * list, char* artist, char* title, char* album, char* genre, int year){
  if (list==NULL){ //if list is empty
    list = insert_front(list, artist, title, album, genre, year);
    return list;
  }
  struct song_node * begin = list;
  struct song_node * new_song = (struct song_node*) malloc(sizeof(struct song_node));
  strcpy(new_song->artist, artist);
  strcpy(new_song->title, title);
  strcpy(new_song->album, album);
  strcpy(new_song->genre, genre);
  new_song->year = year;
  if (songcmp(new_song,list)<1) { //if new is smallest, add to front, return itself
    new_song->next=list;
    return new_song;
  }
  while (list->next!=NULL) { //loop through until n is smaller than list->next, then insert and return begin
    if (songcmp(new_song,list->next)<1) {
      new_song->next=list->next;
      list->next=new_song;
      return begin;
    }
    list = list->next;
  }
  list->next = new_song; //new is biggest
  new_song->next = NULL;
  return begin;
}

struct song_node * free_list(struct song_node * list){
  struct song_node * templist;
  while (list!=NULL){
    templist=list;
    list=list->next;
    free(templist);
  }
  return NULL;
}

struct song_node * find_node(struct song_node * list, char *artist, char * title) {
  while (list!=NULL){
    if (strcmp(list->artist, artist) == 0 && strcmp(list->title, title) == 0) {
      printf("node found! ");
      print_node(list);
      printf("\n");
      return list;
    }
    list = list->next;
  }
  printf("node not found\n");
  return list; //retuns null cant be printed
}

struct song_node * find_artist(struct song_node * list, char * artist) {
  while (list!=NULL){
    if (strcmp(list->artist, artist) == 0) {
      printf("artist found! ");
      print_song_list(list);
      return list;
    }
    list = list->next;
  }
  printf("artist not found\n");
  return list; //retuns null cant be printed
}

struct song_node * random_finder(struct song_node * list){
  int len = 0; //length list
  struct song_node *iter = list;
  while (iter!=NULL){
    iter=iter->next;
    len+=1;
  }
  srand(time(NULL));
  int random = rand()%len;
  while(random>0){
    list=list->next;
    random-=1;
  }
  return list;
}

struct song_node * remove_node(struct song_node * list, char * artist, char * title) {
  if(strcmp(list->artist, artist) == 0 && strcmp(list->title, title) == 0) { //if its the first one
    return list->next;
  }
  struct song_node * begin = list;
  while(list->next != NULL) {
    if (strcmp((list->next)->artist, artist) == 0 && strcmp((list->next)->title, title) == 0) {
      struct song_node *temp = list->next;
      list->next = (list->next)->next;
      free(temp);
      return begin;
    }
    list = list->next;
  }
  printf("ERROR song not found\n");
  return begin; //retuns null nothing was removed
}
