#include <iostream>
#include <vector>
using namespace std;

int n, s, res = 0;
vector<int> v;

void sol(int sum,int index) {
	if (sum + v[index] == s)
		res++;
	for (int i = index + 1;i < n;i++) {
		sol(sum + v[index], i);
	}
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> s;
	v.resize(n);
	for (int &i : v)
		cin >> i;
	for (int i = 0;i < n;i++)
		sol(0, i);

	cout << res;
	return 0;
}