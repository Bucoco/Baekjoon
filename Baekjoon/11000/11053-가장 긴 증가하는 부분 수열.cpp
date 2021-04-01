#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
vector<int> ans;

int LIS(int n) {
	ans.push_back(v[0]);
	for (int i = 1; i < n; i++) {
		if (v[i] > ans.back()) {
			ans.push_back(v[i]);
		}
		else {
			*lower_bound(ans.begin(), ans.end(), v[i]) = v[i];
		}
	}
	return ans.size();
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

	cout << LIS(n);

	return 0;
}