#include "queueInt.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    ifstream file("gpa_2.txt");
    if (!file) {
        cerr << "Unable to open file data.txt";
        return 1;
    }

    MyCircularStringQueue q(20);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        float gpa;
        string name;
        ss >> gpa;
        ss >> name;
        q.enqueue(make_pair(gpa, name));
    }
    file.close();

    float highestGPA = -1.0;
    MyCircularStringQueue highestGPAQueue(20);

    while (!q.isEmpty()) {
        pair<float, string> student = q.Front();
        q.dequeue();
        if (student.first > highestGPA) {
            highestGPA = student.first;
            highestGPAQueue.initialize();
            highestGPAQueue.enqueue(student);
        } else if (student.first == highestGPA) {
            highestGPAQueue.enqueue(student);
        }
    }

    cout << "Highest GPA = " << highestGPA << endl;
    while (!highestGPAQueue.isEmpty()) {
        pair<float, string> student = highestGPAQueue.Front();
        highestGPAQueue.dequeue();
        cout << student.second << " " << student.first << endl;
    }

    return 0;
}
