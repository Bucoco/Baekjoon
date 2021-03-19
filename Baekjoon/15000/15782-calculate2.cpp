#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, a, b, val;

	cin >> n >> a >> b;
	vector<vector<int>> v(n);

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> val;
			v[i].push_back(val);
		}
	}

	bool isHappy = true;
	for (int i = 0;i < n;i++) {
		if (v[a - 1][i] > v[a - 1][b - 1])
			isHappy = false;
	}
	
	for (int i = 0;i < n;i++) {
		if (v[i][b - 1] > v[a - 1][b - 1])
			isHappy = false;
	}

	if (isHappy)
		cout << "HAPPY";
	else
		cout << "ANGRY";


	return 0;
}