#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Node {
	int num;
	int weight;
	int child = 0;
};

vector<int> stree;
vector<int> lazy;

vector<vector<int>> tree;
vector<Node> node;
vector<int> v;

bool visit[100001] = {};

int TtoA(int cur) {
	if (visit[cur])
		return 0;
	visit[cur] = true;
	int cnt = 0;
	for (auto &i : tree[cur]) {
		cnt += TtoA(i);
	}
	node[cur].num = v.size();

	v.push_back(cur);
	node[cur].child = cnt;

	return cnt + 1;
}

int segment(int start, int end, int cur) {
	if (start == end) {
 		return stree[cur] = node[v[start]].weight;
	}
	return stree[cur] = segment(start, (start + end) / 2, cur * 2) ^ segment((start + end) / 2 + 1, end, cur * 2 + 1);
}

int query1(int cur, int start, int end, int a, int b) {
	if (lazy[cur]) {
		if ((end - start + 1) & 1) {
			stree[cur] ^= lazy[cur];
		}
		if (start != end) {
			lazy[cur * 2] ^= lazy[cur];
			lazy[cur * 2 + 1] ^= lazy[cur];
		}
		lazy[cur] = 0;
	}

	if (b < start || a > end) {
		return 0;
	}
	if (a <= start && b >= end) {
		return stree[cur];
	}
	return query1(cur * 2, start, (start + end) / 2, a, b) ^ query1(cur * 2 + 1, (start + end) / 2 + 1, end, a, b);
}

void query2(int cur, int start, int end, int a, int b, int y) {
	if (lazy[cur]) {
		if ((end - start + 1) & 1) {
			stree[cur] ^= lazy[cur];
		}
		if (start != end) {
			lazy[cur * 2] ^= lazy[cur];
			lazy[cur * 2 + 1] ^= lazy[cur];
		}
		lazy[cur] = 0;
	}
	if (b<start || a>end) {
		return;
	}
	if (a <= start && b >= end) {
		if ((end - start + 1) & 1) {
			stree[cur] ^= y;
		}
		if (start != end) {
			lazy[cur * 2] ^= y;
			lazy[cur * 2 + 1] ^= y;
		}
		return;
	}
	query2(cur * 2, start, (start + end) / 2, a, b, y);
	query2(cur * 2 + 1, (start + end) / 2 + 1, end, a, b, y);
	stree[cur] = stree[cur * 2] ^ stree[cur * 2 + 1];
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	
	tree.resize(n + 1);
	node.resize(n + 1);

	int a, b;
	for (int i = 0;i < n - 1;i++){
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	for (int i = 1;i <= n;i++) {
		cin >> node[i].weight;
	}

	TtoA(1);

	int h = (int)ceil(log2(n));
	int size = (1 << h + 1);

	stree.resize(size);
	lazy.resize(size);

	segment(0, n-1, 1);

	int x, y, op;
	for (int i = 0;i < m;i++) {
		cin >> op;
		if (op == 1) {
			cin >> x;
			cout << query1(1, 0, n - 1, node[x].num - node[x].child, node[x].num) << "\n";
		}
		else {
			cin >> x >> y;
			query2(1, 0, n-1, node[x].num - node[x].child, node[x].num, y);
		}
	}

	return 0;
}