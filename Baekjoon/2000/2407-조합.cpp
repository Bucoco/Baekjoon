#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string comb[105][105];

string Bigint(string a, string b) {
	int sum = 0;
	string res;
	while (!a.empty() || !b.empty() || sum) {
		if (!a.empty()) {
			sum += a.back() - '0';
			a.pop_back();
		}
		if (!b.empty()) {
			sum += b.back() - '0';
			b.pop_back();
		}
		res.push_back((sum % 10) + '0');
		sum /= 10;
	}
	reverse(res.begin(), res.end());
	return res;
}

void cal(int n, int m) {
	for (int i = 0; i <= n; i++) {
		comb[i][0] = "1";
		comb[i][i] = "1";
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			comb[i][j] = Bigint(comb[i - 1][j - 1], comb[i - 1][j]);
		}
	}
	cout << comb[n][m];
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	cal(n, m);

	return 0;
}