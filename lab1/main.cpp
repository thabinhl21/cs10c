#include "Playlist.h"

using namespace std;

void PrintMenu(string);

int main()
{
    cout << "Enter playlist's title:" << endl;
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

            cin.ignore(); //ignore endline at end of previous cout statement
            cout << "Enter song's name:" << endl;
            getline (cin, songName);

            cout << "Enter artist's name:" << endl;
            getline (cin, artistName);

            cout << "Enter song's length (in seconds):" << endl;
            cin >> length;

            PlaylistNode* addedSong = new PlaylistNode(ID, songName, artistName, length);

            if (head == nullptr) //if list is empty, point head and tail to new song
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

            if (head->GetID() == ID) //if deleting head
            {
                if (head == tail) //if only one song
                {
                    cout << "\"" << head->GetSongName() << "\"" << " removed." << endl;
                    delete head;
                    head = nullptr;
                    tail = nullptr;
                }
                else
                {
                    cout << "\"" << head->GetSongName() << "\"" << " removed." << endl;
                    PlaylistNode* temp = head;
                    head = head->GetNext();
                    delete temp;
                }
            }

            else if (tail->GetID() == ID) //if deleting tail
            {
                cout << "\"" << tail->GetSongName() << "\"" << " removed." << endl;
                PlaylistNode* temp = head;
                while (temp->GetNext() != tail) //get to node before tail
                {
                    temp = temp->GetNext();
                }
                temp->SetNext(tail->GetNext()); //set second-to-last node's next pointer to nullptr
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
                        cout << "\"" << temp->GetSongName() << "\"" << " removed." << endl;
                        prev->SetNext(temp->GetNext());
                        delete temp;
                        break; //need to break out of loop or it will continue until tail
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

            //find song before song being moved
            PlaylistNode* prevSong = head;
            int j = 1;
            if (songPos > 1) //if song is not first in list (there is no node before node 1)
            {
                while (j != songPos - 1)
                {  
                    prevSong = prevSong->GetNext();
                    ++j;
                }
            }

            //find song before new position
            PlaylistNode* songBefore = head;
            j = 1;
            if (newPos > 1) //if song is not first in list (there is no node before node 1)
            {
                while (j != newPos - 1)
                {
                    songBefore = songBefore->GetNext();
                    ++j;
                }
            }

            // CODE FOR MOVING NODE STARTS HERE
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

            else if (newPos >= numOfSongs) //move song to tail
            {
                if (songToMove == head)
                {
                    head = head->GetNext();
                }
                prevSong->SetNext(songToMove->GetNext());
                songToMove->InsertAfter(tail);
                tail = songToMove;
            }

            else //if not moving song to head or tail
            {
                if (songToMove == tail)
                {
                    tail = prevSong;
                    prevSong->SetNext(songToMove->GetNext());
                    songToMove->InsertAfter(songBefore);
                }
                else if (songToMove == head)
                {
                    head = head->GetNext();
                    songToMove->InsertAfter(songBefore->GetNext()); 
                }
                else
                {
                    if (songPos > newPos) //if moving down the list - like moving tail
                    {
                        prevSong->SetNext(songToMove->GetNext());
                        songToMove->InsertAfter(songBefore);
                    }
                    else //moving up the list - like moving head
                    {
                        prevSong->SetNext(songToMove->GetNext());
                        songToMove->InsertAfter(songBefore->GetNext());
                    }
                }
            }
            cout << "\"" << songToMove->GetSongName() << "\"" << " moved to position " << newPos << endl;
        }

        if (userInput == 'o')
        {
            //cout << endl;
            cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;
            if (head == nullptr)
            {
                cout << "Playlist is empty" << endl;
            }
            else
            {
                PlaylistNode* temp = head;
                int songNum = 1;

                while (temp != nullptr)
                {
                    cout << songNum << "." << endl;
                    temp->PrintPlaylistNode();
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
            cin.ignore();
            getline(cin,artistName);
            cout << endl;
            
            PlaylistNode* curr = head;
            while (curr != nullptr) {
                if (curr->GetArtistName() == artistName) {
                    cout << artistPos << "." << endl;
                    curr->PrintPlaylistNode();
                    cout << endl;
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
    cout << "Choose an option:" << endl;
}