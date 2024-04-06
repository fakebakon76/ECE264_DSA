#ifndef _SIMPLELIST_H
#define _SIMPLELIST_H

#include <iostream>
#include "Node.h"

using namespace std;

template <typename Object>
class SimpleList {
    private:
        string name;
        
    public:
        virtual int push(Object data) = 0;
        virtual Object pop() = 0;
        string getName() {return name;}
        int getSize() {return size;}
        SimpleList(const string n): name(n), size(0), head(NULL), tail(NULL) {}

        

    // Node stuff
    protected:
        Node<Object> *head = NULL;
        Node<Object> *tail = NULL;
        int size = 0;

        int preppend(const Object data) {
            head = new Node(data, head, NULL);
            if(!tail) tail = head;
            size++;
            return 0;
        }

        int append(const Object data) {
            tail = new Node<Object>(data, NULL, tail);
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

            Node<Object> *temp = this->head;
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
            cout << "PROCESSING COMMAND: push " << this->getName() << " " << data << "\n";
            this->append(data);
            
            //Checking if it worked
            if(this->tail->getData() != data) {
                cout << "ERROR: Stack::push() failed!\n";
                return -1;
            }
            return 0;
        }

        Object pop() {
            cout << "PROCESSING COMMAND: pop " << this->getName() << "\n";
            
            Node<Object> *toPop = NULL;
            int size = this->getSize();
            if(! size) cout << "ERROR: This list is empty!\n";
            else if(this->tail) {
                toPop = this->tail;
                if(size == 1) {
                    this->head = NULL;
                    this->tail = NULL;
                } else {
                    this->tail = this->tail->getPrev();
                    this->tail->setNext(NULL);
                }

                this->size--;
            } else cout << "ERROR: Stack::pop() says the stack " << this->getName() << " has a size but has no tail!\n";
            
            cout << "Value popped: " << toPop->getData() << "\n";
            return toPop->getData();
        }
};

template <typename Object>
class Queue : private SimpleList<Object> {
};

#endif
