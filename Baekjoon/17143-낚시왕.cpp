#include <iostream>
#include <vector>
using namespace std;

struct Shark {
	int s, d, z;
};

int r, c, m;
int map[110][110] = {};
vector<Shark> sharks;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> r >> c >> m;
	sharks.resize(m + 1);
	for (int i = 1;i <= m;i++) {
		int a, b;
		cin >> a >> b >> sharks[i].s >> sharks[i].d >> sharks[i].z;
		map[a][b] = i;
	}



	return 0;
}