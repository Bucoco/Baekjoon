#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int k;
	do {
		cin >> k;
		vector<int> v(k);
		for (int &i : v)
			cin >> i;
		vector<int> v2;
		for (int i = 0;i < 6;i++)
			v2.push_back(1);
		for (int i = 0;i < k - 6;i++)
			v2.push_back(0);
		do {
			for (int i = 0;i < k;i++) {
				if (v2[i])
					cout << v[i] << ' ';
			}
			cout << '\n';
		} while (prev_permutation(v2.begin(), v2.end()));
		cout << '\n';
	} while (k);


	return 0;

}