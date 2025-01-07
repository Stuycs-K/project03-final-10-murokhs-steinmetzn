#include "library.h"
#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int main(){
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
    add(library, songs[i][0], songs[i][1]);
  }
  printf("LINKED LIST TESTS\n====================================\n\nTesting print_list:\n\t");
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
  reset(library);
}
