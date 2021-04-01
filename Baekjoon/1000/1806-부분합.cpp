#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 100007

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, s, a, ans = INF;
	vector<int> v;

	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}

	int left = 0, right = 0, sum = 0;
	while (left <= right) {
		if (sum >= s){
			ans = min(ans, right - left);
			sum -= v[left++];
		}
		else if (sum < s) {
			if (right == n)
				break;
			sum += v[right++];
		}
	}

	if (ans == INF)
		cout << 0;
	else
		cout << ans;

	return 0;
}