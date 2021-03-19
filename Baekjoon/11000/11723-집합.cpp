#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int m, x, s = 0;
	string oper;

	cin >> m;
	while (m--) {
		cin >> oper;
		if (oper == "add") {
			cin >> x;
			s |= (1 << x);
		}
		else if (oper == "remove") {
			cin >> x;
			s &= ~(1 << x);
		}
		else if (oper == "check") {
			cin >> x;
			if (s & (1 << x)) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
		}
		else if (oper == "toggle") {
			cin >> x;
			if (s & (1 << x)) {
				s &= ~(1 << x);
			}
			else {
				s |= (1 << x);
			}
		}
		else if (oper == "all") {
			s = (1 << 21) - 2;
		}
		else {
			s = 0;
		}

	}

	return 0;
}