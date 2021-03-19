#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	long long int k;
	long long int fact[21] = {1,1,};
	vector<int> v;
	int n, a;

	for (int i = 2;i < 21;i++) {
		fact[i] = fact[i - 1] * i;
	}

	cin >> n >> a;

	for (int i = 1;i <= n;i++) {
		v.push_back(i);
	}

	if (a & 1) {
		cin >> k;
		for (int i = 1;i <= n;i++) {
			int idx = 0;
			while (k > fact[n - i]) {
				k -= fact[n - i];
				idx++;
			}
			cout << v[idx] << ' ';
			v.erase(v.begin() + idx);
		}
	}
	else {
		int b;
		k = 0;
		for (int i = 1;i <= n;i++) {
			cin >> b;
			for (int j = 0;j < n;j++) {
				if (v[j] == b) {
					k += fact[n - i] * j;
					v.erase(v.begin() + j);
					break;
				}
			}
		}
		cout << ++k;
	}

	return 0;
}