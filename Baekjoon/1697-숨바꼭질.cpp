#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool visit[100010] = {};
int level[100010] = {};
int n, k;

int bfs() {
	queue<int> q;
	q.push(n);
	int tmp;
	while (!q.empty()) {
		tmp = q.front();
		q.pop();
		if (tmp == k)
			break;
		if (tmp - 1 >= 0 && !visit[tmp - 1]) {
			q.push(tmp - 1);
			visit[tmp - 1] = true;
			level[tmp - 1] = level[tmp] + 1;
		}
		if (tmp + 1 <= 100000 && !visit[tmp + 1]) {
			q.push(tmp + 1);
			visit[tmp + 1] = true;
			level[tmp + 1] = level[tmp] + 1;

		}
		if (2 * tmp <= 100000 && !visit[2 * tmp]) {
			q.push(2 * tmp);
			visit[2 * tmp] = true;
			level[2 * tmp] = level[tmp] + 1;
		}
	}
	return level[k];
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> k;
	cout << bfs();

	return 0;
}