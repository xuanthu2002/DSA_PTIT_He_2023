#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, x;
		cin >> n >> x;
		int tmp;
		int kq = 0;
		for(int i = 0; i < n; i++) {
			cin >> tmp;
			if(tmp == x) {
				kq = i + 1;
			}
		}
		cout << kq << endl;
	}
	return 0;
}

