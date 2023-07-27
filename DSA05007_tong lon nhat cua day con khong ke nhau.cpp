#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int a[n + 3], b[n + 3] = {0};
		for(int i = 3; i <= n + 2; i++) {
			cin >> a[i];
			b[i] = max(b[i - 2], b[i - 3]) + a[i];
		}
		cout << max(b[n + 1], b[n + 2]) << endl;	
	}
	return 0;
}

