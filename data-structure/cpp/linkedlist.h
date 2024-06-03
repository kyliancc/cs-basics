//
// Created by kylianc on 6/3/24.
//

#ifndef CPP_LINKEDLIST_H
#define CPP_LINKEDLIST_H


// 链表实现
template <typename T>
class LinkedList {
public:
    LinkedList();
    ~LinkedList();

    // 插入
    void insertFront(const T& value);
    void insertBack(const T& value);
    void insertAt(int index, const T& value);

    // 删除
    void removeFront();
    void removeBack();
    void removeAt(int index);

    // 更改和查询
    void setValueAt(int index, const T& value);
    T& getValueAt(int index) const;

    // 属性
    int size();
    bool isEmpty();

    // 打印
    void print();

private:
    // 链表节点
    class Node {
    public:
        Node* next;
        T value;
        explicit Node(const T& value): next(nullptr), value(value) {}
    };

    Node* head;
};


#endif //CPP_LINKEDLIST_H
