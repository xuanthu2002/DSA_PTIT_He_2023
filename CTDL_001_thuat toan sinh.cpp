#include <iostream>

using namespace std;

int a[20];
int n;

bool check() {
	int l = 0, r = n - 1;
	while(l < r) {
		if(a[l] != a[r]) {
			return false;
		}
		l += 1;
		r -= 1;
	}
	return true;
}

void quayLui(int i) {
	for(int j = 0; j < 2; j++) {
		a[i] = j;
		if(i == n - 1) {
			if(check()) {
				for(int idx = 0; idx < n; idx += 1) {
					cout << a[idx] << " ";
				}
				cout << endl;
			}
		}
		else quayLui(i + 1);
	}
}

int main() {
	cin >> n;
	quayLui(0);
	return 0;
}

