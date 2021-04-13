#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main() {	//CCW ¹®Á¦
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	vector < pair <long long, long long>> v;
	int n;
	long long ans = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		long long x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}
	
	for (int i = 1; i < n - 1; i++) {
		long long s = (v[0].first * v[i].second + v[i].first * v[i + 1].second + v[i + 1].first * v[0].second) -
			(v[i].first * v[0].second + v[i + 1].first * v[i].second + v[0].first * v[i + 1].second);

		ans += s;
	}

	ans = abs(ans);
	if (ans & 1)
		cout << ans / 2 << ".5";
	else
		cout << ans / 2 << ".0";
	return 0;
}