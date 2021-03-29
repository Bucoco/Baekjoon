#include <iostream>
#include <queue>
#include <utility>
using namespace std;

char map[1005][1005];
int visit[1005][1005][2]{};
int dx[] = { 1,-1,0,0 }, dy[]{ 0,0,1,-1 };

struct Node {
	int x, y, w;
};

int bfs(int n, int m) {
	queue<Node> q;
	q.push({ 0, 0, 1 });
	visit[0][0][1] = 1;
	while (!q.empty()) {
		auto temp = q.front();
		q.pop();
		if (temp.x == m - 1 && temp.y == n - 1)
			return visit[temp.y][temp.x][temp.w];
		for (int i = 0; i < 4; i++) {
			int nx = temp.x + dx[i], ny = temp.y + dy[i];
			if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
				if (map[ny][nx] == '1' && temp.w == 1) {
					q.push({ nx,ny,temp.w - 1 });
					visit[ny][nx][temp.w - 1] = visit[temp.y][temp.x][temp.w] + 1;
				}
				else if(map[ny][nx] == '0' && !visit[ny][nx][temp.w]){
					q.push({ nx,ny,temp.w });
					visit[ny][nx][temp.w] = visit[temp.y][temp.x][temp.w] + 1;
				}
			}
		}
	}
	return -1;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	cout << bfs(n, m);

	return 0;
}