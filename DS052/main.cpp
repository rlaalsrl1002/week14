#include "queueInt.h"
#include <iostream>
#include <sstream>
using namespace std;

int main() {
    int queueSize;
    cout << "Queue의 크기를 입력하세요: ";
    cin >> queueSize;
    MyCircularQueue q(queueSize);

    cin.ignore(); // 버퍼를 비웁니다.

    string command;
    while (true) {
        getline(cin, command);
        if (command == "q") {
            break;
        }

        stringstream ss(command);
        string cmd;
        ss >> cmd;

        if (cmd == "en") {
            int value;
            ss >> value;
            q.enqueue(value);
        } else if (cmd == "de") {
            q.dequeue();
        } else if (cmd == "front") {
            cout << "=> " << q.Front() << endl;
        } else if (cmd == "rear") {
            cout << "=> " << q.Rear() << endl;
        } else if (cmd == "size") {
            cout << "=> " << q.size() << endl;
        } else if (cmd == "empty") {
            cout << "=> " << (q.isEmpty() ? "1" : "0") << endl;
        } else if (cmd == "print") {
            q.print();
        }
    }

    return 0;
}
