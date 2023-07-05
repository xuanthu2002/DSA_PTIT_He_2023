#include <iostream>

using namespace std;

int a[100];
int n, k;

void quayLui(int i, int cnt) {
	for(int j = 0; j < 2; j++) {
		a[i] = j;
		cnt += j;
		if(i == n - 1) {
			if(cnt == k) {
				for(int idx = 0; idx < n; idx++) {
					cout << a[idx];
				}
				cout << endl;
			}
		}
		else quayLui(i + 1, cnt);
		cnt -= j; 
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		cin >> n >> k;
		quayLui(0, 0);
	}
	return 0;
}

