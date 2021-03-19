#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	set<string> s;
	string name, op;

	cin >> n;
	while (n--) {
		cin >> name >> op;
		if (op == "enter") {
			s.insert(name);
		}
		else {
			s.erase(name);
		}
	}
	for (auto i = s.rbegin();i != s.rend();i++) {
		cout << *i << '\n';
	}
	

	return 0;
}