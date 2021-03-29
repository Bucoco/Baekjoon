#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, x;
	vector<int> v;
	vector<int> s;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
		s.push_back(x);
	}

	sort(s.begin(), s.end());
	s.erase(unique(s.begin(), s.end()), s.end());
	

	for (int i = 0; i < n; i++) {
		cout << lower_bound(s.begin(), s.end(), v[i]) - s.begin() << ' ';
	}

	return 0;
}