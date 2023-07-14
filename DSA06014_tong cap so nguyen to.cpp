#include <iostream>

using namespace std;

bool nt[1000001] = {false};

void sang() {
	for(int i = 2; i <= 1000000; i++) {
		nt[i] = true;
	}
	for(int i = 2; i <= 1000; i++) {
		if(nt[i]) {
			for(int j = i * i; j <= 1000000; j+= i) {
				nt[j] = false;
			}
		}
	}
}

int main() {
	sang();
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		bool kq = false;
		if(nt[n - 2]) {
			cout << 2 << " " << n - 2;
			kq = true;
		}
		for(int i = 3; i <= n / 2; i += 2) {
			if(nt[i] && nt[n - i]) {
				cout << i << " " << n - i;
				kq = true;
				break;
			}
		}
		if(!kq) cout << -1;
		cout << endl;
	}
	return 0;
}

