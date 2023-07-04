#include<iostream>

using namespace std;

int a[100];
int n, k;

void quayLui(int i) {
	for(int j = a[i - 1] + 1; j <= n - k + i; j++) {
		a[i] = j;
		if(i == k) {
			for(int idx = 1; idx <= k; idx++) {
				cout << (char) ('A' + a[idx] - 1);
			}
			cout << endl;
		}
		else quayLui(i + 1);
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		a[0] = 0;
		quayLui(1);
	}
	return 0;
}

