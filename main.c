#include "playlist.h"
#include "library.h"
#include "playlist.h"
#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void test_run(){
  struct song_node* song_list = NULL;
  struct song_node ** library = init();
  char songs[9][4][100 * sizeof(char)] = {
    {"The Beatles", "I Will", "white album", "pop"},
    {"The Beatles", "Julia", "white album", "pop"},
    {"Dire Straits", "Sultans of Swing", "dire straits", "pop"},
    {"Steely Dan", "Dirty Work", "dan", "pop"},
    {"Paul Mccartney", "Don't Let It Bring You Down", "mc", "pop"},
    {"The Pierces", "You'll Be Mine", "music", "pop"},
    {"zxcursed", "never enough", "russian", "rap"},
    {"The Who", "Behind Blue Eyes", "music", "pop"},
    {"17 SEVENTEEN", "USB", "russian", "hyperpop"}
  };
  for (int i = 0; i<9; i++) {
    song_list = insert_alphabetical(song_list, songs[i][0], songs[i][1], songs[i][2], songs[i][3], 2);
    add(library, songs[i][0], songs[i][1], songs[i][2], songs[i][3], 2);
  }
  printf("LINKED LIST TESTS\n====================================\n\nTesting print_song_list:\n\t");
  print_song_list(song_list);
  printf("====================================\n\nTesting print_node:\n\t");
  print_node(song_list);
  printf("\n====================================\n\nTesting find_node:\nlooking for [The Beatles: Julia]\n\t");
  find_node(song_list, "The Beatles", "Julia");
  printf("looking for [The Beatles: Magical Mystery Tour]\n\t");
  find_node(song_list, "The Beatles", "Magical Mystery Tour");
  printf("\n====================================\n\nTesting find_artist:\nlooking for [The Beatles]\n\t");
  find_artist(song_list, "The Beatles");
  printf("looking for [zxcursed]\n\t");
  find_artist(song_list, "zxcursed");
  printf("looking for [Iron Maiden]\n\t");
  find_artist(song_list, "Iron Maiden");
  printf("====================================\n\nTesting random:\n");
  print_node(random_finder(song_list));
  printf("\n");
  printf("====================================\n\nTesting delete:\n");
  printf("Delete Works?: %d\n", delete_song(library, "The Beatles", "Julia"));
  printf("Delete Works?: %d\n", delete_song(library, "The Beatles", "Julia"));
  print_letter(library, 'T');

  printf("====================================\n\nTesting shuffle:\n");

  shuffle(library, 7);

  printf("====================================\n\nPrinting Library...\n");
  print_library(library);
  reset(library);
}

int main(){
    //test_run();
    //test_run();
    char options[10];
    char line[256];
    char choice;
    printf("Hello! Starting up Knockoff Sony Walkman!...\n\n");
    printf("MENU: \n");
    printf("(C)reate playlist\n"); //will be pretty straightforward, just create a song_list
    printf("(E)dit playlist\n"); //will have to select playlist, then select whether removing or adding
    printf("(V)iew playlist\n"); //will have to select playlist
    printf("(P)lay playlist\n"); //will have to select playlist, then decide which song to play, or if this will be shuffle play, etc.


    fgets(options, sizeof(options), stdin); //take in first selection
    sscanf(options, " %c ", &choice);

    if (choice == 'C' || choice == 'c'){
      //create file for playlist, autosave
      
      printf("Name your playlist: "); //might have to create struct???
      fgets(line, sizeof(line), stdin); //take in playlist name
      //sscanf(line, " %s ", &line);
      line[strlen(line)-1] = 0;
      strcat(line, ".dat");
      create_playlist(line);
    }
/*
        struct song_node* song_list = NULL;
    }
    else if (choice == 'E' || choice == 'e'){
        printf("Select your playlist: \n");
        //list out playlists
        //user choice
        //load playlist from file
        printf("(R)emove or (A)dd song?\n");
        fgets(options, sizeof(options), stdin);
        sscanf(options, " %c ", &choice);
        //write playlist to file, overwrite ??
    }
    else if (choice == 'V' || choice == 'v'){
        printf("Select your playlist: \n");
        list_playlists();
        //user choice
        //load playlist from file
        //print_song_list(playlist);
    }
    else if (choice == 'P' || choice == 'p'){
        printf("Select your playlist: \n");
        //list out playlists
        //user choice
        //load playlist from file
        //simulate playing...
    }
    else{
        printf("Please re-enter.\n");
    }
*/
  create_playlist("test");
  list_playlists();




    //question: should they be able to access and edit the queue? if time permits yes
    return 0;
}
