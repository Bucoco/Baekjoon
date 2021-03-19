#include <iostream>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int t, a, b;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		int tmp = 1;
		while (b) {
			tmp *= a;
			tmp %= 10;
		}

		if (tmp)
			cout << tmp << "\n";
		else
			cout << 10 << "\n";
	}

	return 0;
}