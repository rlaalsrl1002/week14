#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // 현재 요소를 정렬된 부분 배열의 올바른 위치에 삽입
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;

#ifdef DEBUG
        // DEBUG가 정의된 경우 현재 배열 상태를 출력
        std::cout << "[";
        for (int k = 0; k < n; k++) {
            if (k > 0) std::cout << " ";
            std::cout << arr[k];
        }
        std::cout << "]" << std::endl;
#endif
    }
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    // 입력된 배열을 출력
    std::cout << "[";
    for (int i = 0; i < n; i++) {
        if (i > 0) std::cout << " ";
        std::cout << arr[i];
    }
    std::cout << "]" << std::endl;

    insertionSort(arr);

#ifndef DEBUG
    // DEBUG가 정의되지 않은 경우 최종 정렬된 배열을 출력
    std::cout << "[";
    for (int i = 0; i < n; i++) {
        if (i > 0) std::cout << " ";
        std::cout << arr[i];
    }
    std::cout << "]" << std::endl;
#endif

    return 0;
}
