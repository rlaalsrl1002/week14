#include "queueIntList.h"
#include <iostream>
using namespace std;

// 순서를 문자열로 변환하는 함수
string ordinal(int num) {
    if (num % 10 == 1 && num % 100 != 11) return to_string(num) + "st";
    if (num % 10 == 2 && num % 100 != 12) return to_string(num) + "nd";
    if (num % 10 == 3 && num % 100 != 13) return to_string(num) + "rd";
    return to_string(num) + "th";
}



int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    MyQueueIntList fibQueue;
    fibQueue.enqueue(1);
    cout << ordinal(1) << ": " << 1 << endl;  // 첫 번째 피보나치 수 출력
    if (n > 1) {
        fibQueue.enqueue(1);
        cout << ordinal(2) << ": " << 1 << endl;  // 두 번째 피보나치 수 출력
    }

    // 피보나치 수 계산
    int result = 1; // 최종 결과를 저장할 변수
    for (int i = 3; i <= n; ++i) {
        int a = fibQueue.dequeue();
        int b = fibQueue.dequeue();
        int nextFib = a + b;
        fibQueue.enqueue(b);
        fibQueue.enqueue(nextFib);
        result = nextFib; // 결과를 업데이트
        cout << ordinal(i) << ": " << nextFib << endl;  // 각 단계의 피보나치 수 출력
    }

    cout << "=> fibonacci(" << n << ") : " << result << endl;

    return 0;
}
