#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	string str1, str2, str3;
	long long int b1 = 0, b2 = 0;
	cin >> str1 >> str2;
	int sz = str1.size() - 1;
	for (int i = 0;i <= sz;i++) {
		b1 += str1[sz - i] - '0' << i;
	}
	sz = str2.size() - 1;
	for (int i = 0;i <= sz;i++) {
		b2 += str2[sz - i] - '0' << i;
	}
	b1 *= b2;
	if (b1) {
		while (b1) {
			str3 += (char)(b1 % 2 + '0');
			b1 /= 2;
		}
		reverse(str3.begin(), str3.end());
		cout << str3;
	}
	else {
		cout << 0;
	}

	return 0;
}