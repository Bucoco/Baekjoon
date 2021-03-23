#include <iostream>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, a;
	int cnt[10005] = {};

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a;
		cnt[a]++;
	}

	for (int i = 1; i <= 10000;i++) {
		for (int j = 0; j < cnt[i]; j++)
			cout << i << '\n';
	}

	return 0;
}