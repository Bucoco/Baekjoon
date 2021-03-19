#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	std::ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<long long int> v(n);
	v[0] = 1;
	v[1] = 1;
	for (int i = 2;i < n;i++) {
		v[i] = v[i - 1] + v[i - 2];
	}
	cout << v.back();
	return 0;
}