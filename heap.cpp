#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <vector>
#include <fstream>
#include <unistd.h>

using namespace std;

class NoteEntry
{
  public:
    virtual void printNote(){};
};

class Freeform: public NoteEntry
{
  public:
    char data[16];

    void printNote(){
      cout << "Freeform note: " << data << endl;
    }
};

class Reminder: public NoteEntry
{
  public:
    std::string action;
    void printNote(){
      cout << "Remind me to " << action << endl;
    }

    void setAction(string s){
      action = s;
    }
};

std::vector<NoteEntry*> noteArray;

void printAllNotes(){
    std::vector<NoteEntry*>::iterator it;
    for (it = noteArray.begin(); it != noteArray.end(); ++it) {
        cout << "Note #" << it-noteArray.begin() << ":" << endl;
        cout << "-----------------" << endl;
        (*it)->printNote();
        cout << "-----------------" << endl;
  }
}

void printMenu(){
    cout << "What would you like to do?" << endl;
    cout << "(n) Make a new note" << endl;
    cout << "(p) Print all notes" << endl;
    cout << "(q) Quit" << endl;
    cout << "> ";
}

extern "C" void win();

void win(){
  system("/bin/sh");
}

void (*win_ptr)() = &win;

int main(){
    while(true) {
        printMenu();
        char action;
        cin >> action;

        // Ignore newline
        cin.ignore();
        switch (action) {
            case 'n':
              char type;
              cout << "Please enter note type:" << endl;
              cout << "(f) Freeform" << endl;
              cout << "(r) Reminder" << endl;
              cout << "> ";

              cin >> type;
              // Ignore newline
              cin.ignore();
              switch (type){
                case 'r':
                  {
                    Reminder* newNote = new Reminder();
                    string action;

                    cout << "Please enter reminder action:" << endl;

                    cin >> action;

                    newNote->setAction(action);

                    noteArray.push_back(newNote);
                    break;
                  }
                case 'f':
                  {
                    Freeform* newNote = new Freeform();
                    char data[16];
                    char name[16];

                    cout << "Please enter note name:" << endl;
                    read(0, name, sizeof(name));

                    cout << "Please enter note text:" << endl;
                    read(0, data, sizeof(data));

                    strncpy(newNote->data, data, strlen(data));

                    noteArray.push_back(newNote);
                    break;
                  }
                  default:
                    cout << "Unrecognized option!" << endl;
                    break;
              }
              break;
            case 'p':
              printAllNotes();
              break;
            case 'q':
              cout << "Goodbye!" << endl;
              exit(0);
            default:
              cout << "Unrecognized option!" << endl;
              break;
        }
    }
    return 1;
}