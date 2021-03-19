#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n, t, g, res = 100000;
bool visit[100010] = {};

int b(int num) {
	int temp = 2 * num;
	if (temp <= 0)
		return 0;
	else if (temp > 0 && temp < 10)
		return temp - 1;
	else if (temp >= 10 && temp < 100)
		return temp - 10;
	else if (temp >= 100 && temp < 1000)
		return temp - 100;
	else if (temp >= 1000 && temp < 10000)
		return temp - 1000;
	else if (temp >= 10000 && temp < 100000)
		return temp - 10000;
	else if (temp >= 100000)
		return temp;
}

void bfs() {
	queue<pair<int,int>> q;
	q.push({n,0});
	visit[n] = true;
	while (!q.empty()) {
		int f = q.front().first, s = q.front().second;
		q.pop();
		if (f == g) {
			res = s;
			return;
		}
		if (f < 99999 && s < t && !visit[f+1]) {
			q.push({ f + 1,s + 1 });
			visit[f + 1] = true;
		}
		if (b(f) < 100000 && s < t && !visit[b(f)]) {
			q.push({ b(f), s + 1 });
			visit[b(f)] = true;
		}
	}
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> t >> g;
	bfs();

	if (res < 100000)
		cout << res;
	else
		cout << "ANG";

	return 0;
}