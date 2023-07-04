#include<iostream>

using namespace std;

int a[100];
int n;

bool check() {
	if(a[0] != 1 || a[n - 1] != 0) {
		return false;
	}
	for(int i = 0; i < n - 1; i++) {
		if(a[i] == 1 && a[i + 1] == 1) {
			return false;
		}
	}
	return true;
}

void quayLui(int i) {
	for(int j = 0; j < 2; j++) {
		a[i] = j;
		if(i == n - 1) {
			if(check()) {
				for(int idx = 0; idx < n; idx++) {
					if(a[idx] == 0) {
						cout << 'A';
					}
					else {
						cout << 'H';
					}
				}
				cout << endl;
			}
		}
		else quayLui(i + 1);
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		quayLui(0);
	}
	return 0;
}

