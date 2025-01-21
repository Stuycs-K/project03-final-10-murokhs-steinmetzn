[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/Vh67aNdh)
# Knockoff Sony Walkman
Group Number: 37

### Forrest (intentional spelling)

Sasha Murokh and Naomi Steinmetz
       
### Project Description:

This project is a music terminal interface inspired by Spotify and the layout of a Sony Walkman. Users are able to create playlists, add songs, and "play" them. While this project originally built off of the music library project, we are only utilizing the node struct and functions, building more original functionality. </br>
ALLOCATING MEMORY: the original music library project began utilizing this, and we expanded on the concept</br>
WORKING WITH FILES/FINDING INFORMATION ABOUT FILES: Songs can be added directly from the mp3 file tags. For this, we used the id3v2lib library (https://github.com/larsbs/id3v2lib/tree/dev).</br>
SIGNALS: SIGINT to exit after double checking with user, SIGQUIT to exit directly</br>

  
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
&nbsp;&nbsp;&nbsp;&nbsp;(R)emove song -- User is asked for title and artist of song, and the song is removed. </br>
&nbsp;&nbsp;&nbsp;&nbsp;(A)dd song -- Sub-menu is displayed: </br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;(M)anually add -- User is asked to manually input the title, artist, album, genre, and year of song, and the song is added. </br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;(L)oad from mp3 album -- List of mp3 albums is printed, then user is prompted to select an album. The songs are added to the playlist. </br>
(V)iew playlist -- List of playlists is printed, then user is prompted to select a playlist. The contents of the playlist are printed.</br>
(P)lay playlist -- List of playlists is printed, then user is prompted to select a playlist. The program simulates playlist the playlist in order through ASCII art</br>
(S)huffle playlist -- List of playlists is printed, then user is prompted to select a playlist. The contents of the playlist are printed, and a sub-menu is displayed: </br>
&nbsp;&nbsp;&nbsp;&nbsp;(S)huffle -- Shuffles the order of the songs in the playlist.</br>
&nbsp;&nbsp;&nbsp;&nbsp;(A)lphabetical by artist -- Sorts the playlist alphabetically by artist then by song.</br>
&nbsp;&nbsp;&nbsp;&nbsp;(R)everse -- Reverses the order of the playlist. </br>
(L)eave -- Exits the program. </br>
&nbsp;&nbsp;&nbsp;&nbsp;**The program can also be exited by ctrl+C, prompting the user to verify whether they would like to exit.

### Video Link
