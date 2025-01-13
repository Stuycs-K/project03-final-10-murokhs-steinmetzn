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

int err(){
  printf("errno %d\n",errno);
  printf("%s\n",strerror(errno));
  exit(1);
}

int randomTwo(){ //bw 3 and 5
  int x;
  int bytes;
  int r_file = open("/dev/random", O_RDONLY, 0);
  if (r_file == -1)err();
  bytes = read(r_file, &x, 4);
  if (bytes == -1){
      err();
  }
  x = abs(x) % 2;
  x += 3;
  return x;
}

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

void create_playlist(char * name){ //feed in name including .dat
  char * path = "./playlists";
  chdir(path);
  int w_file = open(name, O_RDWR | O_CREAT | O_TRUNC, 0644);
  if(w_file==-1){
    err();
  }
  printf("%s successfully created. Currently empty.\n", name);
  chdir("..");
}

struct song_node * write_to_playlist(char * name, struct song_node* song_list){ //feed in name including .dat
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
  printf("succesfully wrote to %s, cleared active songlist\n", name);
  chdir("..");
}

void play_playlist(char * filename){
  char * path = "./playlists";
  chdir(path);
  int r_file = open(filename, O_RDONLY, 0644);
  if (r_file == -1){
    err();
  }
  struct song_node * songs = NULL;
  struct song_node curr;
  char buffer[256];
  int bytes;
  bytes = read(r_file, &curr,sizeof(struct song_node));
  while (bytes){
    printf("Playing %s by %s, from album %s\n", curr.title, curr.artist, curr.album);
    int time = randomTwo();
    for (int i = 0; i < time; i++){
      printf("     ; \n     ;;\n     ;';.\n     ;  ;;\n     ;   ;;\n     ;    ;;\n     ;    ;;\n     ;   ;'\n     ;  ' \n,;;;,; \n;;;;;;\n`;;;;'\n");
      printf(".\n");
      printf(".\n");
      printf(".\n");
      printf(".\n");
      printf(".\n");
      sleep(1);
    }
    bytes = read(r_file, &curr,sizeof(struct song_node));
  }
  chdir("..");
}


struct song_node* read_from_playlist(char * name){
  char * path = "./playlists";
  chdir(path);
  int playlist = open(name, O_RDONLY);
  if(playlist==-1){
    err();
  }
  struct song_node*temp = (struct song_node*) malloc(sizeof(struct song_node));
  struct song_node*song_list = temp;
  while(read(playlist, temp,sizeof(struct song_node))){
    ///hfjdhjsfdjkfsfd
  }
}
