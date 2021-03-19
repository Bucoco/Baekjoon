#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	int dp[10005] = {};
	cin >> n;
	vector<int> v(n + 1);
	for (int i = 1;i <= n;i++) {
		cin >> v[i];
	}

	dp[1] = v[1];
	if (n > 1)
		dp[2] = v[1] + v[2];
	for (int i = 3;i <= n;i++) {
		dp[i] = max({ (dp[i - 3] + v[i - 1] + v[i]), (dp[i - 2] + v[i]), (dp[i - 1]) });
	}

	cout << dp[n];
	return 0;
}