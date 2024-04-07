#include <fstream>
#include <sstream>
#include <iostream>
#include "SimpleList.h"
#include <unordered_map>
#include <variant>



using namespace std;
using SimpleListVariant = variant<Queue<int>, Queue<double>, Queue<string>, Stack<int>, Stack<double>, Stack<string>>;

template <typename Object>
SimpleList<Object> *retrieveList(string name, unordered_map<string, SimpleListVariant> *map);

int createLists(const string file, unordered_map<string, SimpleListVariant> *map);
int create(string name, string listType, unordered_map<string, SimpleListVariant> *map);

template <typename Object>
int push(string name, Object value, unordered_map<string, SimpleListVariant> *map);

template <typename Object>
int pop(string name, unordered_map<string, SimpleListVariant> *map);

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
    SimpleList<double> *thing = get_if<Queue<double>>(&(map.at("test_queue")));
    if(thing == nullptr) {
        cout << "it worked!!\n";
        thing = get_if<Stack<double>>(&(map.at("test_queue")));
    } else {cout << "It didnt work"; return -1;}
    cout << thing->getName() << "\n\n";
    
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
        
        istringstream iss(line);
        string command, name, third;
        
        iss >> command >> name >> third;
        //cout << command << " " << name << " " << third <<"\n";
        char type = name[0];
        if(command == "push") {
            if(type == 'i')      push<int>(name, stoi(third), map);
            else if(type == 'd') push<double>(name, stod(third), map);
            else if(type == 's') push<string>(name, third, map);
        }
        else if (command == "pop") {
            if(type == 'i')      pop<int>(name, map);
            else if(type == 'd') pop<double>(name, map);
            else if(type == 's') pop<string>(name, map);
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

template <typename Object>
int push(string name, Object value, unordered_map<string, SimpleListVariant> *map) {
    cout << "PROCESSING COMMAND: push " << name << " " << value << "\n";
    
    if(! map->count(name)) {
        cout << "ERROR: This name does not exist!\n";
        return -1;
    }

    SimpleList<Object> *list = retrieveList<Object>(name, map);
    list->push(value);
    list->traverse();
    return 0;
}
/*
template <typename Object>
int pop(string name, unordered_map<string, SimpleListVariant> *map) {
    cout << "PROCESSING COMMAND: pop " << name << "\n";

    SimpleList<Object> *list = retrieveList<Object>(name, map);
    cout << "Value popped: " << list->pop() << "\n";

    return 0;
}*/

template <typename Object>
SimpleList<Object> *retrieveList(string name, unordered_map<string, SimpleListVariant> *map) {
    SimpleList<Object> *list = get_if<Stack<Object>>(&(map->at(name)));
    if(list == nullptr) list = get_if<Queue<Object>>(&(map->at(name)));
    return list;
}
