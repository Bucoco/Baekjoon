#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int map[9][9] = {};
int cnt = 0;
bool fin = false;
vector<pair<int, int>> v;

void sol(int c) {
	if (fin)
		return;
	if (c == cnt) {
		for (int i = 0;i < 9;i++) {
			for (int j = 0;j < 9;j++)
				cout << map[i][j] << ' ';
			cout << '\n';
		}
		fin = true;
		return;
	}
	bool num[10] = {};
	int x = v[c].second;
	int y = v[c].first;
	int mx = x / 3 * 3;
	int my = y / 3 * 3;

	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			num[map[my + i][mx + j]] = true;
		}
	}

	for (int i = 0;i < 9;i++) {
		num[map[y][i]] = true;
		num[map[i][x]] = true;
	}

	for (int i = 1;i <= 9;i++) {
		if (!num[i]) {
			map[y][x] = i;
			sol(c + 1);
			map[y][x] = 0;
		}
	}
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	for (int i = 0;i < 9;i++) {
		for (int j = 0;j < 9;j++) {
			cin >> map[i][j];
			if (!map[i][j]) {
				cnt++;
				v.push_back({ i,j });
			}
		}
	}

	sol(0);
	
	return 0;
}