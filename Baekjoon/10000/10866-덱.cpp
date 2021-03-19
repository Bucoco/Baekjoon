#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	string str;
	deque<int> deq;

	cin >> n;
	while (n--) {
		cin >> str;
		if (str == "push_front") {
			int x;
			cin >> x;
			deq.push_front(x);
		}
		else if (str == "push_back") {
			int x;
			cin >> x;
			deq.push_back(x);
		}
		else if (str == "pop_front") {
			if (deq.empty())
				cout << -1 << '\n';
			else {
				cout << deq.front() << '\n';
				deq.pop_front();
			}
		}
		else if (str == "pop_back") {
			if (deq.empty())
				cout << -1 << '\n';
			else {
				cout << deq.back() << '\n';
				deq.pop_back();
			}
		}
		else if (str == "size") {
			cout << deq.size() << '\n';
		}
		else if (str == "empty") {
			cout << deq.empty() << '\n';
		}
		else if (str == "front") {
			if (deq.empty())
				cout << -1 << '\n';
			else {
				cout << deq.front() << '\n';
			}
		}
		else {
			if (deq.empty())
				cout << -1 << '\n';
			else {
				cout << deq.back() << '\n';
			}
		}
	}

	return 0;
}