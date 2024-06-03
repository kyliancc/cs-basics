//
// Created by kylianc on 6/3/24.
//
#include "linkedlist.h"
#include "linkedlist.cpp"

int main() {
    LinkedList<int> list;
    list.insertFront(20);
    list.insertFront(40);
    list.insertAt(1, -2);
    list.print();
    list.removeAt(2);
    list.setValueAt(1, 100);
    std::cout << list.getValueAt(1) << std::endl;
    list.print();
    std::cout << list.size() << std::endl;
    return 0;
}
