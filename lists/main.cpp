#include <fstream>
#include <iostream>
#include "SimpleList.h"

using namespace std;

int createLists(const string file);
int create(string name, string type);
int push(int key, string value);
int pop(int key);

int main() {
    
    string inFile;
    cout << "Enter the name of the input text file: ";
    cin >> inFile;

    createLists(inFile);
}

int createLists(const string file) {
    
    ifstream input(file);
    string   line    = "", 
             command = "", 
             name    = "", 
             third   = "";
    int      word    = 0;
    
    while(getline(input, line)) {
        // Parsing line for commands
        for(int i = 0; i <= (int)line.length()-1; i++) {
            if(line[i] == ' ') {word++; continue;}
            else if(word == 0) command += line[i];
            else if(word == 1) name += line[i];
            else if(word == 2) third += line[i];
            else {cout << "ERROR: createLists() in main.cpp is out of bounds ~line 31\n\n"; return -1;}
        }
        
        cout << command << " " << name << " " << third << "\n";
        
        // Resetting the line specific strings
        line    = "";
        command = "";
        name    = "";
        third   = "";
        word    = 0;
    }

    input.close();
    return 0;
}

int create(string name, string type) {
    return 0;
}

int push(int key, string value) {
    return 0;
}

int pop(int key) {
    return 0;
}
