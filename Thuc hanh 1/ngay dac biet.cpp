#include <iostream>

using namespace std;

int a[6];

bool check() {
	return !((a[0] == 0 && a[1] == 0) || a[2] == 0);
}

void quayLui(int i) {
	int j = (i == 2) ? 2 : 0;
	for(int j = 0; j < 3; j += 2) {
		a[i] = j;
		if(i == 5) {
			if(check()) {
				cout << a[0] << a[1] << "/02/" << a[2] << a[3] << a[4] << a[5] << endl;
			}
		}
		else quayLui(i + 1);
	}
}

int main() {
	quayLui(0);
	return 0;
}

