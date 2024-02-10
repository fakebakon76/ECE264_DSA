#include <list.h>

    List::List(Foobar *node): head(node), tail(node), length(1){
    }

    int List::append(Foobar *node) {
        tail->setNext(node);
        tail = node;

        if(tail == node) {length++; return 0;}
        else return -1;
    }

    int List::getTail(Foobar **node) {
        *node = &(*tail);
        return 0;
    }

    int List::getHead(Foobar **node) {
        *node = &(*head);
        return 0;
    }
    
    int List::getLength() {
        return length;
    }
