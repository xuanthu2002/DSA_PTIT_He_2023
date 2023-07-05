#include <iostream>

using namespace std;

int a[100];
int n, k;

void quayLui(int i) {
	for(int j = a[i - 1] + 1; j <= n - k + i; j++) {
		a[i] = j;
		if(i == k) {
			for(int idx = 1; idx <= k; idx++) {
				cout << a[idx];
			}
			cout << " ";
		}
		else {
			quayLui(i + 1);
		}
	}
}

int main() {
	int t;
	cin >> t;
	a[0] = 0;
	while(t--) {
		cin >> n >> k;
		quayLui(1);
		cout << endl;
	}
	return 0;
}

