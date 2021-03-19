#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<int> v;
string str;
bool visit[55] = {};
bool flag = false;
int n;

void dfs(int cur) {
	if (cur == str.length()) {
		for (int i : v) {
			cout << i << ' ';
		}
		exit(0);
	}
	int a;
	a = str[cur] - '0';
	if (!visit[a] && a <= n) {
		visit[a] = true;
		v.push_back(a);
		dfs(cur + 1);
		visit[a] = false;
		v.pop_back();
	}
	a = a * 10 + str[cur + 1] - '0';	
	if (!visit[a] && a <= n) {
		visit[a] = true;
		v.push_back(a);
		dfs(cur + 2);
		visit[a] = false;
		v.pop_back();
	}
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);


	cin >> str;
	n = str.length();
	if (n > 9) {
		n = (n - 9) / 2 + 9;
	}

	dfs(0);

	return 0;
}