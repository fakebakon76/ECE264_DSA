#include <list.h>

    List::List(Foobar *node): head(node), tail(node) {
    }

    int List::append(Foobar *node) {
        tail->setNext(node);
        tail = node;

        if(tail == node) return 0;
        else return -1;
    }

    int List::getTail(Foobar **node) {
        *node = &(*tail);
        return 0;
    }

