#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	int dp[1001] = {};
	int n;
	cin >> n;

	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3;i <= n;i++)
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
	cout << dp[n];
	return 0;
}

void Insert(LinkedList* plist, int data) {
	Node* newnode = (Node *)malloc(sizeof(Node)); //�� ���
	newnode->octal = data; //����� �����Ͱ�
	newnode->next = plist->head; //��带 ��忡 ����
	plist->head = newnode; //��� ������Ʈ
	plist->len += 1; //��ũ�帮��Ʈ ���� ����
	int n = plist->len;
	Node* cur = plist->head;
	while (cur->next != NULL) {		//bubble sort
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

