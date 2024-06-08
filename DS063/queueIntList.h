#ifndef QUEUE_INT_LIST_H
#define QUEUE_INT_LIST_H

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;
public:
    Queue();
    ~Queue();
    void enqueue(int val);
    void dequeue();
    int showFront();
    int showRear();
    void displayQueue();
};

#endif // QUEUE_INT_LIST_H
