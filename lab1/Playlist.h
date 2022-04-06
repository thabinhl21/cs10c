#ifndef __PLAYLIST_H__
#define __PLAYLIST_H__

#include <iostream>

using namespace std;

class PlaylistNode
{
    public:

        //Default constructor
        PlaylistNode();

        //Parameterized constructor
        PlaylistNode(string, string, string, int);
        
        void InsertAfter(PlaylistNode*);

        void SetNext(PlaylistNode*);

        string GetID() const;

        string GetSongName() const;

        string GetArtistName() const;

        int GetSongLength() const;

        PlaylistNode* GetNext() const;

        void PrintPlaylistNode() const;

    private:

        string uniqueID;

        string songName;

        string artistName;

        int songLength;

        PlaylistNode* nextNodePtr;
};

#endif