#include <iostream>
using namespace std;

int main() {
	int arr[100000][3] = {};
	int n;

	cin >> n;
	arr[0][0] = arr[0][1] = arr[0][2] = 1;

	for (int i = 1;i < n;i++) { //각각의 식에 9901로 나눠주는 이유는 int의 범위를 넘어가기 때문 

		arr[i][0] = (arr[i - 1][0] + arr[i - 1][1] + arr[i - 1][2]) % 9901;
		arr[i][1] = (arr[i - 1][0] + arr[i - 1][2]) % 9901;
		arr[i][2] = (arr[i - 1][0] + arr[i - 1][1]) % 9901;

	}

	cout << (arr[n - 1][0] + arr[n - 1][1] + arr[n - 1][2]) % 9901;

	return 0;
}