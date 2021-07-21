#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> v;
vector<int> ans;
map<int, int> trace;

void LIS(int n) {
	ans.push_back(v[0]);
	trace[v[0]] = 0;
	for (int i = 1; i < n; i++) {
		if (v[i] > ans.back()) {
			trace[v[i]] = ans.size();
			ans.push_back(v[i]);
		}
		else {
			int idx = lower_bound(ans.begin(), ans.end(), v[i]) - ans.begin();
			ans[idx] = v[i];
			trace[v[i]] = idx;
		}
	}

	int j = ans.size() - 1;
	for (int i = n - 1; i >= 0; i--) {
		if (trace[v[i]] == j) {
			ans[j] = v[i];
			j--;
		}
	}

	cout << ans.size() << '\n';
	for (auto i : ans)
		cout << i << ' ';
}


int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, a;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}

	LIS(n);

	return 0;
}