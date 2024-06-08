#include "queueIntList.h"
#include <iostream>
using namespace std;

MyQueueIntList::MyQueueIntList() { 
    front = rear = nullptr; 
    size = 0;
}

MyQueueIntList::~MyQueueIntList() {
    Node* p = front;
    while (front) {
        front = front->next;
        delete p;
        p = front;
    }
}

void MyQueueIntList::enqueue(int x) {
    Node* p = new Node;
    p->data = x;
    p->next = nullptr;
    if (isFull()) { 
        cout << "Queue is Overflow!" << endl; 
    }
    if (isEmpty()) {
        front = p;
    } else {
        rear->next = p;
    }
    rear = p;
    size++;
}

int MyQueueIntList::dequeue() { 
    Node* p;
    int x = -1; // 초기값 설정
    if (isEmpty()) { 
        cout << "Queue is Empty!" << endl;
    } else {
        p = front;
        front = p->next;
        x = p->data;
        delete p;
        size--;
    }
    return x; // 삭제된 값을 반환
}

int MyQueueIntList::isFull() { 
    Node* p = new Node;
    int r = p ? 0 : 1;
    delete p;
    return r;
}

int MyQueueIntList::isEmpty() {
    return front == nullptr ? 1 : 0;
}

void MyQueueIntList::display() { 
    Node* p = front;
    cout << "Queue ("<< size << ") : ";
    while(p) {
        cout << p->data << " | ";
        p = p->next;
    }
    cout << endl;
}

void MyQueueIntList::showrear() {
    if (rear != nullptr) {
        cout << "Element at rear: " << rear->data << endl;
    } else {
        cout << "Queue is empty" << endl;
    }
}
