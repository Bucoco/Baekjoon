#include <iostream>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, m, val, max = 0, sum = 0;
	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		cin >> val;
		if (val > sum)
			sum = val;
	}
	for (int i = 0;i < m;i++) {
		cin >> val;
		if (val > max)
			max = val;
	}

	cout << max + sum;
	return 0;
}