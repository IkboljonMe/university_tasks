#include <iostream>
#include "DoublyLinkedList.h"

int main() {
    DoublyLinkedList<int> dll;

    dll.addAtBeginning(10);
    dll.addAtBeginning(20);
    dll.addAtEnd(30);
    dll.addAtEnd(40);

    std::cout << "List: ";
    dll.display();  // Output: 20 10 30 40

    dll.removeFirst();
    std::cout << "After removing first: ";
    dll.display();  // Output: 10 30 40

    dll.removeLast();
    std::cout << "After removing last: ";
    dll.display();  // Output: 10 30

    std::cout << "Length: " << dll.length() << std::endl;  // Output: Length: 2

    return 0;
}
