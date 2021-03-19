#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	cin.ignore();
	while (t--) {
		string str;
		int cnt = 0, max = 0;
		getline(cin,str);
		for (auto i : str) {
			if (i == '[') 
				cnt++;
			else 
				cnt--;
			max = max < cnt ? cnt : max;
		}

		cout << (int)pow(2, max)<<'\n';
	}

	return 0;
}