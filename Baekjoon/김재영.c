#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum { false, true } bool;

typedef struct _Node {
	int octal;
	struct _Node* next;
} Node;

typedef struct {
	Node* head;
	int len;
} LinkedList;

void InitList(LinkedList* plist);
int IsEmpty(LinkedList* plist);
void Insert(LinkedList* plist, int data);
void MergeTwoList(LinkedList* plist_a, LinkedList* plist_b, LinkedList* plist_c);
void PrintList(LinkedList* plist);
void PrintListHex(LinkedList* plist);

int main() {
	int i, j;
	int cnt;
	int input;
	LinkedList list_a, list_b, list_c;

	InitList(&list_a);
	InitList(&list_b);
	InitList(&list_c);

	for (i = 0; i<2; i++)
	{
		scanf("%d", &cnt);
		for (j = 0; j<cnt; j++)
		{
			scanf("%d", &input);
			if (i == 0)
				Insert(&list_a, input);
			else
				Insert(&list_b, input);
		}
	}

	MergeTwoList(&list_a, &list_b, &list_c);

	PrintList(&list_a);
	printf("\n");
	PrintList(&list_b);
	printf("\n");
	PrintList(&list_c);
	printf("\n");

	PrintListHex(&list_c);

	return 0;
}

void InitList(LinkedList* plist) {
	plist->head = (Node *)malloc(sizeof(Node));
	plist->head->next = NULL;
	plist->len = 0;
}

bool IsEmpty(LinkedList* plist) {
	return plist->len == 0;
}

void Insert(LinkedList* plist, int data) {
	Node* newnode = (Node *)malloc(sizeof(Node)); //�� ���
	newnode->octal = data; //����� �����Ͱ�
	newnode->next = plist->head; //��带 ��忡 ����
	plist->head = newnode; //��� ������Ʈ
	plist->len += 1; //��ũ�帮��Ʈ ���� ����
	int n = plist->len;
	Node* cur = plist->head;
	while (cur->next != NULL) {      //bubble sort
		if (cur->octal > cur->next->octal) {
			int tmp = cur->octal;
			cur->octal = cur->next->octal;
			cur->next->octal = tmp;
		}
		else
			break;
		cur = cur->next;
	}

}

void MergeTwoList(LinkedList* plist_a, LinkedList* plist_b, LinkedList* plist_c) {
	int n = plist_a;
	Node* cur = plist_a->head->next;
	while (cur != NULL) {      //list a�� c�� ����
		Insert(plist_c, cur->octal);
		cur = cur->next;
	}
	cur = plist_b->head->next;
	while (cur != NULL) {      //list b�� c������
		Insert(plist_c, cur->octal);
		cur = cur->next;
	}
	cur = plist_c->head;
	while (cur->next != NULL) {      //bubble sort
		if (cur->octal > cur->next->octal) {
			int tmp = cur->octal;
			cur->octal = cur->next->octal;
			cur->next->octal = tmp;
		}
		else
			break;
		cur = cur->next;
	}


}

void PrintList(LinkedList* plist) {
	for (Node* cur = plist->head->next; cur != NULL; cur = cur->next) printf("%d ", cur->octal);
}

void PrintListHex(LinkedList* plist) {
	for (Node* cur = plist->head->next; cur != NULL; cur = cur->next) {
		int oct[3] = {0};
		int n = cur->octal;
		int index = 0;
		while (n) {
			oct[index++] = n % 10;
			n /= 10;
		}
		for (int i = 0;i < index;i++) {
			for (int j = 0;j < i;j++)
				oct[i] *= 8;
			n += oct[i];
		}

		printf("%X ", n);
	}
}