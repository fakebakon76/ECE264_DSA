#ifndef _FOOBAR_H
#define _FOOBAR_H

#include <iostream>


using namespace std;

class Foobar {

    protected:
        int position;
        string name;
        int getPosition();

    public:
        explicit Foobar(string n, int pos);
        string getName();
        virtual int getStrength();
        string print();
};

class Foo : public Foobar {
    public:
        Foo(string n, int pos);
        int getStrength();
};

class Bar : public Foobar {
    public:
        Bar(string n, int pos);
        int getStrength();
};


#endif
