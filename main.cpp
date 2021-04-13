#include <iostream>
#include <string>
#include "my_list.h++"

using namespace std;

int main() {

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

    return 0;
}
