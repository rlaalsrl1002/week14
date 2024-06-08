#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class MyQueueIntList {
private:
    Node* front;  // 삭제를 위한 front
    Node* rear;   // 삽입을 위한 rear
    int size;     // 큐의 크기
public:
    MyQueueIntList();    // 큐를 초기화하는 생성자
    ~MyQueueIntList();   // 큐를 메모리에서 제거하는 소멸자
    void enqueue(int x); // 큐의 뒤쪽(rear)에 요소를 추가하는 메서드
    int dequeue();       // 큐의 앞쪽(front)에서 요소를 제거하는 메서드
    int isFull();        // 큐가 가득 찼는지 확인하는 메서드
    int isEmpty();       // 큐가 비어있는지 확인하는 메서드
    void display();      // 큐의 현재 상태를 출력하는 메서드
    void showrear();     // 큐의 마지막 요소를 출력하는 메서드
};
