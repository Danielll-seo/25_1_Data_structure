#include <stdio.h>

// �� ��ȯ �Լ�
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// heapify �Լ�: i��° ��带 ��Ʈ�� �ϴ� ����Ʈ���� �ּ� ������ ����
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
        heapify(arr, n, smaller);  // ��������� �ڽĿ��� ����
    }
}

// buildHeap �Լ�: �迭 ��ü�� �ּ� ������ ��ȯ
void buildHeap(int arr[], int n) {
    int last_parent_index = (n - 2) / 2;

    for (int i = last_parent_index; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

// �迭 ��� �Լ�
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// main �Լ�: �׽�Ʈ
int main() {
    int arr[] = { 7, 9, 4, 8, 6, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("�ʱ� �迭: ");
    printArray(arr, n);

    buildHeap(arr, n);

    printf("�ּ� ������ ������ �迭: ");
    printArray(arr, n);

    return 0;
}