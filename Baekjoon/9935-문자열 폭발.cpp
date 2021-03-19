#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	string cmpl, cmpr, str2, left, right;
	cin >> str2 >> cmpl;
	cmpr = cmpl;
	reverse(cmpr.begin(), cmpr.end());

	int l = 0, r = str2.size() - 1;
	while (l <= r) {
		while (l <= r) {
			left += str2[l++];
			if (left.size() >= cmpl.size()) {
				if (!left.substr(left.size() - cmpl.size()).compare(cmpl)) {
					for (int i = 0;i < cmpl.size();i++)
						left.pop_back();
					break;
				}
			}
		}
		while (l <= r) {
			right += str2[r--];
			if (right.size() >= cmpr.size()) {
				if (!right.substr(right.size() - cmpr.size()).compare(cmpr)) {
					for (int i = 0;i < cmpr.size();i++)
						right.pop_back();
					break;
				}
			}
		}
	}

	reverse(right.begin(), right.end());
	for (auto &i : right) {
		left += i;
		if (left.size() >= cmpl.size()) {
			if (!left.substr(left.size() - cmpl.size()).compare(cmpl)) {
				for (int i = 0;i < cmpl.size();i++)
					left.pop_back();
			}
		}
	}

	if (left.empty())
		cout << "FRULA";
	else
		cout << left;

	return 0;
}