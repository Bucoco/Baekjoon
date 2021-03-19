#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	std::ios::sync_with_stdio(false);

	int n, m;
	cin >> n;
	vector<int> v(n);
	for (auto& i : v)
		cin >> i;
	sort(v.begin(), v.end());
	cin >> m;
	int num;
	for (int i = 0;i < m;i++) {
		cin >> num;
		cout << upper_bound(v.begin(), v.end(), num) - lower_bound(v.begin(), v.end(), num) << " ";
	}
	
	return 0;
}