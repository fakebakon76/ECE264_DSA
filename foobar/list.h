#ifndef LIST_H
#define LIST_H

#include <foobar.h>

class List {
    protected:
        Foobar *head;
        Foobar *tail;

    public:
        explicit List(Foobar *node);
        int append(Foobar *node);
        int getTail(Foobar **node);
};
#endif
