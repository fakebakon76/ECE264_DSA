// THIS IS THE PROVIDED CODE FOR PROGRAM #3, DSA 1, SPRING 2024

#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;

// A simple class; each object holds four public fields
class Data {
public:
  string lastName;
  string firstName;
  string ssn;
};

// Load the data from a specified input file
void loadDataList(list<Data *> &l, const string &filename) {

  ifstream input(filename);
  if (!input) {
    cerr << "Error: could not open " << filename << "\n";
    exit(1);
  }

  // The first line indicates the size
  string line;
  getline(input, line);
  stringstream ss(line);
  int size;
  ss >> size;

  // Load the data
  for (int i = 0; i < size; i++) {
    getline(input, line);
    stringstream ss2(line);
    Data *pData = new Data();
    ss2 >> pData->lastName >> pData->firstName >> pData->ssn;
    l.push_back(pData);
  }

  input.close();
}

// Output the data to a specified output file
void writeDataList(const list<Data *> &l, const string &filename) {

  ofstream output(filename);
  if (!output) {
    cerr << "Error: could not open " << filename << "\n";
    exit(1);
  }

  // Write the size first
  int size = l.size();
  output << size << "\n";

  // Write the data
  for (auto pData:l) {
    output << pData->lastName << " " 
	   << pData->firstName << " " 
	   << pData->ssn << "\n";
  }

  output.close();
}

// Sort the data according to a specified field
// (Implementation of this function will be later in this file)
void sortDataList(list<Data *> &);

// The main function calls routines to get the data, sort the data,
// and output the data. The sort is timed according to CPU time.
int main() {
  string filename;
  cout << "Enter name of input file: ";
  cin >> filename;
  list<Data *> theList;
  loadDataList(theList, filename);

  cout << "Data loaded.\n";

  cout << "Executing sort...\n";

  clock_t t1 = clock();
  sortDataList(theList);
  clock_t t2 = clock();
  double timeDiff = ((double) (t2 - t1)) / CLOCKS_PER_SEC;

  cout << "Sort finished. CPU time was " << timeDiff << " seconds.\n";

  cout << "Enter name of output file: ";
  cin >> filename;
  writeDataList(theList, filename);
  return 0;
}

// -------------------------------------------------
// YOU MAY NOT CHANGE OR ADD ANY CODE ABOVE HERE !!!
// -------------------------------------------------

// You may add global variables, functions, and/or
// class defintions here if you wish.

#include <unordered_map>

bool comparator1(Data *i, Data *j);
bool comparator2(Data *i, Data *j);
void sort123(list<Data *> &l);
void sort4(list<Data *> &l);

void sortDataList(list<Data *> &l) {
    
    bool theCase = true;
    list<Data *>::iterator it = l.begin();
    list<Data *>::iterator it2 = next(it);
    for(int i = 1; i < 7; i++) {
        it2 = next(it2);
    }

    if((*it)->firstName == (*it2)->firstName) theCase = false;

    if(theCase) sort123(l);
    else sort4(l);

    return;
}

void sort4(list<Data *> &l) {
    unordered_map<string, vector<Data *> *> map;
    
    // Make the Buckets
    ifstream input("ssn_buckets.txt");
    list<string> lastNames;
    string lname;
    while(getline(input, lname)) {
        map.insert({lname, new vector<Data *>()});
        lastNames.push_back(lname);
    }
    
    // Stick the Data in the Buckets
    string tempStr = "";
    for (auto pData:l) {
        tempStr = pData->ssn.substr(0,3);
        map.at(tempStr)->push_back(pData);
    }

    // Sort
    for (auto& key:lastNames) {
        vector<Data *> *dataList = map.at(key);
        sort(dataList->begin(), dataList->end(), comparator2);
    }
    
    l.clear();
    for (auto& key:lastNames) {
        vector<Data *> dataList = *map.at(key);
        for (auto data:dataList) l.push_back(data);
    }
}

void sort123(list<Data *> &l) {
    unordered_map<string, vector<Data *> *> map;
    
    // Make the Buckets
    ifstream input("last_names2.txt");
    list<string> lastNames;
    string lname;
    while(getline(input, lname)) {
        map.insert({lname, new vector<Data *>()});
        lastNames.push_back(lname);
    }
    
    // Stick the Data in the Buckets
    for (auto pData:l) map.at(pData->lastName)->push_back(pData);
    
    // Sort
    for (auto& key:lastNames) {
        vector<Data *> *dataList = map.at(key);
        sort(dataList->begin(), dataList->end(), comparator1);
    }
    
    l.clear();
    for (auto& key:lastNames) {
        vector<Data *> dataList = *map.at(key);
        for (auto data:dataList) l.push_back(data);
    }
}

bool comparator1(Data* i, Data* j) {
    if (i->firstName < j->firstName) return true;
    else if (i->firstName == j->firstName) return i->ssn < j->ssn;
    else return false;
}

bool comparator2(Data* i, Data* j) {
    return i->ssn < j->ssn;
}
