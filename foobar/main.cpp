#include "foobar.h"
#include <fstream>
#include "list.h"

using namespace std;

void getFileNames(string *in, string *out);
int createFoobars(string file, List **list);
int createOutput(string file, List *list);

int main() {
    // Getting text files names
    string inFile = "",
           oFile  = "";
    
    getFileNames(&inFile, &oFile);

    // Reading the file and creating the people
    List *list = NULL;

    createFoobars(inFile, &list);
    createOutput(oFile, list);
    cout << "\n---------------------\n\n";   

    return 0;
}

int createOutput(string file, List *list) {
    Foobar *curr = NULL;
    list->getHead(&curr);

    if(!curr) {cout << "There is no start to the list"; return -1;}
    
    ofstream out(file);
    if(out.is_open()) {
        for(int i = 0; i <= list->getLength()-1; i++) {
            out << curr->print();
            curr->getNext(&curr);
        }
        out.close();
    }
    
    return 0;
}

int createFoobars(string file, List **list) {
    string   line = "",
             name = "",
             type = "";
    int      position = 1;
    bool     on_type = 1;
    char     c = ' ';
    Foobar   *temp = NULL,
             *check = NULL;
    ifstream input(file);
    List *listy = NULL;

    while(getline(input, line)) {
        
        for(int i = 0; i <= (int)line.length()-1; i++) {
            c = line[i];
            
            if( c == ' ' )   { on_type = 0; continue; }
            else if( on_type ) type += c;
            else               name += c;
        }
        
        if(type == "foo")          temp = new Foo(name, position);
        else if (type == "bar")    temp = new Bar(name, position);
        else if (type == "foobar") temp = new Foobar(name, position);
        else {cout << "Something got messed up pt1.\n"; return -1;}
        
        if(position == 1) listy = new List(temp);
        else listy->append(temp);
        
        listy->getTail(&check);
        if(temp != check) {
            cout << "Temp @" << temp << "\nTail @" << check << "\n\n"; 
            input.close();
            return -1;
        } else {
            position++;
            name    = "";
            type    = "";
            on_type = 1;
        }
    }
    listy->getTail(&temp);
    temp->setNext(NULL);
    input.close();
    *list = listy;
    return 0;    
}


void getFileNames(string *in, string *out) {
    cout << "Enter the name of the input text file: ";
    cin >> *in;

    cout << "Enter the name of the output text file: ";
    cin >> *out;
    return;
}

