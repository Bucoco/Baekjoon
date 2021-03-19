#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Node{
	int a, b;
};

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int a, b, c;
	bool visit[205][205] = {};

	cin >> a >> b >> c;
	queue<Node> q;
	q.push({ 0,0 });
	visit[0][0] = true;
	while (!q.empty()) {
		Node cur = q.front();
		q.pop();
		int na, nb;
		nb = min(cur.a + cur.b, b);
		na = (cur.a + cur.b) - nb;
		if (!visit[na][nb]) {
			visit[na][nb] = true;
			q.push({ na,nb });
		}
		na = min(cur.a + cur.b, a);
		nb = (cur.a + cur.b) - na;
		if (!visit[na][nb]) {
			visit[na][nb] = true;
			q.push({ na,nb });
		}
		na = cur.a;
		nb = 0;
		if (!visit[na][nb]) {
			visit[na][nb] = true;
			q.push({ na,nb });
		}
		na = cur.a;
		nb = min(c - cur.a, b);
		if (!visit[na][nb]) {
			visit[na][nb] = true;
			q.push({ na,nb });
		}
		na = 0;
		nb = cur.b;
		if (!visit[na][nb]) {
			visit[na][nb] = true;
			q.push({ na,nb });
		}
		na = min(c - cur.b, a);
		nb = cur.b;
		if (!visit[na][nb]) {
			visit[na][nb] = true;
			q.push({ na,nb });
		}
	}
	
	int tmp = min(b, c);
	for (int i = tmp;i >= 0;i--) {
		if (visit[0][i])
			cout << c - i << ' ';
	}

	return 0;
}