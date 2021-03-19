#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n, cnt = 0;
	string str;

	cin >> n;
	while (n--) {
		bool visit[26] = {};
		bool check = true;
		cin >> str;
		for (int i = 0;i < str.size() - 1;i++) {
			visit[str[i]-'a'] = true;
			if (str[i] != str[i + 1] && visit[str[i + 1]-'a']) {
				check = false;
				break;
			}
		}
		if (check)
			cnt++;
	}

	cout << cnt;
	return 0;
}