#include "queueInt.h"
#include <iostream>
using namespace std;

MyCircularStringQueue::MyCircularStringQueue(int size) {
    maxsize = size + 1;
    list = new pair<float, string>[maxsize];
    initialize();
}

MyCircularStringQueue::~MyCircularStringQueue() {
    delete[] list;
}

void MyCircularStringQueue::initialize() {
    front = 0;
    rear = 0;
}

bool MyCircularStringQueue::isEmpty() const {
    return front == rear;
}

bool MyCircularStringQueue::isFull() const {
    return (rear + 1) % maxsize == front;
}

void MyCircularStringQueue::enqueue(const pair<float, string>& elem) {
    if (isFull()) {
        cout << "Queue is full!" << endl;
        return;
    }
    rear = (rear + 1) % maxsize;
    list[rear] = elem;
}

void MyCircularStringQueue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return;
    }
    front = (front + 1) % maxsize;
}

pair<float, string> MyCircularStringQueue::Front() const {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return make_pair(-1.0f, "");
    }
    return list[(front + 1) % maxsize];
}

pair<float, string> MyCircularStringQueue::Rear() const {
    if (isEmpty()) {
        cout << "Queue is empty!" << endl;
        return make_pair(-1.0f, "");
    }
    return list[rear];
}

void MyCircularStringQueue::print() const {
    for (int i = (front + 1) % maxsize; i != (rear + 1) % maxsize; i = (i + 1) % maxsize) {
        cout << "[" << list[i].first << " " << list[i].second << "] ";
    }
    cout << endl;
}

int MyCircularStringQueue::size() const {
    if (rear >= front)
        return rear - front;
    else
        return maxsize - (front - rear);
}

void MyCircularStringQueue::printDetail() const {
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
