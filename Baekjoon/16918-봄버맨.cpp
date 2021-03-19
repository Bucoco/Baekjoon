#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int r, c, n = 0;
int t[210][210] = {};
int dx[] = { 1,-1,0,0 }, dy[] = { 0,0,1,-1 };
bool map[210][210] = {};
queue<pair<int, int>> q;

void bfs() {
	pair<int, int> tmp;
	int mx, my;
	while (!q.empty()){
		tmp = q.front();
		q.pop();
		t[tmp.first][tmp.second] = 0;
		map[tmp.first][tmp.second] = false;
		for (int i = 0;i < 4;i++) {
			mx = tmp.second + dx[i];
			my = tmp.first + dy[i];
			if (mx >= 0 && mx < c && my >= 0 && my < r) {
				map[my][mx] = false;
				t[my][mx] = 0;
			}
		}
	}
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> r >> c >> n;
	char input;
	for (int i = 0;i < r;i++) {
		for (int j = 0;j < c;j++) {
			cin >> input;
			if (input == '.') {
				map[i][j] = false;
			}
			else {
				map[i][j] = true;
			}
			t[i][j] = 1;
		}
	}

	for (int i = 2;i <= n;i++) {
		bfs();
		for (int j = 0;j < r;j++) {
			for (int k = 0;k < c;k++) {
				if (map[j][k]) {
					t[j][k]++;
					if (t[j][k] == 2) {
						q.push(make_pair(j, k));
					}
				}
				else {
					if (t[j][k] == 1) {
						map[j][k] = true;
						t[j][k] = 0;
					}
					else
						t[j][k]++;
				}
			}
		}

	}

	for (int i = 0;i < r;i++) {
		for (int j = 0;j < c;j++) {
			if (map[i][j])
				cout << 'O';
			else
				cout << '.';
		}
		cout << '\n';
	}


	return 0;
}