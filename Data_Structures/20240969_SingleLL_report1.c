#include <stdio.h>
#include <stdlib.h>

// 노드 구조체 정의
typedef struct Node {
	int data;			// 데이터 필드
	struct Node* next;	// 다음 노드의 포인터
} Node;

// 마지막에 노드 추가 함수
Node* insertLast(Node* head, int data) {
	// 새로운 노드 생성
	Node* newNode = (Node*)malloc(sizeof(Node));

}

// 첫 번째 노드 삽입 함수
Node* insertFirst(Node* head, int data) {
	// 새로운 노드 생성
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL; // 새로운 노드는 초기에는 아무것도 가리키지 않음

	// Head가 NULL인 경우(리스트가 비어 있음)
	if (head == NULL) {
		return newNode; // 새노드가 리스트의 시작점
	}

	// Head가 NULL이 아닌 경우 (리스트에 기존 노드가 있음)
	newNode->next = head; // 새 노드의 다음을 기존 Head로 연결
	return newNode;		  // 새 노드를 Head로 설정
}

// 마지막 노드 추가 함수
Node* insertLast(Node* head, int data) {
	// 새로운 노드 생성
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL; // 새 노드는 리스트의 끝을 나타냄

	// 리스트가 비어 있는 경우
	if (head == NULL) {
		return newNode; // 새 노드가 리스트의 시작점이 됨
	}

	// 리스트에 기존 노드가 있는 경우
	Node* current = head;
	while (current->next != NULL) {	// 마지막 노드를 찾음
		current = current->next;
	}
	current->next = newNode; // 마지막 노드의 next에 새 노드를 연결

	return head; // 리스트의 시작점(head) 반환
}

// 리스트의 특정 위치에 삽입
void insertAfterValue(Node* head, int targetValue, int newData) {
	Node* current = head;

	// 노드 탐색
	while (current != NULL) {
		if (current->data == targetValue) {
			// 새 노드 생성 및 삽입
		}
	}
}

int main() {
	// 연결 리스트 초기화(head를 NULL로 초기화 한다.)
	Node* head = NULL;


	// 노드 삽입
	head = insertFirst(head, 10); // 첫 번째 노드 삽입
	head = insertFirst(head, 20); // 두 번째 노드 삽입
	head = insertFirst(head, 30); // 세 번째 노드 삽입

	// 리스트 출력
	Node* current = head;
	while (current != NULL) {
		printf("%d -> ", current->data);
		current = current->next;
	}
	printf("NULL\n");

	// 초기상태 출력
	/*
	if (head == NULL) {
		printf("리스트가 초기화 되었습니다. 현재 리스트는 비어있습니다.\n");
	}
	*/

	return 0;
}