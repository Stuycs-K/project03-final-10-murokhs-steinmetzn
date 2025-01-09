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

void create_playlist(char * name){
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
