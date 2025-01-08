#include "library.h"
#include "node.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <time.h>

void create_playlist(){

  char * path = "./playlists";

  DIR * curr = opendir(path);

  struct dirent * entry;
  entry = readdir(curr);
  while (entry){
    if (entry->d_type != DT_DIR) {
      printf("  %s\n", entry->d_name);
      // stat(entry->d_name, &buffer);
      // total_bytes += buffer.st_size;
    }
    entry = readdir(curr);
  }
}
