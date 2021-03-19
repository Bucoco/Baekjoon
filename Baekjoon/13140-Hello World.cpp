#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	long long n, a, b;
	vector<long long> v;
	bool check = false;
	cin >> n;
	for (int i = 0;i < 10;i++) {
		v.push_back(i);
	}

	do {
		if (v[0] == 0 || v[4] == 0)
			continue;
		a = v[0] * 10000 + v[1] * 1000 + v[2] * 110 + v[3];
		b = v[4] * 10000 + v[3] * 1000 + v[5] * 100 + v[2] * 10 + v[6];
		if (a + b == n) {
			check = true;
			break;
		}

	} while (next_permutation(v.begin(),v.end()));

	if (check) {
		cout << "  " << a << '\n'
			<< "+ " << b << '\n'
			<< "-------\n";
		if (n > 99999)
			cout << " " << n;
		else
			cout << "  " << n;
	}
	else {
		cout << "No Answer";
	}

	return 0;
}