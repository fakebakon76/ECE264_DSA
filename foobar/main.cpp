#include "foobar.h"
#include <fstream>
#include "list.h"

using namespace std;

void getFileNames(string *in, string *out);
int createFoobars(string file, List *list);

int main() {
    // Getting text files names
    string inFile = "",
           oFile  = "";
    
    getFileNames(&inFile, &oFile);

    // Reading the file and creating the people
    List *list = NULL;

    createFoobars(inFile, list);

    return 0;
}

int createFoobars(string file, List *list) {
    string line;
    int i = 0;
    Foobar *temp = NULL;
    Foobar *check = NULL;
    ifstream input(file);

    while(getline(input, line, ' ')) {
        cout<< "Position:  " << i << ", Current line = " << line <<"\n\n";
        
        if(i%2==0) {
            if(line == "foo")          temp = new Foo("", i/2+1);
            else if (line == "bar")    temp = new Bar("", i/2+1);
            else if (line == "foobar") temp = new Foobar("", i/2+1);
            else {cout << "Something got messed up pt1.\n"; return -1;}
            
            if(i==0) list = new List(temp);
            else list->append(temp);
        
        } else if(i%2==1) {
            temp->setName(line);
          
            list->getTail(&check);
            check->print();
            cout << "----------------------";
            string fuck = "";
            cin >> fuck;
        } else {cout << "Something got messed up pt2.\n"; return -1;}
        
        i++;
    }
    return 0;    
}


void getFileNames(string *in, string *out) {
    cout << "Enter the name of the input text file: ";
    cin >> *in;

    cout << "Enter the name of the output text file: ";
    cin >> *out;
    return;
}

