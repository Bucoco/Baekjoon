#include <iostream>
using namespace std;

int abs(int a) {
	if (a < 0)
		return -1 * a;
	return a;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	bool check[10] = {};
	int n, m, a, res;
	cin >> n >> m;
	for (int i = 0;i < m;i++) {
		cin >> a;
		check[a] = true;
	}
	if (!check[0])
		res = n + 1 < abs(n - 100) ? n + 1 : abs(n - 100);
	else
		res = abs(n - 100);
	for (int i = 1;i <= 1000000;i++) {
		int tmp = i, cnt = 0;
		while (tmp) {
			if (check[tmp % 10])
				break;
			tmp /= 10;
			cnt++;
		}
		if (tmp)
			continue;
		cnt += abs(n - i);
		res = cnt < res ? cnt : res;
	}

	cout << res;

	return 0;
}