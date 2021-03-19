#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool vowel(char c) {
	switch (c)
	{
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		return true;
	default:
		return false;
		break;
	}
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int l, c;
	cin >> l >> c;
	vector<char> v(c);
	vector<int> v2;
	for (auto& i : v)
		cin >> i;
	sort(v.begin(), v.end());

	for (int i = 0;i < l;i++)
		v2.push_back(1);
	for (int i = 0;i < c - l;i++)
		v2.push_back(0);

	do {
		int cnt = 0;
		string str;
		for (int i = 0;i < c;i++) {
			if (v2[i]) {
				if (vowel(v[i]))
					cnt++;
				str += v[i];
			}
		}
		
		if (cnt && l - cnt > 1)
			cout << str << '\n';

	} while (prev_permutation(v2.begin(),v2.end()));

	return 0;
}