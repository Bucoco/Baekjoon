#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int n, m, k, a, b;


int sol(int mid) {
	int length, f, s, d = mid;
	for (int i = 0;i < m;i++) {
		length = n;
		f = i;
		s = upper_bound(v.begin(), v.end(), (v[i] + mid))-v.begin();
		if()
		while ((length / mid) >= k) {
		}
	}
	return 0;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> n >> m >> k;
	for (int i = 0;i < m;i++) {
		cin >> a;
		v.push_back(a);
	}

	if (k == 1) {
		cout << n;
	}
	else {
		int l = 1, r = 100000, mid, result;
		while (l <= r) {
			
			if()
		}
	}



	return 0;
}