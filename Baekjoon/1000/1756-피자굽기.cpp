#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int d, n, pizza;	//d:오븐의 깊이 n:피자의 갯수 pizza:피자의 반지름
	int arr[300000] = {};	//오븐 입력값
	int oven[300000] = {};	//실질적인 오븐의 반지름

	cin >> d >> n;

	for (int i = 0;i < d;i++)
		cin >> arr[i];

	oven[0] = arr[0];	//실질적인 오븐의 반지름을 구하는 과정
	for (int i = 1;i < d;i++) {
		if (oven[i - 1] > arr[i])
			oven[i] = arr[i];
		else
			oven[i] = oven[i - 1];
	}

	for (int i = 0;i < n;i++) {
		cin >> pizza;
		while (pizza > oven[d - 1]) {
			d--;
		}
		if (d < 1) {
			cout << 0;
			return 0;
		}
		else if (pizza <= oven[d - 1]) {
			d--;
		}
	}

	cout << d + 1;
	return 0;
}