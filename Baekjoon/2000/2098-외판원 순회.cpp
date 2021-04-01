#include <iostream>
#include <algorithm>
using namespace std;

#define INF 17000000

int n;
int weight[20][20]{};
int dp[70000][20]{};

int TSP(int visit, int cur) {

	if (visit == (1 << n) - 1) {
		if (!weight[cur][0])
			return INF;
		return weight[cur][0];
	}

	if (dp[visit][cur])
		return dp[visit][cur];

	dp[visit][cur] = INF;
	for (int i = 0; i < n; i++) {
		if (weight[cur][i] && !(visit & (1 << i))) {
			dp[visit][cur] = min(weight[cur][i] + TSP((visit | (1 << i)),i), dp[visit][cur]);
		}
	}
	return dp[visit][cur];
}


int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> weight[i][j];
		}
	}

	cout << TSP(1, 0);

	return 0;
}