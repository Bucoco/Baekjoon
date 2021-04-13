#include <iostream>
#include <vector>
using namespace std;

#define MAX 2000000000

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);


	int n;
	cin >> n;
	
	vector<int> v(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];

	int l = 0, r = n - 1;
	pair<int, int> ans;
	int sum = MAX;
	while (l < r) {
		if (abs(sum) > abs(v[l] + v[r])) {
			ans = { v[l],v[r] };
			sum = v[l] + v[r];
		}

		if (v[l] + v[r] <= 0) {
			l++;
		}
		else if (v[l] + v[r] > 0) {
			r--;
		}
	}

	cout << ans.first << ' ' << ans.second;

	return 0;
}