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
    string   line    = "", 
             command = "", 
             name    = "",
             third   = "";
    int      word    = 0;
    
    while(getline(input, line)) {
        
        istringstream iss(line);
        string command, name, third;
        
        iss >> command >> name >> third;
        //cout << command << " " << name << " " << third <<"\n";
        char type = name[0];
        if(command == "push") {
            *text += ("PROCESSING COMMAND: push " + name + " " + third + "\n");
            if(type == 'i')      push<int>(name, stoi(third), map, text);
            else if(type == 'd') push<double>(name, stod(third), map, text);
            else if(type == 's') push<string>(name, third, map, text);
        }
        else if (command == "pop") {
            *text += ("PROCESSING COMMAND: pop " + name + "\n");
            if(type == 'i')      pop<int>(name, map, text);
            else if(type == 'd') pop<double>(name, map, text);
            else if(type == 's') pop<string>(name, map, text);
        }
        else if (command == "create") {
            *text += ("PROCESSING COMMAND: create " + name + " " + third + "\n");

            create(name, third, map, text);
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

int create(string name, string listType, unordered_map<string, SimpleListVariant> *map, string *text) {
    if(map->count(name)) {
        *text += "ERROR: This name already exists!\n";
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

template <typename Object>
SimpleList<Object> *retrieveList(string name, unordered_map<string, SimpleListVariant> *map) {
    SimpleList<Object> *list = get_if<Stack<Object>>(&(map->at(name)));
    if(list == nullptr) list = get_if<Queue<Object>>(&(map->at(name)));
    return list;
}


template <typename Object>
string toString(Object o) {
    ostringstream oss;
    oss << o;
    return oss.str();
}
