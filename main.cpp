#include <iostream>
#include <string>
#include "my_list.h++"
#include "my_queue.h++"

using namespace std;

int main() {
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

    return 0;
}
