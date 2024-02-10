#include "foobar.h"

using namespace std;

    // Foobar Constructor with name and position 
    Foobar::Foobar(string n = "", int pos = 0): strength(pos), position(pos), name(n) {}

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

    void Foobar::print() {
        cout << getName() << " " << getStrength() << "\n";
        return;
    }


    int Foobar::setNext(Foobar *foobar) {
        next = foobar;

        if(next == foobar) return 0;
        else return -1;
    }

    int Foobar::getNext(Foobar *foobar) {
        if(next == NULL) return -1;
        else {
            foobar = next;
            return 0;
        }
    }
