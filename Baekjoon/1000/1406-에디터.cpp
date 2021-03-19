#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	stack<char> left;
	stack<char> right;
	int n;
	string str;
	char c, operation;
	
	cin >> str >> n;
	for (auto i : str) {
		left.push(i);
	}
	while (n--) {
		cin >> operation;
		switch (operation) {
		case 'L':
			if (!left.empty()) {
				right.push(left.top());
				left.pop();
			}
			break;
		case 'D':
			if (!right.empty()) {
				left.push(right.top());
				right.pop();
			}
			break;
		case 'B': 
			if (!left.empty()) {
				left.pop();
			}
			break;
		default:
			cin >> c;
			left.push(c);
			break;
		}
	}
	while (!left.empty()) {
		right.push(left.top());
		left.pop();
	}
	while (!right.empty()) {
		cout << right.top();
		right.pop();
	}
	return 0;
}