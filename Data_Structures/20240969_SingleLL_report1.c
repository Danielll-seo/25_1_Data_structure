#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 노드 구조체 정의
typedef struct Node {
	int data;			// 데이터 필드
	struct Node* next;	// 다음 노드의 포인터
} Node;

// 첫 번째 노드 삽입 함수
Node* insertFirst(Node* head, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;

	if (head == NULL) {
		return newNode;
	}
	newNode->next = head;
	return newNode;
}

// 마지막 노드 삽입 함수
Node* insertLast(Node* head, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;

	if (head == NULL) {
		return newNode;
	}

	Node* current = head;
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = newNode;

	return head;
}

// 특정 값을 가진 노드 뒤에 삽입
void insertAfterValue(Node* head, int targetValue, int newData) {
	Node* current = head;

	while (current != NULL) {
		if (current->data == targetValue) {
			Node* newNode = (Node*)malloc(sizeof(Node));
			newNode->data = newData;
			newNode->next = current->next;
			current->next = newNode;
			return;
		}
		current = current->next;
	}

	printf("값 %d를 가진 노드를 찾을 수 없습니다. 삽입하지 않습니다.\n", targetValue);
}

// 마지막 노드 삭제 함수
Node* deleteLast(Node* head) {
	if (head == NULL) {
		printf("리스트가 비어 있습니다. 삭제할 노드가 없습니다.\n");
		return NULL;
	}

	if (head->next == NULL) {
		free(head);
		return NULL;
	}

	Node* current = head;
	while (current->next->next != NULL) {
		current = current->next;
	}

	free(current->next);
	current->next = NULL;

	return head;
}

// 헤드 노드 삭제 함수
Node* deleteHead(Node* head) {
	if (head == NULL) {
		printf("리스트가 비어 있습니다. 삭제할 노드가 없습니다.\n");
		return NULL;
	}

	Node* temp = head;
	head = head->next;
	free(temp);

	return head;
}

// 특정 값의 노드 삭제 함수
Node* deleteNode(Node* head, int targetValue) {
	if (head == NULL) {
		printf("리스트가 비어 있습니다. 삭제할 노드가 없습니다.\n");
		return NULL;
	}

	if (head->data == targetValue) {
		Node* temp = head;
		head = head->next;
		free(temp);
		return head;
	}

	Node* current = head;
	while (current->next != NULL && current->next->data != targetValue) {
		current = current->next;
	}

	if (current->next == NULL) {
		printf("값 %d를 가진 노드를 찾을 수 없습니다.\n", targetValue);
		return head;
	}

	Node* temp = current->next;
	current->next = current->next->next;
	free(temp);

	return head;
}

// 리스트 출력 함수
void printList(Node* head) {
	Node* current = head;
	while (current != NULL) {
		printf("%d -> ", current->data);
		current = current->next;
	}
	printf("NULL\n");
}

// 메인 함수
int main() {
	Node* head = NULL;

	// 노드 삽입
	head = insertFirst(head, 30);
	head = insertFirst(head, 20);
	head = insertFirst(head, 10);
	head = insertLast(head, 70);
	head = insertLast(head, 80);
	head = insertLast(head, 90);
	insertAfterValue(head, 30, 40);
	insertAfterValue(head, 40, 50);
	insertAfterValue(head, 50, 60);

	// 리스트 출력
	printList(head);

	return 0;
}
