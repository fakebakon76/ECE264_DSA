#include "foobar.h"
#include <fstream>
#include <list>

using namespace std;

int getFileNames(string *in, string *out);
int createFoobars(string file, list<Foobar*> *list);
int createOutput(string file, list<Foobar*> *list);

int main() {

    string inFile = "",
           oFile  = "";

    getFileNames(&inFile, &oFile); // Getting file names

    list<Foobar*> list{};          // Creating list to store the foobar pointers in

    createFoobars(inFile, &list);  // Parsing through the file and making the foobar pointer list
    createOutput(oFile, &list);    // Outputting the foobar information to the desired file

    return 0;
}

/* Function:   createOutput(string file, list<Foobar*> *list)
 * Parameters: file - name of the file to write to (does not have to be pre-existing)
 *             list - pointer to a std::list of foobar pointers (the list should be full at this point)
 * Purpose:    To parse through the list of foobars and print their names and strengths to the designated
 *             output file.
 */
int createOutput(string file, list<Foobar*> *list) {
    // Testing to make sure there is a list to parse
    if(list->size() == 0) {cout << "There is no list so there is nothing to print!\n"; return -1;}
    

    ofstream out(file);
    if(out.is_open()) {
        for(auto i : *list) {
            out << i->print(); // Appending the foobar information to the output file
        }
        out.close();
    }
    
    return 0;
}

/* Function:   createFoobars(string file, list<Foobar*> *list)
 * Parameters: file - name of the file to read from
 *             list - pointer to a std::list of foobar pointers (the list should be empty at this point)
 * Purpose:    To parse through the file and create a list of foobars (including bars and foos) that have 
 *             their position and names already assigned.
 */
int createFoobars(string file, list<Foobar*> *list) {
    // Initializing some variables
    string   line = "",
             name = "",
             type = "";
    int      position = 1;
    bool     on_type = 1;
    char     c = ' ';
    Foobar   *temp = NULL; // Pointer to temperarily store each created foobar in before appending it to the list
    ifstream input(file);

    while(getline(input, line)) {
        
        // Getting the name and type of the foobar on the current line
        for(int i = 0; i <= (int)line.length()-1; i++) {
            c = line[i];
            
            if( c == ' ' )   { on_type = 0; continue; }
            else if( on_type ) type += c;
            else               name += c;
        }
        
        // Determining the type of foobar to create
        if(type == "foo")          temp = new Foo(name, position);
        else if (type == "bar")    temp = new Bar(name, position);
        else if (type == "foobar") temp = new Foobar(name, position);
        else {cout << "Something got messed up pt1.\n"; return -1;}
        
        // Appending recently created foobar to the list
        list->push_back(temp);
        
        // Testing to make sure the foobar was properly appended
        if(list->back() != temp) {
            cout << "ERROR: In createFoobar(), the foobar was not added to the list correctly."; 
            input.close();
            return -1;
        } else {
            // Resetting some variables
            position++;
            name    = "";
            type    = "";
            on_type = 1;
        }
    }

    input.close();
    return 0;    
}

/* Function:   getFileNames(string *in, string *out)
 * Parameters: in  - pointer to an std::string that will be assigned the desired input file name
 *             out - pointer to an std::string that will be assigned the desired output file name
 * Purpose:    To collect the desired input and output file names from the user.
 */

int getFileNames(string *in, string *out) {
    cout << "Enter the name of the input text file: ";
    cin >> *in;

    cout << "Enter the name of the output text file: ";
    cin >> *out;
    
    // I can't think of any tests for this function
    return 0;
}

