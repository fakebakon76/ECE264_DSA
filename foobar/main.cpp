#include "foobar.h"
#include <fstream>
#include <list>
#include <stack>
using namespace std;

int getFileNames(string *in, string *out);
int createFoobars(string file, stack<Foobar*> *list);
int createOutput(string file, stack<Foobar*> *list);

int main() {

    string inFile = "",
           oFile  = "";

    getFileNames(&inFile, &oFile); // Getting file names

    stack<Foobar*> list{};          // Creating list to store the foobar pointers in

    createFoobars(inFile, &list);  // Parsing through the file and making the foobar pointer list
    createOutput(oFile, &list);    // Outputting the foobar information to the desired file

    return 0;
}

/* Function:   createOutput(string file, stack<Foobar*> *list)
 * Parameters: file - name of the file to write to (does not have to be pre-existing)
 *             list - pointer to a std::list of foobar pointers (the list should be full at this point)
 * Purpose:    To parse through the list of foobars and print their names and strengths to the designated
 *             output file.
 */
int createOutput(string file, stack<Foobar*> *list) {
    // Testing to make sure there is a list to parse
    if(!list->size()) {cout << "There is no list so there is nothing to print!\n"; return -1;}
    
    ofstream out(file);
    int size = (int)list->size()-1;
    for(int i = 0; i <= size; i++) {
        Foobar *temp = list->top();
        out << temp->print(); // Appending the foobar information to the output file
        list->pop();
    }
    out.close();
    
    return 0;
}

/* Function:   createFoobars(string file, stack<Foobar*> *list)
 * Parameters: file - name of the file to read from
 *             list - pointer to a std::list of foobar pointers (the list should be empty at this point)
 * Purpose:    To parse through the file and create a list of foobars (including bars and foos) that have 
 *             their position and names already assigned.
 */
int createFoobars(string file, stack<Foobar*> *list) {
    string line = "";
    int stop;   

    stack<string> names;
    stack<string> types;

    ifstream input(file);

    while(getline(input, line)) {
        stop = line.find(' ');
        types.push(line.substr(0, stop));
        names.push(line.substr(stop+1, line.length()-1-stop));
    }

    input.close();
    
    // Initializing some more variables
    int       position = 1;
    string    type, name;
    
    while(!names.empty()) {
        type = types.top();

        // Determining the type of foobar to create
        if(type == "foo")          list->push(new Foo(names.top(), position));
        else if (type == "bar")    list->push(new Bar(names.top(), position));
        else if (type == "foobar") list->push(new Foobar(names.top(), position));
        else {cout << "ERROR: In createFoobar(), no foobar created.\n"; return -1;}
        
        names.pop();
        types.pop();

        position++;
    }

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

