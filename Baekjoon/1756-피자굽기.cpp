#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int d, n, pizza;	//d:������ ���� n:������ ���� pizza:������ ������
	int arr[300000] = {};	//���� �Է°�
	int oven[300000] = {};	//�������� ������ ������

	cin >> d >> n;

	for (int i = 0;i < d;i++)
		cin >> arr[i];

	oven[0] = arr[0];	//�������� ������ �������� ���ϴ� ����
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