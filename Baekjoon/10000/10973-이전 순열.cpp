#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int &i : v)
		cin >> i;

	if (prev_permutation(v.begin(), v.end())) {
		for (int &i : v)
			cout << i << ' ';
	}
	else
		cout << -1;


	return 0;
}