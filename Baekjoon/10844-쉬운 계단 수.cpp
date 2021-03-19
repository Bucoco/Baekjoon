#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	std::ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	vector<long long int> v[10];

	v[0].resize(n);
	for (int i = 1;i < 10;i++) {
		v[i].resize(n);
		v[i][0] = 1;
	}

	for (int i = 0;i < n-1;i++) {
		for (int j = 0;j < 10;j++) {
			if (j == 0)
				v[j][i + 1] = v[j + 1][i] % 1000000000;
			else if (j == 9)
				v[j][i + 1] = v[j - 1][i] % 1000000000;
			else
				v[j][i + 1] = (v[j + 1][i] + v[j - 1][i]) % 1000000000;
		}
	}

	int result = 0;
	for (int i = 0;i < 10;i++) {
		result += v[i].back();
		result %= 1000000000;
	}

	cout << result;
	
	return 0;
}
