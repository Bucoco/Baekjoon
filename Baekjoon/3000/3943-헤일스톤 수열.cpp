#include <iostream>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		int max = n;
		while (n != 1) {
			if (n & 1) {
				n = n * 3 + 1;
			}
			else {
				n /= 2;
			}
			max = n > max ? n : max;
		}
		cout << max << '\n';
	}

	return 0;
}