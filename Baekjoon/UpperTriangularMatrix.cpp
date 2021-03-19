#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;	// n:row m:column
vector<vector<float>> matrix;

bool row_exchange(int a) {
	for (int i = a + 1;i < n;i++) {
		if (matrix[i][a] != 0) {
			swap(matrix[a], matrix[i]);
			return true;
		}
	}
	return false;
}

int main() {
	

	cout << "row : ";	
	cin >> n;
	cout << "column : ";
	cin >> m;


	matrix.resize(n);	// n by m matrix
	for (auto &i : matrix) {
		i.resize(m);
	}

	cout << "matrix component(integer only) : \n";

	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			cin >> matrix[i][j];
		}
	}

	for (int i = 0;i < min(n,m);i++) {
		float pivot = matrix[i][i];
		if (pivot == 0) {
			if (!row_exchange(i)) {
				continue;
			}
		}
		if (i == 0) {
			for (float& com : matrix[i])
				com /= pivot;
			pivot = 1;
		}

		for (int j = i + 1;j < n;j++) {
			float temp = matrix[j][i] / pivot;
			for (int k = 0;k < m;k++) {
				matrix[j][k] -= (matrix[i][k] * temp);
			}
		}
	}

	cout << "result : \n";

	for (auto i : matrix) {
		for (auto j : i)
			cout << j << ' ';
		cout << '\n';
	}

}