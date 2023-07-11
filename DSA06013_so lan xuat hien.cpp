#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, x;
		cin >> n >> x;
		int kq = 0;
		int tmp;
		for(int i = 0; i < n; i++) {
			cin >> tmp;
			if(tmp == x) {
				kq += 1;
			}
		}
		cout << (kq == 0 ? -1 : kq) << endl;
	}
	return 0;
}

