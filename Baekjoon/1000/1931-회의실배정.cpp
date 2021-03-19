#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Meeting
{
	int start, end;
};

bool cmp(const Meeting &a, const Meeting &b) {
	if (a.end == b.end)
		return a.start < b.start;
	return a.end < b.end;
}

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	vector<Meeting> v;

	cin >> n;
	v.resize(n);
	for (auto& i : v) {
		cin >> i.start >> i.end;
	}

	sort(v.begin(), v.end(), cmp);
	int cnt = 0, current = 0;

	for (auto i : v) {
		if (i.start>=current) {
			cnt++;
			current = i.end;
		}
	}

	cout << cnt;
	return 0;
}