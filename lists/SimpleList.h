#ifndef _SIMPLELIST_H
#define _SIMPLELIST_H

#include <iostream>

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
                    

                inline Node *getNext() {return next;}
                inline Node *getPrev() {return prev;}
                inline Object getData() {return data;}

                inline int setNext(Node *n) {
                    next = n;
                    return 0;
                }

                inline int setPrev(Node *n) {
                    prev = n;
                    return 0;
                }
        };
        
    public:
        virtual int push(Object data) = 0;
        virtual Object pop() = 0;
        inline string getName() {return name;}
        inline int getSize() {return size;}
        inline SimpleList(const string n): name(n), size(0), head(NULL), tail(NULL) {}

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
};

template <typename Object>
class Stack : public SimpleList<Object> {
    public:
        inline explicit Stack(const string n): SimpleList<Object>(n) {}

        inline int push(const Object data) {
            this->append(data);
            return 0;
        }

        Object pop() {
            Object toPop;
            if(this->tail) {
                toPop = this->tail->getData();
                if(this->size == 1) {
                    this->head = NULL;
                    this->tail = NULL;
                } else {
                    this->tail = this->tail->getPrev();
                    this->tail->setNext(NULL);
                }

                this->size--;
            } 
            
            return toPop;
        }
};

template <typename Object>
class Queue : public SimpleList<Object> {
    public:
        inline explicit Queue(const string n): SimpleList<Object>(n) {}

        inline int push(const Object data) {
            this->append(data);
            return 0;
        }

        Object pop() {
            Object toPop;
            if(this->tail) {
                toPop = this->head->getData();
                if(this->size == 1) {
                    this->head = NULL;
                    this->tail = NULL;
                } else {
                    this->head = this->head->getNext();
                    this->head->setPrev(NULL);
                }

                this->size--;
            } 
            
            return toPop;
        }
};

#endif
