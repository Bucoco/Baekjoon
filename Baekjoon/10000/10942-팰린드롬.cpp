#include <iostream>
using namespace std;

bool dp[2010][2010] = {};
bool visit[2010][2010] = {};
int arr[2010] = {};

bool sol(int s, int e) {
	if (s > e)
		return true;
	if (visit[s][e])
		return dp[s][e];
	dp[s][e] = (arr[s] == arr[e]) && sol(s + 1, e - 1);
	visit[s][e] = true;
	return dp[s][e];
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, m, s, e;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> arr[i];
		dp[i][i] = true;
		visit[i][i] = true;
	}
	cin >> m;
	for (int i = 0;i < m;i++) {
		cin >> s >> e;
		cout << sol(s, e) << '\n';
	}

	return 0;
}