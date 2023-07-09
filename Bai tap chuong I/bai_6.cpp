#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		string n;
		cin >> n;
		bool tang = false, giam = false;
		for(int i = 0; i < n.length() - 1; i++) {
			if(n[i] <= n[i + 1]) {
				tang = true;
			}
			if(n[i] >= n[i + 1]) {
				giam = true;
			}
		}
		if(tang && giam) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}

