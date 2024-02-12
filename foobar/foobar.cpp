#include "foobar.h"

using namespace std;

    // Foobar Constructor with name and position 
    Foobar::Foobar(string n = "", int pos = 0): strength(pos), position(pos), name(n){}

    Foobar::Foobar(): strength(-1), position(-1), name("") {}

    // Gets the position of the foobar
    int Foobar::getPosition() {
        return position;
    }

    // Gets the name of the foobar
    string Foobar::getName() {
        return name;
    }
    // Gets the strength of the foobar
    int Foobar::getStrength() {
        return strength;
    }

    string Foobar::print() {
        string str = "";
        if(position >= 10)
            str+= string("[")  + to_string(getPosition()) + string("]: ") + getName() + string(", ") + type + string("\n      Power Level: ") + to_string(getStrength()) + string("\n\n");
        else
            str+= string("[")  + to_string(getPosition()) + string("]:  ") + getName() + string(", ") + type + string("\n      Power Level: ") + to_string(getStrength())  + string("\n\n");
        return str;
    }

    int Foobar::setNext(Foobar *foobar) {
        next = foobar;

        if(next != foobar) return -1;
        return 0;
    }

    int Foobar::getNext(Foobar **foobar) {
        if(next == NULL) return -1;
        else {
            *foobar = &(*next);
            return 0;
        }
    }

    int Foobar::setName(string n) {
        name = n;
        if(name == n) return 0;
        else return -1;
    }

    Foo::Foo(string n, int pos): Foobar(n, pos) {
        strength = pos*3;
        type = "foo";
    }

    Bar::Bar(string n, int pos): Foobar(n, pos) {
        strength = pos+15;
        type = "bar";
    }
