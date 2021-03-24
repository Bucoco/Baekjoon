#include <iostream>
#include <vector>
#include <utility>
using namespace std;

#define INF 1e9

vector<vector<pair<int, int>>> v;
int dist[505];
int tc, n, m, w, s, e, t;

bool bellmanford(int root) {
	for (int k = 0; k < n; k++) {
		for (int i = 1; i <= n; i++) {
			for (auto j : v[i]) {
				int next = j.first;
				int cost = j.second;

				if (dist[next] > dist[i] + cost) {
					dist[next] = dist[i] + cost;
					if (k == n - 1)
						return true;
				}
			}
		}	
	}
	return false;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> tc;
	while (tc--) {
		cin >> n >> m >> w;
		v.clear();
		v.resize(n + 1);
		
		for (int i = 0; i < m; i++) {
			cin >> s >> e >> t;
			v[s].push_back({ e,t });
			v[e].push_back({ s,t });
		}
		for (int i = 0; i < w; i++) {
			cin >> s >> e >> t;
			v[s].push_back({ e,-t });
		}
		fill(dist, dist + n + 3, INF);
		dist[1] = 0;
		if (bellmanford(1))
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}