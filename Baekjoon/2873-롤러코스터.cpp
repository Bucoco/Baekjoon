#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	std::ios::sync_with_stdio(false);

	int r, c;
	vector<vector<int>> v;
	cin >> r >> c;

	v.resize(r);
	int num;
	for (int i = 0;i < r;i++) {
		for (int j = 0;j < c;j++) {
			cin >> num;
			v[i].push_back(num);
		}
	}

	if (r % 2 || c % 2) {
		char val;
		if (r % 2) {
			for (int i = 0;i < r;i++) {
				if (i % 2) 
					val = 'L';
				
				else
					val = 'R';
				for (int j = 0;j < c - 1;j++)
					cout << val;
				if (i != r - 1)
					cout << 'D';
			}
		}
		else {
			
			for (int i = 0;i < c;i++) {
				if (i % 2)
					val = 'U';

				else
					val = 'D';
				for (int j = 0;j < r - 1;j++)
					cout << val;
				if (i != c - 1)
					cout << 'R';
			}
		}
	}
	else {
		string str1, str2;
		int min = 1001, mini, minj;
		for (int i = 0;i < r;i++) {
			for (int j = (i+1) % 2;j < c;j += 2) {
				if (min > v[i][j]) {
					min = v[i][j];
					mini = i;
					minj = j;
				}
			}
		}
		int start, end;
		char val;
		
		if (minj % 2) {
			start = minj - 1;
			end = minj;
		}
		else {
			start = minj;
			end = minj + 1;
		}

		for (int i = 0;i < start;i++) {
			if (i % 2)
				val = 'U';
			else
				val = 'D';
			for (int j = 0;j < r - 1;j++)
				str1 += val;
			str1 += 'R';
		}

		for (int i = 0;i < c - end - 1;i++) {
			if (i % 2)
				val = 'U';
			else
				val = 'D';
			for (int j = 0;j < r - 1;j++)
				str2 += val;
			str2 += 'R';
		}

		if (mini % 2) {
			start = mini - 1;
			end = mini;
		}
		else {
			start = mini;
			end = mini + 1;
		}

		for (int i = 0;i < start;i++) {
			if (i % 2)
				val = 'L';
			else
				val = 'R';
			
			str1 += val;
			str1 += 'D';
		}

		for (int i = 0;i < r - end - 1;i++) {
			if (i % 2)
				val = 'L';
			else
				val = 'R';

			str2 += val;
			str2 += 'D';
		}

		if (start == mini)
			str1 += "DR";
		else
			str1 += "RD";

		reverse(str2.begin(), str2.end());
		str1 += str2;
		cout << str1;
	}

	return 0;
}