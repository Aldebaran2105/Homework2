#include <iostream>
#include "DoublyLinkedList.h"

int main() {
    DoublyLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_front(0);
    std::cout << list.front() << " " << list.back() << "\n";
    list.insert(5, 2);
    for (int i = 0; i < list.size(); i++) {
        std::cout << list[i] << " ";
    }
    std::cout << "\n";
    list.remove(2);
    for (int i = 0; i < list.size(); i++) {
        std::cout << list[i] << " ";
    }
    std::cout << "\n";
    list.reverse();
    for (int i = 0; i < list.size(); i++) {
        std::cout << list[i] << " ";
    }
    std::cout << "\n";
    list.clear();
    std::cout << (list.empty() ? "Empty" : "Not Empty") << "\n";
    return 0;
}
