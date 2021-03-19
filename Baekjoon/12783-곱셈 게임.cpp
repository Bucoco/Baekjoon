#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 20

vector<int> cards;
int dp[1000010] = {};

int Find(int cur) {
	if (dp[cur] != MAX)
		return dp[cur];
	for (auto &i : cards) {
		if (cur%i == 0) {
			dp[cur] = min(dp[cur], Find(cur / i) + 1);
		}

	}
	return dp[cur];
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int t, n, m, k;
	cin >> t;
	while (t--) {
		cin >> n;
		cards.resize(n);
		
		for (auto &i : dp)
			i = MAX;

		for (auto &i:cards) {
			cin >> i;
			dp[i] = 0;
		}

		cin >> m;
		for (int i = 0;i < m;i++) {
			cin >> k;
			cout << Find(k) << '\n';
		}

		cards.clear();
	}


	return 0;
}