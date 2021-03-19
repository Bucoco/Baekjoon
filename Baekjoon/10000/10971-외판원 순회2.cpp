#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int map[11][11] = {};
	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> map[i][j];
		}
	}
	vector<int> v;
	for (int i = 0;i < n;i++)
		v.push_back(i);
	int res = 10000000;
	do {
		int sum = 0;
		bool valid = true;
		for (int i = 0;i < n - 1;i++) {
			if (!map[v[i]][v[i + 1]]) {
				valid = false;
				break;
			}
			sum += map[v[i]][v[i + 1]];
		}
		if (!map[v[n - 1]][v[0]])
			continue;
		sum += map[v[n - 1]][v[0]];
		if (!valid) continue;
		if (res > sum) {
			res = sum;
		}
	} while (next_permutation(v.begin(),v.end()));

	cout << res;

	return 0;
}