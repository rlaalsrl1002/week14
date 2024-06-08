#include <iostream>
using namespace std;

void print(int *arr, int n) {
    for (int i = 0; i < n; i++)
        cout << "[" << arr[i] << "] ";
    cout << endl;
}

int partition(int *arr, int low, int high) {
    int pivot = arr[high]; // 마지막 요소를 피벗으로 선택
    int i = (low - 1); // 작은 요소의 인덱스

    for (int j = low; j <= high - 1; j++) {
        // 현재 요소가 피벗보다 작거나 같은 경우
        if (arr[j] <= pivot) {
            i++; // 작은 요소의 인덱스 증가
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int *arr, int low, int high, int n) {
    if (low < high) {
        // 파티션 인덱스, arr[pi]는 올바른 위치에 있음
        int pi = partition(arr, low, high);

#ifdef DEBUG
        print(arr, n);  // 각 단계에서 배열의 상태를 출력
#endif

        // 각각의 파티션을 정렬
        quickSort(arr, low, pi - 1, n);
        quickSort(arr, pi + 1, high, n);
    }
}

int main() {
    int n;
    cout << "배열의 크기를 입력하세요: ";
    cin >> n;

    int *arr = new int[n];
    cout << "배열의 요소를 입력하세요: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\n입력된 배열: ";
    print(arr, n);  // 정렬 전 배열을 출력합니다.

    quickSort(arr, 0, n - 1, n);

#ifndef DEBUG
    cout << "\n정렬된 배열: ";
    print(arr, n);  // 정렬 후 배열을 출력합니다.
#endif

    delete[] arr;

    return 0;
}
