#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, h;
	vector<int> up;
	vector<int> down;
	vector<int> v;
	cin >> n >> h;

	int a;
	for (int i = 0;i < n;i++) {
		cin >> a;
		if (i & 1)
			down.push_back(a);
		else
			up.push_back(a);
	}

	sort(up.begin(), up.end());
	sort(down.begin(), down.end());

	for (int i = 1;i <= h;i++) {
		v.push_back((up.end()-lower_bound(up.begin(), up.end(), i))+(down.end() - upper_bound(down.begin(),down.end(),h - i)));
	}

	sort(v.begin(), v.end());
	cout << v[0] << ' ' << upper_bound(v.begin(), v.end(), v[0]) - v.begin();

	return 0;
}