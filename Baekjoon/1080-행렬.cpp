#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

vector<string> a;
vector<string> b;

void matrix(int i, int j) {
	for (int id1 = i;id1 <= i + 2;id1++) {
		for (int id2 = j;id2 <= j + 2;id2++) {
			if (a[id1][id2] == '0')
				a[id1][id2] = '1';
			else
				a[id1][id2] = '0';
		}
	}
}

int main() {
	cin.tie(0); cout.tie(0);
	std::ios::sync_with_stdio(false);

	int n, m, cnt = 0;
	cin >> n >> m;
	
	a.resize(n);
	b.resize(n);

	
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}
	
	for (int i = 0;i < n;i++) {
		cin >> b[i];
	}

	if (n > 2 && m > 2) {
		for (int i = 0;i < n - 2;i++) {
			for (int j = 0;j < m - 2;j++) {
				if (a[i][j] != b[i][j]) {
					matrix(i, j);
					cnt++;
				}
			}
		}
	}

	if (a == b)
		cout << cnt;
	else
		cout << -1;


	return 0;
}