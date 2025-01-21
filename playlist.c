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
  char curr[256];
  DIR * d;
  d = opendir("playlists/");
  struct dirent *entry;
  int i = 1;
  while(entry = readdir( d )){
    if (strcmp(entry->d_name,".")!=0&&strcmp(entry->d_name,"..")!=0){
      strcpy(curr, entry->d_name);
      curr[strlen(curr)-4] = 0;
      printf("%d. %s\n", i, curr);
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
  printf("%s successfully created. Currently empty.\n\n", name);
  chdir("..");
}

struct song_node * write_to_playlist(char * name, struct song_node* song_list){ //feed in name including .dat
  char line[256];
  strcpy(line, name);
  char * path = "./playlists";
  chdir(path);
  int playlist = open(line, O_WRONLY | O_TRUNC, 0644);
  while(playlist==-1){
    printf("Playlist not found. Please re-enter: \n");
    fgets(line, sizeof(line), stdin);
    line[strlen(line)-1] = 0;
    strcat(line, ".dat");
    playlist = open(line, O_WRONLY | O_TRUNC, 0644);
  }
  struct song_node * beginning = song_list;
  while(song_list!=NULL){
    write(playlist, song_list, sizeof(struct song_node));
    song_list = song_list->next;
  }
  free_list(beginning);
  close(playlist);
  printf("succesfully wrote to %s, cleared active songlist\n", line);
  chdir("..");
}

void play_playlist(char * filename){
  int tries = 0;
  char line[256];
  strcpy(line, filename);
  char * path = "./playlists";
  chdir(path);
  int r_file = open(filename, O_RDONLY, 0644);
  while(r_file==-1){
    printf("Playlist not found. Please re-enter: \n");
    fgets(line, sizeof(line), stdin);
    line[strlen(line)-1] = 0;
    strcat(line, ".dat");
    printf("Attempting to locate %s\n", line);
    r_file = open(line, O_RDONLY);
    tries++;
    if (tries >= 5){
      printf("Exceeded number of tries.\n");
      chdir("..");
      return;
    }
  }
  struct stat stat_buffer;
  stat(filename, &stat_buffer);
  if (stat_buffer.st_size == 0){
    printf("This playlist is currently empty. To add to it, go to edit playlist.\n\n");
  }
  struct song_node * songs = NULL;
  struct song_node curr;
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
  int tries = 0;
  char line[256];
  strcpy(line, name);
  char * path = "./playlists";
  chdir(path);
  int playlist = open(line, O_RDONLY);
  while(playlist==-1){
    printf("Playlist not found. Please re-enter: \n");
    fgets(line, sizeof(line), stdin);
    line[strlen(line)-1] = 0;
    strcat(line, ".dat");
    printf("Attempting to locate %s\n", line);
    playlist = open(line, O_RDONLY);
    tries++;
    if (tries >= 5){
      printf("Exceeded number of tries.\n");
      chdir("..");
      return NULL;
    }
  }
  int arr_size;
  int ind_bytes = sizeof(struct song_node);
  struct stat stat_buffer;
  stat(line, &stat_buffer);
  arr_size = stat_buffer.st_size / ind_bytes;
  struct song_node*temp = NULL; //took away malloc bc that was messing with first node
  struct song_node*song_list = temp;
  struct song_node*curr = (struct song_node*) malloc(sizeof(struct song_node));
  int bytes;
  for (int i = 0; i < arr_size; i++){
    bytes = read(playlist, curr, sizeof(struct song_node));
    song_list = insert_back(song_list, curr->artist, curr->title, curr->album, curr->genre, curr->year);
  }
  chdir("..");
  return song_list;
}

void add_song(char * filename){
  char line[256];
  char title[256];
  char artist[256];
  char album[256];
  char genre[256];
  int year;
  struct song_node * curr_list = read_from_playlist(filename);

  //get new song
  printf("Title of song: ");
  fgets(line, sizeof(line), stdin);
  line[strlen(line)-1] = 0;
  strcpy(title, line);
  printf("\nArtist of song: ");
  fgets(line, sizeof(line), stdin);
  line[strlen(line)-1] = 0;
  strcpy(artist, line);
  printf("\nAlbum of song: ");
  fgets(line, sizeof(line), stdin);
  line[strlen(line)-1] = 0;
  strcpy(album, line);
  printf("\nGenre of song: ");
  fgets(line, sizeof(line), stdin);
  line[strlen(line)-1] = 0;
  strcpy(genre, line);
  printf("\nYear of song: ");
  fgets(line, sizeof(line), stdin);
  line[strlen(line)-1] = 0;
  year = atoi(line);


  curr_list = insert_back(curr_list, artist, title, album, genre, year);
  curr_list = write_to_playlist(filename, curr_list);
  printf("Added %s by %s, album %s, genre %s, year %d to %s.\n", title, artist, album, genre, year, filename);
}

void remove_song(char * filename){
  char line[256];
  char title[256];
  char artist[256];

  struct song_node * curr_list = read_from_playlist(filename);
  if (curr_list == NULL){
    printf("Playlist current empty. No can do.\n");
    return;
  }
  printf("Title of song: ");
  fgets(line, sizeof(line), stdin);
  line[strlen(line)-1] = 0;
  strcpy(title, line);
  printf("\nArtist of song: ");
  fgets(line, sizeof(line), stdin);
  line[strlen(line)-1] = 0;
  strcpy(artist, line);

  curr_list = remove_node(curr_list, artist, title);
  curr_list = write_to_playlist(filename, curr_list);
  printf("Removing %s by %s...\n", title, artist);
}

void shuffle_playlist(char * filename){
  char line[256];
  char title[256];
  char artist[256];

  struct song_node * curr_list = read_from_playlist(filename);
  struct song_node * new_list = NULL;
  struct song_node * curr;
  if (curr_list == NULL){
    printf("Playlist currently empty. Please go to edit to add songs.\n");
    return;
  }

  while (curr_list != NULL){
    curr = random_finder(curr_list);
    new_list = insert_front(new_list, curr->artist, curr->title, curr->album, curr->genre, curr->year);
    curr_list = remove_node(curr_list, curr->artist, curr->title);
  }

  new_list = write_to_playlist(filename, new_list);
}


void alphabetical_playlist(char * filename){ //dupe of shuffle_playlist, except change to insert_alphabetical
  char line[256];
  char title[256];
  char artist[256];

  struct song_node * curr_list = read_from_playlist(filename);
  struct song_node * new_list = NULL;
  struct song_node * curr;
  if (curr_list == NULL){
    printf("Playlist currently empty. Please go to edit to add songs.\n");
    return;
  }

  while (curr_list != NULL){
    curr = random_finder(curr_list);
    new_list = insert_alphabetical(new_list, curr->artist, curr->title, curr->album, curr->genre, curr->year);
    curr_list = remove_node(curr_list, curr->artist, curr->title);
  }

  new_list = write_to_playlist(filename, new_list);
}


void reverse_playlist(char * filename){ //dupe of shuffle_playlist, except change to insert_alphabetical
  char line[256];
  char title[256];
  char artist[256];

  struct song_node * curr_list = read_from_playlist(filename);
  struct song_node * new_list = NULL;
  struct song_node * curr;
  if (curr_list == NULL){
    printf("Playlist currently empty. Please go to edit to add songs.\n");
    return;
  }

  while (curr_list != NULL){
    curr = curr_list;
    new_list = insert_front(new_list, curr->artist, curr->title, curr->album, curr->genre, curr->year);
    curr_list = curr_list->next;
  }

  new_list = write_to_playlist(filename, new_list);
}
