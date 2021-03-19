#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	int price = 0;
	int bundle[50] = {};
	int piece[50] = {};
	cin >> n >> m;
	for (int i = 0;i < m;i++)
		cin >> bundle[i] >> piece[i];
	sort(bundle, bundle + m);
	sort(piece, piece + m);
	if (bundle[0] < piece[0] * 6)
		price = bundle[0] * (n / 6) + min(bundle[0], piece[0] * (n % 6));
	else
		price = piece[0] * n;
	cout << price;
	return 0;

}
