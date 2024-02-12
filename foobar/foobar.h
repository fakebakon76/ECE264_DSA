#ifndef _FOOBAR_H
#define _FOOBAR_H
#define P(a) cout << a << "\n"

#include <iostream>


using namespace std;

class Foobar {

    protected:
        int strength;
        int position;
        Foobar *next;
        string name;
        string type = "foobar";
        int getPosition();

    public:
        explicit Foobar(string n, int pos);
        explicit Foobar();
        string getName();
        int getStrength();
        int setName(string n);
        string print();
        int setNext(Foobar *foobar);
        int getNext(Foobar **foobar);
};

class Foo : public Foobar {
    public:
        Foo(string n, int pos);
};

class Bar : public Foobar {
    public:
        Bar(string n, int pos);
};


#endif
