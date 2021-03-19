#include <iostream>
#include <string>
#include <set>
using namespace std;

struct cmp {
	bool operator() (const string &a, const string &b) const {
		if (a.length() == b.length())
			return a < b;
		return a.length() < b.length();
	}
};

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	set<string, cmp> v;
	string str;
	int t;

	cin >> t;
	while (t--) {
		cin >> str;
		v.insert(str);
	}

	for (auto i : v) {
		cout << i << '\n';
	}

	return 0;
}