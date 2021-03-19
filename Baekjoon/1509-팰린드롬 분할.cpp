#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool dp[2510][2510] = {};
bool visit[2510][2510] = {};
int cnt[2510] = {};
string str;

bool sol(int s, int e) {
	if (s > e)
		return true;
	if (visit[s][e])
		return dp[s][e];
	dp[s][e] = (str[s] == str[e]) && sol(s + 1, e - 1);
	visit[s][e] = true;
	return dp[s][e];
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> str;

	for (auto &i : cnt)
		i = 3000;

	for (int i = 0;i < str.size();i++) {
		if (sol(0, i)) {
			cnt[i] = 1;
			continue;
		}
		for (int j = 1;j <= i;j++) {
			if (sol(j, i)) {
				cnt[i] = min(cnt[i], cnt[j - 1] + 1);
			}
		}
	}

	cout << cnt[str.size() - 1];

	return 0;
}