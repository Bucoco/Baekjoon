#include <iostream>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, k, val, cnt = 0;
	cin >> n >> k;
	for (int i = 0;i < k;i++) {
		cin >> val;
		if (val % 2)
			cnt += val / 2 + 1;
		else
			cnt += val / 2;
	}

	if (cnt >= n)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}