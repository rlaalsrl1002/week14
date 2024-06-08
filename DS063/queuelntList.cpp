#include "queueIntList.h"
#include <iostream>

Queue::Queue() : front(nullptr), rear(nullptr) {}

Queue::~Queue() {
    while (front != nullptr) {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
}

void Queue::enqueue(int val) {
    Node* newNode = new Node(val);
    if (rear == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void Queue::dequeue() {
    if (front == nullptr) {
        std::cout << "Queue is empty" << std::endl;
        return;
    }
    Node* temp = front;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    }
    delete temp;
}

int Queue::showFront() {
    if (front != nullptr) {
        return front->data;
    } else {
        std::cout << "Queue is empty" << std::endl;
        return -1; // 또는 다른 에러 코드
    }
}

int Queue::showRear() {
    if (rear != nullptr) {
        return rear->data;
    } else {
        std::cout << "Queue is empty" << std::endl;
        return -1; // 또는 다른 에러 코드
    }
}

void Queue::displayQueue() {
    Node* temp = front;
    while (temp != nullptr) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL" << std::endl;
}
