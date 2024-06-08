#include <iostream>
using namespace std;

void print(int *arr, int n){
    for(int i = 0; i < n ; i++)
        cout << "[" << arr[i] << "] ";
    cout << endl;
}

void bubbleSortAscending(int *arr, int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
        }
#ifdef DEBUG
        print(arr, n);  // 각 단계에서 배열의 상태를 출력
#endif
    }
#ifndef DEBUG
    print(arr, n);  // 정렬 후 배열을 출력
#endif
}

void bubbleSortDescending(int *arr, int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(arr[j] < arr[j+1])
                swap(arr[j], arr[j+1]);
        }
#ifdef DEBUG
        print(arr, n);  // 각 단계에서 배열의 상태를 출력
#endif
    }
#ifndef DEBUG
    print(arr, n);  // 정렬 후 배열을 출력
#endif
}

int main(){
    int n;
    cout << "배열의 크기를 입력하세요: ";
    cin >> n;

    int *arr = new int[n];
    cout << "배열의 요소를 입력하세요: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\n입력된 배열: ";
    print(arr, n);  // 정렬 전 배열을 출력합니다.

    int *arrAsc = new int[n];
    int *arrDesc = new int[n];
    copy(arr, arr + n, arrAsc);
    copy(arr, arr + n, arrDesc);

    cout << "\n--- ascending order ---" << endl;
    print(arrAsc, n);  // 입력된 배열을 출력
    bubbleSortAscending(arrAsc, n);  // 오름차순 버블 정렬을 수행합니다.

    cout << "\n--- descending order ---" << endl;
    print(arrDesc, n);  // 입력된 배열을 출력
    bubbleSortDescending(arrDesc, n);  // 내림차순 버블 정렬을 수행합니다.

    delete[] arr;
    delete[] arrAsc;
    delete[] arrDesc;

    return 0;
}
