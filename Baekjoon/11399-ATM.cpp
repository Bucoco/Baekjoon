#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	vector<int> v;
	vector<int> v1;
	int n;
	cin >> n;
	v.resize(n);
	for (auto& i : v)
		cin >> i;
	sort(v.begin(), v.end());
	partial_sum(v.begin(), v.end(),back_inserter(v1));
		
	cout << accumulate(v1.begin(), v1.end(),0);

	return 0;
}