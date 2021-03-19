#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<char>> v;
string str;

void matrix(int a,int b,int num) {
	bool isValid = true;
	for (int i = a;i < a+num;i++) {
		for (int j = b;j < b+num;j++) {
			if (v[a][b] != v[i][j]) {
				isValid = false;
				break;
			}
		}
		if (!isValid)
			break;
	}
	if (isValid) {
		str += v[a][b];
	}
	else {
		str += '(';
		matrix(a, b, num / 2);
		matrix(a, b + num / 2, num / 2);
		matrix(a + num / 2, b, num / 2);
		matrix(a + num / 2, b + num / 2, num / 2);
		str += ')';
	}
}

int main() {
	cin.tie(0); cout.tie(0);
	std::ios::sync_with_stdio(false);

	int n;
	cin >> n;
	v.resize(n);
	char val;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> val;
			v[i].push_back(val);
		}
	}

	matrix( 0, 0, n );

	cout << str;

	return 0;
}