#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n, cnt = 1, a;
	bool flag = false;
	vector<int> v;
	vector<char> ans;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		for (cnt; cnt <= a; cnt++) {
			v.push_back(cnt);
			ans.push_back('+');
		}
		if (v.empty() || v.back() != a) {
			flag = true;
			break;
		}
		v.pop_back();
		ans.push_back('-');
	}

	if (flag)
		cout << "NO";

	else
		for (auto i : ans)
			cout << i << '\n';

	return 0;
}