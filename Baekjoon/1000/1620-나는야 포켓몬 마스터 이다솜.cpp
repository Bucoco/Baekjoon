#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	string str;
	vector<string> v;
	map<string, int> mp;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> str;
		v.push_back(str);
		mp.insert({ str,i + 1 });
	}

	for (int i = 0; i < m; i++) {
		cin >> str;
		if (mp.find(str) != mp.end())
			cout << mp[str] << '\n';
		else
			cout << v[stoi(str) - 1] << '\n';
	}

	return 0;
}