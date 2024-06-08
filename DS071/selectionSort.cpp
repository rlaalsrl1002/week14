#include <iostream>
using namespace std;

void print(int *arr, int n){
    for(int i = 0; i < n ; i++)
        cout << "[" << arr[i] << "] ";
    cout << endl;
}

void selectionSort(int *arr, int n){
    int min_i = 0;

    for(int i = 0; i < n-1; i++){
        min_i = i;
        for(int j = i+1; j < n; j++){
            if(arr[min_i] > arr[j]) min_i = j;
        }
        if(i != min_i) swap(arr[i], arr[min_i]);
        print(arr, n);  // 배열의 상태를 출력
    }
}

int main(){
    int arr[] = { 64, 25, 12, 22, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);  // 배열의 크기를 계산합니다.

    print(arr, n);  // 정렬 전 배열을 출력합니다.
    selectionSort(arr, n);  // 선택 정렬을 수행합니다.
    cout << "====" <<endl;
    print(arr, n);  // 정렬 후 배열을 출력합니다.

    return 0;
}
