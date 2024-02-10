#ifndef _FOOBAR_H
#define _FOOBAR_H

#include <iostream>


using namespace std;

class Foobar {

    protected:
        int strength;
        int position;
        Foobar *next;
        string name;
        
        int getPosition();

    public:
        explicit Foobar(string n, int pos);
        explicit Foobar();
        string getName();
        int getStrength();
        void print();
        int setNext(Foobar *foobar);
        int getNext(Foobar *foobar);
};

#endif
