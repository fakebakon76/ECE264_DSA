#include <fstream>
#include <sstream>
#include <iostream>
#include "SimpleList.h"
#include <unordered_map>
#include <variant>


using namespace std;
using SimpleListVariant = variant<Queue<int>, Queue<double>, Queue<string>, Stack<int>, Stack<double>, Stack<string>>;

template <typename Object>
string toString(Object o);

template <typename Object>
SimpleList<Object> *retrieveList(string name, unordered_map<string, SimpleListVariant> *map);

int createLists(const string file, unordered_map<string, SimpleListVariant> *map, string *text);

template <typename Object>
int create(string name, string listType, unordered_map<string, SimpleListVariant> *map, string *text);

template <typename Object>
int push(string name, Object value, unordered_map<string, SimpleListVariant> *map, string *text);

template <typename Object>
int pop(string name, unordered_map<string, SimpleListVariant> *map, string *text);

int main() {
    
    string inFile, outFile, text = "";
    cout << "Enter the name of the input text file: ";
    cin >> inFile;
    cout << "Enter the name of the output text file: ";
    cin >> outFile;

    unordered_map<string, SimpleListVariant> map;
    
    createLists(inFile, &map, &text);
    
    ofstream out(outFile);
    out << text;
    out.close();
}

int createLists(const string file, unordered_map<string, SimpleListVariant> *map, string *text) {
      
    ifstream input(file);
    string   line    = "", command = "", name    = "", third   = "";
    
    while(getline(input, line)) {
        
        // Split the line into three words
        istringstream iss(line);
        string command, name, third;
        iss >> command >> name >> third;

        char type = name[0];
        
        if(command == "push") {
            *text += ("PROCESSING COMMAND: push " + name + " " + third + "\n");
            if(type == 'i')      push<int>(name, stoi(third), map, text);
            else if(type == 'd') push<double>(name, stod(third), map, text);
            else if(type == 's') push<string>(name, third, map, text);
        } else if (command == "pop") {
            *text += ("PROCESSING COMMAND: pop " + name + "\n");
            if(type == 'i')      pop<int>(name, map, text);
            else if(type == 'd') pop<double>(name, map, text);
            else if(type == 's') pop<string>(name, map, text);
        } else if (command == "create") {
            *text += ("PROCESSING COMMAND: create " + name + " " + third + "\n");
            if(type == 'i')      create<int>(name, third, map, text);
            else if(type == 'd') create<double>(name, third, map, text);
            else if(type == 's') create<string>(name, third, map, text);
        }

        // Resetting the line specific strings
        line    = "";
        command = "";
        name    = "";
        third   = "";
    }

    input.close();
    return 0;
}

template <typename Object>
int create(string name, string listType, unordered_map<string, SimpleListVariant> *map, string *text) {
    if(map->count(name)) {
        *text += "ERROR: This name already exists!\n";
        return -1;
    }
    
    if(listType == "stack")  map->insert({name, Stack<Object>(name)});
    else                     map->insert({name, Queue<Object>(name)});

    return 0;
}

template <typename Object>
int push(string name, Object value, unordered_map<string, SimpleListVariant> *map, string *text) {
    if(! map->count(name)) {
        *text += "ERROR: This name does not exist!\n";
        return -1;
    }

    SimpleList<Object> *list = retrieveList<Object>(name, map);
    list->push(value);
    return 0;
}

template <typename Object>
int pop(string name, unordered_map<string, SimpleListVariant> *map, string *text) {
    if(! map->count(name)) {
        *text += "ERROR: This name does not exist!\n";
        return -1;
    }

    SimpleList<Object> *list = retrieveList<Object>(name, map);
    if(!list->getSize()) {
        *text += "ERROR: This list is empty!\n";
        return -1;
    }

    *text += ("Value popped: " + toString(list->pop()) + "\n"); 
    return 0;
}

// Gets the list from the map
template <typename Object>
SimpleList<Object> *retrieveList(string name, unordered_map<string, SimpleListVariant> *map) {
    SimpleList<Object> *list = get_if<Stack<Object>>(&(map->at(name)));
    if(list == nullptr) list = get_if<Queue<Object>>(&(map->at(name)));
    return list;
}

// Converts objects to string (used for int and double)
template <typename Object>
string toString(Object o) {
    ostringstream oss;
    oss << o;
    return oss.str();
}
