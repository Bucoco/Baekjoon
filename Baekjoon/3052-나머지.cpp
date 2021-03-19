#include <iostream>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	bool check[42] = {};
	int a, cnt = 0;

	for (int i = 0;i < 10;i++) {
		cin >> a;
		if (!check[a % 42]) {
			cnt++;
			check[a % 42] = true;
		}
	}

	cout << cnt;

	return 0;
}