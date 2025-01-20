[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/Vh67aNdh)
# Knockoff Sony Walkman
Group Number: 37

### Forrest (intentional spelling)

Sasha Murokh and Naomi Steinmetz
       
### Project Description:

Explain what is this project.
  
### Instructions:

#### How to install/run/compile
1. Clone and move into this repository
```
$ git clone git@github.com:Stuycs-K/project03-final-10-murokhs-steinmetzn.git
```
```
$ cd project03-final-10-murokhs-steinmetzn
```
2. Compile the library we are using to read mp3 tags
```
$ cd id3v2lib-dev
```
```
$ make
```
```
$ cd ..
```
3. Run the program
```
$ make run
```

#### How to interact with this program
When the program is run, a menu is displayed: </br>
(C)reate playlist -- User is prompted for playlist name. </br>
(E)dit playlist -- List of playlists is printed, then user is prompted to select a playlist. The contents of the playlist are printed, and a sub-menu is displayed: </br>
    (R)emove song -- User is asked for title and artist of song, and the song is removed. </br>
    (A)dd song -- User is asked to manually input the title, artist, album, genre, and year of song, and the song is added. </br>
(V)iew playlist -- List of playlists is printed, then user is prompted to select a playlist. The contents of the playlist are printed.</br>
(P)lay playlist -- List of playlists is printed, then user is prompted to select a playlist. The program simulates playlist the playlist in order through ASCII art</br>
(S)huffle playlist -- List of playlists is printed, then user is prompted to select a playlist. The contents of the playlist are printed, and a sub-menu is displayed: </br>
    (S)huffle -- Shuffles the order of the songs in the playlist.</br>
    (A)lphabetical by artist -- Sorts the playlist alphabetically by artist then by song.</br>
    (R)everse -- Reverses the order of the playlist. </br>
(L)eave -- Exits the program. </br>
**The program can also be exited by ctrl+C, prompting the user to verify whether they would like to exit.

### Video Link
