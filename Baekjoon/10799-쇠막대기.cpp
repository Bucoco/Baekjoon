#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char str[100001] = {};
	int si = 0, count = 0; //si�� ���� �ε���, count�� ���밹��
	cin >> str;

	for (int i = 0;i < strlen(str);i++) {
		if (str[i] == '(')
			si++;  //push

		else {
			si--;  //pop

			if (str[i - 1] == '(')  //������ �϶�
				count += si;
			else				//���� �϶�
				count++;
		}
	}

	cout << count;
	return 0;
}