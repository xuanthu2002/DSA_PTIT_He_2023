#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		int s = 0;
		for(int i = 0; i < n; i++) {
			int x;
			cin >> x;
			s += x;
		}
		cout << (s % k == 0) << endl;	
	}
	return 0;
}

