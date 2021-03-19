#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
#include <map>
#include <string>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int res = 123456789;
	int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,1,-1 };
	string str = "";
	char c;
	for (int i = 0;i < 9;i++) {
		cin >> c;
		if (c == '0')
			c = '9';
		str += c;
	}

	queue<int> q;
	map<int, int> visit;
	q.push(stoi(str));
	visit[stoi(str)] = 0;
	while (!q.empty()){
		string cur = to_string(q.front());
		q.pop();
		if (stoi(cur) == res)
			break;
		int idx = cur.find('9');
		for (int i = 0;i < 4;i++) {
			int nx = idx % 3 + dx[i], ny = idx / 3 + dy[i];
			if (nx >= 0 && ny >= 0 && nx < 3 && ny < 3) {
				string tmp = cur;
				swap(tmp[idx], tmp[nx + ny * 3]);
				int next = stoi(tmp);
				if (!visit.count(next)) {
					visit[next] = visit[stoi(cur)] + 1;
					q.push(next);
				}
			}
		}
	}

	if (!visit.count(res))
		cout << -1;
	else
		cout << visit[res];

	return 0;
}