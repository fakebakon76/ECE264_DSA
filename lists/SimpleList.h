#ifndef _SIMPLELIST_H
#define _SIMPLELIST_H

#include <iostream>
//#include "Node.h"

using namespace std;


template <typename Object>
class SimpleList {
    private:
        string name; 
        class Node {
            private:    
                Object data;
                Node *next;
                Node *prev;
            public:

                Node(const Object d, Node *n = NULL, Node *p = NULL) {
                    data = d;
                    if(n) {
                        n->prev = this;
                        next = n;
                    }
                    
                    if(p) {
                        p->next = this;
                        prev = p;
                    }
                }
                    

                Node *getNext() {return next;}
                Node *getPrev() {return prev;}
                Object getData() {return data;}

                int setNext(Node *n) {
                    next = n;
                    return 0;
                }

                int setPrev(Node *n) {
                    prev = n;
                    return 0;
                }
        };
        
    public:
        virtual int push(Object data) = 0;
        virtual Object pop() = 0;
        string getName() {return name;}
        int getSize() {return size;}
        SimpleList(const string n): name(n), size(0), head(NULL), tail(NULL) {}

        

    // Node stuff
    protected:
        Node *head = NULL;
        Node *tail = NULL;
        int size = 0;

        int preppend(const Object data) {
            head = new Node(data, head, NULL);
            if(!tail) tail = head;
            size++;
            return 0;
        }

        int append(const Object data) {
            tail = new Node(data, NULL, tail);
            if(!head) head = tail;
            size++;
            return 0;
        }


    public:
        int traverse() {
            if(! this->size) {
                cout << "ERROR: SimpleList::traverse() has error because list is empty!\n";
                return -1;
            }

            Node *temp = this->head;
            cout << "\nPrinting...\n";
            for(int i = 0; i < this->getSize(); i++) {
                cout << "  " << temp->getData() << "\n";
                temp = temp->getNext();
            }
            cout << " - - - - - - - - - - - - - -\n\n";

            return 0;
        }
};

template <typename Object>
class Stack : public SimpleList<Object> {
    public:
        explicit Stack(const string n): SimpleList<Object>(n) {}

        int push(const Object data) {
            this->append(data);
            
            //Checking if it worked
            if(this->tail->getData() != data) {
                cout << "ERROR: Stack::push() failed!\n";
                return -1;
            }
            return 0;
        }

        Object pop() {
            
            Object toPop;
            
            if(! this->size) cout << "ERROR: This list is empty!\n";
            else if(this->tail) {
                toPop = this->tail->getData();
                if(this->size == 1) {
                    this->head = NULL;
                    this->tail = NULL;
                } else {
                    this->tail = this->tail->getPrev();
                    this->tail->setNext(NULL);
                }

                this->size--;
            } else cout << "ERROR: Stack::pop() says the stack " << this->getName() << " has a size but has no tail!\n";
            
            return toPop;
        }
};

template <typename Object>
class Queue : public SimpleList<Object> {
    public:
        explicit Queue(const string n): SimpleList<Object>(n) {}

        int push(const Object data) {
            this->append(data);
            
            //Checking if it worked
            if(this->tail->getData() != data) {
                cout << "ERROR: Queue::push() failed!\n";
                return -1;
            }
            return 0;
        }

        Object pop() {
            
            Object toPop;
            if(! this->size) cout << "ERROR: This list is empty!\n";
            else if(this->tail) {
                toPop = this->head->getData();
                if(this->size == 1) {
                    this->head = NULL;
                    this->tail = NULL;
                } else {
                    this->head = this->head->getNext();
                    this->head->setPrev(NULL);
                }

                this->size--;
            } else cout << "ERROR: Stack::pop() says the stack " << this->getName() << " has a size but has no tail!\n";
            
            return toPop;
        }

};

#endif
