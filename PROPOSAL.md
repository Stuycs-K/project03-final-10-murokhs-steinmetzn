# Final Project Proposal

## Group Members:

Sasha Murokh and Naomi Steinmetz
       
# Intentions:

We will be building a terminal interface that is inspired by Spotify, building off of the music lab.
    
# Intended usage:

Prints and waits for user input
Show playlists to user: There will be some pre-made playlists from which the user can play. 
There will be some pre-made playlists from which the user can play. Upon running, the user will be prompted with a menu from which they can choose a command (such as “create playlist” or “view playlists”). The user will continue to be prompted for more information (such as playlist name/directories of mp3s to add) based on their choice. 

  
# Technical Details:

We will be building on the music library lab to incorporate new elements that we have covered since. Utilizing the base code from the lab (ALLOCATING MEMORY), we will add functions that can automatically add songs + artists based on mp3 file metadata/tags in a given directory (WORKING WITH FILES/FINDING INFORMATION ABOUT FILES). If time permits, we will allow the user to modify the information on these tags (WORKING WITH FILES/FINDING INFORMATION ABOUT FILES). Also, music playlists can be written to and read from files (WORKING WITH FILES). The user will also be able to play songs (PROCESSES - FORK EXEC), which will either be simulated on the terminal or launch a media player. A sighandler will be implemented for pausing music, or cleanly exiting the program while saving the playlist to a file (SIGNALS).
    
# Intended pacing:

Jan 8: song node modifications and working functionality of initial lab adjustment ✅
Jan 10: working UI for all functions user will be able to access ✅
Jan 13: reading from mp3 files 
Jan 15: play songs (simulated on terminal) ✅
Jan 15: playlist read/write ✅
Jan 17: signal stuff
Jan 19: optional features (modify mp3 file tags, play songs in media player, cleaner UI)
Jan 20: record video

