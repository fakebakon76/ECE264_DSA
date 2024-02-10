#include "foobar.h"
#include <fstream>
#include "list.h"

using namespace std;

void getFileNames(string *in, string *out);
void createFoobars(Foobar *first);

int main() {
    // Getting text files names
    string inFile = "",
           oFile  = "";
    
    //getFileNames(&inFile, &oFile);
    Foobar head = Foobar("Penis", 69);
    List list = List(&head);
    Foobar *fuck = NULL;
    list.getTail(&fuck);
    list.append(new Foobar("Shitfuck", 32));
    fuck->print();

    // Reading the file and creating the people
    ifstream input(inFile);
    



    return 0;
}

void createFoobars(Foobar ) {
}


void getFileNames(string *in, string *out) {
    cout << "Enter the name of the input text file: ";
    cin >> *in;

    cout << "Enter the name of the output text file: ";
    cin >> *out;
    return;
}

