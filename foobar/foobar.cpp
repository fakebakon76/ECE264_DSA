#include "foobar.h"

using namespace std;

    // Foobar constructor with name and position 
    Foobar::Foobar(string n = "", int pos = 0): position(pos), name(n){}

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
        return position;
    }
    
    // Formats the foobar for print and returns the print-ready string
    string Foobar::print() {
        string str = "";
        str+= getName() + ' ' + to_string(getStrength())  + string("\n");
        return str;
    }
    
    // Foo class constructor
    Foo::Foo(string n, int pos): Foobar(n, pos) {}
    
    // Get strength of a foo
    int Foo::getStrength() {
        return getPosition()*3;
    }
    
    // Bar class constructor
    Bar::Bar(string n, int pos): Foobar(n, pos) {}

    // Get strength of a bar
    int Bar::getStrength() {
        return getPosition()+15;
    }
