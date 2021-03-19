#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Order {
	int table, time;
};

bool cmp(const Order &a, const Order &b) {
	if (a.time == b.time) {
		return a.table < b.table;
	}
	return a.time < b.time;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	string str;
	vector<Order> v;

	cin >> n >> m;
	for (int i = 0;i < n;i++) {
		cin >> str;
		if (str == "order") {
			Order tmp;
			cin >> tmp.table >> tmp.time;
			v.push_back(tmp);
		}
		else if (str == "sort") {
			sort(v.begin(), v.end(), cmp);
		}
		else {
			int num;
			cin >> num;
			vector<Order>::iterator it;
			for (it = v.begin();it != v.end();it++) {
				if (it->table == num) {
					v.erase(it);
					break;
				}
			}
		}

		if (v.empty()) {
			cout << "sleep\n";
		}
		else {
			for (auto &i : v) {
				cout << i.table << " ";
			}
			cout << "\n";
		}
	}

	return 0;
}