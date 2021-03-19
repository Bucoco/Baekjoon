#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
	int s, e, w;
};

int visit[1005] = {};
vector<vector<int>> mst;
vector<char> node;
vector<Edge> edges;

bool cmp(const Edge& a, const Edge& b) {
	if (a.w == b.w) {
		if (a.s == b.s) {
			return a.e < b.e;
		}
		return a.s < b.s;
	}
	return a.w < b.w;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	node.resize(n + 1);
	for (int i = 1;i <= n;i++) {
		cin >> node[i];
	}
	int a, b, c;
	for (int i = 0;i < m;i++) {
		cin >> a >> b >> c;
		if (node[a] != node[b]) {
			edges.push_back({ a,b,c });
		}
	}
	sort(edges.begin(), edges.end(), cmp);
	int num = 1, cnt = 0, sum = 0;
	for (int i = 0;i < edges.size();i++) {
		int val1 = visit[edges[i].s], val2 = visit[edges[i].e];

		if (cnt == n - 1) {
			break;
		}
		if (val1 == 0 && val2 == 0) {
			visit[edges[i].s] = visit[edges[i].e] = num;
			num++;
		}
		else if (val1 == 0) {
			visit[edges[i].s] = visit[edges[i].e];
		}
		else if (val2 == 0) {
			visit[edges[i].e] = visit[edges[i].s];
		}
		else if(val1 != val2){
			for (int j = 1;j <= n;j++) {
				if (visit[j] == val2)
					visit[j] = val1;
			}
		}
		else {
			continue;
		}
		cnt++;
		sum += edges[i].w;
	}
	if (cnt < n - 1) {
		cout << "-1";
	}
	else {
		cout << sum;
	}
	return 0;
}