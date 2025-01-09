#include "library.h"
#include "node.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <time.h>

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

void create_playlist(char* name){
  char path[256];
  sprintf(path, "playlists/%s.dat", name);
  FILE *file = fopen(path, "w");
  fclose(file);
}
