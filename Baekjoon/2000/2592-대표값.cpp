#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int arr[10] = {};
	int average = 0, mode, count = 1;
	int temp;

	for (int i = 0;i < 10;i++)
		cin >> arr[i];

	sort(arr, arr + 10);

	for (int i = 0;i < 10;i++)
		average += arr[i];

	average /= 10;

	mode = arr[0];
	temp = count;
	for (int i = 0;i < 9;i++) {
		if (arr[i] == arr[i + 1]) {
			count++;
			if (count > temp) {
				temp = count;
				mode = arr[i];
			}
		}
		else
			count = 1;
	}
	cout << average << "\n" << mode;
	return 0;
}