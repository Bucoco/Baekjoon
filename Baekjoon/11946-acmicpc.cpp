#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct team
{
	int num = 0, sol = 0, score = 0;
};

bool cmp(team &a, team &b) {
	if (a.sol == b.sol) {
		if (a.score == b.score) {
			return a.num < b.num;
		}
		return a.score < b.score;
	}
	return a.sol > b.sol;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, m, q;
	cin >> n >> m >> q;
	int a, b, c;
	string str;
	bool check[101][16] = {};
	int penalty[101][16] = {};
	while (q--) {
		cin >> a >> b >> c >> str;
		if (check[b][c])
			continue;
		if (str == "AC") {
			penalty[b][c] *= 20;
			penalty[b][c] += a;
			check[b][c] = true;
		}
		else {
			penalty[b][c]++;
		}
	}
	vector<team> v;
	for (int i = 1;i <= n;i++) {
		team tmp;
		tmp.num = i;
		for (int j = 1;j <= m;j++) {
			if (check[i][j]) {
				tmp.sol++;
				tmp.score += penalty[i][j];
			}
		}
		v.push_back(tmp);
	}

	sort(v.begin(), v.end(), cmp);
	for (auto &i : v)
		cout << i.num << ' ' << i.sol << ' ' << i.score << '\n';

	return 0;
}