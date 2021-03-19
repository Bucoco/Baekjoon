#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

int sol(int a, int b, int c) {
	if (a < 1000) return 1000;
	string str = to_string(a);
	str[b] = c + '0';
	return stoi(str);
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int t, a, b;
	int depth[10000] = {};
	bool visit[10000] = {};
	bool prime[10000] = {};

	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;
	for (int i = 2;i*i < 10000;i++) {
		if (prime[i])
			for (int j = i + i;j < 10000;j += i)
				prime[j] = false;
	}

	cin >> t;
	while (t--) {
		cin >> a >> b;
		memset(visit, 0, sizeof(visit));

		queue<int> q;
		q.push(a);
		depth[a] = 0;
		visit[a] = true;
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (int i = 0;i < 4;i++) {
				for (int j = 0;j < 10;j++) {
					int tmp = sol(cur, i, j);
					if (prime[tmp] && !visit[tmp]) {
						q.push(tmp);
						depth[tmp] = depth[cur] + 1;
						visit[tmp] = true;
					}
				}
			}
		}

		if (visit[b]) {
			cout << depth[b] << '\n';
		}
		else {
			cout << "Impossible\n";
		}

	}

	return 0;
}