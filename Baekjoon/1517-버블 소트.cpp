#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;
vector<int> tmp;
long long int cnt = 0;

void merge(int a,int b) {
	if (a == b)
		return;

	int mid = (a + b) / 2;
	merge(a, mid);
	merge(mid + 1, b);

	int id1 = a, id2 = mid + 1, id = a;
	while (id1 <= mid && id2 <= b) {
		if (v[id1] > v[id2]) {
			tmp[id++] = v[id2++];
			cnt += mid - id1 + 1;
		}
		else {
			tmp[id++] = v[id1++];
		}
	}
	while (id1<=mid)
	{
		tmp[id++] = v[id1++];
	}
	while (id2 <= b) {
		tmp[id++] = v[id2++];
	}

	for (int i = a;i <= b;i++) {
		v[i] = tmp[i];
	}
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	v.resize(n);
	tmp.resize(n);

	for (auto &i : v)
		cin >> i;

	merge(0, n - 1);

	cout << cnt;

	return 0;
}