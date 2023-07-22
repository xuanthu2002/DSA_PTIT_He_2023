#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int a[100];
int th[100];

void quayLui(int i) {
	for(int j = th[i - 1] + 1; j <= n - k + i - 1; j++) {
		th[i] = j;
		if(i == k) {
			for(int idx = 1; idx <= k; idx++) {
				cout << a[th[idx]] << " ";
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
		for(int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		th[0] = -1;
		quayLui(1);
	}
	return 0;
}

