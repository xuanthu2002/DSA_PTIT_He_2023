#include <iostream>

using namespace std;

int a[8];

bool check() {
	if(a[0] == 0 && a[1] == 0) return false;
	if(a[2] == 2 || a[3] == 0) return false;
	if(a[4] == 0) return false;
	return true;
}

void quayLui(int i) {
	for(int j = 0; j <= 2; j += 2) {
		a[i] = j;
		if(i == 7) {
			if(check()) {
				cout << a[0] << a[1] << "/" << a[2] << a[3] << "/" << a[4] << a[5] << a[6] << a[7] << endl;
			}
		}
		else quayLui(i + 1);
	}
}
int main() {
	quayLui(0);
	return 0;
}

