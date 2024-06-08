#ifndef QUEUESTRING_H
#define QUEUESTRING_H

#include <string>
#include <utility>
using namespace std;

class MyCircularStringQueue {
private:
    pair<float, string> *list;
    int maxsize;
    int front;
    int rear;

public:
    MyCircularStringQueue(int size = 10);
    ~MyCircularStringQueue();
    void initialize();
    bool isEmpty() const;
    bool isFull() const;
    void enqueue(const pair<float, string>& elem);
    void dequeue();
    pair<float, string> Front() const;
    pair<float, string> Rear() const;
    void print() const;
    int size() const; // 현재 큐에 들어있는 element의 개수를 알려주는 함수
    void printDetail() const; // 큐의 상태를 상세히 출력하는 함수
};

#endif // QUEUESTRING_H
