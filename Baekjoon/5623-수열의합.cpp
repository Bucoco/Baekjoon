#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<vector<int>> v(n);
	int sum = 0;
	for (int i = 0;i < n;i++) {
		v[i].resize(n);
		for (int j = 0;j < n;j++) {
			cin >> v[i][j];
		}
	}
	if (n > 2) {
		sum += v[0][1] + v[0][2] + v[1][2];
		sum /= 2;
		sum -= v[1][2];
		cout << sum << " ";
		for (int i = 1;i < n;i++) {
			cout << v[0][i] - sum << " ";
		}
	}
	else {
		cout << "1 1";
	}
	
	return 0;
}