#ifndef _SIMPLELIST_H
#define _SIMPLELIST_H

#include <iostream>

using namespace std;

template <typename Object>
class SimpleList {
    private:
        string name;
        
    public:
        virtual int push(Object data) = 0;
        virtual Object *pop() = 0;
        string get_Name() {return name;}
        explicit SimpleList(const string n): name(n), size(0), head(NULL), tail(NULL) {}

    // Node stuff
    private:
        struct Node {
            Object *data;
            Node *next;
            Node *prev;

            Node(const Object &d, Node *n, Node *p) {
                data = d;
                if(n) n->next = this;
                if(p) p->prev = this;
            }
        };

    protected:
        Node *head;
        Node *tail;
        int size;

        int preppend(const Object &data) {
            head = Node(data, head, NULL);
            if(!tail) tail = head;
            size++;
            return 0;
        }

        int append(const Object &data) {
            tail = Node(data, NULL, tail);
            if(!head) head = tail;
            size++;
            return 0;
        }

        int getSize() {return size;}
};

template <typename Object>
class Stack : public SimpleList<Object> {
    public:
        Stack(string n): SimpleList(n) {}

        int push(const Object &data) {
            append(data);
            
            //Checking if it worked
            if(tail->data != data) {
                cout << "ERROR: Stack::push() failed!\n";
                return -1;
            }
            return 0;
        }

        Object *pop() {
            Object *toPop = NULL;
            
            if(!size) cout << "ERROR: This list is empty!\n";
            else if(tail) {
                toPop = tail->data;
                if(size == 1) {
                    head = NULL;
                    tail = NULL;
                } else {
                    tail = tail->prev;
                    tail->next = NULL;
                }

                size--;
            } else cout << "ERROR: Stack::pop() says the stack " << getName() << " has a size but has no tail!\n";

            return toPop;
        }
};

template <typename Object>
class Queue : private SimpleList<Object> {
    public:
        Queue(string n): SimpleList(n) {}

        int push(const Object &data) {
            append(data);
            
            //Checking if it worked
            if(tail->data != data) {
                cout << "ERROR: Stack::push() failed!\n";
                return -1;
            }
            return 0;
        }

        Object *pop() {
            Object *toPop = NULL;
            
            if(!size) cout << "ERROR: This list is empty!\n";
            else if(head) {
                toPop = head->data;
                if(size == 1) {
                    head = NULL;
                    tail = NULL;
                } else {
                    head = head->next;
                    head->prev = NULL;
                }

                size--;
            } else cout << "ERROR: Stack::pop() says the stack " << getName() << " has a size but has no head!\n";

            return toPop;
        }
};

#endif
