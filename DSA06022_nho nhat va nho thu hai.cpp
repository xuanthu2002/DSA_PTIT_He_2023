#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int min_1 = 1e9, min_2 = 1e9;
		int x;
		for(int i = 0; i < n; i++) {
			cin >> x;
			if(x < min_1) {
				min_2 = min_1;
				min_1 = x;
			}
			if(x < min_2 && x > min_1) {
				min_2 = x;
			}
		}
		if(min_2 == 1e9) {
			cout << -1;
		}
		else {
			cout << min_1 << " " << min_2;
		}
		cout << endl;
	}
	return 0;
}

