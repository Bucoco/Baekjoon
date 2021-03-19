#include <iostream>
#include <bitset>
using namespace std;

#define MOD 1048576;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	bool visit[1048576] = {};
	int train[100000] = {};
	int n, m, op;
	cin >> n >> m;
	int a, b;
	for (int i = 0;i < m;i++) {
		cin >> op;
		switch (op)
		{
		case 1:
			cin >> a >> b;
			train[a - 1] = train[a - 1] | (1 << b - 1);
			break;
		case 2:
			cin >> a >> b;
			train[a - 1] = train[a - 1] & (-524289 >> 20-b);
			break;
		case 3:
			cin >> a;
			train[a - 1] = (train[a - 1] << 1) % MOD;

			break;
		case 4:
			cin >> a;
			train[a - 1] = (train[a - 1] >> 1) % MOD;
			break;

		default:
			break;
		}
	}

	int result = n;

	for (int i = 0;i < n;i++) {
		if (!visit[train[i]])
			visit[train[i]] = true;
		else
			result--;
	}
	cout << result;
	return 0;
}