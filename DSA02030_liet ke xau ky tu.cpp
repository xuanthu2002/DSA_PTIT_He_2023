#include <iostream>

using namespace std;

int a[100];
int n, k;

void quayLui(int i) {
	for(int j = a[i - 1]; j <= n; j++) {
		a[i] = j;
		if(i == k) {
			for(int idx = 1; idx <= k; idx++) {
				cout << (char) ('A' + a[idx]);
			}
			cout << endl;
		}
		else quayLui(i + 1);
	}
}

int main() {
	char c;
	cin >> c >> k;
	a[0] = 0;
	n = (int) (c - 'A');
	quayLui(1);
	return 0;
}

