#include<iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int a[1001];
		a[0] = -1;
		int n, k;
		cin >> n >> k;
		for(int i = 1; i <= k; i++) {
			cin >> a[i];
		}
		int i = k;
		while(a[i] == n - k + i && i > 0) {
			i -= 1;
		}
		a[i] += 1;
		i += 1;
		for(; i <= k; i++) {
			a[i] = a[i - 1] + 1;
		}
		for(i = 1; i <= k; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
	return 0;
}

