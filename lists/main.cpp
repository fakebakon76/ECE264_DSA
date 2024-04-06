#include <fstream>
#include <iostream>
#include "SimpleList.h"
#include <unordered_map>
#include <variant>

using namespace std;
using SimpleListVariant = variant<Queue<int>, Queue<double>, Queue<string>, Stack<int>, Stack<double>, Stack<string>>;

int createLists(const string file, unordered_map<string, SimpleListVariant> *map);
int create(string name, string listType, unordered_map<string, SimpleListVariant> *map);
int push(string name, string value);
int pop(string name);

int main() {
    /*
    string inFile;
    cout << "Enter the name of the input text file: ";
    cin >> inFile;
    */
    unordered_map<string, SimpleListVariant> map;


    createLists("c.txt", &map);
    
    /*
    Stack stack = Stack<double>("test_queue");
    stack.push(5);
    map.insert({stack.getName(), stack});
    cout << "existance of this key in stack is " << map.count("test_queu") << "\n";
    cout << get<Stack<double>>(map.at("test_queue")).getName();
*/
}



int createLists(const string file, unordered_map<string, SimpleListVariant> *map) {
    
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
            else if (word == 1) name += line[i];
            else if(word == 2) third += line[i];
            else {cout << "ERROR: createLists() in main.cpp is out of bounds\n\n"; return -1;}
        }

        if(command == "push") {
        }
        else if (command == "pop") {
        }
        else if (command == "create") {
            create(name, third, map);
        }

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

int create(string name, string listType, unordered_map<string, SimpleListVariant> *map) {
    cout << "PROCESSING COMMAND: create " << name << " " << listType << "\n";
    
    if(map->count(name)) {
        cout << "ERROR: This name already exists!\n";
        return -1;
    }

    char type = name[0];
    if(listType == "stack") {
        if(type == 'i') map->insert({name, Stack<int>(name)});
        else if(type == 'd') map->insert({name, Stack<double>(name)});
        else if(type == 's') map->insert({name, Stack<string>(name)});
    } else {
        if(type == 'i') map->insert({name, Queue<int>(name)});
        else if(type == 'd') map->insert({name, Queue<double>(name)});
        else if(type == 's') map->insert({name, Queue<string>(name)});
    }

    return 0;
}

int push(string name) {
    return 0;
}

int pop(string name) {
    return 0;
}
