#include <iostream>

using namespace std;

int a[100];
int n;

void quayLui(int i) {
	for(int j = 0; j < 2; j++) {
		a[i] = j;
		if(i == n - 1) {
			cout << a[0];
			for(int idx = 1; idx < n; idx++) {
				cout << (a[idx - 1] + a[idx]) % 2;
			}
			cout << " ";
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
		cout << endl;
	}
	return 0;
}

