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
#include <errno.h>

void list_playlists(){
  DIR * d;
  d = opendir("playlists/");
  struct dirent *entry;
  int i = 1;
  while(entry = readdir( d )){
    if (strcmp(entry->d_name,".")!=0&&strcmp(entry->d_name,"..")!=0){
        printf("%d. %s\n", i, entry->d_name);
        i++;
      }
  }
  closedir(d);
}

int err(){
  printf("errno %d\n",errno);
  printf("%s\n",strerror(errno));
  exit(1);
}

void create_playlist(char * name){ //feed in name including .dat
  char * path = "./playlists";
  // DIR * curr = opendir(path);
  // struct dirent * entry;
  // entry = readdir(curr);
  chdir(path);
  int w_file = open(name, O_RDWR | O_CREAT | O_TRUNC, 0644);
  if(w_file==-1){
    err();
  }
  printf("%s successfully created. Currently empty.\n", name);
}

void write_to_playlist(char * name, struct song_node* song_list){ //feed in name including .dat
  char * path = "./playlists";
  chdir(path);
  int playlist = open(name, O_WRONLY | O_TRUNC, 0644);
  if(playlist==-1){
    err();
  }
  struct song_node * beginning = song_list;
  while(song_list!=NULL){
    write(playlist, song_list, sizeof(struct song_node));
    song_list = song_list->next;
  }
  free_list(beginning);
  close(playlist);
  printf("succesfully wrote to %s, cleared active songlist", name);
}

struct song_node* read_from_playlist(char * name){
  char * path = "./playlists";
  chdir(path);
  int playlist = open(name, O_RDONLY);
  if(playlist==-1){
    err();
  }
  struct song_node*song_list = NULL;
  struct song_node*temp = (struct song_node*) malloc(sizeof(struct song_node));
  while(read(playlist, temp,sizeof(struct song_node))){
    ///hfjdhjsfdjkfsfd
  }
}