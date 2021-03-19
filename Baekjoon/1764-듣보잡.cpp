#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, m, cnt = 0;
	string name;
	set<string> s;
	set<string> res;
	cin >> n >> m;
	while (n--) {
		cin >> name;
		s.insert(name);
	}
	while (m--) {
		cin >> name;
		if (s.find(name) != s.end()) {
			res.insert(name);
			cnt++;
		}
	}
	cout << cnt << '\n';
	for (auto i : res)
		cout << i << '\n';

	return 0;
}