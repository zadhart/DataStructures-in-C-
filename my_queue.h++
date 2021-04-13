//
// Created by zadhart on 13/04/2021.
//

#ifndef DATASTRUCTURES_MY_QUEUE_H
#define DATASTRUCTURES_MY_QUEUE_H

#endif //DATASTRUCTURES_MY_QUEUE_H

using namespace std;

template <typename T>
class Queue{
private:

    //Created the class of the queue node
    class qNode{
    public:
        T data;
        qNode* next = NULL;
        qNode* prev = NULL;
    };

    //Created the head and the tail of the queue
    qNode* head = NULL;
    qNode* tail = NULL;

    //This will save the size of the queue
    int size;

public:
    //This function will initializate the queue
    Queue(){
        head = new qNode();
        tail = new qNode();
        this->head->next = this->tail;
        this->tail->prev = this->head;
        this->size = 0;
    }

    //This function will put the new data on the queue
    void enqueue(T newData){
        qNode* n = NULL;
        n = new qNode();
        n->data = newData;
        n->next = this->tail;
        n->prev = this->tail->prev;
        this->tail->prev->next = n;
        this->tail->prev = n;
        this->size++;
    }

    //This function will remove the data from the queue and return the data inside of the node
    T dequeue(){
        qNode* n = NULL;
        n = this->head->next;
        this->head->next = n->next;
        T data = n->data;
        delete n;
        this->size--;
        return data;
    }

    //This function will print the queue
    void printQueue(){
        qNode* n = this->head->next;
        while(n->next != NULL){
            cout << n->data << "\n";
            n = n->next;
        }
    }

    //This funtion will return the size of the queue
    int getSize(){
        return this->size;
    }
};

/*  Example of code:
    Queue<string> minhaFila;

    minhaFila.enqueue("Greg");
    minhaFila.enqueue("Moises");
    minhaFila.enqueue("Marcos");
    minhaFila.enqueue("Erigleison");

    minhaFila.printQueue();

    cout << "Size of the queue: " << minhaFila.getSize() << "\n";

    minhaFila.dequeue();

    minhaFila.printQueue();

    cout << "Size of the queue: " << minhaFila.getSize() << "\n";
 */