#include<iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n + 1];
		a[0] = n;
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		int i = n - 1;
		while(a[i] > a[i + 1] && i >= 1) {
			i -= 1;
		}
		int j = n;
		while(a[j] < a[i] && j > i) {
			j -= 1;
		}
		swap(a[i], a[j]);
		int l = i + 1, r = n;
		while(l < r) {
			swap(a[l], a[r]);
			l += 1;
			r -= 1;
		}
		for(i = 1; i <= n; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
	return 0;
}

