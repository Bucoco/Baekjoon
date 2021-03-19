#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<pair<int, int>> v;

int distance(pair<int,int> a,pair<int,int> b) {
	return (a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second);
}

int drrrrrrrrrr(int a, int b) {
	if (b - a == 1)
		return distance(v[a], v[b]);
	if (b - a == 2)
		return min({ distance(v[a], v[a + 1]), distance(v[a], v[b]), distance(v[a + 1], v[b]) });

	int mid = (a + b) / 2;
	int d = min(drrrrrrrrrr(a, mid), drrrrrrrrrr(mid + 1, b));



	return d;
}


int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	v.resize(n);

	for (auto &i : v)
		cin >> i.first >> i.second;

	sort(v.begin(), v.end());
	
	cout << drrrrrrrrrr(0, n - 1);

	return 0;
}