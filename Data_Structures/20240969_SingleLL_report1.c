#include <stdio.h>
#include <stdlib.h>

// ��� ����ü ����
typedef struct Node {
	int data;			// ������ �ʵ�
	struct Node* next;	// ���� ����� ������
} Node;

// �������� ��� �߰� �Լ�
Node* insertLast(Node* head, int data) {
	// ���ο� ��� ����
	Node* newNode = (Node*)malloc(sizeof(Node));

}

// ù ��° ��� ���� �Լ�
Node* insertFirst(Node* head, int data) {
	// ���ο� ��� ����
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL; // ���ο� ���� �ʱ⿡�� �ƹ��͵� ����Ű�� ����

	// Head�� NULL�� ���(����Ʈ�� ��� ����)
	if (head == NULL) {
		return newNode; // ����尡 ����Ʈ�� ������
	}

	// Head�� NULL�� �ƴ� ��� (����Ʈ�� ���� ��尡 ����)
	newNode->next = head; // �� ����� ������ ���� Head�� ����
	return newNode;		  // �� ��带 Head�� ����
}

// ������ ��� �߰� �Լ�
Node* insertLast(Node* head, int data) {
	// ���ο� ��� ����
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL; // �� ���� ����Ʈ�� ���� ��Ÿ��

	// ����Ʈ�� ��� �ִ� ���
	if (head == NULL) {
		return newNode; // �� ��尡 ����Ʈ�� �������� ��
	}

	// ����Ʈ�� ���� ��尡 �ִ� ���
	Node* current = head;
	while (current->next != NULL) {	// ������ ��带 ã��
		current = current->next;
	}
	current->next = newNode; // ������ ����� next�� �� ��带 ����

	return head; // ����Ʈ�� ������(head) ��ȯ
}

// ����Ʈ�� Ư�� ��ġ�� ����
void insertAfterValue(Node* head, int targetValue, int newData) {
	Node* current = head;

	// ��� Ž��
	while (current != NULL) {
		if (current->data == targetValue) {
			// �� ��� ���� �� ����
		}
	}
}

int main() {
	// ���� ����Ʈ �ʱ�ȭ(head�� NULL�� �ʱ�ȭ �Ѵ�.)
	Node* head = NULL;


	// ��� ����
	head = insertFirst(head, 10); // ù ��° ��� ����
	head = insertFirst(head, 20); // �� ��° ��� ����
	head = insertFirst(head, 30); // �� ��° ��� ����

	// ����Ʈ ���
	Node* current = head;
	while (current != NULL) {
		printf("%d -> ", current->data);
		current = current->next;
	}
	printf("NULL\n");

	// �ʱ���� ���
	/*
	if (head == NULL) {
		printf("����Ʈ�� �ʱ�ȭ �Ǿ����ϴ�. ���� ����Ʈ�� ����ֽ��ϴ�.\n");
	}
	*/

	return 0;
}