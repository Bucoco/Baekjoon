#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const int &a, const int &b) {
	if (a <= 0 && b <= 0)
		return a < b;
	return a > b;
}

int main() {
	cin.tie(0); cout.tie(0);
	std::ios::sync_with_stdio(false);

	int n;
	vector<int> v;
	cin >> n;
	v.resize(n);
	for (auto &i : v)
		cin >> i;

	sort(v.begin(), v.end(), cmp);
	int result = 0;
	int sum,mul;
	int i;
	for (i = 0;i < n-1;i++) {
		mul = v[i] * v[i + 1];
		sum = v[i] + v[i + 1];
		if (mul > sum) {
			result += mul;
			i++;
		}
		else {
			result += v[i];
		}
	}
	if (i < n)
		result += v[i];
	cout << result;
	return 0;
}