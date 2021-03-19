#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

struct Loc {
	int x, y, z;
};

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int l, r, c;
	Loc s, e;
	int dx[6] = { 1,-1,0,0,0,0 }, dy[6] = { 0,0,1,-1,0,0 }, dz[6] = { 0,0,0,0,1,-1 };
	while (true) {
		int visit[40][40][40] = {};
		cin >> l >> r >> c;
		if (!l && !r && !c) {
			break;
		}

		char ch;
		for (int i = 0;i < l;i++) {	
			for (int j = 0;j < r;j++) {	
				for (int k = 0;k < c;k++) {
					cin >> ch;
					switch (ch)
					{
					case 'S':
						s.x = i; s.y = j; s.z = k;
						visit[i][j][k] = 1;
						break;
					case 'E':
						e.x = i; e.y = j; e.z = k;
						break;
					case '#':
						visit[i][j][k] = -1;
						break;
					default:
						break;
					}
				}
			}
		}

		queue<Loc> q;
		q.push(s);
		while (!q.empty()) {
			Loc tmp = q.front();
			q.pop();
			for (int i = 0;i < 6;i++) {
				int mx = tmp.x + dx[i], my = tmp.y + dy[i], mz = tmp.z + dz[i];
				if (mx >= 0 && mx < l && my >= 0 && my < r && mz >= 0 && mz < c && !visit[mx][my][mz]) {
					visit[mx][my][mz] = visit[tmp.x][tmp.y][tmp.z] + 1;
					q.push({ mx, my, mz });
				}
			}
		}

		if (visit[e.x][e.y][e.z]) {
			cout << "Escaped in " << visit[e.x][e.y][e.z] - 1 << " minute(s).\n";
		}
		else {
			cout << "Trapped!\n";
		}
	}

	return 0;
}