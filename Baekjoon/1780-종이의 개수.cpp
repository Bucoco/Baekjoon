#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> v;
int arr[3] = {};

void matrix(int num,int a,int b) {
	if (num == 1) {
		arr[v[a][b]+1]++;
		return;
	}
	bool isValid = true;
	for (int i = a;i < a + num;i++) {
		for (int j = b;j < b + num;j++) {
			if (v[a][b] != v[i][j]) {
				isValid = false;
				break;
			}
		}
		if (!isValid)
			break;
	}

	if (isValid)
		arr[v[a][b]+1]++;
	else {
		for (int i = 0;i < 3;i++) {
			for (int j = 0;j < 3;j++) {
				matrix(num / 3, a+(num/3*i), b+(num/3*j));
			}
		}
	}

}

int main() {
	cin.tie(0); cout.tie(0);
	std::ios::sync_with_stdio(false);

	int n;
	cin >> n;
	v.resize(n);
	int m;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> m;
			v[i].push_back(m);

		}
	}

	matrix(n, 0, 0);

	for (auto& i : arr)
		cout << i << "\n";

	return 0;
}