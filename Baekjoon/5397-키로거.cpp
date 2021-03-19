#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	char c;
	Node* next;
	Node* prev;
	Node(char c) {
		this->c = c;
		prev = 0;
		next = 0;
	}
};

class List {
public:
	Node* head;
	Node* cur;
	List() {
		head = new Node(0);
		cur = head;
	}
	void Ins(char c) {
		Node* newNode = new Node(c);
		newNode->prev = cur;
		newNode->next = cur->next;
		if(newNode->next != NULL)
			newNode->next->prev = newNode;
		cur->next = newNode;
		cur = cur->next;
	}
	void Del() {
		if (cur == head)
			return;
		else {
			Node* tmp = cur;
			cur->prev->next = cur->next;
			if (cur->next != NULL)
				cur->next->prev = cur->prev;
			cur = cur->prev;
			delete tmp;
		}
	}
	void Left() {
		if (cur != head)
			cur = cur->prev;
	}
	void Right() {
		if (cur->next != NULL)
			cur = cur->next;
	}

	void Print() {
		cur = head->next;
		delete head;
		while (cur != NULL) {
			Node* tmp = cur;
			cur = cur->next;
			cout << tmp->c;
			delete tmp;
		}
		cout << '\n';
	}
};

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		string str;
		List res;
		cin >> str;
		
		for (auto &i : str) {
			switch (i)
			{
			case '<':
				res.Left();
				break;
			case '>':
				res.Right();
				break;

			case '-':
				res.Del();
				break;
			default:
				res.Ins(i);
				break;
			}
		}
		res.Print();
	}

	return 0;
}