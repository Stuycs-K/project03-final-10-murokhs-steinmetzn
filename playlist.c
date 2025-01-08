#include "library.h"
#include "node.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <dirent.h>

void list_playlists(){
  DIR * d;
  d = opendir("playlists/");
  struct dirent *entry;
  while(entry = readdir( d )){
    printf("%s\n", entry->d_name);
  }
}
