#include <iostream>

using namespace std;

int a[100];
int n;

bool check() {
	for(int i = 2; i < n - 1; i++) {
		if((a[i] == 8 && a[i - 1] == 8) || (a[i - 2] == 6) && (a[i - 1] == 6 && a[i] == 6 && a[i + 1] == 6)) {
			return false;
		}
	}
	return true;
}

void quayLui(int i) {
	for(int j = 6; j <= 8; j += 2) {
		a[i] = j;
		if(i == n - 2) {
			if(check()) {
				for(int idx = 0; idx < n; idx++) {
					cout << a[idx];
				}
				cout << endl;
			}
		}
		else quayLui(i + 1);
	}
}

int main() {
	cin >> n;
	a[0] = 8;
	a[n - 1] = 6;
	a[1] = 6;
	quayLui(2);
	return 0;
}

