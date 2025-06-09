#include <stdio.h>

// 값 교환 함수
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// heapify 함수: i번째 노드를 루트로 하는 서브트리를 최소 힙으로 유지
void heapify(int arr[], int n, int i) {
    int smaller = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    if (leftChild < n && arr[leftChild] < arr[smaller])
        smaller = leftChild;

    if (rightChild < n && arr[rightChild] < arr[smaller])
        smaller = rightChild;

    if (smaller != i) {
        swap(&arr[i], &arr[smaller]);
        heapify(arr, n, smaller);  // 재귀적으로 자식에게 적용
    }
}

// buildHeap 함수: 배열 전체를 최소 힙으로 변환
void buildHeap(int arr[], int n) {
    int last_parent_index = (n - 2) / 2;

    for (int i = last_parent_index; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

// 배열 출력 함수
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// main 함수: 테스트
int main() {
    int arr[] = { 7, 9, 4, 8, 6, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("초기 배열: ");
    printArray(arr, n);

    buildHeap(arr, n);

    printf("최소 힙으로 구성된 배열: ");
    printArray(arr, n);

    return 0;
}