/*************************************************************/
/*                MusicPlaylist Definition                   */
/*************************************************************/
/* TODO: Implement the member functions of a MusicPLaylist   */
/*     This class uses a linked-list of Song structs to      */
/*     represent a playlist structure                        */
/*************************************************************/

#include "musicPlaylist.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

/*
 * Purpose: Constructor for empty linked list
 * @param none
 * @return none
 */
MusicPlaylist::MusicPlaylist() {
    /*
    DO NOT MODIFY THIS
    This constructor is already complete. 
    */
    head = nullptr;
}

MusicPlaylist::MusicPlaylist(Song* song) {
    /*
    DO NOT MODIFY THIS
    This constructor is already complete. 
    */
    head = song;
}

Song* MusicPlaylist::getFirstSong(){
    //DO NOT MODIFY THIS
    return this->head;
}
/*======================== ALL FUNCTIONS BELOW ARE #TODO ======================= */

/**
 * Display the song object
 * 
 * @param song The song object to display
 * @return No output returned. Should write to cout
 */
void Song::displaySong(){
    // TODO
    cout <<"[ " << this->songName << ", " << this->artistNames << ", ";
    if(this->liked){
        cout << "<3 ]";
    }else{
        cout << "</3 ]";
    }
}

/**
 * Checks whether the music playlist is empty or not
 * 
 * @return True/False if the playlist is empty or not
 */
bool MusicPlaylist::isEmpty(){
    //TODO
    if(getFirstSong() == nullptr){
        return true;
    }
    return false;
}


/**
 * Walk through all songs in a playlist and display each one based on readme specs.
 * 
 * @return No output returned. Should write to cout using displaySong
 */
void MusicPlaylist::displayPlaylist(){
    //todo
    cout << "Displaying songs" << endl;
    cout << "==================" << endl;
    if(!isEmpty()){
        Song* song;
        song = getFirstSong();
        song -> displaySong();
        cout << " -> ";
        while(song -> next != nullptr){
            song = song -> next;
            song->displaySong();
            cout << " -> ";
        }
    }
    cout << "NULL" << endl;
    cout << "==================" << endl;

}


/**
 * Adds a song to the playlist after the passed song. 
 * @param previousSong The song object to which the newSong should be added to.
 * @param newSong The newSong to be added to the playlist. It should be added after the previousSong (if previousSong is nullptr, song gets added to the beginning)
 * @return No output returned. Should modify the MusicPlaylist 
 */
void MusicPlaylist::addSong(Song* previousSong, Song* newSong){
    if(previousSong == nullptr){
        newSong -> next = head;
        head = newSong;
    }else{ 
        newSong -> next = previousSong -> next;
        previousSong -> next = newSong;
    }
}

/**
 * Search through the music playlist until you find the song by name.
 * 
 * @param name The name of the song being looked for
 * @return Should return a song object. If no song is found, should return nullptr.
 */
Song* MusicPlaylist::searchSongByName(std::string name){
    if(isEmpty()){
        return nullptr;
    }
    Song* song;
    song = getFirstSong();

    bool found = false;
    while(!found && song!= nullptr){
        if(song -> songName == name){
            return song;
        }
        song = song -> next;
    }
    return nullptr;
    
}

/**
 * Like the song. Change the boolean (*liked*) from false->true or true->false
 * 
 * @param name The name of the song to like
 * @return No output returned. Should modify the Song and print according to readme specifications.
 */
void MusicPlaylist::likeSong(std::string name){
    Song* temp = searchSongByName(name);
    if(temp != nullptr){
        if(temp -> liked == false){
            temp -> liked = true;
            cout << "Song: " << temp->songName << " liked!" << endl;
        }
        else{
            temp -> liked = false;

        }
        
    }else{
        cout << "Song not found." << endl;
    }
}

/**
 * Traverse the playlist and display all songs that match the given artistName
 * 
 * @param name The name of the artist that we should search for
 * @return No output returned. Should write to cout each song that matches the artist.
 */  
void MusicPlaylist::displayAllSongsbyArtist(std::string name){
    // TODO
    bool found = false;
    if(!isEmpty()){
        Song* song;
        song = getFirstSong();
        while(song != nullptr){
            if(song -> artistNames == name){
                song->displaySong();
                cout << endl;
                found = true;
            }
            song = song -> next;
        }
    }
    if(!found){
        cout << "No songs found." << endl;
    }

}