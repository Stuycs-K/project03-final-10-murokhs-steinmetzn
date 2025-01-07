//Sasha's library.c
#include "library.h"
#include "node.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct song_node ** init(){
  struct song_node ** array = (struct song_node **) calloc(27, sizeof(struct song_node *));
  for (int i=0;i<27;i++){
    array[i] = NULL;
  }
  return array;
}

char to_index(char letter){ //helper
  if(letter>=65&&letter<91){
    letter-=65;
  }
  else if (letter>=97&&letter<123){
    letter-=97;
  }
  else {
    letter = 26; //symbol
  }
  return letter;
}

void add(struct song_node ** library, char* artist, char* title) {
  char a1 = artist[0];
  a1 = to_index(a1);
  library[a1] = insert_alphabetical(library[a1], artist, title);
}

void print_letter(struct song_node ** library, char letter){
  letter = to_index(letter);
  if(letter!= 26) {
    printf("%c: ", (char)(letter + 97));
  }
  else {
    printf("%d: ", 0);
  }
  print_list(library[letter]);
}

void print_artist(struct song_node ** library, char* artist){
  char a1 = artist[0];
  a1 = to_index(a1);
  find_artist(library[a1],artist);
}

void print_library(struct song_node ** library) {
    int i = 0;
    for(i = 0; i < 27; i++) {
        if(library[i] != NULL) {
            print_letter(library, i + 97);
        }
    }
}

struct song_node * search_song(struct song_node ** library, char* artist, char* title ){
    char firstChar = to_index(artist[0]);
    printf("Looking for [%s: %s]\n", artist, title);
    return find_node(library[firstChar], artist, title);
}

struct song_node * search_artist(struct song_node ** library, char* artist){
    char firstChar = to_index(artist[0]);
    printf("Looking for [%s]\n", artist);
    return find_artist(library[firstChar], artist);
}


int delete_song(struct song_node ** library, char* artist, char* title ){
  if(search_song(library, artist, title) == NULL) {
    return 1;
  }
  char firstChar = to_index(artist[0]);
  library[firstChar] = remove_node(library[firstChar], artist, title);
  return 0;
}

int reset(struct song_node ** library){
  for (int i=0;i<27;i++){
    library[i] = free_list(library[i]);
  }
  return 1;
}

void shuffle (struct song_node ** library, int n) {
  int j = 0; //For counting number of songs
  srand(time(NULL));
  for(int i = 0; i < 27; i++) {
    if(library[i] != NULL) {
      struct song_node* iter = library[i];
      while(iter!=NULL){
        iter = iter->next;
        j+=1;
      }
    }
  }
  struct song_node* list = NULL; //new linked list
  while(n>0) { //Iterates through n
    int random = rand() % j+1;
    for(int m = 0; m < 27; m++) {
      if(library[m] != NULL) {
        struct song_node* iter2 = library[m];
        while(iter2!=NULL){
          random-=1;
          if(random==0){
            list = insert_front(list, iter2->artist, iter2->title);
            break;
            break;
          }
          iter2 = iter2->next;
        }
      }
    }
    n-=1;
  }
  print_list(list);
  free_list(list);
}