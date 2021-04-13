#include <iostream>
using namespace std;


int row[9], col[9], sq[9];
char map[10][10];
bool fin = false;

bool check(int a, int x, int y, int z) {
	return (row[y] & 1 << a) || (col[x] & 1 << a) || (sq[z] & 1 << a);
}

void dfs(int cur) {
	if (fin)
		return;
	if (cur == 81) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				cout << map[i][j];
			cout << '\n';
		}
		fin = true;
		return;
	}

	int y = cur / 9, x = cur % 9;
	int val = map[y][x] - '0';
	int z = (y / 3) * 3 + x / 3;
	if (val == 0) {
		for (int i = 1; i < 10; i++) {
			if (!check(i, x, y, z)) {
				map[y][x] = i + '0';
				row[y] |= 1 << i;
				col[x] |= 1 << i;
				sq[z] |= 1 << i;
				dfs(cur + 1);
				map[y][x] = '0';
				row[y] &= ~(1 << i);
				col[x] &= ~(1 << i);
				sq[z] &= ~(1 << i);
			}
		}
		if (map[y][x] == '0')
			return;
	}
	dfs(cur + 1);
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++) {
			int z = (i / 3) * 3 + j / 3;
			cin >> map[i][j];
			row[i] |= 1 << (map[i][j]-'0');
			col[j] |= 1 << (map[i][j] - '0');
			sq[z] |= 1 << (map[i][j] - '0');
		}

	dfs(0);

	return 0;
}