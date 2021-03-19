#include <iostream>
#include <vector>

using namespace std;

int n, ans = 0;
bool c[100] = {}, up[100] = {}, down[100] = {};

void solve(int y, int x)
{
	if (y > n)
	{
		ans++;
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (c[i] || up[n + y - i] || down[y + i])
			continue;
		c[i] = up[n + (y - i)] = down[y + i] = true;
		solve(y + 1, i);
		c[i] = up[n + (y - i)] = down[y + i] = false;
	}

	return;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	
	solve(1, 1);

	cout << ans;
	return 0;
}