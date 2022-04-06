#include "Playlist.h"

using namespace std;

void PrintMenu(string);

int main()
{
    cout << "Enter playlist's title: " << endl;
    string playlistTitle;
    getline (cin, playlistTitle);
    PrintMenu(playlistTitle);

    PlaylistNode* head = nullptr;
    PlaylistNode* tail = nullptr;
    int numOfSongs = 0;
    char userInput;
    cin >> userInput;

    while (userInput != 'q')
    {
        if (userInput == 'a')
        {
            string ID;
            string songName;
            string artistName;
            int length;

            cout << endl;
            cout << "ADD SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            cin >> ID;
            cout << endl;

            cin.ignore(); //not sure why, but this fixed something...
            cout << "Enter song's name:" << endl;
            getline (cin, songName);
            cout << endl;

            cout << "Enter artist's name:" << endl;
            getline (cin, artistName);
            cout << endl;

            cout << "Enter song's length (in seconds):" << endl;
            cin >> length;

            PlaylistNode* addedSong = new PlaylistNode(ID, songName, artistName, length);

            if (head == nullptr)
            {
                head = addedSong;
                tail = addedSong;
            }
            else
            {
                tail->SetNext(addedSong);
                tail = addedSong;
            }

            ++numOfSongs;
        }

        if (userInput == 'd')
        {
            cout << endl;
            cout << "REMOVE SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            string ID;
            cin >> ID;
            cout << endl;

            if (head->GetID() == ID) //if deleting head
            {
                if (head == tail) //if only one song
                {
                    cout << "\"" << head->GetSongName() << "\"" << " removed" << endl;
                    delete head;
                    head = nullptr;
                    tail = nullptr;
                }
                else
                {
                    cout << "\"" << head->GetSongName() << "\"" << " removed" << endl;
                    PlaylistNode* temp = head;
                    head = head->GetNext();
                    delete temp;
                }
            }

            else if (tail->GetID() == ID) //if deleting tail
            {
                cout << "\"" << tail->GetSongName() << "\"" << " removed" << endl;
                PlaylistNode* temp = head;
                while (temp->GetNext() != tail)
                {
                    temp = temp->GetNext();
                }
                temp->SetNext(tail->GetNext());
                delete tail;
                tail = temp;
            }
            
            else
            {
                PlaylistNode* temp = head->GetNext();
                PlaylistNode* prev = head;

                while (temp != tail)
                {
                    if (temp->GetID() == ID)
                    {
                        cout << "\"" << temp->GetSongName() << "\"" << " removed" << endl;
                        prev->SetNext(temp->GetNext());
                        delete temp;
                    }
                    else
                    {
                        temp = temp->GetNext();
                        prev = prev->GetNext();
                    }
                }
            }

            --numOfSongs;
        }

        if (userInput == 'c')
        {
            cout << endl;
            cout << "CHANGE POSITION OF SONG" << endl;
            cout << "Enter song's current position:" << endl;
            int songPos;
            cin >> songPos;
            cout << endl;
            cout << "Enter new position for song:" << endl;
            int newPos;
            cin >> newPos;

            //find song being moved
            PlaylistNode* songToMove = head;

            int i = 1;

            while (i != songPos)
            {
                songToMove = songToMove->GetNext();
                ++i;
            }
            cout << "song to move finished" << endl;

            PlaylistNode* prevSong = head;
            int j = 1;
            //find song before song being moved
            if (songPos > 1) //if song is not first in list
            {
                while (j != songPos - 1)
                {  
                    prevSong = prevSong->GetNext();
                    ++j;
                }
            }
            cout << "prevsong finished" << endl;

            //find song before new position
            PlaylistNode* songBefore = head;
            j = 1;
            if (newPos > 1) //if song is not first in list
            {
                while (j != newPos - 1)
                {
                    songBefore = songBefore->GetNext();
                    ++j;
                }
            }
            cout << "songbefore finished" << endl;

            
            if (newPos <= 1) //move song to head
            {
                if (songToMove == tail)
                {
                    tail = prevSong;
                }
                
                prevSong->SetNext(songToMove->GetNext());
                songToMove->SetNext(head);
                head = songToMove;
            }

            else if (newPos >= numOfSongs) //move node to tail
            {
                if (songToMove == head)
                {
                    head = head->GetNext();
                }
                songToMove->InsertAfter(tail);
                tail = songToMove;
            }

            else
            {
                if (songToMove == tail)
                {
                    tail = prevSong;
                }
                else if (songToMove == tail)
                {
                    tail = prevSong;
                }
                songToMove->InsertAfter(songBefore);
            }
        }

        if (userInput == 'o')
        {
            cout << endl;
            if (head == nullptr)
            {
                cout << "Playlist is empty" << endl;
            }
            else
            {
                cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;
                PlaylistNode* temp = head;
                int songNum = 1;

                while (temp != nullptr)
                {
                    cout << songNum << endl;
                    cout << "Unique ID: " << temp->GetID() << endl;
                    cout << "Song Name: " << temp->GetSongName() << endl;
                    cout << "Artist Name: " << temp->GetArtistName() << endl;
                    cout << "Song Length (in seconds): " << temp->GetSongLength() << endl;
                    if (temp != tail)
                    {
                        cout << endl;
                    }
                    ++songNum;
                    temp = temp->GetNext();
                }
            }  
        }

        if (userInput == 's') {
            string artistName;
            int artistPos = 1;

            cout << endl;
            cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
            cout << "Enter artist's name:" << endl;
            getline(cin,artistName);
            //cin >> artistName;
            cin.ignore();
            //cout << artistName;
            cout << endl;
            
            PlaylistNode* curr = head;
            while (curr != nullptr) {
                if (curr->GetArtistName() == artistName) {
                    cout << artistPos << "." << endl;
                    curr->PrintPlaylistNode();
                }
                artistPos += 1;
                curr = curr->GetNext();
            }
            
        }

        if (userInput == 't') {
            int sum = 0;
            PlaylistNode* curr = head;

            cout << endl;
            cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;

            while (curr != nullptr) {
                sum += curr->GetSongLength();
                curr = curr->GetNext();
            }

            cout << "Total time: " << sum << " seconds" << endl;

        }

        PrintMenu(playlistTitle);
        cin >> userInput;
    }


    return 0;
}

void PrintMenu(string playlistTitle)
{
    cout << endl;
    cout << playlistTitle << " PLAYLIST MENU" << endl;
    cout << "a - Add song" << endl;
    cout << "d - Remove song" << endl;
    cout << "c - Change position of song" << endl;
    cout << "s - Output songs by specific artist" << endl;
    cout << "t - Output total time of playlist (in seconds)" << endl;
    cout << "o - Output full playlist" << endl;
    cout << "q - Quit" << endl;
    cout << endl;
    cout << "Choose an option: " << endl;
}