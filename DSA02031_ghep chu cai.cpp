#include <iostream>

using namespace std;

int a[100];
int n;
bool used[100] = {false};

bool isNguyenAm(int i) {
	return i == 0 || i == 4;
}

bool check() {
	for(int i = 1; i < n - 1; i++) {
		if(isNguyenAm(a[i]) && !isNguyenAm(a[i - 1]) && !isNguyenAm(a[i + 1]))
			return false;
	}
	return true;
}

void quayLui(int i) {
	for(int j = 0; j < n; j++) {
		if(!used[j]) {
			a[i] = j;
			used[j] = true;
			if(i == n - 1) {
				if(check()) {
					for(int idx = 0; idx < n; idx++) {
						cout << (char) ('A' + a[idx]);
					}
					cout << endl;
				}
			}
			else quayLui(i + 1);
			used[j] = false;
		}
	}
}

int main() {
	char c;
	cin >> c;
	n = c - 'A' + 1;
	quayLui(0);
	return 0;
}

