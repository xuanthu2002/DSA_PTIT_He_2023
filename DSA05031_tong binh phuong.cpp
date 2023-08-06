#include <iostream>

using namespace std;

int qhd(int n) {
	int d[n + 1];
	for(int i = 0; i <= n; i++) {
		d[i] = i;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j * j <= n; j++) {
			if(i >= j * j) {
				d[i] = min(d[i], d[i - j * j] + 1);
			}
		}
	}
	return d[n];
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		cout << qhd(n) << endl;
	}
	return 0;
}
