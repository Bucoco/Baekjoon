#include <iostream>
#include <algorithm>
using namespace std;

#define M 10001

int main() {
	int n, k;
	int coin[100] = {};
	int dp[10001] = {};
	cin >> n >> k;
	for (int i = 0;i < n;i++)
		cin >> coin[i];
	for (int& i : dp)
		i = M;
	dp[0] = 0;
	for (int i = 0;i < n;i++) {
		for (int j = coin[i];j <= k;j++)
			dp[j] = min(dp[j - coin[i]] + 1, dp[j]);
	}

	if (dp[k] == M)
		cout << "-1";
	else
		cout << dp[k];
	return 0;
}