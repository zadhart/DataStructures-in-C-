//
// Created by zadhart on 13/04/2021.
//

#ifndef DATASTRUCTURES_MY_LIST_H
#define DATASTRUCTURES_MY_LIST_H

#endif //DATASTRUCTURES_MY_LIST_H

using namespace std;

template <typename T>
class LinkedList{

private:
    class sNode{
    public:
        T data;
        sNode* next = NULL;
        sNode* prev = NULL;
    };

    sNode* head = NULL;
    sNode* tail = NULL;
    int size;

public:

    LinkedList(){
        this->size = 0;
        this->head = new sNode;
        this->tail = new sNode;
        this->head->next = this->tail;
        this->tail->prev = this->head;
    }

    void push(T newData){
        sNode* n = NULL;
        n = new sNode();
        n->data = newData;
        n->prev = this->tail->prev;
        n->next = this->tail;
        this->tail->prev->next = n;
        this->tail->prev = n;
        this->size++;
    }

    void pop(int position){
        if(position > this->size){
            cout << "We aren't that big yet bro, come and join us" << "\n";
        }
        else{
            sNode* n = this->head;
            for (int i = 0; i < position; ++i) {
                n = n->next;
            }
            sNode* nn = n->next->next;
            delete n->next;
            n->next = nn;
        }
    }

    void printList(){
        sNode* n = head->next;

        while(n->next != NULL){
            cout << n->data << "\n";
            n = n->next;
        }
    }

    int getSize(){
        return this->size;
    }
};

/*  Example of code:
    LinkedList<string> centopeia_humana;

    centopeia_humana.push("Gregory");
    centopeia_humana.push("Moises");
    centopeia_humana.push("Marcos");
    centopeia_humana.push("Erigleison");

    centopeia_humana.printList();

    cout << "Size of centopeia: " << centopeia_humana.getSize() << "\n";

    centopeia_humana.pop(2);

    centopeia_humana.printList();

    cout << "Size of centopeia: " << centopeia_humana.getSize() << "\n";
 */