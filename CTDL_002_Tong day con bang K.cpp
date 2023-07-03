#include<iostream>
#include <algorithm>

using namespace std;

int a[100];
int n;
int k;
int res[100];
int cnt = 0;

void quayLui(int i, int sum) {
	for(int j = 0; j < 2; j += 1) {
		res[i] = j;
		sum += a[i] * j;
		if(i == n - 1) {
			if(sum == k) {
				for(int idx = 0; idx < n; idx += 1) {
					if(res[idx] > 0) {
						cout << a[idx] << " ";
					}
				}
				cnt += 1;
				cout << endl;
			}
		}
		else quayLui(i + 1, sum);
		sum -= a[i] * j;
	}
}

int main() {
	cin >> n >> k;
	for(int i = 0; i < n; i += 1) {
		cin >> a[i];
	}
	sort(a, a + n);
	quayLui(0, 0);
	cout << cnt;
	return 0;
}

