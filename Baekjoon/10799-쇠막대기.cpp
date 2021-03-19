#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char str[100001] = {};
	int si = 0, count = 0; //si는 스택 인덱스, count는 막대갯수
	cin >> str;

	for (int i = 0;i < strlen(str);i++) {
		if (str[i] == '(')
			si++;  //push

		else {
			si--;  //pop

			if (str[i - 1] == '(')  //레이저 일때
				count += si;
			else				//막대 일때
				count++;
		}
	}

	cout << count;
	return 0;
}