#include <iostream>
#include <string.h>
using namespace std;

int n;
int map[11][11] = {};
int sum[11][11] = {};
int dx[4] = { -1 ,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int res = 3001;
bool visit[11][11] = {};

bool valid(int i, int j) {
	if (!visit[i - 1][j] && !visit[i + 1][j] && !visit[i][j - 1] && !visit[i][j + 1] && !visit[i][j]) {
		for (int k = 0;k < 4;k++) {
			visit[i + dy[k]][j + dx[k]] = true;
		}
		visit[i][j] = true;
		return true;
	}
	return false;
}

void find(int i, int j, int cnt, int val) {
	if (cnt == 2 && valid(i,j)) {
		if (res > val) {
			res = val;
		}
		visit[i][j] = false;
		for (int k = 0;k < 4;k++) {
			visit[i + dy[k]][j + dx[k]] = false;
		}
	}
	else {
		if (valid(i, j)) {
			for (int a = 1;a < n - 1;a++) {
				for (int b = 1;b < n - 1;b++) {
					find(a, b, cnt + 1, val + sum[a][b]);
				}
			}
			
		}
		else {
			return;
		}
		visit[i][j] = false;
		for (int k = 0;k < 4;k++) {
			visit[i + dy[k]][j + dx[k]] = false;
		}
	}
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	
	
	cin >> n;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 1;i < n - 1;i++) {
		for (int j = 1;j < n - 1;j++) {
			for (int k = 0;k < 4;k++) {
				sum[i][j] += map[i + dy[k]][j + dx[k]];
			}
			sum[i][j] += map[i][j];
		}
	}

	for (int i = 1;i < n - 1;i++) {
		for (int j = 1;j < n - 1;j++) {
			find(i, j, 0, sum[i][j]);
		}
	}

	cout << res;

	return 0;
}