#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	vector<int> v;
	cin >> n;
	for (int i = 1;i <= n;i++)
		v.push_back(i);

	do {
		for (int &i : v)
			cout << i << ' ';
		cout << '\n';
	} while (next_permutation(v.begin(),v.end()));


	return 0;
}