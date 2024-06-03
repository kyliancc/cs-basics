//
// Created by kylianc on 6/3/24.
//

#include <iostream>
#include "linkedlist.h"

template <typename T>
LinkedList<T>::LinkedList(): head(nullptr) {}

template <typename T>
LinkedList<T>::~LinkedList() {
    if (!head) {
        return;
    }

    Node* curNode = head;
    while (true) {
        if (!curNode->next) {
            delete curNode;
            return;
        }
        Node* pNode = curNode;
        curNode = curNode->next;
        delete pNode;
    }
}

template <typename T>
void LinkedList<T>::insertFront(const T& value) {
    if (!head) {
        head = new Node(value);
        return;
    }

    Node* pNode = head;
    head = new Node(value);
    head->next = pNode;
}

template <typename T>
void LinkedList<T>::insertBack(const T& value) {
    if (!head) {
        head = new Node(value);
        return;
    }

    Node* curNode = head;
    while (true) {
        if (!curNode->next) {
            curNode->next = new Node(value);
            return;
        }
        curNode = curNode->next;
    }
}

template <typename T>
void LinkedList<T>::insertAt(int index, const T& value) {
    if (index == 0) {
        insertFront(value);
        return;
    }
    if (!head) {
        throw "Index out of range!";
    }

    Node* curNode = head;
    for (int i = 0; i < index - 1; ++i) {
        if (!curNode->next) {
            throw "Index out of range!";
        }
        curNode = curNode->next;
    }

    Node* pNode = curNode->next;
    curNode->next = new Node(value);
    curNode->next->next = pNode;
}

template <typename T>
void LinkedList<T>::removeFront() {
    if (!head) {
        throw "The linked list is empty!";
    }

    Node* pNode = head->next;
    delete head;
    head = pNode;
}

template <typename T>
void LinkedList<T>::removeBack() {
    if (!head) {
        throw "The linked list is empty!";
    }

    if (!head->next) {
        delete head;
        head = nullptr;
        return;
    }
    Node* curNode = head;
    while (true) {
        if (!curNode->next->next) {
            delete curNode->next;
            curNode->next = nullptr;
            return;
        }
        curNode = curNode->next;
    }
}

template <typename T>
void LinkedList<T>::removeAt(int index) {
    if (index == 0) {
        removeFront();
        return;
    }
    if (!head) {
        throw "The linked list is empty!";
    }

    Node* curNode = head;
    for (int i = 0; i < index - 1; ++i) {
        if (!curNode->next->next) {
            throw "Index out of range!";
        }
        curNode = curNode->next;
    }

    Node* pNode = curNode->next->next;
    delete curNode->next;
    curNode->next = pNode;
}

template <typename T>
void LinkedList<T>::setValueAt(int index, const T& value) {
    if (!head) {
        throw "The linked list is empty!";
    }

    Node* curNode = head;
    for (int i = 0; i < index; ++i) {
        if (!curNode->next) {
            throw "Index out of range!";
        }
        curNode = curNode->next;
    }
    curNode->value = value;
}

template <typename T>
T& LinkedList<T>::getValueAt(int index) const {
    if (!head) {
        throw "The linked list is empty!";
    }

    Node* curNode = head;
    for (int i = 0; i < index; ++i) {
        if (!curNode->next) {
            throw "Index out of range!";
        }
        curNode = curNode->next;
    }

    return curNode->value;
}

template <typename T>
int LinkedList<T>::size() {
    if (!head) {
        return 0;
    }

    int cnt = 1;
    Node* curNode = head;
    while (true) {
        if (!curNode->next) {
            return cnt;
        }
        curNode = curNode->next;
        ++cnt;
    }
}

template <typename T>
bool LinkedList<T>::isEmpty() {
    return !head;
}

template <typename T>
void LinkedList<T>::print() {
    if (!head) {
        std::cout << "< EMPTY >" << std::endl;
        return;
    }

    std::cout << "Linked List: < ";
    Node* curNode = head;
    while (true) {
        if (!curNode) {
            break;
        }
        std::cout << curNode->value;
        curNode = curNode->next;
        std::cout << ", ";
    }
    std::cout << "\b\b >" << std::endl;
}