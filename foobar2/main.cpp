#include "foobar.h"
#include <fstream>
#include <list>

using namespace std;

void getFileNames(string *in, string *out);
int createFoobars(string file, list<Foobar*> *list);
int createOutput(string file, list<Foobar*> *list);

int main() {
    // Getting text files names
    string inFile = "",
           oFile  = "";
    
    getFileNames(&inFile, &oFile);

    // Reading the file and creating the people
    list<Foobar*> list{};


    createFoobars(inFile, &list);
    createOutput(oFile, &list);
    cout << "\n---------------------\n\n";   

    return 0;
}

int createOutput(string file, list<Foobar*> *list) {
    if(list->size() == 0) {cout << "There is no start to the list"; return -1;}
    
    ofstream out(file);
    if(out.is_open()) {
        for(auto i : *list) {
            out << i->print();
        }
        out.close();
    }
    
    return 0;
}

int createFoobars(string file, list<Foobar*> *list) {
    string   line = "",
             name = "",
             type = "";
    int      position = 1;
    bool     on_type = 1;
    char     c = ' ';
    Foobar   *temp = NULL;
    ifstream input(file);

    while(getline(input, line)) {
        
        for(int i = 0; i <= (int)line.length()-1; i++) {
            c = line[i];
            
            
            if( c == ' ' )   { on_type = 0; continue; }
            else if( on_type ) type += c;
            else               name += c;
        }
        //P("Line: " << line << "\n   Type: " << type <<"\n   Name: " << name << "\n");
        
        if(type == "foo")          temp = new Foo(name, position);
        else if (type == "bar")    temp = new Bar(name, position);
        else if (type == "foobar") temp = new Foobar(name, position);
        else {cout << "Something got messed up pt1.\n"; return -1;}
        
        list->push_back(temp);

        if(list->back() != temp) {
            cout << "Temp @" << temp << "\nBack @" << list->back()->print() << "\n\n"; 
            input.close();
            return -1;
        } else {
            position++;
            name    = "";
            type    = "";
            on_type = 1;
        }
    }
    input.close();
    return 0;    
}


void getFileNames(string *in, string *out) {
    cout << "Enter the name of the input text file: ";
    cin >> *in;

    cout << "Enter the name of the output text file: ";
    cin >> *out;
    return;
}

