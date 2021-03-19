#include <iostream>
#include <queue>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int D(int a) {
	return (2 * a) % 10000;
}

int S(int a) {
	if (a == 0) return 9999;
	return (a - 1) % 10000;
}

int L(int a) {
	int tmp = a / 1000;
	return tmp + ((a % 1000) * 10);
}

int R(int a) {
	int tmp = a % 10;
	return (tmp * 1000) + (a / 10);
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int t, a, b;
	
	cin >> t;
	while (t--) {
		int parent[10010] = {};
		char oper[10010] = {};
		cin >> a >> b;
		queue<int> q;
		q.push(a);
		oper[a] = 1;
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			int tmp = D(cur);
			if (oper[tmp] == 0) {
				q.push(tmp);
				oper[tmp] = 'D';
				parent[tmp] = cur;
				if (tmp == b)
					break;
			}
			tmp = S(cur);
			if (oper[tmp] == 0) {
				q.push(tmp);
				oper[tmp] = 'S';
				parent[tmp] = cur;
				if (tmp == b)
					break;
			}
			tmp = L(cur);
			if (oper[tmp] == 0) {
				q.push(tmp);
				oper[tmp] = 'L';
				parent[tmp] = cur;
				if (tmp == b)
					break;
			}
			tmp = R(cur);
			if (oper[tmp] == 0) {
				q.push(tmp);
				oper[tmp] = 'R';
				parent[tmp] = cur;
				if (tmp == b)
					break;
			}
		}
		int tmp = b;
		string res = "";
		while (tmp!=a) {
			res += oper[tmp];
			tmp = parent[tmp];
		}
		reverse(res.begin(), res.end());
		cout << res << '\n';
	}

	return 0;
}