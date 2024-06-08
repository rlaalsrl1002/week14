#include "queueIntList.h"
#include <iostream>
using namespace std;

int main() {
    MyQueueIntList myQueue;
    int choice, value;

    while (true) {
        cout << "1.enqueue 2.dequeue 3.showfront 4.showrear 5.displayQueue 6.exit > ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a Value: ";
                cin >> value;
                myQueue.enqueue(value);
                break;
            case 2:
                cout << myQueue.dequeue() << endl;
                break;
            case 3:
                if (!myQueue.isEmpty()) {
                    cout << "Element at front: " << myQueue.dequeue() << endl;
                } else {
                    cout << "Queue is empty" << endl;
                }
                break;
            case 4:
                myQueue.showrear();
                break;
            case 5:
                myQueue.display();
                break;
            case 6:
                cout << "bye!" << endl;
                return 0;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    }
}
