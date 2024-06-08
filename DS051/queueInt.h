#ifndef QUEUEINT_H
#define QUEUEINT_H

class MyCircularQueue {
private:
    int *list;
    int maxsize;
    int front;
    int rear;

public:
    MyCircularQueue(int size = 10);
    ~MyCircularQueue();
    void initialize();
    bool isEmpty() const;
    bool isFull() const;
    void enqueue(const int& elem);
    void dequeue();
    int Front() const;
    int Rear() const;
    void print() const;
    int size() const; // 현재 큐에 들어있는 element의 개수를 알려주는 함수
    void printDetail() const; // 큐의 상태를 상세히 출력하는 함수
};

#endif // QUEUEINT_H
