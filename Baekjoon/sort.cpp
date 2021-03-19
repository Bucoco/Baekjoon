#include <iostream>
#include <vector>
using namespace std;

void swap(int&, int&);
void BubbleSort(vector<int>& v);
void SelectionSort(vector<int>& v);
void InsertionSort(vector<int>& v);
void HeapSort(vector<int>& v);

int main() {
	cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	vector<int> v;

	int n, a;
	cin >> n;
	while (n--) {
		cin >> a;
		v.push_back(a);
	}
	InsertionSort(v);
	for (auto i : v) {
		cout << i << "\n";
	}
	return 0;
}

void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void BubbleSort(vector<int>& v) {
	if (v.size() < 2) {
		return;
	}
	else {
		for (int i = 0;i < v.size();i++) {
			for (int j = 0;j < v.size() - i - 1;j++) {
				if (v[j] > v[j + 1])
					swap(v[j], v[j + 1]);
			}
		}
	}
}

void SelectionSort(vector<int>& v) {
	if (v.size() < 2) {
		return;
	}
	else {
		int min;
		for (int i = 0;i < v.size();i++) {
			min = i;
			for (int j = i;j < v.size();j++) {
				if (v[min] > v[j])
					min = j;
			}
			swap(v[i], v[min]);
		}
	}
}

void InsertionSort(vector<int>& v) {
	if (v.size() < 2) {
		return;
	}
	else {
		for (int i = 1;i < v.size();i++) {
			for (int j = i;j > 0;j--) {
				if (v[j] < v[j - 1])
					swap(v[j], v[j - 1]);
				else
					break;
			}
		}
	}
}

void HeapSort(vector<int>& v) {
	if (v.size() < 2) {
		return;
	}
	else {
		
	}
}

vector<vector<vector<char>>> building;
bool visit[40][40][40] = {};
cin >> l >> r >> c;
if (!l && !r && !c) {
	break;
}

building.resize(l);
for (int i = 0;i < l;i++) {
	building[i].resize(r);
	for (int j = 0;j < r;j++) {
		building[i][j].resize(40);
		for (int k = 0;k < c;k++) {
			cin >> building[i][j][k];
			switch (building[i][j][k])
			{
			case 'S':
				a = i; b = j; c = k;
				break;
			case 'E':
				x = i; y = j;z = k;
				break;
			case '#':
				visit[i][j][k] = true;
				break;
			default:
				break;
			}
		}
	}
}