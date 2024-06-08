#include "queueInt.h"
#include <iostream>
using namespace std;

MyCircularQueue::MyCircularQueue(int size) {
    maxsize = size + 1;
    list = new int[maxsize];
    initialize();
}

MyCircularQueue::~MyCircularQueue() {
    delete[] list;
}

void MyCircularQueue::initialize() {
    front = 0;
    rear = 0;
}

bool MyCircularQueue::isEmpty() const {
    return front == rear;
}

bool MyCircularQueue::isFull() const {
    return (rear + 1) % maxsize == front;
}

void MyCircularQueue::enqueue(const int& elem) {
    if (isFull()) {
        cout << "Queue is full!" << endl;
        return;
    }
    rear = (rear + 1) % maxsize;
    list[rear] = elem;
}

void MyCircularQueue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return;
    }
    front = (front + 1) % maxsize;
}

int MyCircularQueue::Front() const {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    return list[(front + 1) % maxsize];
}

int MyCircularQueue::Rear() const {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    return list[rear];
}

void MyCircularQueue::print() const {
    for (int i = (front + 1) % maxsize; i != (rear + 1) % maxsize; i = (i + 1) % maxsize) {
        cout << "[" << list[i] << "] ";
    }
    cout << endl;
}

int MyCircularQueue::size() const {
    if (rear >= front)
        return rear - front;
    else
        return maxsize - (front - rear);
}

void MyCircularQueue::printDetail() const {
    cout << "Size: " << size() << endl;
    cout << "Queue: ";
    print();
    cout << "index: ";
    for (int i = (front + 1) % maxsize, idx = 1; i != (rear + 1) % maxsize; i = (i + 1) % maxsize, idx++) {
        cout << idx << " ";
    }
    cout << endl;
    cout << "front: " << front << ", rear: " << rear << endl;
}
