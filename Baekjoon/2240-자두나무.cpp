#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int t, w;
	int dp[1010][32] = {};
	vector<int> v;

	cin >> t >> w;
	v.resize(t + 1);
	for (int i = 1;i <= t;i++) {
		cin >> v[i];
	}

	for (int i = 1;i <= t;i++) {
		dp[i][0] = dp[i - 1][0];
		if (v[i] % 2)
			dp[i][0]++;
		for (int j = 1;j <= w;j++) {
			dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]);
			if (v[i] % 2 != j % 2) {
				dp[i][j]++;
			}
		}
	}
	int res = dp[t][0];
	for (int i : dp[t]) {
		res = res > i ? res : i;
	}
	
	cout << res;

	return 0;
}