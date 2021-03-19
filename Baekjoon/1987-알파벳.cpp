#include <iostream>
using namespace std;

int r, c, res = 1;
int dx[] = { 1,-1,0,0 }, dy[] = { 0,0,1,-1 };

bool visit[26] = {};
char map[23][23] = {};

void sol(int lv,int x,int y) {
	visit[map[y][x] - 'A'] = true;
	res = res > lv ? res : lv;
	for (int i = 0;i < 4;i++) {
		int mx = x + dx[i], my = y + dy[i];
		if (mx >=0 && mx < c && my>=0 && my < r && !visit[map[my][mx] - 'A']) {
			sol(lv + 1, mx, my);
		}
	}

	visit[map[y][x] - 'A'] = false;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> r >> c;

	for (int i = 0;i < r;i++)
		for (int j = 0;j < c;j++)
			cin >> map[i][j];

	sol(1, 0, 0);

	cout << res;
	return 0;
}