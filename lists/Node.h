#ifndef NODE_H
#define NODE_H
template <typename Object>
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

#endif 
