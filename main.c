#include "playlist.h"
#include "library.h"
#include "playlist.h"
#include "node.h"
#include "mp3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <signal.h>

static void sighandler(int signo) {
  if ( signo == SIGINT ){
    char options[10];
    char choice;
    printf("\nAre you sure you would like to exit? (y/n)\n");
    fgets(options, sizeof(options), stdin); //take in first selection
    sscanf(options, " %c ", &choice);
    if (choice == 'Y' || choice =='y'){
      exit(0);
    }
  }
  if (signo == SIGQUIT){
    //break out of while loop?
    printf("\nLeaving...\n");
    exit(0);
  }
}

int main(){
    signal(SIGINT, sighandler);
    signal(SIGQUIT, sighandler);
    char options[10];
    char line[256];
    char choice;
    struct song_node* curr_list = NULL;
    printf("\033[35;46m\n");
    printf("Hello! Starting up Knockoff Sony Walkman!...\n\n");
    while (1){
      signal(SIGINT, sighandler);
      signal(SIGQUIT, sighandler);
      printf("\nMENU: \n");
      printf("(C)reate playlist\n"); //working
      printf("(E)dit playlist\n"); //will have to select playlist, then select whether removing or adding
      printf("(V)iew playlist\n"); //working
      printf("(P)lay playlist\n"); //working
      printf("(T)esting\n"); //temporary
      printf("(L)eave\n");

      fgets(options, sizeof(options), stdin); //take in first selection
      sscanf(options, " %c ", &choice);

      if (choice == 'C' || choice == 'c'){
        //create file for playlist, autosave
        //CURRENT ISSUES: playlist name must be entered with no spaces before or after

        printf("Name your playlist: ");
        fgets(line, sizeof(line), stdin); //take in playlist name
        //sscanf(line, " %s ", &line);
        line[strlen(line)-1] = 0;
        strcat(line, ".dat");
        create_playlist(line);
      }
      else if (choice == 'E' || choice == 'e'){
        printf("\n***Playlists*** \n"); //should always have a default there
        list_playlists();
        printf("Select your playlist: \n");
        fgets(line, sizeof(line), stdin);
        line[strlen(line)-1] = 0;
        strcat(line, ".dat");
        curr_list = read_from_playlist(line); //crashes if you put the wrong thing
        printf("***Titles in %s:***\n", line);
        print_song_list(curr_list);
        printf("(R)emove or (A)dd song?\n");
        fgets(options, sizeof(options), stdin);
        sscanf(options, " %c ", &choice);
        if (choice == 'R' || choice == 'r'){
          remove_song(line);
        }
        else if (choice == 'A' || choice == 'a'){
          add_song(line);
        }
        else{
          printf("Please re-enter.\n");
        }
      }
      else if (choice == 'P' || choice == 'p'){
        printf("\n***Playlists*** \n"); //should always have a default there
        list_playlists();
        printf("Select your playlist: \n");
        fgets(line, sizeof(line), stdin);
        line[strlen(line)-1] = 0;
        strcat(line, ".dat");
        play_playlist(line);
      }
      else if (choice == 'V' || choice == 'v'){
        //suggestion: prompt user at the end, asking if they'd like to play it
        printf("\n***Playlists*** \n"); //should always have a default there
        list_playlists();
        printf("Select your playlist: \n");
        fgets(line, sizeof(line), stdin);
        line[strlen(line)-1] = 0;
        strcat(line, ".dat");
        curr_list = read_from_playlist(line);
        print_song_list(curr_list);
      }
      else if (choice == 'T' || choice == 't'){ //testing

        //create
        /*printf("Name your playlist: ");
        fgets(line, sizeof(line), stdin);
        line[strlen(line)-1] = 0;
        strcat(line, ".dat");
        create_playlist(line);

        //get a song list
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
          curr_list = insert_back(curr_list, songs[i][0], songs[i][1], songs[i][2], songs[i][3], 2);
        }

        //write
        curr_list = write_to_playlist(line, curr_list);

        add_song(line);

        curr_list = read_from_playlist(line);

        print_song_list(curr_list);

        remove_song(line);

        curr_list = read_from_playlist(line);

        print_song_list(curr_list);*/

        curr_list = read_from_playlist("tatertots.dat");

        print_song_list(curr_list);

        //playing
        //play_playlist(line);

      }
      else if (choice == 'L' || choice == 'l'){
        break;
      }
      else{
        printf("Please re-enter.\n");
      }
    }
    printf("exiting...\n");

    //question: should they be able to access and edit the queue? if time permits yes
    return 0;
}
