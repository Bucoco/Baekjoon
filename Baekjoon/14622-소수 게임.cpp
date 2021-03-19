#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>
using namespace std;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	long long int res1 = 0, res2 = 0;
	bool prime[5000000] = {};
	bool visit[5000000] = {};
	priority_queue<int, vector<int>, less<int>> pq1;
	priority_queue<int, vector<int>, less<int>> pq2;
	memset(prime, true, sizeof(prime));
	prime[1] = prime[0] = false;
	for (int i = 2;i*i < 5000000;i++) {
		for (int j = i * 2;j < 5000000;j += i) {
			prime[j] = false;
		}
	}
	cin >> n;
	int a, b;
	for (int i = 0;i < n;i++) {
		cin >> a >> b;
		if (!prime[a]) {
			if (pq2.size() < 3) {
				res2 += 1000;
			}
			else {
				int val1 = pq2.top();
				pq2.pop();
				int val2 = pq2.top();
				pq2.pop();
				res2 += pq2.top();
				pq2.push(val1);
				pq2.push(val2);
			}
				
		}
		else {
			if (visit[a]) {
				res1 -= 1000;
			}
			else {
				visit[a] = true;
				pq1.push(a);
			}
		}
		if (!prime[b]) {
			if (pq1.size() < 3) {
				res1 += 1000;
			}
			else {
				int val1 = pq1.top();
				pq1.pop();
				int val2 = pq1.top();
				pq1.pop();
				res1 += pq1.top();
				pq1.push(val1);
				pq1.push(val2);
			}
		}
		else {
			if (visit[b]) {
				res2 -= 1000;
			}
			else {
				visit[b] = true;
				pq2.push(b);
			}
		}
	}

	if (res1 > res2) {
		cout << "소수의 신 갓대웅";
	}
	else if (res1 < res2) {
		cout << "소수 마스터 갓규성";
	}
	else {
		cout << "우열을 가릴 수 없음";
	}

	return 0;
}